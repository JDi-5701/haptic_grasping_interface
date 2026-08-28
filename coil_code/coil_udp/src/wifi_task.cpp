#include "wifi_task.h"

/* ===================== 网络配置 ===================== */
// IPAddress ip(192, 168, 2, 200);      // ESP32 静态 IP
// IPAddress gateway(192, 168, 2, 1);   // 默认网关
// IPAddress subnet(255, 255, 255, 0);  // 子网掩码
// IPAddress server(192, 168, 2, 104);  // 笔记本/服务器 IP

// uint16_t serverPort = 5001;          // 笔记本监听端口
// uint16_t localPort = 5000;           // ESP32 监听端口
// const char* ssid = "WLAN-5FMWSL";
// const char* password = "1616149905085129";

// Network Configuration
// IPAddress ip(10, 200, 2, 148);
// IPAddress server(10, 200, 2, 83);
// uint16_t serverPort = 5001;
// uint16_t localPort = 5000;
// IPAddress gateway(10, 200, 2, 1);
// IPAddress subnet(255, 255, 255, 0);
// const char* ssid = "cobot-t2-wifi";
// const char* password = "PaulanerSpezi";

IPAddress ip(10, 200, 2, 148);
IPAddress server(10, 200, 2, 193);
uint16_t serverPort = 5001;
uint16_t localPort = 5000;
IPAddress gateway(10, 200, 2, 1);
IPAddress subnet(255, 255, 255, 0);
const char* ssid = "cobot-t2-wifi";
const char* password = "fortiss123!!!";

/* ===================== 构造与析构 ===================== */
WifiTask::WifiTask(const uint8_t task_core, MotorTask& motor_task) 
    : Task("Wifi", 4096, 1, task_core), 
      motor_task_(motor_task) {
}

WifiTask::~WifiTask() {
    udp.stop();
}

/* ===================== WiFi 初始化 ===================== */
void WifiTask::setupWiFi() {
    Serial.println("\n[WiFi] Debug: Entering setupWiFi...");
    delay(1000); // 额外等待供电稳定

    WiFi.disconnect(true); // 清除旧配置
    WiFi.mode(WIFI_STA);
    
    Serial.println("[WiFi] Debug: Configuring Static IP...");
    if (!WiFi.config(ip, gateway, subnet)) {
        Serial.println("[WiFi] Error: Static IP config failed.");
    }

    Serial.printf("[WiFi] Debug: Calling WiFi.begin(%s)...\n", ssid);
    WiFi.begin(ssid, password);

    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < 40) { // 增加重试次数
        delay(500);
        // 打印当前的 WiFi 状态码，方便排查
        Serial.printf("Status: %d ", WiFi.status()); 
        attempts++;
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println("\n[WiFi] Success! IP: " + WiFi.localIP().toString());
        udp.begin(localPort);
    } else {
        Serial.printf("\n[WiFi] Failed. Final Status Code: %d\n", WiFi.status());
    }
}
/* ===================== UDP 发送 ===================== */
void WifiTask::sendMotorState(const MotorMsg& msg) {
    if (udp.beginPacket(server, serverPort)) {
        udp.write((uint8_t*)&msg, sizeof(MotorMsg));
        udp.endPacket();
    }
}

/* ===================== UDP 接收 ===================== */
void WifiTask::receiveUDP() {
    int packetSize = udp.parsePacket();
    
    if (packetSize == sizeof(ForceMsg)) { 
        ForceMsg incoming;
        udp.read((uint8_t*)&incoming, sizeof(ForceMsg));

        motor_task_.force_x = incoming.force_x;
        motor_task_.force_y = incoming.force_y;
        motor_task_.force_timestamp = micros();

        // --- 新增：每收到 100 个包打印一次，确认数据正确 ---
        static int debug_counter = 0;
        if (++debug_counter >= 100) {
            Serial.printf("[UDP] Rx Force - X: %.2f, Y: %.2f\n", incoming.force_x, incoming.force_y);
            debug_counter = 0;
        }
    } else if (packetSize > 0) {
        udp.flush();
    }
}

/* ===================== 任务循环 ===================== */
void WifiTask::run() {
    setupWiFi();
    
    // --- 频率监控变量 ---
    uint32_t packet_count = 0;
    uint32_t last_report_time = millis();

    for(;;) {
        if (WiFi.status() == WL_CONNECTED) {
            // 1. 发送反馈
            MotorMsg tx_msg;
            tx_msg.knob_state = motor_task_.knob_state;
            sendMotorState(tx_msg);

            // 2. 接收并统计有效包
            int packetSize = udp.parsePacket();
            if (packetSize == sizeof(ForceMsg)) { 
                ForceMsg incoming;
                udp.read((uint8_t*)&incoming, sizeof(ForceMsg));
                motor_task_.force_x = incoming.force_x;
                motor_task_.force_y = incoming.force_y;
                motor_task_.force_timestamp = micros();
                
                packet_count++; // 仅统计有效数据包
            }

            // --- 每隔 1 秒打印一次接收频率 ---
            if (millis() - last_report_time >= 1000) {
                Serial.printf("[Monitor] WiFi Rx Hz: %u\n", packet_count);
                packet_count = 0;
                last_report_time = millis();
            }

        } else {
            setupWiFi();
            vTaskDelay(pdMS_TO_TICKS(1000));
            continue;
        }

        vTaskDelay(pdMS_TO_TICKS(10)); // 任务自身循环约 100Hz
    }
}