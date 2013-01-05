#ifndef _TEST_
#define _TEST_

// gray_code
// Copyright (c) 2013/1/4 
// Author: xdutaotao (xdutaotao@gmail.com)
// 


/*
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/

//思路:dfs,搜索;全错;根据格雷码算法

/*
Run Status: Accepted!
Program Runtime: 24 milli secs
Progress: 12/12 test cases passed.
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
	vector<int> grayCode(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> entry;

		int total=1<<n; //2^n
		for(int i=0;i<total;++i)
		{
			entry.push_back((i>>1)^i); //格雷码算法,见 http://baike.baidu.com/view/358724.htm
		}
		
		return entry;
	}
};

void solve()
{

}

#endif 
