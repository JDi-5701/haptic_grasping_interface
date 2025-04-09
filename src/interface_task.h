#pragma once

#include <Arduino.h>
#include <vector>

#include "motor_task.h"
#include "wifi_task.h"
#include "task.h"
#include "proto_gen/smartknob.pb.h"

class InterfaceTask : public Task<InterfaceTask> {
    friend class Task<InterfaceTask>; // Allow base Task to invoke protected run()

    public:
        // InterfaceTask(const uint8_t task_core, MotorTask& motor_task, UARTTask& uart_task);
        InterfaceTask(const uint8_t task_core, MotorTask& motor_task, WifiTask& wifi_task);
        virtual ~InterfaceTask() {};

        void addListener(QueueHandle_t queue);

    protected:
        void run();

    private:
        std::vector<QueueHandle_t> listeners_;
        MotorTask& motor_task_;
        // UARTTask& uart_task_;
        WifiTask& wifi_task_;
        char buf_[64];

        int current_config_ = 0;

        QueueHandle_t log_queue_;
        QueueHandle_t knob_state_queue_;
        // QueueHandle_t uart_queue_if;
        QueueHandle_t wifi_queue_if;

        void updateHardware();
};
