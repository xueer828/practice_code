#ifndef _TEST_
#define _TEST_

// decode_ways
// Copyright (c) 2012/12/26 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

//˼·:Ӧ���ǵ���,��ʽ: f(n) ��������n����ʱ�����Ŀ = {f(n-1)+2 | ��ǰ�����ӵ���С�ڵ��� 26, f(n-1) + 1 | ǰ�����ӵ������� 26 ���ܹ���decode}

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
	int numDecodings(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int len=s.length();
		if(len <=0)
			return 0;
		int pre_f;
		if(s[0]=='0')
			pre_f=0;
		else
			pre_f=1;
		for(int i=1;i<len;++i)
		{
			if((s[i-1]-'0')*10+s[i]-'0' <= 26)
				++pre_f;
			if(s[i]-'0' != 0)
				++pre_f;
		}

		return pre_f;
	}
};

void solve()
{
	Solution s;
	cout<<s.numDecodings("12");
}

#endif