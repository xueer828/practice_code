#ifndef _TEST_
#define _TEST_

// minimum_path_sum
// Copyright (c) 2013/4/25 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
 */

//题意: MxN的表格,填充非负整数, 找出一条从左上角到右下角的最小和的路径,注意,每次只能望下或往右走一步

//思路: DP, 公式: DP[i][j]=min{DP[i-1][j],DP[i][j-1]} //因为只能往下或者往右, DP[i][j]表示从(0,0)到(i,j)位置的最小和

/*
一次性AC, happy!!
Run Status: Accepted!
Program Runtime: 76 milli secs
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
	int minPathSum(vector<vector<int> > &grid) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		
		int row_sz=grid.size();
		if(row_sz <= 0)
			return 0;
		int col_sz=grid[0].size();
		
		vector<vector<int> > DP(row_sz);
		
		for(int i=0;i<row_sz;++i)
		{
			DP[i].resize(col_sz);
		}

		DP[0][0]=grid[0][0];

		for(int i=1;i<row_sz;++i)
			DP[i][0]=DP[i-1][0]+grid[i][0];
		for(int i=1;i<col_sz;++i)
			DP[0][i]=DP[0][i-1]+grid[0][i];

		for(int i=1;i<row_sz;++i)
			for(int j=1;j<col_sz;++j)
				DP[i][j]=min(DP[i-1][j],DP[i][j-1])+grid[i][j];

		return DP[row_sz-1][col_sz-1];
	}
};

void solve()
{
}

#endif 