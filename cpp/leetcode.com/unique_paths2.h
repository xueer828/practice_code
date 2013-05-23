#ifndef _TEST_
#define _TEST_

// unique_paths2
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 
/*
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,

There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
[0,0,0],
[0,1,0],
[0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
*/

/*
思想是类似前一题的,只是中间加了砖块,DP公式就需要做一点点改变

dp[i,j]=0 ; //如果(i,j)位置是砖块

一次通过!nice
Run Status: Accepted!
Program Runtime: 32 milli secs
Progress: 42/42 test cases passed.
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
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		int m=obstacleGrid.size();
		if(m <=0)
			return 0;
		int n=obstacleGrid[0].size();
		if(n <=0)
			return 0;

		vector<vector<int> > v(m);
		for(int i=0;i<m;++i)
			v[i].resize(n);

		bool blocked=false;
		for(int i=0;i<m;++i)
		{
			if(!blocked && obstacleGrid[i][0] == 1)
				blocked = true;
			if(blocked)
				v[i][0]=0;
			else
				v[i][0]=1;
		}

		blocked = false;
		for(int i=0;i<n;++i)
		{
			if(!blocked && obstacleGrid[0][i] == 1)
				blocked = true;

			if(blocked)
				v[0][i]=0;
			else
				v[0][i]=1;
		}

		for(int i=1;i<m;++i)
			for(int j=1;j<n;++j)
			{
				if(obstacleGrid[i][j]==1)
					v[i][j]=0;
				else
					v[i][j] = v[i-1][j]+v[i][j-1];
			}

		return v[m-1][n-1];
	}
};

void solve()
{

}

#endif