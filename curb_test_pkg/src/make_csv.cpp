/*make csv file codes*/

#include<iostream>
#include<fstream>
#include<string>
#include<curb_test_pkg/dtlane_pak_info.h>

using namespace std;

/* function for making the file having the data of the points */
void make_point_csv_file()
{
	/*empty vector case*/
	if (get_pt_vector_size() == 0) {cout << "nothing in the pt_vector" << endl; return;}

	/*making csv file using iterator of the pt_vector*/
	vector<point *>::iterator it = get_pt_vector_begin();
	
//	string filePath = "point.csv";
//	ofstream writeFile(filePath.data());//char * type  // "" -> return char *
	
	ofstream writeFile("point.csv");
	while(writeFile.is_open()){
		point p = **it;  // it = pt_vector.begin()

		if( p.PID == 1 ) // initial line of csv file
			writeFile << "PID,B,L,H,Bx(y),Ly(x),Ref,MCODE1,MCODE2,MCODE3" << '\n'; 

		writeFile << p.PID <<','<< p.B << ',' << p.L <<','
			<< p.H << ',' << p.Bx << ',' << p.Ly << ',' 
			<< p.Ref <<','<< p.MCODE1 << ',' << p.MCODE2 << ',' 
			<< p.MCODE3 << '\n';
		
		if(++it == get_pt_vector_end()) 
			break;
	}
	writeFile.close();
	printf("make_point_csv_file completed\n");
}
