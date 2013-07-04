#ifndef _TEST_
#define _TEST_

// sqrt_x
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Implement int sqrt(int x).

Compute and return the square root of x.
*/

/*
Run Status: Accepted!
Program Runtime: 56 milli secs
Progress: 1016/1016 test cases passed.
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

//����������sqrt(x),
/*
ע��: 
1) ���ص���sqrt(x)�ķǾ�ȷֵ,Ҳ����˵��n, ����  n*n<=x �� (n+1)*(n+1)>x
2) ���ֵ�high��low��Ҫ��unsigned int,������������,�����ѭ��
*/

class Solution {
public:
	int sqrt(int x) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		if(x <= 0) return 0;

		unsigned int mx=65535;
		if(mx*mx < x) return mx;

		//���������� 1 �� mx, Ѱ�� n*n == x

		unsigned int mn=0;
		unsigned int mid=0;

		while(1)
		{
			mid = (mx + mn) >> 1;
			if(mid*mid > x)
			{
				mx = mid-1;
			}else if((mid+1)*(mid+1) <= x)
			{
				mn = mid +1;
			}else{
				return mid;
			}
		}		
	}
};


void solve()
{
	Solution s;
	s.sqrt(2147395599);
}

#endif