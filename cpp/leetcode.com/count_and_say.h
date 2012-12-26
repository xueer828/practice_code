#ifndef _TEST_
#define _TEST_

// count_and_say
// Copyright (c) 2012/12/26 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

//直接硬算?模拟整个过程?

/*
参考了别人的方案,原来就是模拟硬算,faint,题目应该限制不会连续出现>10个的数字结果
Run Status: Accepted!
Program Runtime: 8 milli secs
Progress: 18/18 test cases passed.
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
	string countAndSay(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		string cur_s("1"),next_s("");

		for(int idx=2;idx<=n;++idx)
		{
			int count=0,j=0;
			char tmp=0;
			int len=cur_s.length();
			while(1)
			{
				if(j==0 || tmp == cur_s[j])
					++count;
				else
				{
					next_s += (char)(count + '0');
					next_s += tmp;
					count = 1;
				}
				tmp=cur_s[j];
				++j;

				if(j>=len)
				{
					next_s += (char)(count + '0');
					next_s += tmp;
					break;
				}
			}
			cur_s = next_s;
			next_s = "";
		}

		return cur_s;
	}
};

void solve()
{
	Solution s;
	cout<<s.countAndSay(4)<<endl;
}

#endif