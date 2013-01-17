#ifndef _TEST_
#define _TEST_

// Insertion_Sort
// Copyright (c) 2013/01/14 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
https://www.interviewstreet.com/challenges/dashboard/#problem/4e90477dbd22b
*/

//˼·:�����,�����ù鲢��˼·,���

//passed, ò��OJ������c���ַ������������

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

long long total = 0L;

//����Ҫ��һ��,�鲢����,���ܾ͵�����,��Ҫ���⿪��һƬ�ռ�

void merge_sort(vector<int>& arr,vector<int>& space, int beg, int end)
{
	if(beg >= end)
		return;

	int mid=(beg+end)>>1;

	merge_sort(arr,space,beg,mid);
	merge_sort(arr,space,mid+1,end);

	int i=beg,j=mid+1,k=beg;
	while(i<=mid && j<= end)
	{
		if(arr[i] > arr[j])
		{
			space[k++]=arr[j]; //arr[i..mid]����arr[j]��,���Լ�����ĿΪ(mid-i+1)
			total += (mid-i+1); 
			++j;
		}else{
			space[k++]=arr[i];
			++i;
		}
	}

	while(i<=mid)
		space[k++]=arr[i++];

	while(j<=end)
		space[k++]=arr[j++];

	for(int m=beg;m<=end;++m)
		arr[m]=space[m];

}


void solve()
{
	int n;
	//ifstream cin("a.txt");
	cin>>n;
	while(n-->0)
	{
		int sz;
		cin>>sz;
		vector<int> arr(sz),space(sz);

		for(int i=0;i<sz;++i)
		{
			cin>>arr[i];
			space[i]=arr[i];
		}

		total = 0;
		merge_sort(arr,space,0,sz-1);
		cout<<total<<endl;
	}
}

#endif