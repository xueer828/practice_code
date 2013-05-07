#ifndef _TEST_
#define _TEST_

// pow_x_n
// Copyright (c) 2013/4/28 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Implement pow(x, n).
 */

/*
Solution1 大数据 TLE 超时
*/

/*
Solution2 
Run Status: Accepted!
Program Runtime: 12 milli secs
Progress: 299/299 test cases passed.
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
public:
	double pow(double x, int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n < 0)
			return 1.0/pow(x,-n);
		if(n==0)
			return 1;

		double tmp=x;

		//***************重要的区别******
		for(int i=1;i<n;++i)
		{
			tmp *= x;
		}
		//***************重要的区别******

		return tmp;
	}
};

class Solution {
	double pow_unsigned(double x, unsigned n)
	{
		double base=x,res=1;

		while(n)
		{
			if(n&0x1)
				res *= base;

			base *= base; // x^2 
			n >>= 1; //
		}

		return res;
	}
public:
	double pow(double x, int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		unsigned int un;
		if(n < 0)
		{
			un = (-n);
			return 1.0/pow_unsigned(x,un);
		}else if(n == 0)
			return 1.0;
		else
			return pow_unsigned(x,n);
	}
};

void solve()
{
	Solution s;
	cout<<s.pow(1.0,-2147483648)<<endl;
}

#endif 