/*
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 *
 *    Copyright (c) 2023 fortiss GmbH, Xiangyu Fu
 *    All rights reserved.
 */

#include "wifi_task.h"
#include <IPAddress.h>
#include "WiFi.h"

// WiFi

struct FSRMsg {
    int32_t id;
    int32_t fsr_value;
    float force_filtered;
    uint64_t timestamp;
};

// wifi_task.h 中的 WifiTask 私有变量
uint64_t esp1_sync_micros = 0;
uint64_t esp2_sync_micros = 0;
bool time_synced = false;


// External
// IPAddress ip(10, 0, 25, 243);
// IPAddress server(10, 0, 25, 142);
// uint16_t serverPort = 11411;
// const char*  ssid = "external";
// const char*  password = "WirelessNetzwerkbetrieb";


// cobot 
IPAddress ip(10, 200, 2, 148);
IPAddress server(10, 200, 2, 102);
uint16_t serverPort = 5001;
uint16_t localPort = 5000;  // Local port to receive UDP messages
IPAddress gateway(10, 200, 2, 1);     // Replace with your actual gateway
IPAddress subnet(255, 255, 255, 0);   // Typical subnet
const char*  ssid = "acra4dt-wifi";
const char*  password = "PaulanerSpezi";
/* const char*  ssid = "cobot-t2-wifi";
const char*  password = "PaulanerSpezi"; */

/* IPAddress ip(192, 168, 3, 101);
IPAddress server(192, 168, 3, 71);
uint16_t serverPort = 11411;
const char*  ssid = "Xiaomi_E2CC";
const char*  password = "12345678"; */

/* IPAddress ip(192, 168, 2, 119);
IPAddress server(192, 168, 2, 104);
uint16_t serverPort = 11411;
const char*  ssid = "WLAN-5FMWSL";
const char*  password = "1616149905085129"; */

// cobot-t1-wifi
// IPAddress ip(10, 200, 2, 148);
// IPAddress server(10, 200, 2, 144);
// uint16_t serverPort = 11411;
// const char*  ssid = "cobot-t1-wifi";
// const char*  password = "PaulanerSpezi_3Bc5gpysrFypN";

// Other Wifi
// IPAddress ip(192, 168, 178, 153);
// IPAddress server(192, 168, 178, 69);
// uint16_t serverPort = 11411;
// const char*  ssid = "FRITZ!Box 7530 JQ";
// const char*  password = "27635171366830739521";

//extern float tcp_force;
//extern int32_t knob_state;

WifiTask::WifiTask(const uint8_t task_core, MotorTask& motor_task) 
    : Task("Wifi", 3000, 1, task_core),
      motor_task_(motor_task) {
    Serial.println("WifiTask constructor start");
}

void WifiTask::sendActualKnobState(const MotorMsg& msg) {
    if (udp.beginPacket(server, serverPort)) {
        Serial.printf(
            "MotorMsg {\n"
            "  id: %d\n"
            "  fsr_value: %d\n"
            "  force_filtered: %.2f N\n"
            "  force_timestamp: %llu µs\n"
            "  motor_timestamp: %llu µs\n"
            "  motor_torque: %.2f V\n"
            "  knob_state: %d\n"
            "}\n",
            (int)msg.id,
            (int)msg.fsr_value,
            msg.force_filtered,
            (unsigned long long)msg.force_timestamp,
            (unsigned long long)msg.motor_timestamp,
            msg.motor_torque,
            (int)msg.knob_state
        );

        Serial.printf("sizeof(MotorMsg): %d\n", sizeof(MotorMsg));

        udp.write((uint8_t*)&msg, sizeof(msg));

        if (!udp.endPacket()) {
            Serial.println("Failed to send UDP packet");
        }
    } else {
        Serial.println("Failed to begin UDP packet");
    }
}

void WifiTask::receiveUdpForce() {
    int packetSize = udp.parsePacket();
    if (packetSize == sizeof(FSRMsg)) {
        FSRMsg msg;
        udp.read((uint8_t*)&msg, sizeof(msg));

        if (!time_synced) {
            esp1_sync_micros = msg.timestamp;
            esp2_sync_micros = micros();
            time_synced = true;

            Serial.printf("[SYNC] Synced at: esp1 = %llu, esp2 = %llu\n",
                          (unsigned long long)esp1_sync_micros,
                          (unsigned long long)esp2_sync_micros);
        }

        // 使用同步点换算为 ESP2 上的时间戳
        uint64_t corrected_time = esp2_sync_micros + (msg.timestamp - esp1_sync_micros);

        Serial.printf("Received force id:%d, FSR: %d, Force: %.2f N\n", msg.id, msg.fsr_value, msg.force_filtered);
        Serial.printf("Original Force Time: %llu µs → Corrected (ESP2): %llu µs\n",
                      (unsigned long long)msg.timestamp, (unsigned long long)corrected_time);

        motor_task_.tcp_force = msg.force_filtered;
        motor_task_.force_timestamp = corrected_time;
        motor_task_.fsr_value = msg.fsr_value;
        motor_task_.force_id = msg.id; 

    } else if (packetSize > 0) {
        Serial.printf("Warning: Received packet of unexpected size %d (expected %lu)\n",
                      packetSize, sizeof(FSRMsg));
    }
}


void WifiTask::setupWiFi() {
    Serial.println("Starting WiFi setup...");
    vTaskDelay(pdMS_TO_TICKS(1000));
    
    WiFi.disconnect();
    WiFi.mode(WIFI_STA);
    
    Serial.println("Connecting to WiFi...");
    WiFi.config(ip, gateway, subnet);
    WiFi.begin(ssid, password);
 
    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < 20) {
        delay(500);
        Serial.print(".");
        attempts++;
    }
    
    if (WiFi.status() != WL_CONNECTED) {
        Serial.println("\nFailed to connect to WiFi");
        return;
    }
    
    Serial.print("\nSSID: ");
    Serial.println(WiFi.SSID());
    Serial.print("IP: ");
    Serial.println(WiFi.localIP());

    // Initialize UDP
    if (udp.begin(localPort)) {
        Serial.printf("UDP initialized on port %d\n", localPort);
    } else {
        Serial.println("Failed to initialize UDP");
    }
}

void WifiTask::run() {
    setupWiFi();
    
    for(;;) {
        if (WiFi.status() != WL_CONNECTED) {
            Serial.println("WiFi connection lost, reconnecting...");
            setupWiFi();
            vTaskDelay(pdMS_TO_TICKS(1000));
            continue;
        }
        
        // Send current knob state from motor task
        MotorMsg msg;
        msg.id = motor_task_.force_id; // Current force ID
        msg.fsr_value = motor_task_.fsr_value;                 // 如果你还保留
        msg.force_filtered = motor_task_.tcp_force;
        msg.force_timestamp = motor_task_.force_timestamp;
        msg.motor_timestamp = motor_task_.motor_timestamp;
        msg.motor_torque = motor_task_.motor_torque;
        msg.knob_state = motor_task_.knob_state;  // Current knob state

        sendActualKnobState(msg);
        
        // Check for incoming force messages
        receiveUdpForce();
        
        // Small delay between messages
        vTaskDelay(pdMS_TO_TICKS(10));  // 100ms delay
    }
}

WifiTask::~WifiTask() {
    udp.stop();
}