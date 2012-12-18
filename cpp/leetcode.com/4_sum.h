#ifndef _TEST_
#define _TEST_

// 4_sum
// Copyright (c) 2012/12/18 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ¡Ü b ¡Ü c ¡Ü d)
The solution set must not contain duplicate quadruplets.
For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

A solution set is:
(-1,  0, 0, 1)
(-2, -1, 1, 2)
(-2,  0, 0, 2)
*/

/*
Run Status: Accepted!
Program Runtime: 196 milli secs
Progress: 282/282 test cases passed.
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {

	bool exist(vector<vector<int> >& v,vector<int>& t)
	{
		for(int i=0;i<v.size();++i)
		{
			vector<int>& tmp=v[i];
			if(tmp[0]==t[0] && tmp[1]==t[1] && tmp[2] == t[2] && tmp[3] == t[3])
				return true;
		}
		return false;
	}

public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		
		vector<vector<int> > ret;

		if(num.size()<4)
			return ret;

		sort(num.begin(),num.end());

		int len=num.size();

		for(int i=1;i<len-2;++i)
		{
			for(int j=i+1;j<len-1;++j)
			{
				int m=i-1;
				int n=j+1;

				int s_mid=num[i]+num[j];

				while(m>=0 && n<len)
				{
					int s=s_mid + num[m]+num[n];

					if(s==target)
					{
						vector<int> tmp(4);
						tmp[0]=num[m];
						tmp[1]=num[i];
						tmp[2]=num[j];
						tmp[3]=num[n];

						if(!exist(ret,tmp))
						{
							ret.push_back(tmp);
						}
						--m,++n;
					}else if(s<target)
					{
						++n;
					}else{
						--m;
					}
				}
			}
		}

		return ret;
	}
};

void solve()
{
	Solution s;

	vector<int> v;

	v.push_back(1);
	v.push_back(0);
	v.push_back(-1);
	v.push_back(0);
	v.push_back(-2);
	v.push_back(2);

	vector<vector<int> > ret = s.fourSum(v,0);

	for(int i=0;i<ret.size();++i)
	{
		vector<int>& tmp=ret[i];
		printf("%d,%d,%d,%d\n",tmp[0],tmp[1],tmp[2],tmp[3]);
	}
}

#endif