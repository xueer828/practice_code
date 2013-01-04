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

//思路:要求复杂度O(n), 同时仅仅使用固定大小的空间
//思路,因为数组大小为n,第一个missing的正数,肯定在0到n中的某个数
//(有可能0到n-1都填在数组中,那么此刻,第一个missing正数就是n),所以,可以读取数组的数字,然后置对应的
//数组的位置为0x80000000,如果读取到的数<0或者大于n都将不做任何操作
//最后在loop一遍整个数组,第一次碰到的非(n+1)的数即为
//PS. 貌似思路不是非常好~~~虽然水过了
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
