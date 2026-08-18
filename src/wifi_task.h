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
// 回传状态包 (12 字节): id=包序号, motor_torque=q轴电压(V), knob_state=旋钮位置(毫弧度)
struct MotorMsg {
    int32_t id;
    float motor_torque;
    int32_t knob_state;
};
#pragma pack(pop)

// 3D 力指令 (来自 PC/ROS 驱动, 12 字节):
//   force_x / force_y -> 2D 电磁线圈
//   force_z           -> 旋钮力反馈 (对应原来的 1D 力)
struct ForceMsg3D {
    float force_x;
    float force_y;
    float force_z;
};

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
    