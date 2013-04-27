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

//��Ŀ:�������ź����A��B, ��B�ϲ�����A, A���㹻�Ŀռ�����B

//˼·,��·�鲢,�������Ǵ�A�ĺ��濪ʼ���͹鲢

/*
��ϧ��,�Ͳ�һ���,��һ���Ϳ���һ����AC��.. :'(
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

		if(n <= 0) //B Ϊ��,��A����
			return; 

		//�Ӻ���ǰ���й鲢
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

		//copyʣ���B
		while(nb >= 0)
		{
			A[tofill--] = B[nb--];
		}

		//A��ʣ��ľͲ��ñ仯��copy��

	}
};

void solve()
{
}

#endif 