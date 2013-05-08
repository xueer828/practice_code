#ifndef _TEST_
#define _TEST_

// poj2499_binary_tree
// Copyright (c) 2013/5/8 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
http://poj.org/problem?id=2499
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
	int n,x,y;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		cin>>x>>y;

		int l(0),r(0);

		while(x!=0 && y!=0)
		{
			if(x < y)
			{
				r += y/x;
				y %= x;
				if(y == 0)
					--r;
			}else{
				l += x/y;
				x %= y;
				if(x == 0)
					--l;
			}
		}
	
		cout<<"Scenario #"<<i+1<<":\n"<<l<<" "<<r<<endl<<endl;
	}
}

#endif 