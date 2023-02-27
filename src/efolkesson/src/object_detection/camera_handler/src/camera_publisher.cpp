#include "camera_handler/camera_publisher.hpp"

/// @brief Constructor for CameraHandlerNode class
/// @param node_name The name of the node
/// @param topic_name The name of the topic
CameraPublisherNode::CameraPublisherNode(const std::string &node_name, const std::string &topic_name)
    : Node(node_name)
{
    this->node_name_ = node_name;
    this->topic_name_ = topic_name;

    image_transport::ImageTransport image_transport_(this->create_sub_node("namespace_" + this->node_name_));

    this->publisher_ = image_transport_.advertise(this->topic_name_, 1);

    RCLCPP_INFO(this->get_logger(), "The node %s has been created.", this->node_name_.c_str());
    RCLCPP_INFO(this->get_logger(), "And is publishing to topic %s", this->topic_name_.c_str());
}

/// @brief Publish the image
/// @param image The image to be published
void CameraPublisherNode::publish(const cv::Mat &image)
{
    this->msg_ = cv_bridge::CvImage(this->hdr_, "bgr8", image).toImageMsg();

    rclcpp::WallRate loop_rate(5);
    while (rclcpp::ok())
    {
        publisher_.publish(this->msg_);
        rclcpp::spin_some(this->internal_node_);
        loop_rate.sleep();
    }
}