#ifndef _TEST_
#define _TEST_

// 3_sum_closest
// Copyright (c) 2012/12/18 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

For example, given array S = {-1 2 1 -4}, and target = 1.

The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

/*
1stly Run Status: TLE

Run Status: Accepted!
Program Runtime: 80 milli secs
Progress: 119/119 test cases passed.
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		//O(N^3) algorithm, time limit exceeded 5555~~~~~
		/*
		int m=0x7fffffff;
		int mv;

		for(int i=0;i<num.size()-2;++i)
		{
			for(int j=i+1;j<num.size()-1;++j)
			{
				for(int k=j+1;k<num.size();++k)
				{
					int tmp = num[i]+num[j]+num[k];
					if(abs(tmp-target)<m)
					{
						m=abs(tmp-target);
						mv=tmp;
						//printf("%d,%d,%d %d\n",i,j,k,mv);
					}
				}
			}
		}
		return mv;
		*/

		// sort 1stly
		sort(num.begin(),num.end());

		int len=num.size();

		int minimum=0x7fffffff;
		int result=0;

		for(int i=1;i<len-1;++i)
		{
			int j=i-1;
			int k=i+1;

			while(j>=0 && k<len)
			{
				int sum=num[j]+num[i]+num[k];

				if(sum >= target)
				{
					if(sum-target < minimum)
					{
						minimum = sum - target;
						result = sum;
					}

					// in order to reach target
					--j;
				}else{ //sum < target
					if(target-sum < minimum)
					{
						minimum = target - sum;
						result = sum;
					}

					++k;
				}
			}
		}
		return result;
	}
};

void solve()
{
	Solution s;
	vector<int> v;
	v.push_back(-1);
	v.push_back(2);
	v.push_back(1);
	v.push_back(-4);

	cout<<"closest value:"<<s.threeSumClosest(v,1)<<endl;

}

#endif