#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main (int argc, char **argv) {
   
    ros::init(argc, argv, "test_node");
    ros::NodeHandle nh;
    ros::Publisher test_pub = nh.advertise<std_msgs::String>("test_topic", 1000);
    ros::Rate loop_rate(10);

    while(ros::ok()) {
        std_msgs::String message;
        std::stringstream ss;

        ss << "Test node is alive!";
        message.data = ss.str();
        ROS_INFO("%s", message.data.c_str());
        test_pub.publish(message);

        ros::spinOnce();
        loop_rate.sleep();
    }
    return 0; 
}