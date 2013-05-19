#ifndef _TEST_
#define _TEST_

// poj1050_to_the_max
// Copyright (c) 2013/05/19 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
http://poj.org/problem?id=1050
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

int matrix[110][110]={0};
int sum[110]={0}; //用来暂存选取的列的和
/*
将二维压缩为一维,然后再求一维的最大子段和
*/

int dp(int A[], int n)
{
	int res=A[0],last=A[0],cur;
	for(int i=1;i<n;++i)
	{
		if(last > 0)
			cur = last + A[i];
		else
			cur = A[i];

		last = cur;

		if(res < cur)
			res = cur;
	}

	return res;
}

void solve()
{
	int N,num;
	cin>>N;
	num = N*N;

	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			cin>>matrix[i][j];

	//二维压成一维
	int max_sum=matrix[0][0]; //令第一个元素为最大值
	for(int i=0;i<N;++i) //第一个行号
	{
		memset(sum,0,N*sizeof(int));
		for(int j=i;j<N;++j) //第二行号,从i到N得出和
		{
			for(int k=0;k<N;++k)
				sum[k] += matrix[j][k];

			//在求出一维后,求最大子段和
			int msum=dp(sum,N); 
			if(max_sum < msum)
				max_sum = msum;
		}
	}

	cout<<max_sum<<endl;
}

#endif