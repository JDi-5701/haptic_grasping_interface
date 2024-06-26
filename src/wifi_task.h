/*
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 *
 *    Copyright (c) 2023 fortiss GmbH, Xiangyu Fu
 *    All rights reserved.
 */
#pragma once

#include <Arduino.h>
#include <ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Int32.h>
#include <std_msgs/Float32.h>
#include <vector>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "logger.h" 
#include "task.h"
#include "proto_gen/smartknob.pb.h"
#include "knob_robot_control/KnobState.h"
#include "knob_robot_control/KnobCommand.h"


class WifiTask : public Task<WifiTask> {
    friend class Task<WifiTask>; // Allow base Task to invoke protected run()

public:
    WifiTask(const uint8_t task_core);
    ~WifiTask();

    void addListener(QueueHandle_t queue);
    void setLogger(Logger* logger);
    void publish(const PB_SmartKnobConfig & config);
    static void StaticCommandCallback(const knob_robot_control::KnobCommand& msg);
    static void TcpForceCallback(const std_msgs::Float32& msg);

protected:
    void run();

private:
    // QueueHandle_t uart_queue_;
    Logger* logger_;
    std::vector<QueueHandle_t> listeners_;
    PB_SmartKnobConfig wifiConfig;
    static WifiTask* instance;
    

    void loop();
    void setupWiFi();
    void CommandCallback(const knob_robot_control::KnobCommand& msg);

};
    