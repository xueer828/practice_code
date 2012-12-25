#ifndef _TEST_
#define _TEST_

// combinations
// Copyright (c) 2012/12/25 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
[2,4],
[3,4],
[2,3],
[1,2],
[1,3],
[1,4],
]
*/

/*
一次通过,深度递归
Run Status: Accepted!
Program Runtime: 52 milli secs
Progress: 26/26 test cases passed.
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
	typedef vector<vector<int> > VVINT;
	typedef vector<int> VINT;

	VVINT ret;

	void combine_recusive(VINT& ctx, int idx, int k)
	{
		if(k <= 0)
		{
			VINT tmp;
			for(int i=0;i<ctx.size();++i)
			{
				if(ctx[i]>0)
					tmp.push_back(i+1);
			}
			ret.push_back(tmp);

			return;
		}

		if(idx >= ctx.size())
			return;

		//chose or not chose
		ctx[idx]=1;
		combine_recusive(ctx,idx+1,k-1);
		ctx[idx]=0;
		combine_recusive(ctx,idx+1,k);
	}
public:
	vector<vector<int> > combine(int n, int k) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		ret.clear();

		if(n<k)
			return ret;

		VINT contxt(n);
		combine_recusive(contxt,0,k);

		return ret;
	}
};

void solve()
{

}

#endif