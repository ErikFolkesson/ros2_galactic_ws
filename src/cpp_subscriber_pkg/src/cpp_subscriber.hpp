#include "rclcpp/rclcpp.hpp"

class CppSubscriberNode : public rclcpp::Node
{
public:
    CppSubscriberNode(const std::string &node_name, const std::string &topic_name);

private:
    std::string node_name_;
    std::string topic_name_;
};