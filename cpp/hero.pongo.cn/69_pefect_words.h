#ifndef _TEST_
#define _TEST_

// 69_pefect_words
// Copyright (c) 2013/7/26 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
http://hero.pongo.cn/OnlineCompiler/Index?ID=71&ExamID=69
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

int perfect(const string &s) {
	if(s.size()<=0)
		return 0;

	int mp[26]={0};
	for(int i=0;i<s.size();++i)
	{
		if(s[i] >'Z')
			++mp[s[i]-'a'];
		else
			++mp[s[i]-'A'];
	}

	//sort
	sort(mp,mp+26);

	unsigned long result = 0;
	for(int i=0;i<26;++i)
	{
		result += mp[i]*(i+1);
	}

	return result;
}

void solve()
{
	cout<<perfect("dad")<<endl;
}

#endif 