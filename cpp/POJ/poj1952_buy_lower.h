#ifndef _TEST_
#define _TEST_

// poj1952_buy_lower
// Copyright (c) 2013/05/31 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
http://poj.org/problem?id=1952
*/

/*
这是一个标准的求最长单调子序列的问题
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

void solve()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int i=0;i<n;++i)
		cin>>v[i];

	int tmx(1),mx(0);
	vector<int> dp(n,0);
	vector<int> num(n,0);
	dp[0]=1;
	num[0]=1;
	for(int i=1;i<n;++i)
	{
		mx=0;
		for(int j=0;j<i;++j)
		{
			if(v[j] > v[i] && mx < dp[j])
				mx = dp[j];
		}

		for(int j=0;j<i;++j)
		{
			if(v[j] > v[i] && mx == dp[j])
				num[i] += num[j];
		}

		dp[i] = mx + 1;
		if(dp[i] > tmx)
			tmx = dp[i];
	}

	int count=0;
	for(int i=0;i<n;++i)
	{
		if(tmx == dp[i])
			count += num[i];
	}

	cout<<tmx<<" "<<count<<endl;
}

#endif