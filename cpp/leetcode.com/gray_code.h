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

//思路:dfs,搜索

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
	vector<int> entry;
	int total;
	void dfs(int cur)
	{
		entry.push_back(cur);

		if(entry.size()>= (int)pow(2,total))
			return;

		//遍历每个可能改变的位置
		for(int i=0;i<n;++i)
		{
			int digit= ((1<<i) & cur);

			if(digit) //不是0,即相应位置为1,把这个数变成0,遍历下一位
			{
				dfs((cur & ~(digit)));
			}else{
				dfs((cur | (1<<i)));
			}
		}
	}
public:
	vector<int> grayCode(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> entry;

		int total=pow(2,n);
		int cur=0;
		while(entry.size()<total)
		{
			entry.push_back(cur);

			//遍历每个可能改变的位置
			for(int i=0;i<n;++i)
			{
				int digit= ((1<<i) & cur);

				if(digit) //不是0,即相应位置为1,把这个数变成0,遍历下一位
				{
					entry.push_back((cur & ~(digit)));
				}else{
					entry.push_back((cur | (1<<i)));
				}
			}

		}
		return entry;
	}
};

void solve()
{
	Solution s;
	s.grayCode(2);
}

#endif 
