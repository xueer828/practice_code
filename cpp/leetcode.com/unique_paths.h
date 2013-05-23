#ifndef _TEST_
#define _TEST_

// unique_paths
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?



Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
*/

/*
DP问题: 
要到达(i,j)节点,只有两个格子可以到,(i-1,j)和(i,j-1),那么就转换为
DP(i,j)=DP(i-1,j)+DP(i,j-1); DP[i,j]为从(0,0)位置到(i,j)位置的唯一路径数

一次通过,great
Run Status: Accepted!
Program Runtime: 28 milli secs
Progress: 61/61 test cases passed.
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
	int uniquePaths(int m, int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		vector<vector<int> > dp(101);
		for(int i=0;i<dp.size();++i)
			dp[i].resize(101);

		for(int i=0;i<m;++i)
			dp[i][0]=1;

		for(int i=0;i<n;++i)
			dp[0][i]=1;

		for(int i=1;i<m;++i)
			for(int j=1;j<n;++j)
				dp[i][j]=dp[i-1][j]+dp[i][j-1];

		return dp[m-1][n-1];
	}
};

void solve()
{

}

#endif