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

/*
探讨收获: (这就是递归和回溯需要注意的地方)
1) 如果仅仅只需要求出一组解,那么只需要在递归点上,判断是否已经得出结果,如果得出就可以返回了;如果需要求解的所有结果,那么在递归点上就不能返回,必须恢复本次解空间设定,然后尝试求的所有可能的解, (所谓递归点就是递归的函数调用的地方)
2) 对于每一次从本函数体返回到上一层调用,包含最后函数结束默认的返回,都需要对本次调用过程中所设定的解空间进行清除.(很重要)
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
	typedef vector<vector<int> > vvint;
	void combin_recusive(vector<int>& c,int target,  vector<int>& r, int n, int sum, vvint& entry)
	{
		if(sum == target)
		{
			//把结果压入
			vector<int> tmp;
			for(int i=0;i<c.size();++i)
				for(int j=0;j<r[i];++j)
					tmp.push_back(c[i]);
			//压入最后结果
			entry.push_back(tmp);

			//r[n-1]=0;
			return;
		}		

		if(n>= c.size()) //已经枚举到了最后一个元素,但是未达到目标,则回溯到上一层
		{
			//r[n-1]=0;
			return;
		}

		//枚举可能的数量,从0到最大的可能值
		for(int i=0;i<=target/c[n];++i)
		{
			r[n]=i;
			if(sum+c[n]*r[n]<=target)
				combin_recusive(c,target,r,n+1,sum+c[n]*r[n],entry);
		}
		//在此回溯点(返回到上一层调用),需要清除本次调用过程中状态的设定
		r[n]=0;
	}

public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		vvint entry;
		sort(candidates.begin(),candidates.end());

		vector<int> status(candidates.size());
		combin_recusive(candidates,target,status,0,0,entry);
		
		return entry;
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