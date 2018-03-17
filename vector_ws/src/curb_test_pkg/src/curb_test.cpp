#include<ros/ros.h>
#include<geometry_msgs/PoseStamped.h>
#include<iostream>

using namespace std;

void callback(const geometry_msgs::PoseStamped::ConstPtr& msg_sub){
	double x_cor = msg_sub->pose.position.x;
	cout << "x_cor = " << x_cor << endl;
	double y_cor = msg_sub->pose.position.y;
	cout << "y_cor = " << y_cor << endl;
	double z_cor = msg_sub->pose.position.z;
	cout << "z_cor = " << z_cor << endl;
}

int main(int argc, char** argv){

	ros::init(argc, argv, "curb_test_node");
	ros::NodeHandle nh;
	ros::Subscriber x_sub;

	x_sub = nh.subscribe("ndt_pose", 10, callback);

	ros::spin();
}
