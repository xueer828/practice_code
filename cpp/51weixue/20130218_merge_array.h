#ifndef _TEST_
#define _TEST_

// 20130218_merge_array
// Copyright (c) 2013/03/12 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
http://51weixue.com/thread-502-1-1.html


两个数组int a[m],b[n]。他们分别是有序的，a足够长（共m + n元素，末尾有n空位),请把它们归并到数组a中
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

void solve(int a[],int m,int b[], int n)
{
	int cur=m+n-1;
	int pa(m-1),pb(n-1);
	while(pa>=0 && pb>=0)
	{
		if(a[pa]>b[pb])
		{
			a[cur--]=a[pa--];
		}else{
			a[cur--]=b[pb--];
		}
	}

	while(pa>=0)
		a[cur--]=a[pa--];

	while(pb>=0)
		a[cur--]=b[pb--];
}

#endif