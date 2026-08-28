#include "motor_task.h"

MotorTask::MotorTask(const uint8_t task_core) 
    : Task("Motor", 4096, 10, task_core) { // 优先级较高，确保实时性
}

void MotorTask::setupHardware() {
    // 初始化 LEDC
    ledcSetup(CH_X_FWD, PWM_CARRIER_HZ, PWM_RES_BITS);
    ledcSetup(CH_X_REV, PWM_CARRIER_HZ, PWM_RES_BITS);
    ledcSetup(CH_Y_FWD, PWM_CARRIER_HZ, PWM_RES_BITS);
    ledcSetup(CH_Y_REV, PWM_CARRIER_HZ, PWM_RES_BITS);

    ledcAttachPin(PIN_X_FWD, CH_X_FWD);
    ledcAttachPin(PIN_X_REV, CH_X_REV);
    ledcAttachPin(PIN_Y_FWD, CH_Y_FWD);
    ledcAttachPin(PIN_Y_REV, CH_Y_REV);

    // 初始关闭
    ledcWrite(CH_X_FWD, 0);
    ledcWrite(CH_X_REV, 0);
    ledcWrite(CH_Y_FWD, 0);
    ledcWrite(CH_Y_REV, 0);
}

// 将 -1.0 ~ 1.0 的力转换为 PWM 计数
uint32_t MotorTask::forceToCounts(float force_val) {
    float magnitude = fabs(force_val);
    if (magnitude > 1.0f) magnitude = 1.0f; // 限幅
    uint32_t max_counts = (1UL << PWM_RES_BITS) - 1;
    return (uint32_t)(magnitude * max_counts);
}

// 核心 H 桥控制逻辑 (移除 Delay 以适配实时任务)
void MotorTask::applyCoilControl(int ch_fwd, int ch_rev, float force) {
    uint32_t duty = forceToCounts(force);

    if (force > 0.001f) {
        // 正向：关闭 REV，开启 FWD
        ledcWrite(ch_rev, 0);
        ledcWrite(ch_fwd, duty);
    } else if (force < -0.001f) {
        // 反向：关闭 FWD，开启 REV
        ledcWrite(ch_fwd, 0);
        ledcWrite(ch_rev, duty);
    } else {
        // 停止
        ledcWrite(ch_fwd, 0);
        ledcWrite(ch_rev, 0);
    }
}

void MotorTask::run() {
    setupHardware();
    
    TickType_t xLastWakeTime = xTaskGetTickCount();
    const TickType_t xFrequency = pdMS_TO_TICKS(1); // 目标 1kHz

    // --- 频率监控变量 ---
    uint32_t loop_count = 0;
    uint32_t last_report_time = millis();

    for(;;) {
        loop_count++;

        // 安全检查
        if (micros() - force_timestamp > 500000) {
            force_x = 0;
            force_y = 0;
        }

        applyCoilControl(CH_X_FWD, CH_X_REV, force_x);
        applyCoilControl(CH_Y_FWD, CH_Y_REV, force_y);

        // --- 每隔 1 秒打印一次频率 ---
        if (millis() - last_report_time >= 1000) {
            Serial.printf("[Monitor] Motor Task Hz: %u\n", loop_count);
            loop_count = 0;
            last_report_time = millis();
        }

        vTaskDelayUntil(&xLastWakeTime, xFrequency);
    }
}

MotorTask::~MotorTask() {
    // 析构时安全关闭
    ledcWrite(CH_X_FWD, 0);
    ledcWrite(CH_X_REV, 0);
    ledcWrite(CH_Y_FWD, 0);
    ledcWrite(CH_Y_REV, 0);
}