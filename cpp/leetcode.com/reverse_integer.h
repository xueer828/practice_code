#ifndef _TEST_
#define _TEST_

// reverse_integer
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

/*
Run Status: Accepted!
Program Runtime: 52 milli secs
Progress: 1020/1020 test cases passed.
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
	int reverse(int x) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		bool neg=false;
		unsigned int ux(0),uy(0);
		if(x < 0)
		{
			neg = true;
			ux = -x;
		}else
			ux = x;

		int dig=0;
		while(ux)
		{
			dig = ux % 10;
			ux /= 10;
			uy = uy*10 + dig;
		}

		if(neg)
			return -uy;
		else
			return uy;
	}
};

void solve()
{

}

#endif