#ifndef _TEST_
#define _TEST_

// combination_sum
// Copyright (c) 2012/12/23 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/

//思路,递归

/*
Run Status: Accepted!
Program Runtime: 124 milli secs
Progress: 168/168 test cases passed.
*/

//虽然通过了,但是觉得实现的非常不好,需要跟人探讨下这个问题

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
	vector<vector<int> > entry;
	void combin_recusive(vector<int>& c,int target,  vector<int>& r, int n, int sum)
	{
		if(sum == target)
		{
			entry.push_back(r); //压入结果,回溯
			//r[n-1]=0;
			return;
		}		

		if(n>= c.size())
		{
			r[n-1]=0;
			return;
		}

		//枚举可能的数量,从0到最大
		for(int i=0;i<=target/c[n];++i)
		{
			r[n]=i;
			if(sum+c[n]*r[n]<=target)
				combin_recusive(c,target,r,n+1,sum+c[n]*r[n]);
		}
		r[n]=0;
	}

public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		entry.clear();
		vector<vector<int> > result;
		sort(candidates.begin(),candidates.end());

		vector<int> status(candidates.size());
		combin_recusive(candidates,target,status,0,0);
		
		vector<int> t;
		for(int i=0;i<entry.size();++i)
		{
			vector<int>& tmp=entry[i];
			for(int j=0;j<tmp.size();++j)
			{
				for(int k=1;k<=tmp[j];++k)
					t.push_back(candidates[j]);
			}
			if(t.size()>0)
			{
				result.push_back(t);
				t.clear();
			}
			
		}
		
		return result;
	}
};

void solve()
{
	Solution s;

	vector<int> test;
	test.push_back(2);
	test.push_back(3);
	

	s.combinationSum(test,6);
}

#endif