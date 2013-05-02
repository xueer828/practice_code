#ifndef _TEST_
#define _TEST_

// next_perutation
// Copyright (c) 2013/4/25 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
 */

/*
下一个排列的算法:
1) 从后往前搜寻相邻元素: 找到第一个i满足 a[i] < a[i+1],如果i是0,表示,整个是单调递减队列,也就是说这是最后一个排列,下一个就全部逆转就可以了
2) 从后往前查找a[j]: 使得 a[i] < a[j] (i为第一阶段找到的元素, j为单调序列的最大index), 交换此时a[i]和a[j]位置
3) 从i往后,所有元素逆转,不包含i (也就是从i+1开始到最后所有元素,全部逆转)

*/

/*
Run Status: Accepted!
Program Runtime: 76 milli secs
Progress: 265/265 test cases passed.
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
	void swap(vector<int>& v, int s,int e)
	{
		int tmp;
		for(;s<=e;++s,--e)
		{
			tmp=v[s];
			v[s]=v[e];
			v[e]=tmp;
		}
	}
public:
	void nextPermutation(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		int i=num.size()-2;
		for(;i>=0;--i)
		{
			if(num[i] < num[i+1])
				break;
		}

		if(i >= 0) //暂未到序列最开始
		{
			//从序列尾往前查找第一个a[j] 使 a[i]<a[j]
			int j=num.size()-1;
			for(;j>=i;--j)
			{
				if(num[i] < num[j])
					break;
			}

			//交换 a[i]和a[j]
			int tmp=num[i];
			num[i]=num[j];
			num[j]=tmp;
		}

		//从i+1开始到最后,全部逆转
		swap(num,i+1,num.size()-1);
	}

	/*对于prev Permutation,算法跟nextPermutation是一致的,
	唯一区别就是:
	prevPermuation比较大小是用a[i] > a[i+1], (逆序)
	nextPermutation比较大小用a[i] < a[i+1] (正序)*/
	void prevPermutation(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
	
		int sz=num.size();
		if(sz<= 1)
			return;

		int i=sz-2;
		for(;i >=0;--i)
		{
			if(num[i] > num[i+1])
				break;
		}

		if(i >= 0) //i并未越界
		{
			//从后往前查找第一个满足num[i]大于num[j]的数
			int j=sz-1;
			for(;j > i;--j)
			{
				if(num[i] > num[j]) //必然是存在这么一个值的
					break;
			}

			//交换
			int tmp=num[j];
			num[j]=num[i];
			num[i]=tmp;
		}

		//从第一个到i为止(不包含i)全部逆转
		swap(num,i+1,sz-1);
	}
};

void solve()
{
	vector<int> v(10);
	v[0]=3;
	v[1]=7;
	v[2]=2;
	v[3]=3;
	v[4]=5;
	v[5]=1;
	v[6]=7;
	v[7]=9;
	v[8]=4;
	v[9]=8;
	Solution s;
	s.prevPermutation(v);
}

#endif 