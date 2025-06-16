/*
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 *
 *    Copyright (c) 2023 fortiss GmbH, Xiangyu Fu
 *    All rights reserved.
 */
#include <SimpleFOC.h>

#include "motor_task.h"

// #### 
// Hardware-specific motor calibration constants.
// Run calibration once at startup, then update these constants with the calibration results.
static const float ZERO_ELECTRICAL_OFFSET = 2.35;
static const Direction FOC_DIRECTION = Direction::CW;
static const int MOTOR_POLE_PAIRS = 11;
// ####


MotorTask::MotorTask(const uint8_t task_core) : Task("Motor", 2500, 1, task_core) {
    Serial.println("MotorTask constructor start");
}

MotorTask::~MotorTask() {}

MagneticSensorI2C encoder = MagneticSensorI2C(AS5600_I2C);
TwoWire I2Cone = TwoWire(0);

float target_angle = 5.0;
long timestamp_us = _micros();

void MotorTask::run(){

    pinMode(13, OUTPUT); // Using pin 13 instead of 12 for ESP32 compatibility
    digitalWrite(13, LOW); // Explicitly set to LOW

    motor.controller = MotionControlType::torque;
    motor.controller = MotionControlType::torque;
motor.torque_controller = TorqueControlType::voltage;

    // motor setup
    driver.voltage_power_supply = 12;
    driver.init();
    motor.linkDriver(&driver);

    // Initialize the I2C bus
    I2Cone.setPins(4, 0);
    encoder.init(&I2Cone);
    motor.linkSensor(&encoder);

    motor.voltage_limit = 6;
    motor.velocity_limit = 1000;
    motor.pole_pairs = MOTOR_POLE_PAIRS;

    /* Calibration of motor and sensors*/
    
    motor.init();
    motor.controller = MotionControlType::torque;
motor.torque_controller = TorqueControlType::voltage;
    motor.initFOC();

    motor.controller = MotionControlType::torque;
    motor.torque_controller = TorqueControlType::voltage;

    encoder.update(); // here is from the future version of SimpleFOC
    vTaskDelay(pdMS_TO_TICKS(10));

    motor.monitor_downsample = 0; // disable monitor at first - optional

    float initial_poistion = encoder.getAngle();

    uint32_t last_publish = 0;

    Serial.println("Motor ready!");
    tcp_force = 0.0;
    knob_state = 0;
    while (1)
    {
        motor.loopFOC();

        // print current position, after checking the sensor reading is work well
    
        char str_angle[100];
        float encoder_angle = encoder.getAngle();    

        float angle_to_detent_center = encoder.getAngle() - initial_poistion;

        float torque = 0;
        if (fabsf(motor.shaft_velocity) > 600) {
            motor.move(0);
        } else {
            // Apply TCP force feedback
            //torque = motor.PID_velocity(-0.1 * tcp_force);
            motor.move(-1 * tcp_force);

            /* Serial.print("tcp_force:");
            Serial.print(tcp_force);
            Serial.print("\t"); */
        }


        knob_state = int32_t(1000 * angle_to_detent_center);
        /* Serial.print("motor task knob state:");
        Serial.print(knob_state);
        Serial.print("\t");  */

        motor_torque = motor.voltage.q;
        
        Serial.print("tcp_force: ");
        Serial.print(tcp_force);
        Serial.print("Applied voltage (V): ");
        Serial.println(motor.voltage.q);

        Serial.print("Controller type: ");
        Serial.println((int)motor.controller);

        Serial.print("Torque controller type: ");
        Serial.println((int)motor.torque_controller);

        motor.monitor();
        
        vTaskDelay(pdMS_TO_TICKS(1));
    }
}