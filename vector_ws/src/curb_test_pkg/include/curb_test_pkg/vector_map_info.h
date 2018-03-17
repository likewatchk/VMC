namespace vector_map{
	class point
	{
		public:
			point(){}
			int PID;
			double B;
			double L;
			double H;
			double Bx;
			double Ly;
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
}
