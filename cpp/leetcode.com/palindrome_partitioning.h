#ifndef _TEST_
#define _TEST_

// palindrome_partitioning
// Copyright (c) 2013/4/28 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

[
["aa","b"],
["a","a","b"]
]
 */

//思路: dfs 深度递归

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
	vector<vector<string> > rt;
	void dfs(string& s, vector<string>& v, int n)
	{
		if(n >= s.size())
		{
			rt.push_back(v);
			return;
		}

		for(int i=n;i<s.size();++i)
		{

		}
	}
public:
	vector<vector<string>> partition(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

	}
};

void solve()
{
}

#endif 