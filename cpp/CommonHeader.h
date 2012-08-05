#pragma once

#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
#include <ctime>
#include <cassert>
#include <string>

using namespace std;

double cal_time()
{
	static double last_cal=0;
	double all_cal=clock()/(double)CLOCKS_PER_SEC;
	double this_cal=all_cal-last_cal;
	last_cal = all_cal;
	return this_cal;
}

template<class T>
inline void out(const T& t)
{
	cout<<t<<" ";
}

template<class T>
inline void _swap(T& t1, T& t2)
{
	T tmp=t1;
	t1 = t2;
	t2 = tmp;
}