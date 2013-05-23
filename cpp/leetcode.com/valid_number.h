#ifndef _TEST_
#define _TEST_

// valid_number
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
*/

/*
not so easy.

Run Status: Accepted!
Program Runtime: 44 milli secs
Progress: 1479/1479 test cases passed.
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
	bool isNumber(const char *s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		if(!s) return false;

		bool sign(false),emark(false),point(false),number(false),blank(false);

		while(*s == ' ') ++s;

		if(*s == '+' || *s == '-')
		{
			sign = true;
			++s;
		}

		while(*s)
		{
			if(*s >='0' && *s <= '9')
			{
				if(blank)
					return false;

				number = true;
				++s;
			}
			else if(*s == '.')
			{
				if(emark || point || blank) //E后面不能是小数
					return false;
				else{
					point=true;
					//number = false;
					++s;
				}
			}else if(*s == 'e' || *s == 'E')
			{
				if(!number || emark || blank) //E前没有数字,则失败
					return false;
				else{
					emark = true;
					number = false;
					++s;
				}
			}else if(*s == '+' || *s=='-')
			{
				if(*(s-1)=='e' || *(s-1) == 'E')
				{
					number =false;
					++s;
				}else{
					return false;
				}
			}
			else if(*s == ' ')
			{
				blank = true;
				++s;
			}else{
				return false;
			}
		}

		return number;
	}
};

void solve()
{

}

#endif