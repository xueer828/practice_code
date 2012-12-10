// trial.cpp : Defines the entry point for the console application.
//



#include "..\CommonHeader.h"



struct NeighborPoint{
	bool inGridNotOccupied;
};

struct classname{
	void function1();
	bool cannotMoveIn(NeighborPoint mp);
};


void classname::function1()
{
	vector<NeighborPoint> neighbors;
	neighbors.erase(std::remove_if(neighbors.begin(),neighbors.end(),bind1st(mem_fun(&classname::cannotMoveIn),this)), neighbors.end()); 
}

bool classname::cannotMoveIn(NeighborPoint mp)
{
	return !mp.inGridNotOccupied;
}


void main()
{

}
