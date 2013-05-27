#ifndef _TEST_
#define _TEST_

// wildcard_matching
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "*") ? true
isMatch("aa", "a*") ? true
isMatch("ab", "?*") ? true
isMatch("aab", "c*a*b") ? false
*/

/*
方法1 必须要用递归
我的递归方法大数据TLE超时,faint
*/

/*
方法2: 递归 依然失败
大数据TLE超时
*/

/*
方法3: 看来需要非递归思想
非递归方法的主要思想是，从匹配串和模式串开头匹配，如果发现当前不能匹配了
则检测之前是否出现过 *， 如果有*出现过，则模式串跳过当前不匹配的字符，模式串跳过星号。

Run Status: Accepted!
Program Runtime: 76 milli secs
Progress: 1800/1800 test cases passed.
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
	bool isMatch(const char *s, const char *p) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!s || !p) return false;

		if(*s == 0 && *p == 0) 
			return true;

		if((*p=='?' && *s) || *p == *s)
		{
			++p,++s;
			if(isMatch(s,p))
				return true;
		}else if(*p == '*')
		{
			while(*p=='*') ++p;

			//从后往前尝试
			const char* stmp=s;
			while(*stmp) ++stmp;

			for(;stmp>=s;--stmp)
			{
				if(isMatch(stmp,p))
					return true;
			}
			return false;
		}

		return false;
	}
};

class Solution2 {
public:
	bool isMatch(const char *s, const char *p) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		if(!p && !s) return true;

		while(*p)
		{
			if((*p == '?' && *s) || *p == *s)
			{
				++p,++s;
			}else if(*p == '*')
			{
				while(*p=='*') ++p;

				//从后往前尝试
				const char* stmp=s;
				while(*stmp) ++stmp;

				for(;stmp>=s;--stmp)
				{
					if(isMatch(stmp,p))
						return true;
				}
				return false;
			}else
				return false;
		}

		if(*p == *s)
			return true;
		else 
			return false;
	}
};

class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!s && !p) return true;

		const char *star_p=NULL,*star_s=NULL;

		while(*s)
		{
			if(*p == '?' || *p == *s)
			{
				++p,++s;
			}else if(*p == '*')
			{
				//skip all continuous '*'
				while(*p == '*') ++p;

				if(!*p) return true; //if end with '*', its match.

				star_p = p; //store '*' pos for string and pattern
				star_s = s;
			}else if((!*p || *p != *s)  && star_p)
			{
				s = ++star_s; //skip non-match char of string, regard it matched in '*'
				p = star_p; //pattern backtrace to later char of '*'
			}else
				return false;
		}

		//check if later part of p are all '*'
		while(*p)
			if(*p++ != '*')
				return false;

		return true;
	}
};

void solve()
{
	Solution s;
	cout<<s.isMatch("mississippi","m*si*")<<endl;
}

#endif