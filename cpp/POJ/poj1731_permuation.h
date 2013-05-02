#ifndef _TEST_
#define _TEST_

// poj1731_permuation
// Copyright (c) 2013/05/03 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

//输入一字符串,求其所有的排列数

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
#include <set>
using namespace std;

int sz=0;


void permuation(string& v,int n)
{
	if(n >= sz)
	{
		cout<<v<<endl;
		return;
	}

	//set<char> s;
	char tmp=v[n];
	for(int i=n;i<sz;++i)
	{
		//去除重复
		if(i!=n && v[i]==tmp)
			continue;

		//s.insert(v[i]);

		v[n]=v[i];
		v[i]=tmp;

		permuation(v,n+1);

		//恢复
		v[i]=v[n];
		v[n]=tmp;
	}
}

void solve()
{
	string s;
	while(cin>>s){

		sort(s.begin(),s.end());
		sz=s.length();

		permuation(s,0);
	}
}


/*
int main()
{
solve();
return 0;
}
*/
#endif