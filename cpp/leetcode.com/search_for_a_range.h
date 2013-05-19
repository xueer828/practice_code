#ifndef _TEST_
#define _TEST_

// search_for_a_range
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
*/

/*
这个似乎就是equal_range()啊~~

Run Status: Accepted!
Program Runtime: 64 milli secs
Progress: 81/81 test cases passed.
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
public:
	vector<int> searchRange(int A[], int n, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> res(2);
		res[0]=res[1]=-1;
		if(n <= 0)
			return res;

		int s(0),e(n-1),m;
		while(s <= e)
		{
			m = (s+e) >> 1;
			if(A[m]==target)
			{
				//从m往前找和从m往后找
				int k=m;
				while(k >0 && A[k-1]==target) --k;
				res[0]=k;
				k=m;
				while(k < n-1 && A[k+1]==target) ++k;
				res[1]=k;
				return res;
			}
			else if(A[m] < target)
				s = m + 1;
			else
				e = m - 1;
		}

		return res; //未找到
	}
};

void solve()
{
	int A[]={2,2};
	Solution s;
	s.searchRange(A,2,2);
}

#endif