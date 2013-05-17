#ifndef _TEST_
#define _TEST_

// poj1193_memory_allocation
// Copyright (c) 2013/5/17 
// Author: xdutaotao (xdutaotao@gmail.com)
// 


/*
http://poj.org/problem?id=1193
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

struct task{
	int t,m,p;
	task(int nt,int nm,int np):t(nt),m(nm),p(np){};
};

struct run_task{
	int s,e,alive;
	run_task(int ns,int ne,int nalive):s(ns),e(ne),alive(nalive){};
};

struct task_cmp{
	bool operator()(const task& t1, const task& t2)
	{
		return t1.t < t2.t;
	}
};

void solve()
{
	int n,t,m,p;
	cin>>n;

	queue<task> vt; 
	queue<run_task> rt;
	queue<task> wt; //waiting task queue
	map<int,int> mt;

	while(cin>>t>>m>>p)
	{
		if(t == 0 && m == 0 && p == 0)
			break;

		vt.push_back(task(t,m,p));
	}

	//½«task ÅÅÐò
	sort(vt.begin(),vt.end(),task_cmp());

	int tick=0;
	for(;;++tick)
	{
		if(vt.empty() && rt.empty() && wt.empty())
			break;


	}
	
	cout<<tick<<endl;

}

#endif 