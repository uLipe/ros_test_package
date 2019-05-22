#include "ros/ros.h" 
#include "test_package/test_service.h" 
#include <iostream> 
#include <sstream> 
 
bool test_service_callback(test_package::test_service::Request &req, 
     test_package::test_service::Response &res) { 

    std::stringstream ss; 
    ss << "Received Here"; 
    res.out = ss.str(); 
    ROS_INFO("From Client [%s], Server says [%s]",req.in.c_str(),res.out.c_str()); 
    return true; 
} 
 
int main(int argc, char **argv) 
{ 
 ros::init(argc, argv, "ros_server_node"); 
 ros::NodeHandle n; 
 ros::ServiceServer service = n.advertiseService("test_service", test_service_callback); 
 ROS_INFO("Ready to receive from client."); 
 ros::spin(); 
 return 0; 
} 