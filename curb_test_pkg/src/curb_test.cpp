#include<ros/ros.h>
#include<geometry_msgs/PoseStamped.h>
#include<iostream>
#include<curb_test_pkg/vector_map_info.h>
#include<vector>

using namespace std;

vector_map::point P_past;

void callback(const geometry_msgs::PoseStamped::ConstPtr& msg_sub){ //
	double x_cor = msg_sub->pose.position.x;
	cout << "x_cor = " << x_cor << endl;
	double y_cor = msg_sub->pose.position.y;
	cout << "y_cor = " << y_cor << endl;
	double z_cor = msg_sub->pose.position.z;
	cout << "z_cor = " << z_cor << endl;
	
	double x_dif_s = x_cor - P_past.Ly;
	x_dif_s *= x_dif_s;
	double y_dif_s = y_cor - P_past.Bx;
	y_dif_s *= y_dif_s;
	double z_dif_s = z_cor - P_past.H;
	z_dif_s *= z_dif_s;
	double distance_s = x_dif_s + y_dif_s + z_dif_s;

	if (distance_s >= 1){
		P_past.Ly = x_cor;
		P_past.Bx = y_cor;
		P_past.H = z_cor;
		cout << "######*******Point updated*******######" << endl;
	}
	
	cout << "Point : x = " << P_past.Ly << ", y = " << P_past.Bx << ", z = " << P_past.H << endl;
}

int main(int argc, char** argv){

	ros::init(argc, argv, "curb_test_node");
	ros::NodeHandle nh;
	ros::Subscriber x_sub;

	x_sub = nh.subscribe("ndt_pose", 10, callback);

	ros::spin();
}
