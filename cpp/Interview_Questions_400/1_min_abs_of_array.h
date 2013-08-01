#ifndef _TEST_
#define _TEST_

// min_abs_of_array
// Copyright (c) 2013/7/15 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Q:
有一个整数数组，请求出两两之差绝对值最小的值, 只要得出最小值即可，不需要求出是哪两个数
*/

/*
思路:
方法 1) 排序先,然后求相邻两个元素的最小的差的绝对值.
方法 2) 预处理,先求出数组相邻两个元素A[i],A[i+1]的差值,构成新的数组B[0..N-2], 然后类似DP求最大子段和的方式求子段和的最小绝对值
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

template<class T>
inline void myswap(T& t1, T& t2)
{
	T tmp=t1;
	t1 = t2;
	t2 = tmp;
}

template<class T>
inline int median(T& a, T& b,T& c)
{
	//sure b<=a<=c
	if(b > a) myswap(a,b);
	if(b > c) myswap(b,c);
	if(a > c) myswap(a,c);
	return a;
}

class Solution1{
	
	//快排
	void myqsort(int *arr,int beg, int end)
	{
		if(beg >= end)
			return;

		//获得枢轴,求起点元素,最后元素和中间元素三者的中间值
		int mid=(beg+end)>>1;
		int p=median(arr[beg],arr[mid],arr[end]);

		int b(beg+1),e(end);

		while(b<e)
		{
			while(arr[b] < p) ++b;
			while(arr[e] > p) --e;

			if(b<e)
				myswap(arr[b],arr[e]);
			else
				break;
			++b,--e;
		}

		myswap(arr[beg],arr[e]);

		myqsort(arr,beg,e-1);
		myqsort(arr,e+1,end);
	}
public:
	int get_min_abs(int *arr, int len)
	{
		if(!arr || len <= 1) return 0;

		unsigned mn=0xffffffff;

		myqsort(arr,0,len-1);
		for(int i=0;i<len-1;++i)
		{
			unsigned t=(arr[i]>=arr[i+1]?arr[i]-arr[i+1]:arr[i+1]-arr[i]);
			if(mn > t)
				mn = t;
		}

		return mn;
	}
};

class Solution2
{
public:
	int get_min_abs(int arr[],int len)
	{
		if(!arr || len <= 1) return 0;

		int* B=new int[len-1];

		for(int i=0;i<len-1;++i)
			B[i]=arr[i]-arr[i+1];

		unsigned mn=0xffffffff;

		int pre=0;

		for(int i=0;i<len-1;++i)
		{
			if(abs(pre+B[i]) < abs(B[i]))
				pre = pre+B[i];
			else
				pre = B[i];

			if(mn > abs(pre))
				mn = abs(pre);
		}

		delete[] B;

		return mn;
	}
};

void solve()
{
	/*
	int arr[]={0,4,1};
	cout<<median(arr[0],arr[1],arr[2])<<endl;
	*/

	int arr[]={1,9,4,20,-1};

	Solution1 s;
	cout<<s.get_min_abs(arr,sizeof(arr)/sizeof(arr[0]))<<endl;

	Solution2 s2;
	cout<<s2.get_min_abs(arr,sizeof(arr)/sizeof(arr[0]))<<endl;
}

#endif 