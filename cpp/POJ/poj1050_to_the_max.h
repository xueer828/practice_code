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
int sum[110]={0}; //�����ݴ�ѡȡ���еĺ�
/*
����άѹ��Ϊһά,Ȼ������һά������Ӷκ�
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

	//��άѹ��һά
	int max_sum=matrix[0][0]; //���һ��Ԫ��Ϊ���ֵ
	for(int i=0;i<N;++i) //��һ���к�
	{
		memset(sum,0,N*sizeof(int));
		for(int j=i;j<N;++j) //�ڶ��к�,��i��N�ó���
		{
			for(int k=0;k<N;++k)
				sum[k] += matrix[j][k];

			//�����һά��,������Ӷκ�
			int msum=dp(sum,N); 
			if(max_sum < msum)
				max_sum = msum;
		}
	}

	cout<<max_sum<<endl;
}

#endif