#ifndef _TEST_
#define _TEST_

// search_in_rotated_sorted_array2
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 
/*
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/

/*
重复元素的数组

相比于上一题的问题,我想不同的地方在于可能存在相同元素再头尾和中间值相等的情况下
算法复杂度提升为O(n)

太容易出错了,bug-free不容易啊

Run Status: Accepted!
Program Runtime: 44 milli secs
Progress: 271/271 test cases passed.
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
	bool search(int A[], int n, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!A || n <=0) return false;

		int low(0),high(n-1),mid;

		while(low <= high)
		{
			mid = (low+high) >> 1;
			if(A[mid] == target)
				return true;
			
			if(A[low] < A[mid]) //very sure: low part is sorted
			{
				if(target < A[mid] && A[low] <= target)
					high = mid - 1;
				else
					low = mid + 1;

			}else if(A[low] > A[mid]) //very sure: high part is sorted
			{
				if(target > A[mid] && target <= A[high])
					low = mid + 1;
				else
					high = mid - 1;
			}else{ //low == mid == high的情况
				++low;  //逐步消除破坏 low mid 和high 相等的情况,
						//使其变成前面的两种情况,最坏情况是只有一个要查询的元素不同,其他元素均相同
			}
		}

		return false;
	}
};

void solve()
{

}

#endif