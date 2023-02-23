#include "cpp_publisher.hpp"

CppPublisherNode::CppPublisherNode(const std::string &node_name, const std::string &topic_name)
    : Node(node_name)
{
    this->node_name_ = node_name;
    this->topic_name_ = topic_name;

    publisher_ = this->create_publisher<example_interfaces::msg::String>(topic_name, 10);
    timer_ = this->create_wall_timer(std::chrono::milliseconds(500),
                                     std::bind(&CppPublisherNode::publish, this));
    RCLCPP_INFO(this->get_logger(), "Created publisher");
}

void CppPublisherNode::publish()
{
    auto msg = example_interfaces::msg::String();
    msg.data = std::string("Hello, this is ") + node_name_ + std::string("!");

    publisher_->publish(msg);
}