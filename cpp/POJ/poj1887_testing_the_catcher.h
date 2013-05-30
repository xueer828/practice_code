#ifndef _TEST_
#define _TEST_

// poj1887_testing_the_catcher
// Copyright (c) 2013/05/30 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
http://poj.org/problem?id=1887
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

//最长的单调递减序列长度
int len_dec(vector<short>& v)
{
	int sz=v.size();
	
	vector<unsigned int> n(sz,0);

	short t_mx(1),mx(0);
	n[0]=1;
	for(int i=1;i<sz;++i)
	{
		mx=0;
		for(int j=0;j<i;++j)
		{
			if(v[j] >= v[i] && mx < n[j])
			{
				mx = n[j];
			}
		}
		n[i]=mx + 1;
		if(t_mx < n[i])
			t_mx = n[i];
	}
	return t_mx;
}

void solve()
{
	int n,count(0);
	vector<short> v;
	while(cin>>n)
	{
		if(n==-1)
			break;
		v.clear();
		v.push_back(n);
		while(cin>>n)
		{
			if(n == -1)
				break;

			v.push_back(n);
		}

		//处理
		cout<<"Test #"<<++count<<":"<<endl<<"  maximum possible interceptions: "<<len_dec(v)<<endl<<endl;
	}
}

#endif