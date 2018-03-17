namespace vector_map{
	class point
	{
		public:
			point(){}
			point(int pid, double b, double l, double h, double bx, double ly,double ref, double mcode1,double mcode2, double mcode3);
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
	class csv
	{
		
	};
	void add_point(double x, double y, double z);
	void make_point_csv_file();
	void delete_all_points();
	point* pt_vector_back();
	int get_point_cnt();

}
