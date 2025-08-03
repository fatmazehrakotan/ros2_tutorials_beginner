<!-- # 🚗 ROS2 Odometry Publisher & Subscriber Project

This project demonstrates how to create a basic ROS 2 workspace, build a custom package, and implement a publisher and subscriber using `nav_msgs/msg/Odometry` messages. Developed as part of a beginner ROS 2 tutorial series.

---

## 🏗️ Project Setup

### ✅ 1. Create a ROS 2 Workspace

```bash
mkdir -p ~/ros2_ws/src
cd ~/ros2_ws/
colcon build
source install/setup.bash


### ✅ 2. Create a Package

cd ~/ros2_ws/srcgit sy
ros2 pkg create --build-type ament_cmake odometry_pub_sub


### ✅ 2. Create a Package

cd ~/ros2_ws/src
ros2 pkg create --build-type ament_cmake <package_name>
ros2 pkg create --build-type ament_cmake --node-name my_node my_package
cd ~/ros2_ws
colcon build -->
