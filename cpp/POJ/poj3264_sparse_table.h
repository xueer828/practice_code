#ifndef _TEST_
#define _TEST_

// poj3264_sparse_table
// Copyright (c) 2013/4/20 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

//http://poj.org/problem?id=3264

//实际就是RMQ区间最值的问题

//Accepted

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
#include <cmath>
using namespace std;

const int maxN=50000;
//const int maxQ=200000;

//const int logN=(log(maxN+0.0)/log(2.0)+1); 约为16
const int logN=16;

int cows[maxN]={0};

int maxDP[logN][maxN];
int minDP[logN][maxN];

void solve()
{


	int N,Q;
	scanf("%d %d",&N,&Q);
	int idx=0;
	while(idx < N)
	{
		scanf("%d",&cows[idx++]);
	}
	
	//初始化DP数组,获取
	//DP[j,i] 以A[i]为起始,到2^j区段的最大值或者最小值
	for(int i=0;i<maxN;++i)
	{
		maxDP[0][i]=minDP[0][i]=cows[i];
	}

	int tmp_lg=(int)(log(N*1.0)/log(2.0));
	for(int i=1;i<=tmp_lg;++i)
		for(int j=0;j+(1<<i)-1 < N;++j)
		{
			maxDP[i][j]=max(maxDP[i-1][j],maxDP[i-1][j+(1<<(i-1))]);
			minDP[i][j]=min(minDP[i-1][j],minDP[i-1][j+(1<<(i-1))]);
		}

	int a, b;
	while(Q-- > 0)
	{
		scanf("%d %d",&a,&b);
		--a,--b;

		// (1<<x) <= (b-a+1) , x为所求的值 x <= log(2,(b-a+1))
		int x = (int)(log(b-a+1.0)/log(2.0));

		int max_v=max(maxDP[x][a],maxDP[x][b-(1<<x)+1]);
		int min_v=min(minDP[x][a],minDP[x][b-(1<<x)+1]);

		printf("%d\n",max_v-min_v);
 	}
}

#endif 