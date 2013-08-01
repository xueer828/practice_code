// trial.cpp : Defines the entry point for the console application.
//

#include <iostream>
using namespace std;

#if 0
#include "a.h"


void print_a();

//test t;

extern test t;


void print_b()
{
	cout<<t.x<<t.y<<endl;
}

#endif

class CTEST
{
public:
	int m;
	CTEST():m(0){cout<<"ctor"<<endl;}
	CTEST(int a):m(a){cout<<"int ctor"<<endl;}
	CTEST(CTEST& t){cout<<"copy ctor"<<endl;}
	CTEST& operator=(const CTEST& t)
	{
		if(this == &t)
			return *this;
		cout<<"assign"<<endl;
		m = t.m;
		return *this;
	}

	CTEST& operator=(const int t)
	{
		m = t;
		cout<<"int assign"<<endl;
		return *this;
	}
protected:
private:
};

void main()
{
	//print_b();
	//print_a();

	//int b[100];

	//cout<<sizeof(b)<<","<<sizeof(&b)<<endl; //´ð°¸ÊÇ400,4

	CTEST a;
	CTEST b(1);
	CTEST c=a;
	b=a;
	c=3;
}
