#pragma once
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include "task.h"
#include "motor_task.h"

// 结构体定义：必须与发送端（如 Python）保持字节对齐一致
struct MotorMsg { 
    int32_t knob_state; 
};

struct ForceMsg { 
    float force_x; 
    float force_y; 
};

class WifiTask : public Task<WifiTask> {
    friend class Task<WifiTask>;

public:
    WifiTask(const uint8_t task_core, MotorTask& motor_task);
    virtual ~WifiTask();

    // 任务主体逻辑
    void run(); 

    // 发送电机状态到服务器
    void sendMotorState(const MotorMsg& msg);

private:
    WiFiUDP udp;
    MotorTask& motor_task_;
    
    // 内部辅助函数
    void setupWiFi();
    void receiveUDP();
};