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

float MotorTask::computeForceFeedback(float gripper_force) {
    // --- 可调参数 ---
    constexpr float FORCE_FEEDBACK_RATIO = 0.1f;
    constexpr float FORCE_OFFSET = 0.5f;
    constexpr float LOG_A = 2.085f;
    constexpr float LOG_B = 1.0f;
    constexpr float MAX_OUTPUT = 5.0f;
    constexpr float DEADZONE = 0.1f;
    constexpr float CLAMP_MIN = 0.0f;
    constexpr float CLAMP_MAX = 1.0f;

    // 1. 线性预处理
    float force_input = FORCE_FEEDBACK_RATIO * (gripper_force + FORCE_OFFSET);
    force_input = std::max(force_input, 0.0f);  // 忽略负值

    // 2. 非线性对数映射
    float force_human = LOG_A * logf(1.0f + LOG_B * force_input);

    // 3. 死区
    if (fabsf(force_human) < DEADZONE)
        force_human = 0.0f;

    // 4. 限幅
    if (force_human > 0.0f)
        force_human = std::min(CLAMP_MAX, std::max(CLAMP_MIN, force_human));
    else
        force_human = std::max(-CLAMP_MAX, std::min(-CLAMP_MIN, force_human));

    // 5. 输出方向（必要时反向）
    return force_human;
}

void MotorTask::run(){

    pinMode(13, OUTPUT); // Using pin 13 instead of 12 for ESP32 compatibility
    digitalWrite(13, LOW); // Explicitly set to LOW

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

    uint64_t last_cycle_start = micros();
    while (1)
    {

        int32_t current_force_id = force_id;
        uint64_t current_force_time = force_timestamp;
        float current_force = tcp_force;

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
            motor_command = computeForceFeedback(current_force);

            // Serial.print("tcp_force: ");
            // Serial.print(tcp_force);
            // Serial.print("motor_command: ");
            // Serial.print(motor_command);

            motor.move(motor_command);

        }


        knob_state = int32_t(1000 * angle_to_detent_center);
        /* Serial.print("motor task knob state:");
        Serial.print(knob_state);
        Serial.print("\t");  */

        motor_torque = motor.voltage.q;

        
        // Serial.print("tcp_force: ");
        // Serial.print(tcp_force);
        // Serial.print("Applied voltage (V): ");
        // Serial.println(motor.voltage.q);

        // Serial.print("Controller type: ");
        // Serial.println((int)motor.controller);

        // Serial.print("Torque controller type: ");
        // Serial.println((int)motor.torque_controller);

        motor.monitor();
        
        vTaskDelay(pdMS_TO_TICKS(1));


        uint64_t now = micros();
        uint64_t cycle_time = now - last_cycle_start;
        last_cycle_start = now;

        static uint64_t cycle_sum = 0;
        static uint64_t cycle_max = 0;
        static int cycle_count = 0;

        cycle_sum += cycle_time;
        if (cycle_time > cycle_max) {
            cycle_max = cycle_time;
        }
        cycle_count++;

        if (cycle_count >= 400) {
            uint64_t cycle_avg = cycle_sum / cycle_count;
            Serial.printf("[Motor Task Cycle] avg: %llu µs | max: %llu µs\n",
                        (unsigned long long)cycle_avg,
                        (unsigned long long)cycle_max);
            // reset
            cycle_sum = 0;
            cycle_max = 0;
            cycle_count = 0;
            Serial.printf("[MotorTask] Running on core: %d\n", xPortGetCoreID());
        }

    }
}