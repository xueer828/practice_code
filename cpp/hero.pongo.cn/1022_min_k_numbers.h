#ifndef _TEST_
#define _TEST_

// 1022_min_k_numbers
// Copyright (c) 2013/4/5 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
题目描述：
输入n个整数，找出其中最小的K个数。例如输入4,5,1,6,2,7,3,8这8个数字，则最小的4个数字是1,2,3,4,。
输入：
每个测试案例包括2行：
第一行为2个整数n，k(1<=n，k<=200000)，表示数组的长度。
第二行包含n个整数，表示这n个数，数组中的数的范围是[0,1000 000 000]。
输出：
对应每个测试案例，输出最小的k个数，并按从小到大顺序打印。
样例输入：
8 4
4 5 1 6 2 7 3 8
样例输出：
1 2 3 4
*/

//最小的K个数,用大顶堆来实现

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

//大顶堆

template<class T>
void adjust_heap(T arr[],int root,int end)
{
	if(!arr || root < 0 || end <= 0)
		return;

	while(root < end)
	{
		int left=root*2+1;
		int right=root*2+2;
		int rep;

		//第一步获得可能需要替换的节点
		if(right < end && arr[right] >arr[left])
		{
			rep=right;
		}else{
			rep=left;
		}

		//第二步确定可以替换,并替换
		if(rep < end && arr[rep] > arr[root])
		{
			T tmp=arr[root];
			arr[root]=arr[rep];
			arr[rep]=tmp;
			root=rep;
		}else{
			return;
		}
	}
	return;
}

template<class T>
void add(T arr[], int sz, T v)
{
	if(!arr)
		return;

	if(v > arr[0])
		return;

	arr[0]=v;

	adjust_heap(arr,0,sz);

}

template<class T>
void sort_heap(T arr[],int sz)
{
	if(!arr || sz <= 0) return;

	for(int i=sz-1;i>=0;--i)
	{
		T tmp=arr[i];
		arr[i]=arr[0];
		arr[0]=tmp;

		adjust_heap(arr,0,i);
	}
}

//令顶点i的左右孩子为2i+1和2(i+1), 即2i+1和2i+2;
template<class T>
void init_heap(T arr[],int sz)
{
	if(!arr || sz <= 0)
		return;

	//从最后一个非叶子节点往前调整
	int cur=(sz-2)/2;

	for(;cur>=0;--cur)
	{
		adjust_heap(arr,cur,sz);
	}
}

template<class T>
struct print_f{
void operator()(const T& t)
{
	cout<<t<<" ";
}
};

void solve()
{
	int sz,k,i,tmp;
	cin>>sz>>k;
	int *array=new int[k];
	for(i=0;i<k;++i)
	{
		cin>>array[i];
	}

	init_heap(array,k);

	for(;i<sz;++i)
	{
		cin>>tmp;
		add(array,k,tmp);
	}

	sort_heap(array,k);

	for_each(array,array+k,print_f<int>());
	delete[] array;
}

#endif 