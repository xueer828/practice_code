#ifndef _TEST_
#define _TEST_

// permutations
// Copyright (c) 2013/4/28 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
 */

/*
Run Status: Accepted!
Program Runtime: 88 milli secs
Progress: 25/25 test cases passed.
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
	vector<vector<int> > vec;

	void permute_recusive(vector<int>& num, int n)
	{
		int sz=num.size();
		if(n >= sz-1)
		{
			//此时出现个排列
			vec.push_back(num);
			return;
		}

		int tmp=num[n];
		for(int i=n;i<sz;++i)
		{
			//将n后的每一位同第n位进行交换,然后排列后面的n-1位
			num[n]=num[i];
			num[i]=tmp; 

			permute_recusive(num,n+1);

			//恢复,继续下一位
			num[i]=num[n];
			num[n]=tmp;
		}
	}
public:
	vector<vector<int> > permute(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vec.clear();
		int sz=num.size();
		if(sz <= 0)
			return vec;

		permute_recusive(num,0);

		return vec;
	}
};

void solve()
{
	vector<int> a(3);
	a[0]=1;
	a[1]=2;
	a[2]=3;
	Solution s;
	s.permute(a);
}

#endif 