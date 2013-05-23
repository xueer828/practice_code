#ifndef _TEST_
#define _TEST_

// valid_palindrome
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

/*
Run Status: Accepted!
Program Runtime: 56 milli secs
Progress: 475/475 test cases passed.
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
	bool is_alph(char c)
	{
		if(c >='a' && c<='z' || c >= 'A' && c <= 'Z' || c >= '0' && c<= '9')
			return true;
		else 
			return false;
	}
public:
	bool isPalindrome(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int len=s.length();

 		if(len==0)
			return true;

		int beg(0),end(len-1);
		for(;beg<end;++beg,--end)
		{
			while( beg < end && !is_alph(s[beg])) ++beg;
			while( beg < end && !is_alph(s[end])) --end;

			if(beg < end){
				if(s[beg] >= 'A' && s[beg] <= 'Z')
					s[beg] += 'a'-'A';
				if(s[end] >= 'A' && s[end] <= 'Z')
					s[end] += 'a'-'A';

				if(s[beg] != s[end])
					return false;
			}
		}

		return true;
	}
};

void solve()
{
	Solution s;
	s.isPalindrome(".,");
}

#endif