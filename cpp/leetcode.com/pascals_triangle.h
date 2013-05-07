#ifndef _TEST_
#define _TEST_

// pascals_triangle
// Copyright (c) 2013/4/28 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
[1],
[1,1],
[1,2,1],
[1,3,3,1],
[1,4,6,4,1]
]
 */

/*
一次性通过
Run Status: Accepted!
Program Runtime: 20 milli secs
Progress: 15/15 test cases passed.
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
	vector<vector<int> > res;
public:
	vector<vector<int> > generate(int numRows) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		res.clear();

		if(numRows <= 0)
			return res;

		vector<int> elem; //初始化第一个元素
		elem.push_back(1);
		res.push_back(elem);

		for(int i=1;i<numRows;++i)
		{
			elem.push_back(1);
			for(int j=i-1;j>0;--j)
			{
				elem[j]=elem[j]+elem[j-1];
			}
			res.push_back(elem);
		}

		return res;
	}
};

void solve()
{
}

#endif 