#ifndef _TEST_
#define _TEST_

// valid_parentheses
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

/*
第一个感官,就是用栈

一次性通过

Run Status: Accepted!
Program Runtime: 8 milli secs
Progress: 61/61 test cases passed.
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
	bool isValid(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int sz=s.length();
		if(sz <=0)
			return true;

		stack<char> st;

		int i=0;
		for(;i<sz;++i)
		{
			if(st.empty())
			{
				if(s[i] == ')' || s[i] == '}' || s[i]==']')
					return false;
				else
					st.push(s[i]);
			}else{
				if(s[i] == ')' || s[i] == '}' || s[i]==']')
				{
					char top=st.top();
					if(top == '(' && s[i] != ')')
						return false;
					if(top == '{' && s[i] != '}')
						return false;
					if(top == '[' && s[i] != ']')
						return false;

					st.pop(); 
				}else{
					st.push(s[i]);
				}				
			}
		}

		if(st.empty())
			return true;
		else
			return false;
	}
};

void solve()
{

}

#endif