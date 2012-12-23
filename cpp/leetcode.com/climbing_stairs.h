#ifndef _TEST_
#define _TEST_

// climbing_stairs
// Copyright (c) 2012/12/23 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

/*
思路,基本的递归,实际上是菲波那契数列, f(n)=f(n-1)+f(n-2)
*/

/*
Solution 1: 直接f(n-1)+f(n-2), 递归 TLE 超时
*/

/*
Solution 2: DP
Run Status: Accepted!
Program Runtime: 12 milli secs
Progress: 45/45 test cases passed.
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

int dp[1000]={0};
class Solution {
public:
	int climbStairs(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(dp[n]>0) return dp[n];

		if(n==1) {dp[1]=1;return 1;}
		if(n==2) {dp[2]=2;return 2;}

		dp[n] = climbStairs(n-1) + climbStairs(n-2);
		return dp[n];
	}
};

void solve()
{
	Solution s;
}

#endif