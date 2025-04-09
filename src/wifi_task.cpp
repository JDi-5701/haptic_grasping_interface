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
#include "pb_encode.h"
#include "pb_decode.h"
#include "pb.h"


// WiFi


// External
// IPAddress ip(10, 0, 25, 243);
// IPAddress server(10, 0, 25, 142);
// uint16_t serverPort = 11411;
// const char*  ssid = "external";
// const char*  password = "WirelessNetzwerkbetrieb";


// cobot 
IPAddress ip(10, 200, 2, 148);
IPAddress server(10, 200, 2, 81);
uint16_t serverPort = 5000;
uint16_t localPort = 5000;  // Local port to receive UDP messages
IPAddress gateway(10, 200, 2, 1);     // Replace with your actual gateway
IPAddress subnet(255, 255, 255, 0);   // Typical subnet
const char*  ssid = "cobot-t2-wifi";
const char*  password = "PaulanerSpezi";

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

void WifiTask::addListener(QueueHandle_t queue) {
    listeners_.push_back(queue);
}

void WifiTask::sendActualKnobState(int32_t position, float force) {
    if (udp.beginPacket(server, serverPort)) {
        Serial.printf("Sending position: %d, force: %.2f\n", position, force);
        udp.write((uint8_t*)&position, sizeof(position));
        udp.write((uint8_t*)&force, sizeof(force));
        if (!udp.endPacket()) {
            Serial.println("Failed to send UDP packet");
        }
    } else {
        Serial.println("Failed to begin UDP packet");
    }
}

void WifiTask::receiveUdpForce() {
    int packetSize = udp.parsePacket();
    if (packetSize) {
        Serial.printf("Received packet of size %d\n", packetSize);
        float received_force;
        udp.read((uint8_t*)&received_force, sizeof(received_force));
        Serial.printf("Received Force: %.2f\n", received_force);
        motor_task_.tcp_force = received_force;  // Update motor task directly
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
        sendActualKnobState(motor_task_.knob_state, 0.0f);
        
        // Check for incoming force messages
        receiveUdpForce();
        
        // Small delay between messages
        vTaskDelay(pdMS_TO_TICKS(100));  // 100ms delay
    }
}

WifiTask::~WifiTask() {
    udp.stop();
}