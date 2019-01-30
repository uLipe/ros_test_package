#include <pluginlib/class_list_macros.h>
#include <nodelet/nodelet.h>
#include <ros/ros.h>
#include <std_msgs/String.h>
#include <sstream>

namespace test_package {


class TestNodelet : public nodelet::Nodelet {
private:

virtual void onInit() {
    ros::NodeHandle& nh = getNodeHandle();
    nodelet_pub = nh.advertise<std_msgs::String>("nodelet_shout", 1000);
    nodelet_sub = nh.subscribe("test_topic",1000, &TestNodelet::callback, this);
}

void callback(const std_msgs::String::ConstPtr& message) {
    NODELET_DEBUG("test_nodelet: [%s]", message->data.c_str());
    std_msgs::String out_message;
    std::stringstream ss;
    ss << "test_nodelet is talking!";
    out_message.data = ss.str();
    nodelet_pub.publish(out_message);
}

ros::Publisher nodelet_pub;
ros::Subscriber nodelet_sub;
};


PLUGINLIB_EXPORT_CLASS(test_package::TestNodelet, nodelet::Nodelet)
}