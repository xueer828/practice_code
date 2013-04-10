#ifndef _TEST_
#define _TEST_

// jump_game2
// Copyright (c) 2013/01/07 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in *the minimum number* of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/

//思路1:我认为是DP问题,DP(i)=min{DP(x)+1 | if x 可以到 i位置} 算法复杂度O(n^2)



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

//时间复杂度O(n^2) TLE 大数据超时
class Solution {
public:
	int jump(int A[], int n) {
		
		unsigned *DP=new unsigned[n];

		for(int j=0;j<n;++j)
			DP[j]=1<<10;
		DP[0]=0;

		for(int i=1;i<n;++i)
		{
			for(int j=0;j<i;++j)
			{
				if(A[j]+j >= i)
					DP[i]=DP[i]>(DP[j]+1)?(DP[j]+1):DP[i];
			}
		}

		return DP[n-1];

		delete[] DP;

	}
};


void solve()
{
	Solution s;
	int d[]={2,3,1,1,4};
	cout<<s.jump(d,sizeof(d)/sizeof(d[0]))<<endl;
}

#endif