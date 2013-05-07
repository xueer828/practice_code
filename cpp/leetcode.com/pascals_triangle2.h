#ifndef _TEST_
#define _TEST_

// pascals_triangle2
// Copyright (c) 2013/4/28 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
 */

/*
Run Status: Accepted!
Program Runtime: 8 milli secs
Progress: 34/34 test cases passed.
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
	vector<int> getRow(int rowIndex) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> res;

		if(rowIndex < 0)
			return res;

		res.resize(rowIndex+1);

		res[0]=1;

		for(int i=1;i<=rowIndex;++i)
		{
			res[i]=1;
			for(int j=i-1;j>0;--j)
				res[j]=res[j]+res[j-1];
		}

		return res;
	}
};

void solve()
{
}

#endif 