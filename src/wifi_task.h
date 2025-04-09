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

class WifiTask : public Task<WifiTask> {
    friend class Task<WifiTask>;

public:
    WifiTask(const uint8_t task_core, MotorTask& motor_task);
    virtual ~WifiTask();

    void sendActualKnobState(int32_t position, float force);
protected:
    void run();

private:
    WiFiUDP udp;
    MotorTask& motor_task_;  // Reference to motor task
    
    void setupWiFi();
    void receiveUdpForce();
};
    