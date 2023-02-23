#include "cpp_publisher.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv); // Initilize

    auto node = std::make_shared<CppPublisherNode>("robot_news_station_node",
                                                   "robot_news_station_topic");

    rclcpp::spin(node); // Keep the node awake.

    rclcpp::shutdown(); // Shutdown
    return 0;
}