#ifndef _TEST_
#define _TEST_

// first_missing_positive
// Copyright (c) 2013/1/4 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

//˼·:Ҫ���Ӷ�O(n), ͬʱ����ʹ�ù̶���С�Ŀռ�
//˼·,��Ϊ�����СΪn,��һ��missing������,�϶���0��n�е�ĳ����
//(�п���0��n-1������������,��ô�˿�,��һ��missing��������n),����,���Զ�ȡ���������,Ȼ���ö�Ӧ��
//�����λ��Ϊ0x80000000,�����ȡ������<0���ߴ���n���������κβ���
//�����loopһ����������,��һ�������ķ�(n+1)������Ϊ
//PS. ò��˼·���Ƿǳ���~~~��Ȼˮ����
//

/*
Run Status: Accepted!
Program Runtime: 12 milli secs
Progress: 156/156 test cases passed.
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
	int firstMissingPositive(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		for(int i=0;i<n;++i)
		{
			if(A[i]!=0x80000000)
			{
				int data=A[i];
				while(data>0 && data<=n)
				{
					int tmp=A[data-1];
					if(tmp == 0x80000000)
						break;
					A[data-1]=0x80000000;
					data = tmp;
				}
			}
		}

		int i=0;
		for(i=0;i<n;++i)
		{
			if(A[i]!=0x80000000)
				break;
		}

		return i+1;
	}
};

void solve()
{
	int d[]={1,1};
	Solution s;
	s.firstMissingPositive(d,sizeof(d)/sizeof(d[0]));
}

#endif 
