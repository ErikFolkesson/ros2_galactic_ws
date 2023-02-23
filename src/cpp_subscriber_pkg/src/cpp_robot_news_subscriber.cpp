#include "cpp_subscriber.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv); // Initilize

    auto node = std::make_shared<CppSubscriberNode>("robot_news_subscriber", "robot_news_topic");

    rclcpp::spin(node); // Keep the node awake.

    rclcpp::shutdown(); // Shutdown
    return 0;
}