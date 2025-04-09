/*
 * This file is subject to the terms and conditions defined in
 * file 'LICENSE', which is part of this source code package.
 *
 *    Copyright (c) 2023 fortiss GmbH, Xiangyu Fu
 *    All rights reserved.
 */

#include "interface_task.h"

#define COUNT_OF(A) (sizeof(A) / sizeof(A[0]))

// Force feedback
float tcp_force = 0.0;

InterfaceTask::InterfaceTask(const uint8_t task_core, MotorTask& motor_task, WifiTask& wifi_task) :
    Task("Interface", 3000, 1, task_core),
    motor_task_(motor_task),
    wifi_task_(wifi_task) {
    
    log_queue_ = xQueueCreate(10, sizeof(std::string *));
    assert(log_queue_ != NULL);

    knob_state_queue_ = xQueueCreate(1, sizeof(PB_KnobState));
    assert(knob_state_queue_ != NULL);

    wifi_queue_if = xQueueCreate(1, sizeof(PB_TcpForce));
    assert(wifi_queue_if != NULL);
}

void InterfaceTask::run() {
    // Set up the motor task
    motor_task_.addListener(knob_state_queue_);
    
    for(;;) {
        PB_KnobState state;
        if (xQueueReceive(knob_state_queue_, &state, 0) == pdTRUE) {
            // Send actual knob state to WiFi task
            wifi_task_.sendActualKnobState(state.position, state.force);
            vTaskDelay(pdMS_TO_TICKS(5));
        }

        PB_TcpForce force;
        if (xQueueReceive(wifi_queue_if, &force, 0) == pdTRUE) {
            // Update the global tcp_force variable
            tcp_force = force.force;
        }

        vTaskDelay(pdMS_TO_TICKS(1));
    }
}

void InterfaceTask::addListener(QueueHandle_t queue) {
    listeners_.push_back(queue);
}
