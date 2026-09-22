/*
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 *
 *    Copyright (c) 2023 fortiss GmbH, Xiangyu Fu
 *    All rights reserved.
 */
#pragma once

#include <Arduino.h>
#include <SimpleFOC.h>
#include <vector>

#include "task.h"

// #### 2D 电磁线圈配置 (集成自 coil_code/coil_udp) ####
// 线圈工程 X 轴原用 GPIO 25/26, 与本工程 BLDC 驱动 (32, 33, 25, 26) 冲突, 故 X 轴改用 16/17
//#define PIN_COIL_X_FWD 16
//#define PIN_COIL_X_REV 17
#define PIN_COIL_X_FWD 4
#define PIN_COIL_X_REV 23
#define PIN_COIL_Y_FWD 14
#define PIN_COIL_Y_REV 27

// LEDC PWM: 通道 4-7 避开 SimpleFOC 可能使用的 LEDC 通道 0-3
#define COIL_PWM_RES_BITS     10
#define COIL_PWM_CARRIER_HZ   5000.0f

class MotorTask : public Task<MotorTask> {
    friend class Task<MotorTask>; // Allow base Task to invoke protected run()

    public:
        MotorTask(const uint8_t task_core);
        ~MotorTask();
        float tcp_force;
        int32_t knob_state;
        int32_t fsr_value;
        uint64_t force_timestamp; // Timestamp of the last received force value
        float motor_torque = 0.0; // Current torque applied to the moto
        uint64_t motor_timestamp = 0.0; // Timestamp of the last torque value
        float motor_command = 0.0; // Current position of the motor in radians
        int32_t force_id = -1;

        // --- 2D 线圈力指令 (由 WifiTask 写入, 本任务消费) ---
        volatile float coil_force_x = 0.0f;
        volatile float coil_force_y = 0.0f;
        volatile uint32_t coil_timestamp = 0; // 最近一次线圈指令时间 (µs)

    protected:
        void run();

    private:

        // BLDC motor & driver instance
        BLDCMotor motor = BLDCMotor(11, 4.4); // Motor pairs, phase resistance (line-to-neutral = 8.8Ω phase-to-phase / 2)
        // BLDCDriver6PWM driver = BLDCDriver6PWM(PIN_UH, PIN_UL, PIN_VH, PIN_VL, PIN_WH, PIN_WL);
        BLDCDriver3PWM driver = BLDCDriver3PWM(32, 33, 25, 26); // PWM1, PWM2, PWM3, EN (using pin 22 which supports output)
        //BLDCDriver3PWM driver = BLDCDriver3PWM(26, 27, 14, 12);
        // InlineCurrentSense current_sense = InlineCurrentSense(0.01, 50.0, 35, 34);
        // PhaseCurrent_s currents;
        // float current_magnitude;
        // DQCurrent_s dq_current;
        
        // --- 2D 线圈控制 (H 桥) ---
        const int CH_X_FWD = 4;
        const int CH_X_REV = 5;
        const int CH_Y_FWD = 6;
        const int CH_Y_REV = 7;

        void setupCoilHardware();
        void applyCoilControl(int ch_fwd, int ch_rev, float force);
        uint32_t forceToCounts(float force_val);

        float computeForceFeedback(float gripper_force);
};
