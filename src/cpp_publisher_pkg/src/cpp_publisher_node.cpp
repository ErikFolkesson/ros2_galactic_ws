#include "rclcpp/rclcpp.hpp"

class MyNode: public rclcpp::Node // Create a class with the type Node
{
public:
    MyNode(): Node("cpp_test") // Create a Node object. This is a constructor.
    {
        RCLCPP_INFO(this->get_logger(), "Hello C++ ROS");
    }

private:

};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv); // Initilize

    /* make_shared creates a shared pointer. This is used almost everywhere in ROS C++ */
    /* Create a node from the class MyNode */
    auto node = std::make_shared<MyNode>();

    rclcpp::spin(node); // Keep the node awake.

    rclcpp::shutdown(); // Shutdown
    return 0;
}