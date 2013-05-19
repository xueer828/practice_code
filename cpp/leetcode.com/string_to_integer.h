#ifndef _TEST_
#define _TEST_

// string_to_integer
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

INT_MAX (2147483647) or INT_MIN (-2147483648) is returned
*/

/*
Run Status: Accepted!
Program Runtime: 48 milli secs
Progress: 1039/1039 test cases passed.
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
	int atoi(const char *str) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!str) return 0;

		const char*p =str;
		bool neg=false;

		const unsigned int PV_max=0x7FFFFFFF;
		const unsigned int NV_max=0x80000000;

		//skip blanks
		while(*p==' '||*p=='\t') ++p;

		//
		if(*p=='-' || *p=='+')
		{
			if(*p=='-') neg = true;
			++p;
		}

		unsigned res=0,tmp;
		
		while(*p)
		{
			if(*p >= '0' && *p <= '9')
			{
				if(neg)
				{
					tmp = (NV_max - (*p-'0'))/10;
					if(res > tmp)
						return -1*NV_max;
				}else{
					tmp = (PV_max - (*p-'0'))/10;
					if(res > tmp)
						return PV_max;
				}
				res = res*10 + (*p - '0');
			}
			else
				break; //meet wrong digits

			++p;
		}

		return neg?-1*res:res;
	}
};

void solve()
{
	Solution s;
	cout<<s.atoi("    10522545459");
}

#endif