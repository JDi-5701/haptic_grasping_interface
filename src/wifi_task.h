/*
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 *
 *    Copyright (c) 2023 fortiss GmbH, Xiangyu Fu
 *    All rights reserved.
 */
#pragma once

#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include <vector>

#include "task.h"
#include "motor_task.h"

#pragma pack(push, 1)
struct MotorMsg {
    int32_t id;
    int32_t fsr_value;
    float force_filtered;
    uint64_t force_timestamp;
    uint64_t motor_timestamp;
    float motor_torque;
    int32_t knob_state;
};
#pragma pack(pop)

class WifiTask : public Task<WifiTask> {
    friend class Task<WifiTask>;

public:
    WifiTask(const uint8_t task_core, MotorTask& motor_task);
    virtual ~WifiTask();

    void sendActualKnobState(const MotorMsg& msg);
protected:
    void run();

private:
    WiFiUDP udp;
    MotorTask& motor_task_;  // Reference to motor task
    
    void setupWiFi();
    void receiveUdpForce();

};
    