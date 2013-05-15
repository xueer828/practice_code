#ifndef _TEST_
#define _TEST_

// roman_to_integer
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
*/

/*
罗马数字, 规律,前一个字符如果比后一个字符进制小,那么这一位是减,反之则加
Run Status: Accepted!
Program Runtime: 212 milli secs
Progress: 3999/3999 test cases passed.
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
	//进制表
	map<char,int> vmap;

	void init()
	{
		vmap['I']=1;
		vmap['V']=5;
		vmap['X']=10;
		vmap['L']=50;
		vmap['C']=100;
		vmap['D']=500;
		vmap['M']=1000;
	}
public:
	int romanToInt(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int sz=s.length();
		int sz_less=sz-1;
		if(sz <= 0)
			return 0;

		init();

		int res=0;
		for(int i=0;i<sz;)
		{
			if(i<sz_less && vmap[s[i]] < vmap[s[i+1]])
			{
				res += vmap[s[i+1]] -  vmap[s[i]];
				i += 2;
			}else{
				res += vmap[s[i]];
				++i;
			}
		}

		return res;
	}
};

void solve()
{
	Solution s;
	cout<<s.romanToInt("MMMCMXCIX");
}

#endif