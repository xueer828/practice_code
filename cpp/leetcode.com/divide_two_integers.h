#ifndef _TEST_
#define _TEST_

// divide_two_integers
// Copyright (c) 2012/12/26 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Divide two integers without using multiplication, division and mod operator.
*/

//思路,可以利用移位模拟计算机的除法运算
//

/*
Run Status: Accepted!
Program Runtime: 40 milli secs
Progress: 987/987 test cases passed.
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
	int divide(int dividend, int divisor) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		bool flag=true; //positive number
		if(divisor == 0 || dividend == 0)
			return 0;
		if(dividend <0)
		{
			dividend = 0 - dividend;
			flag = !flag;
		}

		if(divisor < 0)
		{
			divisor = 0 - divisor;
			flag = !flag;
		}

		unsigned t_dividend = dividend;
		unsigned t_divisor = divisor;

		//先将除数左移与被除数对齐,直到被除数小于除数
		int num=0;
		while(t_dividend>t_divisor && num < 31) {
			++num;
			t_divisor <<= 1;
		}

		int result = 0;

		while(num-- >= 0)
		{
			if(t_dividend >= t_divisor)
			{
				result = (result << 1) + 1;
				t_dividend -= t_divisor;
			}else{
				result = result << 1;
			}
			t_divisor >>= 1;
		}

		return flag?result:-result;
	}
};

void solve()
{
	Solution s;
	s.divide(2147483647,1);
}

#endif
