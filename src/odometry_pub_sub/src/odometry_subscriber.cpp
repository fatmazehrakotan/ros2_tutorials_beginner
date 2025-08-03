#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/msg/odometry.hpp"

class OdometrySubscriber : public rclcpp::Node
{
public:
    OdometrySubscriber() : Node("odometry_subscriber")
    {
        subscription_ = this->create_subscription<nav_msgs::msg::Odometry>(
            "/vehicle/odometry", 10,
            std::bind(&OdometrySubscriber::topic_callback, this, std::placeholders::_1));
    }

private:
    void topic_callback(const nav_msgs::msg::Odometry::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "Received Odometry: position=(%.2f, %.2f)",
                    msg->pose.pose.position.x, msg->pose.pose.position.y);
    }

    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr subscription_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<OdometrySubscriber>());
    rclcpp::shutdown();
    return 0;
}
