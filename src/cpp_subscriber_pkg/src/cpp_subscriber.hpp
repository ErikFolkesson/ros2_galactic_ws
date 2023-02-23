#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

class CppSubscriberNode : public rclcpp::Node
{
public:
    CppSubscriberNode(const std::string &node_name, const std::string &topic_name);

private:
    void callback(const example_interfaces::msg::String::SharedPtr msg);

    rclcpp::Subscription<example_interfaces::msg::String>::SharedPtr subscription_;

    std::string node_name_;
    std::string topic_name_;
};