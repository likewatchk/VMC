/* codes related to pt_vector*/

/* store points using global declared vector :*/

/* add_point(x, y, z)
 * void delete_all_pts_in_vector()
 * 
 * get_pt_vector_back()
 * get_pt_vector_begin()
 * get_pt_point_cnt()
 * get_pt_vector_size()
 * print_pt_vector_back()*/

#include<iostream>
#include<vector>
#include<string>
#include<curb_test_pkg/dtlane_pak_info.h>

using namespace std;

/* global containner and count declared. there are get func for using these on main */
vector<point *> pt_vector;
int point_cnt = 0; // == PID


/* function for adding a point to the pt_vector global declared */
void add_point(double x, double y, double z)
{
	point_cnt++;
	pt_vector.push_back(new point(point_cnt,0,0,z,x,y,0,0,0,0));
}


/* function for dynamic object deletion */
void delete_all_pts_in_vector()
{
	vector<point *>::iterator it;

	/* deletion loop using iterator of the pt_vector */
	for(it = pt_vector.begin(); it != pt_vector.end(); it++){
		delete *it;
	}

	point_cnt = 0;
}


/* function for getting the <point*> of the last point in the pt_vector */
point* get_pt_vector_back()
{
	return pt_vector.back();  // point*
}


/* function for getting the <begin_iterator> of the vector */
pt_iterator get_pt_vector_begin() 
{
	vector<point *>::iterator it = pt_vector.begin(); // iterator of the vector
	return it;
}

pt_iterator get_pt_vector_end()
{
	return pt_vector.end();
}


/* function for getting the value of the <point_cnt> */
int get_point_cnt()
{
	return point_cnt;
}

/* function for getting the <size> of the vector */
int get_pt_vector_size()
{
	return pt_vector.size();
}

/* print the latest added point coordinate */
void print_pt_vector_back()
{
	point p = *(pt_vector.back());
	double x_cor = p.Ly;
	double y_cor = p.Bx;
	double z_cor = p.H;
	
	cout << "Latest added point  " << "x : " << x_cor << "y : " << y_cor << "z : " << z_cor << endl;
}
