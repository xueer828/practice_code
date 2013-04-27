#ifndef _TEST_
#define _TEST_

// maximum_subarray
// Copyright (c) 2013/4/25 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.

More practice:
If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 */

//最大子段和,题目要求至少包含一个数字,且为O(n)方案,并且提出另外一种分治方案

//方案1: DP, 公式 DP[i] = {DP[i-1] + A[i]; if DP[i-1] > 0, or A[i]; if DP[i-1] <= 0} 算法复杂度O(n)

/*
DP 方案一次性AC
Run Status: Accepted!
Program Runtime: 48 milli secs
Progress: 200/200 test cases passed.
 */

//方案2: 分治,分别求左右最大子段和,然后判断是否可以合并为新的最大和

/*
分治法,AC
Run Status: Accepted!
Program Runtime: 52 milli secs
Progress: 200/200 test cases passed.
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

class Solution1 {
public:
	int maxSubArray(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		if(n <=0) return 0;

		int mx_sum = A[0]; //先令最大和为第一个数
		int sum=A[0];
		for(int i=1;i<n;++i)
		{
			if(sum > 0)
				sum += A[i];
			else
				sum = A[i];

			if(sum > mx_sum)
				mx_sum = sum;
		}
		return mx_sum;
	}
};


/*
分治法,将数组分成两部分,[1..n/2]和[n/2+1..n],那么最大子段和有三种情况
1) 最大子段和在前半部分[1..n/2]中
2) 在后半部分[n/2+1..n]中
3) 在两段合并中,这种情况下,需要从n/2处开始往外求和,并获取最大的值
整个算法复杂度T(n)=2T(n/2)+O(n)=O(nlgN)
 */

/*
Run Status: Accepted!
Program Runtime: 52 milli secs
Progress: 200/200 test cases passed.
 */
class Solution {
	int max_sum_array(int A[], int beg, int end)
	{
		assert(beg <= end);

		if(beg == end)
		{
			return A[beg]; //因为必须有一个数,所以不考虑=0的情况
		}

		int mid=(beg + end) >> 1; //求取中间节点
		int left_sum=max_sum_array(A,beg,mid);
		int right_sum=max_sum_array(A,mid+1,end);

		//从mid开始往前,求左边最大的和
		int lsum=A[mid],mx_lsum=A[mid];
		for(int i=mid-1;i>=beg;--i)
		{
			lsum += A[i];
			if(lsum > mx_lsum)
				mx_lsum = lsum;
		}

		//从mid开始往右,求右边的最大和
		int rsum=A[mid+1],mx_rsum=rsum;
		for(int i=mid+2;i<=end;++i)
		{
			rsum += A[i];
			if(rsum > mx_rsum)
				mx_rsum = rsum;
		}

		//将左右最大值合并起来
		int sum = mx_lsum + mx_rsum;

		if(sum < left_sum)
			sum = left_sum;

		if(sum < right_sum)
			sum = right_sum;

		return sum;
	}
public:
	int maxSubArray(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		return max_sum_array(A,0,n-1);
	}
};


void solve()
{
}

#endif 