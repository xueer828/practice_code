#ifndef _TEST_
#define _TEST_

// length_of_last_word
// Copyright (c) 2013/01/07 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

/*
Run Status: Accepted!
Program Runtime: 24 milli secs
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
	int lengthOfLastWord(const char *s) {
		if(!s) return 0;

		const char* t=s;
		while(*t) ++t;

		--t; //ÅÙ³ý×îºóµÄ¿Õ×Ö·û
		while(*t == ' ' && t >= s) --t;

		int cnt=0;
		while(t >= s)
		{
			if(*t == ' ') break;
			++cnt,--t;
		}
	
		return cnt;
	}
};

void solve()
{
	Solution s;
	cout<<s.lengthOfLastWord("a")<<endl;
}

#endif