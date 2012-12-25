#ifndef _TEST_
#define _TEST_

// combination_sum2
// Copyright (c) 2012/12/24 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

Each number in C may only be used once in the combination.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
A solution set is: 
[1, 7] 
[1, 2, 5] 
[2, 6] 
[1, 1, 6] 
*/

/*
Run Status: Accepted!
Program Runtime: 56 milli secs
Progress: 172/172 test cases passed.
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
	void combin_recusive(vector<int>& num, int target, int n, vector<int>& s, int sum, VVINT& result)
	{
		if(sum == target) //meet
		{
			VINT tmp;
			for(int i=0;i<num.size();++i)
				if(s[i]>0)
					tmp.push_back(num[i]);
			result.push_back(tmp);

			return;
		}

		if(n >= num.size() || sum > target) //not match
			return;

		//仅仅考虑第一个数
		//当且仅当与前一个数不同,或者与前一个数相同且前一个数被选中的情况
		if(n==0 || num[n-1]!=num[n] || s[n-1]==1)
		{
			s[n]=1;
			combin_recusive(num,target,n+1,s,sum+num[n],result);
		}
		
		//not chose
		s[n] = 0;
		combin_recusive(num,target,n+1,s,sum,result);

		//注意每次返回应该保证本次设定的状态已经被清掉了,当然这里已经为0了,不必要再清了
		//s[n] = 0;		
	}

public:
	vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		sort(num.begin(),num.end());

		VVINT w;

		vector<int> status(num.size());

		combin_recusive(num,target,0,status,0,w);

		return w;
	}
};


void solve()
{
	Solution s;
}

#endif