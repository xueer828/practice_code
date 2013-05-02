#ifndef _TEST_
#define _TEST_

// 20130310_Min_SumOfDistance
// Copyright (c) 2013/03/12 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
http://51weixue.com/thread-638-1-1.html
X轴上有N个点，每个点除了包括一个位置数据X，还包括一个权值W。该点到其他点的带权距离 = 实际距离 * 权值。求X轴上一点使它到这N个点的带权距离之和最小，输出这个最小的带权距离之和。

输入 N及权值
输出 最小的权值之和。
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <cstdlib>
using namespace std;

const int NUM=10;
int pos[NUM];
int val[NUM];

//对每一个点,加权距离和=(此点后面的点的位置和-此点前面的点位置的和+前后点数差*此点位置)*权值
//假定这里权值为正,求和的地方可以用longlong,这样避免溢出

long long solve(int pos[],int val[],int sz)
{
	long long pre(0),post(0);
	for(int i=1;i<sz;++i)
		post += pos[i];

	int num_of_pre(0),num_of_post(sz-1);

	//第一个点
	long long result=(post-pre+(num_of_pre-num_of_post)*pos[0])*val[0]; 

	for(int j=1;j<sz;++j)
	{
		if(j==sz-1) //处理最后一个点
			post = 0;
		else
			post -= pos[j+1];

		pre += pos[j-1];

		++num_of_pre,--num_of_post; 

		long long tmp_res=(post-pre+(num_of_pre-num_of_post)*pos[j])*val[j];
		if(tmp_res < result)
			result = tmp_res;
	}

	return result;
}

#endif