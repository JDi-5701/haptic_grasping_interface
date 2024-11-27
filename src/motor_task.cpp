/*
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 *
 *    Copyright (c) 2023 fortiss GmbH, Xiangyu Fu
 *    All rights reserved.
 */
#include <SimpleFOC.h>

#include "motor_task.h"
#if SENSOR_MT6701
#include "mt6701_sensor.h"
#endif
#if SENSOR_TLV
#include "tlv_sensor.h"
#endif
#include "util.h"


// #### 
// Hardware-specific motor calibration constants.
// Run calibration once at startup, then update these constants with the calibration results.
static const float ZERO_ELECTRICAL_OFFSET = 2.77;
static const Direction FOC_DIRECTION = Direction::CW;
static const int MOTOR_POLE_PAIRS = 7;
// ####


static const float DEAD_ZONE_DETENT_PERCENT = 0.1;
static const float DEAD_ZONE_RAD = 0.1 * _PI / 180;

static const float IDLE_VELOCITY_EWMA_ALPHA = 0.001;
static const float IDLE_VELOCITY_RAD_PER_SEC = 0.05;
static const uint32_t IDLE_CORRECTION_DELAY_MILLIS = 500;
static const float IDLE_CORRECTION_MAX_ANGLE_RAD = 5 * PI / 180;
static const float IDLE_CORRECTION_RATE_ALPHA = 0.0005;


// force feedback
extern float tcp_force;

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

    // motor setup
    driver.voltage_power_supply = 12;
    driver.init();

    motor.linkDriver(&driver);

    // Initialize the I2C bus
    I2Cone.setPins(19, 18);
    encoder.init(&I2Cone);

    motor.controller = MotionControlType::torque;
    motor.voltage_limit = 5;
    motor.velocity_limit = 10000;
    motor.linkSensor(&encoder);


    // velocity control loop setup
    motor.PID_velocity.P = 0;
    motor.PID_velocity.I = 0;
    motor.PID_velocity.D = 0;
    motor.PID_velocity.output_ramp = 10000; 
    motor.PID_velocity.limit = 2;

    // velocity low pass filter time constant
    //motor.LPF_velocity.Tf = 0.01;

    // // angle control loop setup
    // motor.P_angle.P = 5;
    // motor.P_angle.I = 0;
    // motor.P_angle.D = 0;
    // // acceleration limit for angle control loop
    // motor.P_angle.output_ramp = 10000;

    // /* motion control limitation */
    // // maximal voltage for motor
    // motor.voltage_limit = 12;
    // // current limitation - if phase resistance is set
    // motor.current_limit = 3;
    // // set the maximal velocity limit
    // motor.velocity_limit = 4;

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
    PB_SmartKnobConfig config = {
        .num_positions = 2,
        .position = 0,
        .position_width_radians = 60 * _PI / 180,
        .detent_strength_unit = 0,
    };

    uint32_t last_publish = 0;

    // PB_SmartKnobConfig latest_config = config;

    // UART setup
    // Serial.begin(115200);
    Serial.println("Motor ready!");
    // Serial.println("Set target velocity [rad/s]");
    tcp_force = 0.0;
    while (1)
    {
        motor.loopFOC();

        // print current position, after checking the sensor reading is work well
    
        char str_angle[100];
        float encoder_angle = encoder.getAngle();
        float motor_angle = motor.shaft_angle;
        float angle_difference = motor_angle - encoder_angle;
       
        Serial.print("Encoder: ");
        Serial.print(encoder_angle, 4);
        Serial.print(", Motor: ");
        Serial.print(motor_angle, 4);
        Serial.print(", Diff: ");
        Serial.println(angle_difference, 4);

        float angle_to_detent_center = encoder.getAngle() - current_detent_center;

        motor.PID_velocity.limit = 2;
        motor.PID_velocity.P = 0.9;

        float torqueMsg = 0;
        if (fabsf(motor.shaft_velocity) > 60) {
            motor.move(0);
        } else {
            float torque = motor.PID_velocity(-0.1 * tcp_force);
            
            #if SK_INVERT_ROTATION
            torque = -torque;
            #endif
            motor.move(torque);
            torqueMsg = torque;
        }

        // Publish current status to other registered tasks periodically
        int32_t pub_pos = int32_t(100*angle_to_detent_center);
        if (millis() - last_publish > 5) {
            publish({
                .current_position = pub_pos,
                .sub_position_unit = 0,
                .has_config = true,
                .current_force = torqueMsg,
                .config = config,
            });
            last_publish = millis();
        }

        motor.monitor();
        
        vTaskDelay(pdMS_TO_TICKS(1));
    }
}


void MotorTask::setConfig(const PB_SmartKnobConfig& config) {
    Command command = {
        .command_type = CommandType::CONFIG,
        .data = {
            .config = config,
        }
    };
    xQueueSend(queue_, &command, portMAX_DELAY);
}


void MotorTask::playHaptic(bool press) {
    Command command = {
        .command_type = CommandType::HAPTIC,
        .data = {
            .haptic = {
                .press = press,
            },
        }
    };
    xQueueSend(queue_, &command, portMAX_DELAY);
}

// this addListener is used for the logger
void MotorTask::addListener(QueueHandle_t queue) {
    listeners_.push_back(queue); // push_back is a vector method
}

// publish is used for the logger
void MotorTask::publish(const PB_SmartKnobState& state) {
    for (auto listener : listeners_) {
        xQueueOverwrite(listener, &state); // xQueueOverwrite will overwrite the queue if it is full
    }
}

// not work because the macro is not defined
void MotorTask::checkSensorError() {
#if SENSOR_TLV
    if (encoder.getAndClearError()) {
        log("LOCKED!");
    }
#elif SENSOR_MT6701
    MT6701Error error = encoder.getAndClearError();
    if (error.error) {
        snprintf(buf_, sizeof(buf_), "CRC error. Received %d; calculated %d", error.received_crc, error.calculated_crc);
        log(buf_);
    }
#endif
}

void MotorTask::setLogger(Logger* logger) {
    logger_ = logger;
}

void MotorTask::log(const char* msg) {
    if (logger_ != nullptr) {
        logger_->log(msg);
    }
}