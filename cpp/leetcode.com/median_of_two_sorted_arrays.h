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

/*
���ƹ鲢�ⷨ:
Run Status: Accepted!
Program Runtime: 196 milli secs
Progress: 2078/2078 test cases passed.
*/

/*
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
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!A ||!B || m+n <= 0) return 0;

		int a1(0),b1=(0);

		int mid(0),lessmid(0);

		while(a1 < m && b1 < n)
		{
			
			if(A[a1] < B[b1])
			{
				lessmid = mid;
				mid = A[a1++];
			}else{
				lessmid = mid;
				mid = B[b1++];
			}

			//��ʱA��B�ṩ����Ŀ����Ϊ�ܺ͵�һ��,�򷵻����һ�εõ���mid��
			if(a1+b1 == ((m+n+2)>>1))
			{
				if((m+n)%2 == 1) //�ܳ�Ϊ����,�򷵻�mid����
					return mid;
				else{ //�ܳ�Ϊż��,����Ҫ���ش�����ǰһ����
					return (lessmid +mid)/2.0;
				}
			}
		}

		while(a1<m)
		{
			lessmid = mid;
			mid = A[a1++];
			if(a1+b1 == ((m+n+2)>>1))
			{
				if((m+n)%2 == 1) //�ܳ�Ϊ����,�򷵻�mid����
					return mid;
				else{ //�ܳ�Ϊż��,����Ҫ���ش�����ǰһ����
					return (lessmid +mid)/2.0;
				}
			}		
		}

		while(b1<n)
		{
			lessmid = mid;
			mid = B[b1++];
			if(a1+b1==((m+n+2)>>1))
			{
				if((m+n)%2 == 1) //�ܳ�Ϊ����,�򷵻�mid����
					return mid;
				else{ //�ܳ�Ϊż��,����Ҫ���ش�����ǰһ����
					return (lessmid +mid)/2.0;
				}
			}
		}

		return 0;
	}
};

//O(lg(m+n))�㷨,���ƶ��ֲ��ҷ�
class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!A || !B || (m+n) <= 0) return 0;

		if(m==0){
			if((n&0x01)==1)
				return B[n/2];
			else
				return (B[n/2-1] + B[n/2])/2;
		}

		if(n==0)
		{
			if((m&0x01)==1)
				return A[m/2];
			else
				return (A[m/2-1]+A[m/2])/2;
		}

		int midA=A[m/2],midB=B[n/2];

		if(midA==midB)
			return midA;
		else if(midA > midB) //A����λ������B����λ��,˵����A��ǰ�벿�ֺ�B�ĺ�벿��
		{
			return findMedianSortedArrays(A,m/2,B+(n/2)+1,n-(n/2));
		}else{
			return findMedianSortedArrays(A+m/2+1,m-m/2,B,n/2);
		}
	}
};

void solve()
{
	int a[]={0};
	int b[]={2,3,3,4,5};

	Solution s;
	cout<<s.findMedianSortedArrays(a,0,b,2)<<endl;
}

#endif 