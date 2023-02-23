#include "rclcpp/rclcpp.hpp"
#include "example_interfaces/msg/string.hpp"

class CppPublisherNode : public rclcpp::Node
{
public:
    CppPublisherNode(const std::string & node_name, const std::string & topic_name);

private:
    void publish();

    rclcpp::Publisher<example_interfaces::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

    std::string node_name_;
    std::string topic_name_;
};