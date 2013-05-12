#ifndef _TEST_
#define _TEST_

// regular_expression_matching
// Copyright (c) 2013/5/8 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "a*") ? true
isMatch("aa", ".*") ? true
isMatch("ab", ".*") ? true
isMatch("aab", "c*a*b") ? true
 */

/*
Run Status: Accepted!
Program Runtime: 64 milli secs
Progress: 439/439 test cases passed.

//这一题,非常不好做,正则匹配not so easy.
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

//正则式匹配一般用递归来实现,因为这样可以做到贪婪匹配,从后往前匹配

class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function    
		if(!s || !p) return false;

		if(*p == 0) return *s==0;

		if(*(p+1) == '*') //对于 .* 和 x* 两种情况
		{
			while(*p==*s || (*p=='.' && *s)) //对于每个相等的字符均进行尝试比对
			{
				if(isMatch(s++,p+2))  //
					return true;	
			}
			return isMatch(s,p+2); //在尝试错误之后,进行不扩展匹配
		}else{
			if(*p == *s || (*p == '.' && *s))
				return isMatch(++s,++p);
		}

		return false;
	}
};

void solve()
{
	Solution s;
	s.isMatch("aaa","a*a");
}

#endif 