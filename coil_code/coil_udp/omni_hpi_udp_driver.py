#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from std_msgs.msg import Int32
from geometry_msgs.msg import Vector3  # 使用 Vector3 处理 XYZ
import socket
import struct

# --- 网络配置 (根据你当前的 WiFi 测试结果修改) ---
PC_IP = "0.0.0.0"
PC_PORT = 5001
ESP32_IP = "192.168.2.200"  # 你刚才 Ping 通的 IP
ESP32_PORT = 5000

# --- 结构体定义 (严格匹配 ESP32 端) ---
# ESP32 接收: ForceMsg { float x, float y } -> 8 bytes
UDP_TX_FORMAT = "<ff" 
# ESP32 发送: MotorMsg { int32 knob_state } -> 4 bytes
UDP_RX_FORMAT = "<i"
UDP_RX_SIZE = struct.calcsize(UDP_RX_FORMAT)

class Esp32ForceInterface(Node):
    def __init__(self):
        super().__init__('esp32_force_interface')
        
        # 1. ROS 2 话题
        # 发布来自 ESP32 的旋钮位置
        self.publisher_ = self.create_publisher(Int32, 'knob_state', 10)
        # 订阅来自算法层或手柄的 3D 力指令
        self.subscription = self.create_subscription(
            Vector3, 'force_command_xyz', self.force_callback, 10)
        
        # 2. UDP 套接字
        self.sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        self.sock.bind((PC_IP, PC_PORT))
        self.sock.setblocking(False)
        
        # 3. 状态变量
        self.cmd_x = 0.0
        self.cmd_y = 0.0
        self.cmd_z = 0.0 # 预留 Z 轴，虽然目前线圈只有 XY

        # 4. 循环定时器 (100Hz)
        self.timer = self.create_timer(0.01, self.udp_loop)
        self.get_logger().info(f'UDP Bridge Active: Sending to {ESP32_IP}:{ESP32_PORT}')

    def force_callback(self, msg):
        # 限制输出范围在 -1.0 到 1.0 之间，防止线圈过热
        self.cmd_x = max(min(msg.x, 1.0), -1.0)
        self.cmd_y = max(min(msg.y, 1.0), -1.0)
        self.cmd_z = msg.z # Z 轴数据已接收，但暂不发送给硬件

    def udp_loop(self):
        # A. 发送力指令给 ESP32 (仅发送 XY)
        try:
            # 打包为 2 个 float (8 bytes)
            tx_data = struct.pack(UDP_TX_FORMAT, float(self.cmd_x), float(self.cmd_y))
            self.sock.sendto(tx_data, (ESP32_IP, ESP32_PORT))
        except Exception as e:
            self.get_logger().error(f'UDP Send Error: {e}')

        # B. 接收来自 ESP32 的反馈
        try:
            data, addr = self.sock.recvfrom(1024)
            if len(data) == UDP_RX_SIZE:
                # 解包 4 字节整数
                raw_state = struct.unpack(UDP_RX_FORMAT, data)[0]
                
                # 发布到 ROS 话题
                msg = Int32()
                msg.data = raw_state
                self.publisher_.publish(msg)
        except BlockingIOError:
            pass # 没有收到数据包，跳过
        except Exception as e:
            self.get_logger().error(f'UDP Recv Error: {e}')

    def destroy_node(self):
        self.sock.close()
        super().destroy_node()

def main(args=None):
    rclpy.init(args=args)
    node = Esp32ForceInterface()
    try:
        rclpy.spin(node)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()