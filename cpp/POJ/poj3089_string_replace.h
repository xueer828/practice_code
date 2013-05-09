#ifndef _TEST_
#define _TEST_

// poj3089_string_replace
// Copyright (c) 2013/5/9 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
http://poj.org/problem?id=3981
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
	char s[1001]={0};
	while(cin.getline(s,1000))
	{
		char* wt=s, *start=s;
		while(*start)
		{
			if(*start == 'y' && *(start+1)=='o' && *(start+2)=='u')
			{
				*wt++ = 'w';
				*wt++ = 'e';
				start += 3;
				continue;
			}

			if(*wt != *start) //copy
				*wt = *start;
			++wt,++start;
		}

		*wt = 0;
		cout<<s<<endl;
	}

}

#endif 