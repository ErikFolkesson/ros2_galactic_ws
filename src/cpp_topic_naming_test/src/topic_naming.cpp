#include "camera_handler/camera_publisher.hpp"

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);

    auto node1 = std::make_shared<CameraPublisherNode>("pub_1", "~/topic_1");
    auto node2 = std::make_shared<CameraPublisherNode>("pub_2", "/topic_2");
    auto node3 = std::make_shared<CameraPublisherNode>("pub_3", "topic_3");

    rclcpp::spin(node1); // Keep the node awake.
    rclcpp::spin(node2);
    rclcpp::spin(node3);

    rclcpp::shutdown(); // Shutdown
    return 0;
}