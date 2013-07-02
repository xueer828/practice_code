#ifndef _TEST_
#define _TEST_

// median_of_two_sorted_arrays
// Copyright (c) 2013/4/25 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 */

//两种解法:
/*
1) 常规解法,类似归并思路,复杂度O(m+n)
2) 分别求A和B的中位数,然后比较其中位数大小,如果相等,则返回此中位数,如果A[mid]<B[mid],说明
   要在A[mid..end]和B[beg..mid]求中位数,如果A[mid]>B[mid],则要在A[beg..mid]和B[mid..end]
   部分求中位数

注意题意:是返回中位数,如果m+n为奇数,则返回最中间的数,否则就返回最中间俩数和的一半
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
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!A ||!B || m+n <= 0) return 0;

		int a1=0,b1=0;

		int mid(0),lessmid(0);

		while(a1 < m && b1 < n)
		{
			//此时A和B提供的数目正好为总和的一半,则返回最后一次得到的mid数
			if(a1+b1 == ((m+n+1)>>1))
			{
				if((m+n)%2 == 1) //总长为奇数,则返回mid即可
					return mid;
				else{ //总长为偶数,则需要返回此数和前一个数
					return (lessmid +mid)>>1;
				}
			}
			if(A[a1] < B[b1])
			{
				lessmid = mid;
				mid = A[a1++];
			}else{
				lessmid = mid;
				mid = B[b1++];
			}
		}

		while(a1<m)
		{
			lessmid = mid;
			mid = A[a1++];
			if(a1+b1 == ((m+n+1)>>1))
			{
				if((m+n)%2 == 1) //总长为奇数,则返回mid即可
					return mid;
				else{ //总长为偶数,则需要返回此数和前一个数
					return (lessmid +mid)>>1;
				}
			}
		
		}

		while(b1<n)
		{
			lessmid = mid;
			mid = B[b1];
			if(a1+b1==((m+n+1)>>1))
			{
				if((m+n)%2 == 1) //总长为奇数,则返回mid即可
					return mid;
				else{ //总长为偶数,则需要返回此数和前一个数
					return (lessmid +mid)>>1;
				}
			}
			
		}

		return 0;
	}
};

void solve()
{
	int a[]={0};
	int b[]={2,3};

	Solution s;
	cout<<s.findMedianSortedArrays(a,0,b,2)<<endl;
}

#endif 