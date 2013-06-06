#ifndef _TEST_
#define _TEST_

// poj1163_the_triangle
// Copyright (c) 2013/06/07 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
http://poj.org/problem?id=1163
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
	int n,mx;
	cin>>n;
	vector<int> v(n,0);
	vector<int> d(n,0);
	
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<=i;++j)
		{
			cin>>d[j];
		}

		for(int j=i;j>=0;--j){
			if(j > 0 && v[j-1] > v[j])
				v[j]=v[j-1]+d[j];
			else
				v[j]=v[j] + d[j];
		}
	}

	mx = v[0];
	for(int i=1;i<n;++i)
	{
		if(mx < v[i])
			mx = v[i];
	}

	cout<<mx<<endl;
}

#endif