#pragma once

#include <Arduino.h>
#include "task.h"

// 硬件引脚定义
#define PIN_X_FWD 25
#define PIN_X_REV 26
#define PIN_Y_FWD 14
#define PIN_Y_REV 27

// PWM 配置
#define PWM_RES_BITS     10
#define PWM_CARRIER_HZ   20000.0

class MotorTask : public Task<MotorTask> {
    friend class Task<MotorTask>;

public:
    MotorTask(const uint8_t task_core);
    virtual ~MotorTask();

    // 被 WifiTask 异步更新的变量
    volatile float force_x = 0.0f;
    volatile float force_y = 0.0f;
    volatile uint32_t force_timestamp = 0;
    
    // 供 WifiTask 读取的状态
    volatile int32_t knob_state = 0;

protected:
    void run();

private:
    // LEDC 通道分配
    const int CH_X_FWD = 0;
    const int CH_X_REV = 1;
    const int CH_Y_FWD = 2;
    const int CH_Y_REV = 3;

    void setupHardware();
    void applyCoilControl(int ch_fwd, int ch_rev, float force);
    uint32_t forceToCounts(float force_val);
};