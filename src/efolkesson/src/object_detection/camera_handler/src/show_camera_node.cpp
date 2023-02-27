#include "camera_handler/camera_subscriber.hpp"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv); // Initilize

    auto show_camera_node = std::make_shared<CameraSubscriberNode>("camera_subscriber", "/image_raw", true);

    rclcpp::spin(show_camera_node); // Keep the node awake.

    rclcpp::shutdown(); // Shutdown
    return 0;
}