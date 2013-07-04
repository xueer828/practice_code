#ifndef _TEST_
#define _TEST_

// sqrt_x
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

/*
Run Status: Accepted!
Program Runtime: 56 milli secs
Progress: 1016/1016 test cases passed.
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

//二分搜索求sqrt(x),
/*
注意: 
1) 返回的是sqrt(x)的非精确值,也就是说求n, 满足  n*n<=x 且 (n+1)*(n+1)>x
2) 二分的high和low都要是unsigned int,否则会溢出出错,造成死循环
*/

class Solution {
public:
	int sqrt(int x) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		if(x <= 0) return 0;

		unsigned int mx=65535;
		if(mx*mx < x) return mx;

		//二分搜索从 1 到 mx, 寻找 n*n == x

		unsigned int mn=0;
		unsigned int mid=0;

		while(1)
		{
			mid = (mx + mn) >> 1;
			if(mid*mid > x)
			{
				mx = mid-1;
			}else if((mid+1)*(mid+1) <= x)
			{
				mn = mid +1;
			}else{
				return mid;
			}
		}		
	}
};


void solve()
{
	Solution s;
	s.sqrt(2147395599);
}

#endif