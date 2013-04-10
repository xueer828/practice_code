#ifndef _TEST_
#define _TEST_

// 1022_min_k_numbers
// Copyright (c) 2013/4/5 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
��Ŀ������
����n���������ҳ�������С��K��������������4,5,1,6,2,7,3,8��8�����֣�����С��4��������1,2,3,4,��
���룺
ÿ�����԰�������2�У�
��һ��Ϊ2������n��k(1<=n��k<=200000)����ʾ����ĳ��ȡ�
�ڶ��а���n����������ʾ��n�����������е����ķ�Χ��[0,1000 000 000]��
�����
��Ӧÿ�����԰����������С��k������������С����˳���ӡ��
�������룺
8 4
4 5 1 6 2 7 3 8
���������
1 2 3 4
*/

//��С��K����,�ô󶥶���ʵ��

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

//�󶥶�

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

		//��һ����ÿ�����Ҫ�滻�Ľڵ�
		if(right < end && arr[right] >arr[left])
		{
			rep=right;
		}else{
			rep=left;
		}

		//�ڶ���ȷ�������滻,���滻
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

//���i�����Һ���Ϊ2i+1��2(i+1), ��2i+1��2i+2;
template<class T>
void init_heap(T arr[],int sz)
{
	if(!arr || sz <= 0)
		return;

	//�����һ����Ҷ�ӽڵ���ǰ����
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