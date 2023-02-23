#include "cpp_subscriber.hpp"

CppSubscriberNode::CppSubscriberNode(const std::string &node_name, const std::string &topic_name)
    : Node(node_name)
{
    this->node_name_ = node_name;
    this->topic_name_ = topic_name;

    RCLCPP_INFO(this->get_logger(), std::string("Created node: ") + node_name_;
}