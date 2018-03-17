#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<curb_test_pkg/vector_map_info.h>


using namespace std;
vector<vector_map::point *> pt_vector;
int point_cnt = 0;

namespace vector_map{
	point::point(int pid, double b, double l, double h, double bx, double ly,double ref, double mcode1,double mcode2, double mcode3)
	{
		PID = pid;
		B = b;
		L = l;
		H = h;
		Bx = ly; //different coordinate
		Ly = bx;
		Ref = ref;
		MCODE1 = mcode1;
		MCODE2 = mcode2;
		MCODE3 = mcode3;
	}


	void add_point(double x, double y, double z)
	{
		pt_vector.push_back(new vector_map::point(++point_cnt,0,0,z,x,y,0,0,0,0));
	}

	void delete_all_points()
	{
		vector<vector_map::point *>::iterator it;
		for(it = pt_vector.begin(); it != pt_vector.end(); it++){
			delete *it;
		}
		point_cnt = 1;
	}

	void make_point_csv_file()
	{
		printf("make_point_csv_file called\n");
		//std::cout << pt_vector.size() << std::endl;
		if(pt_vector.size() == 0) {std::cout << "nothing to add" << std::endl; return;}
		vector<vector_map::point *>::iterator it = pt_vector.begin();
		string filePath = "point.csv";
		ofstream writeFile(filePath.data());
		while(writeFile.is_open()){
			vector_map::point p = **it;
			if( p.PID == 1 ) writeFile << '\n'; //initial line
			writeFile << p.PID <<',' << p.B << ',' << p.L <<',' << p.H << ',' << p.Bx << ',' << p.Ly << ',' << p.Ref <<','
			<< p.MCODE1 << ',' << p.MCODE2 << ',' << p.MCODE3 << '\n';
			it++;
			if(it == pt_vector.end()) break;
		}
		writeFile.close();
	}
	point* pt_vector_back()
	{
		return pt_vector.back();
	}
	
	int get_point_cnt()
	{
		return point_cnt;
	}

}
