#ifndef _TEST_
#define _TEST_

// poj1068_parencodings
// Copyright (c) 2013/5/13 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
http://poj.org/problem?id=1068
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
	int m,n,tmp;
	cin>>m;
	vector<int> s;
	while(m--)
	{
		cin>>n;
		s.clear();
		int last(0),cur(0),cnt(0),sz(0);
		for(int i=0;i<n;++i)
		{
			cin>>tmp;
			cur = tmp - last;
			last = tmp;
			while(cur --){
				s.push_back(0);
			}
			//then for ')'

			int sz = s.size();

			//更新前面所有的左括号 +1
			for(int j=0;j<sz;++j)
			{
				++s[j];
			}

			if(sz > 0)
			{
				if(i==0)
					cout<<s[sz-1];
				else
					cout<<" "<<s[sz-1];
				s.pop_back(); //弹出最后一个
			}else{
				cout<<"not support!\n";
			}
		}

		cout<<endl;
	}
}

#endif 