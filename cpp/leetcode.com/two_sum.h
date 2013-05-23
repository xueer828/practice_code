#ifndef _TEST_
#define _TEST_

// two_sum
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/

/*
Run Status: Accepted!
Program Runtime: 12 milli secs
Progress: 10/10 test cases passed.
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

bool cmp(const pair<int,int>& p1, const pair<int,int>& p2)
{
	return p1.first < p2.first;
}

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> v(2,0);
		int sz=numbers.size();
		if(sz <= 0)
			return v;

		vector<pair<int,int> > pnumbers(sz);

		for(int i=0;i<sz;++i)
		{
			pnumbers[i].first = numbers[i];
			pnumbers[i].second=i;
		}

		//sort(pnumbers.begin(),pnumbers.end(),cmp);
		sort(pnumbers.begin(),pnumbers.end());

		int s(0),e(sz-1),sum;
		for(;s<e;)
		{
			sum =pnumbers[s].first + pnumbers[e].first;
			if(sum==target)
			{
				if(pnumbers[s].second < pnumbers[e].second)
				{
					v[0]=pnumbers[s].second+1;
					v[1]=pnumbers[e].second+1;
				}else{
					v[0]=pnumbers[e].second+1;
					v[1]=pnumbers[s].second+1;
				}
				break;
			}else if(sum > target)
				--e;
			else
				++s;
		}

		return v;
	}
};

void solve()
{

}

#endif