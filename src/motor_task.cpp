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

// Merkel mechanism state
bool merkel_active = false;
uint64_t merkel_start_time = 0;
constexpr float MERKEL_TRIGGER_THRESHOLD = 2.0f;
constexpr float MERKEL_FORCE_N = 6.0f;
constexpr uint64_t MERKEL_DURATION_US = 500000; // 0.5 seconds
float merkel_delta = 1.0f;  // to be initialized in run()

bool isInContact(float current_force) {
    static bool IN_CONTACT = false;
    // 判断是否接触
    static float prev_force = 0.0f;
    
    if (prev_force <= MERKEL_TRIGGER_THRESHOLD &&
        current_force > MERKEL_TRIGGER_THRESHOLD) {
            IN_CONTACT = true;
    } else if (current_force < MERKEL_TRIGGER_THRESHOLD) {
        IN_CONTACT = false;
        }
    
    prev_force = current_force;

    return IN_CONTACT;
}

float applyMerkelMechanism(float current_force) {
    static bool merkel_active = false;
    static uint64_t merkel_start_time = 0;
    uint64_t now_us = micros();

    // 在外部触发时调用此函数才算激活，内部只计时
    if (!merkel_active) {
        merkel_active = true;
        merkel_start_time = now_us;
    }

    if (now_us - merkel_start_time <= MERKEL_DURATION_US) {
        return merkel_delta;
    } else {
        merkel_active = false;
        return 0.0;
    }
}

float applyPacinianMechanism(float current_force) {
    uint64_t now_us = micros();
    // 参数设定
    constexpr float PACINIAN_FREQ = 40.0f;        // 固定频率 (Hz)
    constexpr float AMPLITUDE = 2.0f;          // 最大振幅

    static uint64_t pacinian_start_time = 0;

    if (pacinian_start_time == 0) {
        pacinian_start_time = now_us;
    }

    float t = (now_us - pacinian_start_time) / 1e6f; // 秒
    float pacinian_force = AMPLITUDE * sinf(2.0f * PI * PACINIAN_FREQ * t);

    return pacinian_force;
}


float MotorTask::computeForceFeedback(float gripper_force) {
    // --- 可调参数 ---
    constexpr float FORCE_FEEDBACK_RATIO = 0.1f;
    constexpr float FORCE_OFFSET = 0.2f;
    constexpr float LOG_A = 0.3f;
    constexpr float LOG_B = 5.0f;
    constexpr float CLAMP_MIN = 0.0f;
    constexpr float CLAMP_MAX = 2.0f;
    static bool IN_CONTACT = false;

    float merkel_force;
    float pacinian_force;
    float gripper_force_with_merkel_with_pacinian;

    IN_CONTACT = isInContact(gripper_force);
    if (IN_CONTACT) {
        // 如果接触，应用 Merkel 和 Pacinian 机制
        merkel_force = applyMerkelMechanism(gripper_force);
        pacinian_force = applyPacinianMechanism(gripper_force);
    } else {
        // 如果没有接触，直接返回原始力
        merkel_force = 0.0f;
        pacinian_force = 0.0f;
    }

    gripper_force_with_merkel_with_pacinian = gripper_force + merkel_force + pacinian_force;

    // 1. 线性预处理
    float force_input = FORCE_FEEDBACK_RATIO * (gripper_force_with_merkel_with_pacinian + FORCE_OFFSET);
    force_input = std::max(force_input, 0.0f);  // 忽略负值

    // 2. 非线性对数映射
    float force_human = LOG_A * logf(1.0f + LOG_B * force_input);

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
    I2Cone.setPins(21, 22);
    encoder.init(&I2Cone);
    motor.linkSensor(&encoder);

    motor.voltage_limit = 8;
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

            motor.move(-1.0 * motor_command);

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