#include "cpp_subscriber.hpp"

CppSubscriberNode::CppSubscriberNode(const std::string &node_name, const std::string &topic_name)
    : Node(node_name)
{
    this->node_name_ = node_name;
    this->topic_name_ = topic_name;

    subscription_ = this->create_subscription<example_interfaces::msg::String>(topic_name,
                    10, std::bind(&CppSubscriberNode::callback, this, std::placeholders::_1));

    RCLCPP_INFO(this->get_logger(), "The node %s has been created.", this->node_name_.c_str());
}

void CppSubscriberNode::callback(const example_interfaces::msg::String::SharedPtr msg) {
    RCLCPP_INFO(this->get_logger(), "%s", msg->data.c_str());
}