#include <Arduino.h>
#include "motor_task.h"
#include "wifi_task.h"

static MotorTask motor_task(0);
static WifiTask wifi_task(0, motor_task); // 建议将 WiFi 放在 core 1，与电机(core 0)分开

void setup() {
    Serial.begin(115200);
    
    // 启动任务（内部调用 xTaskCreatePinnedToCore）
    motor_task.begin();
    wifi_task.begin();
}

void loop() {
    // FreeRTOS 环境下 loop 保持为空
}