#ifndef _TEST_
#define _TEST_

// remove_duplicates_from_sorted_array
// Copyright (c) 2013/5/8 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
 */

/*
大意了,竟然不能一次性AC
Run Status: Accepted!
Program Runtime: 80 milli secs
Progress: 160/160 test cases passed.
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
	int removeDuplicates(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!A || n<=0) return 0;

		int p1=0,p2=1; //一前一后两指针

		//p1为写位置,p2为读位置,只有当p2的值等于p1位置的值,且p1跟p2不在同一位置时,只移动读位置
		while(p2 < n)
		{
			if(A[p1] != A[p2])
			{
				A[++p1] = A[p2];
			}
			++p2;
		}

		return p1+1;
	}
};

void solve()
{
	int arr[]={1,1,1};
	Solution s;
	s.removeDuplicates(arr,3);
}

#endif 