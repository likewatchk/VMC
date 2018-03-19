#include<vector>
/* 4 classes for dtlane on Autoware. point, dtlane, lane, node. */
class point;
class dtlane;
class lane;
class node;

typedef std::vector<point*>::iterator pt_iterator;

/* vector functions */
void add_point(double x, double y, double z);
void delete_all_pts_in_vector();
int get_point_cnt();
int get_pt_vector_size();
point* get_pt_vector_back();
pt_iterator get_pt_vector_begin();
pt_iterator get_pt_vector_end();
void print_pt_vector_back();


/* making csv file functions */
void make_point_csv_file();
void make_dtlane_csv_file();
void make_lane_csv_file();
void make_node_csv_file();


/* class definitions */
class point
{
	public:
		point(){}
		point(int pid, double b, double l, double z, double x, double y,double ref, double mcode1,double mcode2, double mcode3)
		{
			PID = pid; B = b; L = l; H = z;
			Bx = y; //japaness's coordinate
			Ly = x;
			Ref = ref; MCODE1 = mcode1; MCODE2 = mcode2; MCODE3 = mcode3;
		}
		int PID;
		double B;
		double L;
		double H; //z
		double Bx; //y
		double Ly; //x
		double Ref;
		double MCODE1;
		double MCODE2;
		double MCODE3;
};

class dtlane
{
	public:
		dtlane(){}
		int DID; //dt id
		double Dist; //distance (in meter)
		int PID; //point id
		double Dir; //direction (in rad)
		double Apara; //not used
		double r; // ?
		double slope; //not used
		double can; //not used
		double LW; // ?
		double RW; // ?
};

class lane
{
	public:
		lane(){}
		int LnID;
		int DID;
		int BLID;
		int FLID;
		int BNID;
		int FNID;
		double JCT;
		double BLID2;
		double BLID3;
		double BLID4;
		double FLID2;
		double FLID3;
		double FLID4;
		double ClassID;
		double span;
		double LCnt;
		double Lno;
		double LaneType;
		double LimitVel;
		double RefVel;
		int RoadSecID;
		double LaneChgFG;
};

class node
{
	int NID;
	int PID;
};
