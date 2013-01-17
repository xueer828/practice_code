#ifndef _TEST_
#define _TEST_

// Insertion_Sort
// Copyright (c) 2013/01/14 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
https://www.interviewstreet.com/challenges/dashboard/#problem/4e90477dbd22b
*/

//思路:逆序对,可以用归并的思路,求解

//passed, 貌似OJ不接受c的字符串输出和输入

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

//很重要的一点,归并排序,不能就地排序,需要另外开辟一片空间

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
			space[k++]=arr[j]; //arr[i..mid]都比arr[j]大,所以计算数目为(mid-i+1)
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