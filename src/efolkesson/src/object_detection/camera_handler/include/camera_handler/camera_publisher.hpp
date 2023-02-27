#ifndef _CAMERA_PUBLISHER_
#define _CAMERA_PUBLISHER_

#include "rclcpp/rclcpp.hpp"
#include "opencv2/opencv.hpp"
#include "cv_bridge/cv_bridge.h"
#include "sensor_msgs/msg/image.hpp"
#include "image_transport/image_transport.hpp"

class CameraPublisherNode : public rclcpp::Node
{
public:
    CameraPublisherNode(const std::string &node_name, const std::string &topic_name);
    void publish(const cv::Mat &image);

protected:
    std::string node_name_;
    std::string topic_name_;

    rclcpp::Node::SharedPtr internal_node_;

    image_transport::Publisher publisher_;

    std_msgs::msg::Header hdr_;
    sensor_msgs::msg::Image::SharedPtr msg_;
};

#endif // _CAMERA_PUBLISHER_