#ifndef _TEST_
#define _TEST_

// find_local_min_20130117
// Copyright (c) 2013/01/21 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
   ����һ���������飬���һ��ֵ��������ǰ��������Ԫ�أ���a<=a[i-1] && a <=a[i + 1]�������ͷ����β����ֻ��һ��)����a����һ���ֲ���Сֵ������������һ����Сֵ���±ꡣ��ֻ��һ�����ɣ�
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

int find_local_min(int arr[], int sz)
{
	assert(sz > 0);
	int left=0;
	int pos=0,res=arr[pos];

	while(left<sz-1 && arr[left+1] <= arr[left]) ++left;
	if(arr[left] < res)
	{
		res = arr[left];
		pos=left;
	}

	return pos;
}

void solve()
{
	int arr[]={7,9};
	cout<<find_local_min(arr,sizeof(arr)/sizeof(arr[0]))<<endl;
}

#endif