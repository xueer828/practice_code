#ifndef _TEST_
#define _TEST_

// triangle
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle

[
[2],
[3,4],
[6,5,7],
[4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

/*
Run Status: Accepted!
Program Runtime: 48 milli secs
Progress: 43/43 test cases passed.
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
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int rows=triangle.size();
		if(rows <= 0)
			return 0;

		vector<int> v(rows,0);

		//第一行
		v[0] = triangle[0][0];
		int mn=0;

		for(int i=1;i<rows;++i)
		{
			int j=i;
			
			while(j>=0) //得从后往前覆盖v
			{
				if(j==0 || j > 0 && j<i && v[j-1] > v[j])
					v[j] = v[j] + triangle[i][j];
				else
					v[j] = v[j-1] + triangle[i][j];

				--j;
			}
		}

		mn = v[0];
		for(int i=1;i<rows;++i)
			if(mn > v[i])
				mn = v[i];
		return mn;
	}
};

void solve()
{
	vector<vector<int> > v(4,vector<int>(4));

	v[0][0]=2;
	v[1][0]=3,v[1][1]=4;
	v[2][0]=6,v[2][1]=5,v[2][2]=7;
	v[3][0]=4,v[3][1]=1,v[3][2]=8,v[3][3]=3;

	Solution s;
	cout<<s.minimumTotal(v)<<endl;
}

#endif