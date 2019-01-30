#include "ros/ros.h"
#include "std_msgs/String.h"

void TestNodeCallback(const std_msgs::String::ConstPtr& message) {
    ROS_INFO("recv_node: [%s]", message->data.c_str());
}

void TestNodeletCallback(const std_msgs::String::ConstPtr& message) {
    ROS_INFO("recv_node: [%s]", message->data.c_str());
}


int main (int argc, char **argv) {
   
    ros::init(argc, argv, "recv_node");
    ros::NodeHandle nh;
    ROS_INFO("recv_node: starting!");
    ros::Subscriber test_sub = nh.subscribe("test_topic", 1000, TestNodeCallback);
    ros::Subscriber nodelet_sub = nh.subscribe("nodelet_shout", 1000, TestNodeletCallback);
    ros::spin();
    
    return 0; 
}