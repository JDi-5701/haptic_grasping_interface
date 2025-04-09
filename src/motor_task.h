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

#include "proto_gen/smartknob.pb.h"
#include "task.h"

enum class CommandType {
    CALIBRATE,
    CONFIG,
    HAPTIC,
};

struct HapticData {
    bool press;
};

struct Command {
    CommandType command_type;
    union CommandData {
        uint8_t unused;
        HapticData haptic;
    };
    CommandData data;
};

class MotorTask : public Task<MotorTask> {
    friend class Task<MotorTask>; // Allow base Task to invoke protected run()

    public:
        MotorTask(const uint8_t task_core);
        ~MotorTask();
        float tcp_force;
        int32_t knob_state;

        void addListener(QueueHandle_t queue);
    protected:
        void run();

    private:
        QueueHandle_t queue_;
        std::vector<QueueHandle_t> listeners_;
        char buf_[128];

        // BLDC motor & driver instance
        BLDCMotor motor = BLDCMotor(11, 8.8); // Motor pairs, phase resistance
        // BLDCDriver6PWM driver = BLDCDriver6PWM(PIN_UH, PIN_UL, PIN_VH, PIN_VL, PIN_WH, PIN_WL);
        BLDCDriver3PWM driver = BLDCDriver3PWM(32, 33, 25, 22); // PWM1, PWM2, PWM3, EN (using pin 22 which supports output)
        //BLDCDriver3PWM driver = BLDCDriver3PWM(26, 27, 14, 12);
        // InlineCurrentSense current_sense = InlineCurrentSense(0.01, 50.0, 35, 34);
        // PhaseCurrent_s currents;
        // float current_magnitude;
        // DQCurrent_s dq_current;

        void publish(const PB_KnobState& state);
        void checkSensorError();
};
