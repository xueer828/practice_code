#ifndef _TEST_
#define _TEST_

// spiral_matrix2
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
[ 1, 2, 3 ],
[ 8, 9, 4 ],
[ 7, 6, 5 ]
]
*/

/*
类似前面那道,这次用递归的算法,和非递归算法

Run Status: Accepted!
Program Runtime: 20 milli secs
Progress: 21/21 test cases passed.
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


class Solution {
	void fill_matrix_recusive(vector<vector<int> >& v,int lt,int rb, int cnt)
	{
		if(lt > rb)
			return;
		
		//第一行 (包含头尾)
		for(int i=lt;i<=rb;++i)
			v[lt][i]=cnt++;

		//最后一列 (包含头尾)
		for(int i=lt+1;i<rb;++i)
			v[i][rb]=cnt++;

		//最下面一行 (不包含头尾)
		if(lt != rb)
		for(int i=rb;i>=lt;--i)
			v[rb][i]=cnt++;

		//第一列 (不包含头尾)
		if(lt != rb)
		for(int i=rb-1;i>lt;--i)
			v[i][lt]=cnt++;

		fill_matrix_recusive(v,lt+1,rb-1,cnt);
	}

	void fill_matrix_iterative(vector<vector<int> >& v, int n)
	{
		int num=n*n;
		int l(0),r(n-1),t(0),b(n-1);
		for(int cnt=1;cnt<=num;)
		{
			//第一行
			for(int i=l;i<=r;++i)
				v[t][i]=cnt++;
			//最后一列 (不包含头 尾)
			for(int i=t+1;i<b;++i)
				v[i][r]=cnt++;
			//最后一行
			if(t < b)
				for(int i=r;i>=l;--i)
					v[b][i]=cnt++;
			//第一列
			if(l < r)
				for(int i=b-1;i>t;--i)
					v[i][l]=cnt++;

			++l,++t,--r,--b;
		}
	}
public:
	vector<vector<int> > generateMatrix(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<vector<int> > v;
		if(n <=0)
			return v;

		v.resize(n);
		for(int i=0;i<n;++i)
			v[i].resize(n);
		//fill_matrix_recusive(v,0,n-1,1);
		fill_matrix_iterative(v,n);
	}
};


void solve()
{
	Solution s;
	s.generateMatrix(2);
}

#endif