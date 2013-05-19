#ifndef _TEST_
#define _TEST_

// search_insert_postition
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

/*
一样二分方法,前提,数字不同

Run Status: Accepted!
Program Runtime: 32 milli secs
Progress: 62/62 test cases passed.
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
	int searchInsert(int A[], int n, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!A || n<=0) return 0;

		int s(0),e(n-1),m;

 		while(s<=e) //这里相等依然可以进入,那就是说如果不相等
					//最后跳出时 e < s; e肯定是比插入的值小,s肯定是比插入的值大
		{
			m = (s+e) >> 1;
			if(target == A[m])
				return m;
			else if(target > A[m])
			{
				s = m + 1;
			}else{
				e = m - 1;
			}
		}

		//未查到
		return e+1;
	}
};


void solve()
{
	int A[]={1,3};
	Solution s;
	s.searchInsert(A,2,2);
}

#endif