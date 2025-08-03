#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"

class OdometryPublisher : public rclcpp::Node
{
public:
    OdometryPublisher() : Node("odometry_publisher")
    {
        publisher_ = this->create_publisher<nav_msgs::msg::Odometry>("/vehicle/odometry", 10);
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(33),  // ~30 Hz
            std::bind(&OdometryPublisher::publish_odometry, this));
    }

private:
    void publish_odometry()
    {
        auto msg = nav_msgs::msg::Odometry();
        msg.header.stamp = this->now();
        msg.header.frame_id = "odom";
        msg.child_frame_id = "base_link";

        // Örnek veriler
        msg.pose.pose.position.x = 1.0;
        msg.pose.pose.position.y = 2.0;
        msg.pose.pose.position.z = 0.0;

        msg.twist.twist.linear.x = 0.5;
        msg.twist.twist.angular.z = 0.1;
        std::cout << "mesaj okey \n";
        publisher_->publish(msg);
    }

    rclcpp::Publisher<nav_msgs::msg::Odometry>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<OdometryPublisher>());
    rclcpp::shutdown();
    return 0;
}

