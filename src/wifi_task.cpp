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


// External
// IPAddress ip(10, 0, 25, 243);
// IPAddress server(10, 0, 25, 142);
// uint16_t serverPort = 11411;
// const char*  ssid = "external";
// const char*  password = "WirelessNetzwerkbetrieb";


// cobot 
/* IPAddress ip(10, 200, 2, 148);
IPAddress server(10, 200, 2, 81);
uint16_t serverPort = 11411;
const char*  ssid = "cobot-t2-wifi";
const char*  password = "PaulanerSpezi"; */

/* IPAddress ip(192, 168, 3, 101);
IPAddress server(192, 168, 3, 71);
uint16_t serverPort = 11411;
const char*  ssid = "Xiaomi_E2CC";
const char*  password = "12345678"; */

IPAddress ip(192, 168, 2, 119);
IPAddress server(192, 168, 2, 104);
uint16_t serverPort = 11411;
const char*  ssid = "WLAN-5FMWSL";
const char*  password = "1616149905085129";

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

uint16_t period = 1000;
uint32_t last_time = 0;

// Static member initialization
WifiTask* WifiTask::instance = nullptr;

// ROS
ros::NodeHandle  nh;
knob_robot_control::KnobState knob_state_msg;
knob_robot_control::KnobCommand knob_command_msg;
ros::Publisher knob_state_publisher("knob_state", &knob_state_msg);
ros::Subscriber<knob_robot_control::KnobCommand> knob_command_subscriber("knob_command", &WifiTask::StaticCommandCallback);
ros::Subscriber<std_msgs::Float32> tcp_force_subscriber("tcp_force", &WifiTask::TcpForceCallback);

// Force feedback
float tcp_force = 0.0;

static float tcp_force_process(float force){
  if(force > 0.0){
    return force;
  } else {
    return force;
  }
}

WifiTask::WifiTask(const uint8_t task_core) : Task("WIFI Task", 8192, 0, task_core) {
    // wifi_queue_ = xQueueCreate(1, sizeof(WifiConfig));
    instance = this;
}

WifiTask::~WifiTask() {
    // Destructor code here
    instance = nullptr;
}

void WifiTask::StaticCommandCallback(const knob_robot_control::KnobCommand& msg) {
    if (instance) {
        instance->CommandCallback(msg);
    }
}

void WifiTask::addListener(QueueHandle_t queue) {
    Serial.println("Add listener");
    listeners_.push_back(queue);
}

void WifiTask::setLogger(Logger* logger) {
    logger_ = logger;
}

// publish is used for the logger
void WifiTask::publish(const PB_SmartKnobConfig & config) {
    for (auto listener : listeners_) {
        xQueueOverwrite(listener, &config); // xQueueOverwrite will overwrite the queue if it is full
    }
}

void WifiTask::TcpForceCallback(const std_msgs::Float32& msg){
  tcp_force = tcp_force_process(msg.data);
}

// CommandCallback is used for the subscriber
void WifiTask::CommandCallback(const knob_robot_control::KnobCommand& msg){

  std::string command_type = msg.text.data;
  // check if command_type incluedes "force"
  if (command_type.find("force") != std::string::npos)
  {
    tcp_force = tcp_force_process(msg.tcp_force.data);
  } else {
    // for configuration
    wifiConfig.num_positions = msg.num_positions.data;
    wifiConfig.position = msg.position.data;
    wifiConfig.position_width_radians = msg.position_width_radians.data; 
    wifiConfig.detent_strength_unit = msg.detent_strength_unit.data;
    wifiConfig.endstop_strength_unit = msg.endstop_strength_unit.data;
    wifiConfig.snap_point = msg.snap_point.data;

    // for haptic feedback
    tcp_force = tcp_force_process(msg.tcp_force.data);

    strcpy(wifiConfig.text, msg.text.data);
    publish(wifiConfig);
  }
}

void WifiTask::run(){
  setupWiFi();

  nh.getHardware()->setConnection(server, serverPort);
  nh.initNode();

  // Another way to get IP
  Serial.print("ROS IP = ");
  Serial.println(nh.getHardware()->getLocalIP());

  // Start ros publisher
  nh.advertise(knob_state_publisher);

  // Start ros subscriber
  nh.subscribe(knob_command_subscriber);
  nh.subscribe(tcp_force_subscriber);
  
  for(;;){
    if(millis() - last_time >= period)
    {
      last_time = millis();
      if (nh.connected())
      {

      } else {
        Serial.println("Not Connected");
      }
    }
    nh.spinOnce();
    vTaskDelay(pdMS_TO_TICKS(20));
  }
}

void WifiTask::setupWiFi()
{  
    vTaskDelay(pdMS_TO_TICKS(1000));
    Serial.println("Connecting to WiFi");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) { delay(500);Serial.print("."); }
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());
    Serial.print("IP:   ");
    Serial.println(WiFi.localIP());
}