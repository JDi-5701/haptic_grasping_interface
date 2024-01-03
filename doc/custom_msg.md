# How to use custom messages in PlatfromIO
`rosserial` 是一个用于 ROS (Robot Operating System) 的工具，允许 ROS 与嵌入式系统（如 Arduino、Raspberry Pi 等）进行通信。使用 `rosserial`，你可以在 ROS 和嵌入式设备之间发送和接收标准的 ROS 消息。

当你需要发送自定义的消息类型，你需要创建一个自定义的 ROS 消息，并在你的嵌入式系统和 ROS 主机上都有相应的定义。

以下是如何使用 `rosserial` 传递自定义消息类型的步骤：

1. **创建自定义消息**:
   在你的 ROS 包中，创建一个 `msg` 目录（如果还没有的话）。然后，在该目录下创建一个新的 `.msg` 文件来定义你的自定义消息。例如，你可以创建一个名为 `MyCustomMessage.msg` 的文件，内容如下：

   ```
   int32 data1
   string data2
   ```

2. **修改 CMakeLists.txt 和 package.xml**:
   确保你的 `CMakeLists.txt` 和 `package.xml` 文件已经正确配置，以便编译和安装你的自定义消息。

3. **编译消息**:
   在你的 ROS 工作区中，运行以下命令来编译你的消息：

   ```
   catkin_make
   ```

4. **生成 rosserial Arduino 库**:
   为了在 Arduino 上使用这个自定义消息，你需要生成一个更新的 `rosserial` Arduino 库，这样 Arduino 代码就可以知道这个新的消息类型了。在你的 ROS 环境中运行：

   ```
   rosrun rosserial_arduino make_libraries.py <path_to_your_arduino_libraries_directory>
   ```

5. **编写 Arduino 代码**:
   在你的 Arduino 代码中，你现在可以包含并使用这个新的消息类型了：

   ```cpp
   #include <ros.h>
   #include <your_package_name/MyCustomMessage.h>

   ros::NodeHandle nh;
   your_package_name::MyCustomMessage custom_msg;
   ros::Publisher pub("topic_name", &custom_msg);

   void setup() {
     nh.initNode();
     nh.advertise(pub);
   }

   void loop() {
     custom_msg.data1 = 123;
     custom_msg.data2 = "Hello";
     pub.publish(&custom_msg);
     nh.spinOnce();
     delay(1000);
   }
   ```

6. **在 ROS 中接收自定义消息**:
   你可以像处理任何其他 ROS 消息一样，使用 `rostopic` 和 `rosnode` 工具或在你的 ROS 节点中编写代码来处理这个自定义消息。

这就是如何使用 `rosserial` 传递自定义消息类型的基本步骤。希望对你有所帮助！