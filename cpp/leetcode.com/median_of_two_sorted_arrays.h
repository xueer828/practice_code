#ifndef _TEST_
#define _TEST_

// median_of_two_sorted_arrays
// Copyright (c) 2013/4/25 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 */

//���ֽⷨ:
/*
1) ����ⷨ,���ƹ鲢˼·,���Ӷ�O(m+n)
2) �ֱ���A��B����λ��,Ȼ��Ƚ�����λ����С,������,�򷵻ش���λ��,���A[mid]<B[mid],˵��
   Ҫ��A[mid..end]��B[beg..mid]����λ��,���A[mid]>B[mid],��Ҫ��A[beg..mid]��B[mid..end]
   ��������λ��

ע������:�Ƿ�����λ��,���m+nΪ����,�򷵻����м����,����ͷ������м������͵�һ��
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
			//��ʱA��B�ṩ����Ŀ����Ϊ�ܺ͵�һ��,�򷵻����һ�εõ���mid��
			if(a1+b1 == ((m+n+1)>>1))
			{
				if((m+n)%2 == 1) //�ܳ�Ϊ����,�򷵻�mid����
					return mid;
				else{ //�ܳ�Ϊż��,����Ҫ���ش�����ǰһ����
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
				if((m+n)%2 == 1) //�ܳ�Ϊ����,�򷵻�mid����
					return mid;
				else{ //�ܳ�Ϊż��,����Ҫ���ش�����ǰһ����
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
				if((m+n)%2 == 1) //�ܳ�Ϊ����,�򷵻�mid����
					return mid;
				else{ //�ܳ�Ϊż��,����Ҫ���ش�����ǰһ����
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