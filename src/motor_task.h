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

    protected:
        void run();

    private:

        // BLDC motor & driver instance
        BLDCMotor motor = BLDCMotor(11, 6.5); // Motor pairs, phase resistance
        // BLDCDriver6PWM driver = BLDCDriver6PWM(PIN_UH, PIN_UL, PIN_VH, PIN_VL, PIN_WH, PIN_WL);
        BLDCDriver3PWM driver = BLDCDriver3PWM(32, 33, 25, 26); // PWM1, PWM2, PWM3, EN (using pin 22 which supports output)
        //BLDCDriver3PWM driver = BLDCDriver3PWM(26, 27, 14, 12);
        // InlineCurrentSense current_sense = InlineCurrentSense(0.01, 50.0, 35, 34);
        // PhaseCurrent_s currents;
        // float current_magnitude;
        // DQCurrent_s dq_current;
        
        float computeForceFeedback(float gripper_force);
};
