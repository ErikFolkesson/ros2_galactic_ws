#include "camera_handler/camera_subscriber.hpp"
#include "opencv2/opencv.hpp"
#include "cv_bridge/cv_bridge.h"

/// @brief Constructor for the CameraSubscriberNode class
/// @param node_name The name of the ROS node
/// @param topic_name The name of the ROS topic that the camera publishes to
CameraSubscriberNode::CameraSubscriberNode(const std::string &node_name, const std::string &topic_name,
                                           const bool &show_image) : Node(node_name)
{
    this->node_name_ = node_name;
    this->topic_name_ = topic_name;
    this->show_image_ = show_image;

    if (this->show_image_)
    {
        cv::namedWindow(this->node_name_);
        cv::startWindowThread();
    }

    image_transport::ImageTransport image_transport_(this->create_sub_node("namespace_" + this->node_name_));

    this->subscriber_ = image_transport_.subscribe(this->topic_name_, 1,
                                                   std::bind(&CameraSubscriberNode::imageCallback,
                                                             this, std::placeholders::_1));

    RCLCPP_INFO(this->get_logger(), "The node %s has been created.", this->node_name_.c_str());
    RCLCPP_INFO(this->get_logger(), "And is subscribing to topic %s", this->topic_name_.c_str());
}

/// @brief Destructor for the CameraSubscriberNode class
CameraSubscriberNode::~CameraSubscriberNode()
{
    if (this->show_image_)
    {
        cv::destroyWindow(this->node_name_);
    }
    RCLCPP_INFO(this->get_logger(), "The node %s has been destroyed.", this->node_name_.c_str());
}

/// @brief Image callback function for the camera message
/// @param msg The message received
void CameraSubscriberNode::imageCallback(const sensor_msgs::msg::Image::ConstSharedPtr &msg)
{
    try
    {
        if (this->show_image_)
        {
            cv::imshow(this->node_name_, cv_bridge::toCvShare(msg, "bgr8")->image);
            cv::waitKey(10);
        }
    }
    catch (const cv_bridge::Exception &e)
    {
        auto logger = rclcpp::get_logger(this->node_name_.c_str());
        RCLCPP_ERROR(logger, "Could not convert from '%s' to 'bgr8'.", msg->encoding.c_str());
    }
}