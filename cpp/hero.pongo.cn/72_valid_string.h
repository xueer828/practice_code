#ifndef _TEST_
#define _TEST_

// 72_valid_string
// Copyright (c) 2013/7/28 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
http://hero.pongo.cn/OnlineCompiler/Index?ID=74&ExamID=72
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

#ifdef WIN32
typedef __int64 ll;
#else
typedef long long ll;
#endif

int validstring(int n, int m) {
	ll p_1(n-n/2),p_2(n*(n-n/2)),p_cur(0);
	if(m == 1) return p_1;
	if(m == 2) return p_2;

	ll d1(n/2),d2(n/2*(n-n/2));
 	for(int i=3;i<=m;++i)
	{
		p_cur = p_2 * d1 + p_1 * d2;
		p_1 = p_2;
		p_2 = p_cur;
	}

	return p_cur%100000007;
}

void solve()
{
	cout<<validstring(2,2)<<endl;
}

#endif 