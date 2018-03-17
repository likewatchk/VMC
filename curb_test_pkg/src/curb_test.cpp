#include<ros/ros.h>
#include<geometry_msgs/PoseStamped.h>
#include<iostream>
#include<curb_test_pkg/vector_map_info.h>
using namespace std;

void callback(const geometry_msgs::PoseStamped::ConstPtr& msg_sub){ //
	double x_cor = msg_sub->pose.position.x;
	cout << "x_cor = " << x_cor << endl;
	double y_cor = msg_sub->pose.position.y;
	cout << "y_cor = " << y_cor << endl;
	double z_cor = msg_sub->pose.position.z;
	cout << "z_cor = " << z_cor << endl;

	
	
	double x_dif_s = x_cor - vector_map::pt_vector_back()->Ly;
	x_dif_s *= x_dif_s;
	double y_dif_s = y_cor - vector_map::pt_vector_back()->Bx;
	y_dif_s *= y_dif_s;
	double z_dif_s = z_cor - vector_map::pt_vector_back()->H;
	z_dif_s *= z_dif_s;
	double distance_s = x_dif_s + y_dif_s + z_dif_s;
	if(vector_map::get_point_cnt() == 0) vector_map::add_point(x_cor,y_cor,z_cor);

	if (distance_s >= 1){
		vector_map::add_point(x_cor,y_cor,z_cor);
		cout << "######*******Point updated*******######" << endl;
	}
	
	if(vector_map::get_point_cnt() == 10) vector_map::make_point_csv_file();
	//cout << "Point : x = " << pt_vector.back().Ly << ", y = " << pt_vector.back().Bx << ", z = " << pt_vector.back().H << endl;
}

int main(int argc, char** argv){

	ros::init(argc, argv, "curb_test_node");
	ros::NodeHandle nh;
	ros::Subscriber x_sub;

	x_sub = nh.subscribe("ndt_pose", 10, callback);

	ros::spin();
}
