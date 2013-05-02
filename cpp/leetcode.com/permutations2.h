#ifndef _TEST_
#define _TEST_

// permutations2
// Copyright (c) 2013/4/28 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
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
	set<int> v;

	void permute_recusive(vector<int>& num, int n)
	{
		if(n >= num.size()-1)
		{
			vec.push_back(num);
			return;
		}

		int tmp=num[n];
		for(int i=n;i<num.size();++i)
		{
			//此时需要判断需要交换的数,是否前面已经排过了
			if(v.count(tmp))
				continue;

			num[n]=num[i];
			num[i]=tmp;

			permute_recusive(num,n+1);

			//恢复
			num[i]=num[n];
			num[n]=tmp;
		}
	}
public:
	vector<vector<int> > permuteUnique(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		vec.clear();
		if(num.size()<=0)
			return vec;

		permute_recusive(num,0);
		return vec;
	}
};

void solve()
{
}

#endif 