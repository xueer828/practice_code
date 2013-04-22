#ifndef _TEST_
#define _TEST_

// longest_valid_parentheses
// Copyright (c) 2013/01/07 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

/*
思路: 利用栈,左括号,进行压栈,右括号,就与栈顶进行匹配,并弹出栈顶,不匹配则丢弃此括号
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
	int longestValidParentheses(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int sz=s.length();
		if(sz <=0 ) return 0;
		stack<char> con;

		int max_cnt(0),cnt(0);
		for(int i=0;i<sz;++i)
		{
			if(s[i]=='(')
				con.push(s[i]);
			else if(con.size()>0 && con.top()=='(')
			{
				con.pop();
				cnt += 2;
			}else{
				if(max_cnt < cnt)
					max_cnt = cnt;
				cnt = 0;
			}
		}
		if(max_cnt < cnt)
			max_cnt = cnt;
		return max_cnt;
	}
};

void solve()
{
	Solution s;
	cout<<s.longestValidParentheses(")()())");
}

#endif