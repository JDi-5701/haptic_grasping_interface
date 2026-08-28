# OmniHGI: Omni-directional Haptic Grasping Interface

**OmniHGI** is a high-bandwidth, dual-axis electromagnetic haptic interface specifically engineered for **wearable robot teleoperation**. By utilizing a high-speed UDP-based control loop, it enables users to perceive real-time lateral shear forces and friction during remote grasping tasks, significantly enhancing telepresence and manipulation precision.

This repository contains the **ESP32 Real-Time Firmware** (C++/FreeRTOS) and the **ROS 2 UDP Driver** (Python) required to bridge tactile sensor data to physical actuation.

---

## 1. System Architecture

The OmniHGI system operates in a high-speed distributed loop to maintain haptic transparency:

1.  **Tactile Sensing (ROS 1)**: High-frequency force acquisition from a Paxini PX6AX tactile sensor.
2.  **Protocol Translation (ros1_bridge)**: Dynamic bridging of `WrenchStamped` messages from ROS 1 to ROS 2.
3.  **Command Center (ROS 2 Node)**: A dedicated Python controller that extracts force vectors, applies manual scaling (Ratio), and enforces safety limits.
4.  **Hardware Execution (ESP32)**: A dual-core FreeRTOS implementation receiving UDP packets at **200Hz** and driving H-Bridge circuits at **1000Hz**.

---

## 2. Hardware Setup

### Component List
* **Microcontroller**: ESP32 DevKit V1.
* **Actuators**: Dual-axis electromagnetic coils (X and Y).
* **Motor Driver**: H-Bridge module (DRV8833, TB6612FNG, or L298N).
* **Power Supply**: External 5V-12V DC (Ensure a common ground between the ESP32 and the driver).

### Pin Mapping (ESP32)

| Component | GPIO | LEDC Channel | Function |
| :--- | :--- | :--- | :--- |
| **X-Axis FWD** | 25 | 0 | X-Forward PWM |
| **X-Axis REV** | 26 | 1 | X-Reverse PWM |
| **Y-Axis FWD** | 14 | 2 | Y-Forward PWM |
| **Y-Axis REV** | 27 | 3 | Y-Reverse PWM |
| **GND** | GND | - | Shared Ground |

---

## 3. Software Components

### A. Real-Time Firmware (`/firmware`)
The firmware is optimized for the ESP32 dual-core architecture:
* **Motor Control (Core 0)**: Runs a deterministic 1kHz loop for PWM generation.
* **WiFi Stack (Core 1)**: Manages asynchronous UDP communication and frequency monitoring.
* **Safety Watchdog**: Includes a 500ms fail-safe. If no UDP command is received within 0.5s, the coils are automatically de-energized to prevent thermal damage.
* **Live Diagnostics**: Outputs `Motor Task Hz` and `WiFi Rx Hz` to the serial monitor for latency analysis.

### B. ROS 2 UDP Driver (`/scripts/omni_hgi_driver.py`)
This node bridges the ROS 2 ecosystem with the hardware:
* **Topic**: Subscribes to `/tactile_resultant_wrench` (`geometry_msgs/msg/WrenchStamped`).
* **Tunable Parameters**: 
    * `RATIO`: Manual gain (Duty Cycle per Newton).
    * `MAX_DUTY`: Hard safety limit for PWM output (e.g., `0.5` for 50%).
* **Telemetry**: Provides 10Hz logging of the current command sent to the hardware.

---

## 4. Quick Start Guide

### Firmware Deployment
1. Open the firmware project in **PlatformIO**.
2. Set your WiFi credentials in the `STASSID` and `STAPSK` variables.
3. Flash the ESP32 and confirm the Static IP via the Serial Monitor (Default: `10.0.0.188`).

### Running the Driver
```bash
# In your ROS 2 workspace
source install/setup.bash
python3 omni_hgi_udp_driver.py
