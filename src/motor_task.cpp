/*
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 *
 *    Copyright (c) 2023 fortiss GmbH, Xiangyu Fu
 *    All rights reserved.
 */
#include <SimpleFOC.h>

#include "motor_task.h"
#include "proto_gen/smartknob.pb.h"

// #### 
// Hardware-specific motor calibration constants.
// Run calibration once at startup, then update these constants with the calibration results.
static const float ZERO_ELECTRICAL_OFFSET = 2.77;
static const Direction FOC_DIRECTION = Direction::CW;
static const int MOTOR_POLE_PAIRS = 11;
// ####


// force feedback
//extern float tcp_force;
//extern int32_t knob_state;

MotorTask::MotorTask(const uint8_t task_core) : Task("Motor", 2500, 1, task_core) {
    queue_ = xQueueCreate(5, sizeof(Command));
    assert(queue_ != NULL);
}

MotorTask::~MotorTask() {}

MagneticSensorI2C encoder = MagneticSensorI2C(AS5600_I2C);
TwoWire I2Cone = TwoWire(0);

float target_angle = 5.0;
long timestamp_us = _micros();

void MotorTask::run(){

    pinMode(13, OUTPUT); // Using pin 13 instead of 12 for ESP32 compatibility
    digitalWrite(13, LOW); // Explicitly set to LOW

    // motor setup
    driver.voltage_power_supply = 12;
    driver.init();

    motor.linkDriver(&driver);

    // Initialize the I2C bus
    I2Cone.setPins(4, 0);
    encoder.init(&I2Cone);


    motor.voltage_limit = 12;
    motor.velocity_limit = 10000;
    motor.linkSensor(&encoder);

    motor.controller = MotionControlType::torque;

    // velocity control loop setup
    motor.PID_velocity.P = 1.4;    // Reduced from 1.0
    motor.PID_velocity.I = 0.0;   // Added small I term
    motor.PID_velocity.D = 0.0;    // Keep D at 0
    motor.PID_velocity.output_ramp = 1000;  // Reduced from 10000
    motor.PID_velocity.limit = 2;  // Keep same limit

    /* Calibration of motor and sensors*/
    motor.init();

    encoder.update(); // here is from the future version of SimpleFOC
    vTaskDelay(pdMS_TO_TICKS(10));

    motor.pole_pairs = MOTOR_POLE_PAIRS;
    motor.initFOC();
    // motor.initFOC(ZERO_ELECTRICAL_OFFSET, FOC_DIRECTION); // the calibration routine is called inside the init function
    // command.add('T', doTarget, "target velocity");
    
    motor.monitor_downsample = 0; // disable monitor at first - optional


    float current_detent_center = encoder.getAngle();

    uint32_t last_publish = 0;

    // PB_SmartKnobConfig latest_config = config;

    // UART setup
    // Serial.begin(115200);
    Serial.println("Motor ready!");
    // Serial.println("Set target velocity [rad/s]");
    tcp_force = 0.0;
    knob_state = 0;
    while (1)
    {
        motor.loopFOC();

        // print current position, after checking the sensor reading is work well
    
        char str_angle[100];
        float encoder_angle = encoder.getAngle();
        float motor_angle = motor.shaft_angle;
        float angle_difference = motor_angle - encoder_angle;
       
        /* Serial.print("Encoder: ");
        Serial.print(encoder_angle, 4);
        Serial.print(", Motor: ");
        Serial.print(motor_angle, 4);
        Serial.print(", Diff: ");
        Serial.println(angle_difference, 4); */

        float angle_to_detent_center = encoder.getAngle() - current_detent_center;

        float torque = 0;
        if (fabsf(motor.shaft_velocity) > 60) {
            motor.move(0);
        } else {
            // Apply TCP force feedback
            torque = motor.PID_velocity(-0.1 * tcp_force);
            motor.move(torque);

            /* Serial.print("tcp_force:");
            Serial.print(tcp_force);
            Serial.print("\t"); */
        }


        knob_state = int32_t(100 * angle_to_detent_center);
        /* Serial.print("motor task knob state:");
        Serial.print(knob_state);
        Serial.print("\t");  */

        motor.monitor();
        
        vTaskDelay(pdMS_TO_TICKS(1));

        /* Serial.print("tcp_force:");
        Serial.print(tcp_force);
        Serial.print("\t"); */
    }

}

void MotorTask::publish(const PB_KnobState& state) {
    // Send to all listeners
    for (auto listener : listeners_) {
        xQueueOverwrite(listener, &state);
    }
}

void MotorTask::addListener(QueueHandle_t queue) {
    listeners_.push_back(queue);
}