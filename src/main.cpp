/*
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 *
 *    Copyright (c) 2023 fortiss GmbH, Xiangyu Fu
 *    All rights reserved.
 */
#include <Arduino.h>
#include <SimpleFOC.h>

#include "motor_task.h"
// #include "interface_task.h"
#include "wifi_task.h"
#include "task.h"

static MotorTask motor_task(0);
static WifiTask wifi_task(0, motor_task);
// static InterfaceTask interface_task(0, motor_task, wifi_task);

void setup() {
    // Initialize serial communication
    Serial.begin(115200);
    delay(1000);  // Give time for serial to initialize
    Serial.println("\n\nStarting...");
    Serial.println("Testing serial output...");
    Serial.flush();
    
    // Initialize tasks
    wifi_task.begin();
    motor_task.begin();
    // interface_task.begin();
    
    // Start the scheduler
    //vTaskStartScheduler();
}

void loop() {
    // Not used - FreeRTOS scheduler handles task execution
}