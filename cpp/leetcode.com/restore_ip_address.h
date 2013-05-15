#ifndef _TEST_
#define _TEST_

// restore_ip_address
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

//思路: dfs搜索解空间,同时搜索的过程中剪枝

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
	bool ip_dfs(string s,int idx, int n)
	{
		if(n <= 0)
		{

		}

		int len=s.length();


	}
public:
	vector<string> restoreIpAddresses(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function


	}
};

void solve()
{

}

#endif