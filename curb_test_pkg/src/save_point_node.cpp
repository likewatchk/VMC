#include<ros/ros.h>
#include<geometry_msgs/PoseStamped.h>
#include<iostream>
#include<math.h>
#include<curb_test_pkg/dtlane_pak_info.h>
using namespace std;

void callback(const geometry_msgs::PoseStamped::ConstPtr& msg_sub){ //
	double x_cor = msg_sub->pose.position.x;
	double y_cor = msg_sub->pose.position.y;
	double z_cor = msg_sub->pose.position.z;

	if(get_point_cnt() == 0) 
		add_point(x_cor,y_cor,z_cor);
	
	double x_dif_s = x_cor - get_pt_vector_back()->Ly; // Ly == x cor 
	x_dif_s *= x_dif_s; // delta x ^ 2
	double y_dif_s = y_cor - get_pt_vector_back()->Bx; // Bx == y cor
	y_dif_s *= y_dif_s; // delta y ^ 2
	double z_dif_s = z_cor - get_pt_vector_back()->H; // H == z cor
	z_dif_s *= z_dif_s; // delta z ^ 2
	double distance_s = x_dif_s + y_dif_s + z_dif_s;  // distance ^ 2       
	double distance = sqrt(distance_s);

	if (distance >= 1){
		add_point(x_cor,y_cor,z_cor);
		cout <<"distance =  " << distance << " ######*******Point updated*******######" << endl;
		print_pt_vector_back();
	}
	
}


int main(int argc, char** argv){

	ros::init(argc, argv, "dtlane_pak_csv_making_node");
	ros::NodeHandle nh;
	ros::Subscriber x_sub;

	x_sub = nh.subscribe("ndt_pose", 10, callback);

	ros::spin();
}
