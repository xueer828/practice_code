#ifndef _TEST_
#define _TEST_

// jump_game
// Copyright (c) 2013/01/07 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

//注意题意:是最长的跳,也就是说可以从1到对应的正数跳,dfs深度搜索

/*
Solution1 dfs 深度搜索 大数据超时
*/

/*
Solution2 一维DP 超时
*/

/*
思路3: 看了网上的评论才明白,这实际上是个贪心问题,对于每一步,可以跨越[1..val],如果能够到达位置k,那么表面其可以到达k前的任意一个位置,所以,没必要dfs或者DP,利用贪心算法,每次都选取最大值,看最后是否可以>=最后一个位置,即可
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

class Solution1 {
	bool jump2end(int A[], int n, int cur)
	{
		if(cur == n-1)
			return true;

		if(cur >= n)
			return false;

		int max_next=A[cur];

		for(int i=1;i<=max_next;++i)
		{
			if(jump2end(A,n,cur+i))
				return true;
		}
		return false;
	}
public:
	bool canJump(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n<=0)
			return false;

		return jump2end(A,n,0);		
	}
};

//思路2: DP
class Solution2 {
public:
	bool canJump(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n<=0)
			return false;

		//vector<bool> DP(n); //超时
		bool *DP=new bool[n];
		

		DP[0]=true;

		for(int i=1;i<n;++i)
		{
			DP[i] = false; //初始化
			for(int j=i-1;j>=0;--j)
			{
				if(DP[j] && A[j] >= (i-j)) //满足跳转
				{
					DP[i]=true;
					continue;
				}
			}
		}
		bool tmp=DP[n-1];
		delete[] DP;
		return tmp;

	}
};

//贪心
class Solution {
public:
	bool canJump(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n <= 0)
			return false;

		int max_val=A[0],cur_pos=0;
		while(1)
		{
			//获取最大最长的跳
			for(int i=1;i<=max_val;++i)
			{

			}
		}
	}
};

void solve()
{
	Solution s;
	int d[]={2,0};
	cout<<s.canJump(d,sizeof(d)/sizeof(d[0]))<<endl;
}

#endif