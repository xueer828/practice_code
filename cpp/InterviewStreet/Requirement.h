#ifndef _TEST_
#define _TEST_

// Requirement
// Copyright (c) 2013/01/28 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
https://www.hackerrank.com/challenges/requirement

There are n variables and m requirements. Requirements are represented as (x <= y), which means the x-th variable must be smaller or equal to the y-th variable. Assign nonnegative numbers smaller than 10 to each variable. Please calculate how many different assignments that match all requirements. Two assignments are different if and only if at least one variable is assigned different number in these two assignment. Module the answer by 1007.



Input Format:

First line of the input contains two integers n and m.

Then following m lines each containing 2 space-seperated integers x and y, which means a requirement (x <= y).



Output Format:

Output the answer in one line.



Constraints:

0 < n < 14

0 < m < 200

0 <= x, y < n



Sample Input:

6 7

1 3

0 1

2 4

0 4

2 5

3 4

0 2



Sample Output:

1000
*/

//˼·:��Ϊÿ��λ�����ִ�0��9,������0<n<14��ô,����֪���������ֿ�ѡ����Ϊ1~

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

struct requirement{
	int x,y;
	req(i,j):x(i),y(j){};
};

template<class T>
struct req_sort::binary_function<T,T,bool>{
	bool operator()(T& l,T& r) const
	{
		return l.x <= l.y;
	}
};

void solve()
{
	int n,m,k,j,tmp=0;
	cin>>n>>m;
	vector<requirement> req;
	req.reserve(m);
	while(tmp++ < m){
		cin>>k>>j;
		req.push_back(requirement(k,j));
	}

	//sort by x
	sort(req.begin(),req.end(),req_sort<requirement>);

	int number[13]={0}; //��1��ʼ�����,һֱ��999...9 һ��13��9

	number[0]=1;

	int counter=0;

	while(1)
	{
		int i=0;
		if(number[n] >= 1)
			break;
		
		//��������ֱ������requirement������
		for(int j=0;j<m;++j)
		{
			if(number[req[j].x] <=)
		}
	}


}

#endif