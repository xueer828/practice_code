#ifndef _TEST_
#define _TEST_

// search_in_rotated_sorted_array
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

/*
Ҳ�ö��ַ�
ע�����ַ���ֻ�������� û����ͬԪ�ص���� (����ͼ,��Ƚ���ȷ)

Run Status: Accepted!
Program Runtime: 32 milli secs
Progress: 194/194 test cases passed.
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
	int search(int A[], int n, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!A || n <= 0)
			return -1;

		int s(0),e(n-1),m;
		while(s <= e)
		{
			m = (s+e) >> 1;

			if(A[m] == target)
				return m;
			else if(A[m] < target) //mid��targetС
			{
				if(target >= A[s] && A[s] > A[m]) //target��ǰ�벿��
					e = m-1;
				else
					s = m+1;
			}else{
				if(target <= A[e] && A[m] > A[e]) //target�ں�벿��
					s = m+1;
				else
					e = m-1;
			}
		}

		return -1;
	}
};

void solve()
{
	int A[]={4,5,6,7,8,1,2,3};
	Solution s;
	s.search(A,8,8);
}

#endif