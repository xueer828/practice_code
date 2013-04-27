#ifndef _TEST_
#define _TEST_

// merge_sorted_array
// Copyright (c) 2013/4/25 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given two sorted integer arrays A and B, merge B into A as one sorted array.

Note:
You may assume that A has enough space to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
 */

//题目:现有已排好序的A和B, 将B合并进入A, A有足够的空间容纳B

//思路,二路归并,这个最好是从A的后面开始填充和归并

/*
可惜啊,就差一点点,就一点点就可以一次性AC了.. :'(
Run Status: Accepted!
Program Runtime: 32 milli secs
Progress: 59/59 test cases passed.
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
	void merge(int A[], int m, int B[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		if(n <= 0) //B 为空,则A不动
			return; 

		//从后往前进行归并
		int tofill=m+n-1,nb=n-1,na=m-1;
		while(na >= 0 && nb >=0)
		{
			if(A[na] > B[nb])
			{
				A[tofill] = A[na];
				--na;
			}else{
				A[tofill] = B[nb];
				--nb;
			}
			--tofill;
		}

		//copy剩余的B
		while(nb >= 0)
		{
			A[tofill--] = B[nb--];
		}

		//A中剩余的就不用变化和copy了

	}
};

void solve()
{
}

#endif 