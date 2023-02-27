#ifndef _CAMERA_SUBSCRIBER_
#define _CAMERA_SUBSCRIBER_

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "image_transport/image_transport.hpp"

class CameraSubscriberNode : public rclcpp::Node
{
public:
    CameraSubscriberNode(const std::string &node_name, const std::string &topic_name, const bool &show_image);
    ~CameraSubscriberNode();

protected:
    void imageCallback(const sensor_msgs::msg::Image::ConstSharedPtr &msg);

    std::string node_name_;
    std::string topic_name_;
    bool show_image_;

    rclcpp::Node::SharedPtr internal_node_;

    image_transport::Subscriber subscriber_;
};

#endif // _CAMERA_SUBSCRIBER_