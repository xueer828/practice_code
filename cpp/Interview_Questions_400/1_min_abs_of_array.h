#ifndef _TEST_
#define _TEST_

// min_abs_of_array
// Copyright (c) 2013/7/15 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Q:
��һ���������飬���������֮�����ֵ��С��ֵ, ֻҪ�ó���Сֵ���ɣ�����Ҫ�������������
*/

/*
˼·:
���� 1) ������,Ȼ������������Ԫ�ص���С�Ĳ�ľ���ֵ.
���� 2) Ԥ����,�����������������Ԫ��A[i],A[i+1]�Ĳ�ֵ,�����µ�����B[0..N-2], Ȼ������DP������Ӷκ͵ķ�ʽ���Ӷκ͵���С����ֵ
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
	
	//����
	void myqsort(int *arr,int beg, int end)
	{
		if(beg >= end)
			return;

		//�������,�����Ԫ��,���Ԫ�غ��м�Ԫ�����ߵ��м�ֵ
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