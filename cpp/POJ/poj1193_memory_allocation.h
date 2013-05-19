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

	vector<task> vt; 
	vector<run_task> rt;
	queue<task> wt; //waiting task queue
	map<int,int> mt;

	mt[0]=n;

	while(cin>>t>>m>>p)
	{
		if(t == 0 && m == 0 && p == 0)
			break;

		vt.push_back(task(t,m,p));
	}

	//将task 排序
	sort(vt.begin(),vt.end(),task_cmp());

	int tick(0),cnt(0);
	for(;;++tick)
	{
		if(vt.empty() && rt.empty() && wt.empty())
			break;
		
		//先处理运行队列
		vector<run_task>::iterator t=rt.begin();
		for(;t!=rt.end();)
		{
			-- t->alive;
			if(t->alive == 0) //应该释放
			{
				mt[t->s]=t->e;
				t = rt.erase(t);
			}else{
				++t;
			}
		}

		//再合并map
		map<int,int>::iterator mi=mt.begin(), last;
		for(;mi!=mt.end();)
		{
			if(mi != mt.begin())
			{
				if(last->second == mi->first)
				{
					last->second = mi->second;
					mi = mt.erase(mi);
					continue;
				}
			}

			last = mi;
			++mi;
		}

		//分配内存
		//1.首先分配等待队列中的
		while(!wt.empty())
		{
			task& t=wt.front();
			map<int,int>::iterator mi=mt.begin();
			bool available=false;
			for(;mi!=mt.end();)
			{
				if(mi->second - mi->first >= t.m) //可以分配
				{
					int new_s=mi->first;
					int new_e=mi->first + t.m;
					if(new_e < mi->second) //分不完
						mt[new_e] = mi->second; //内存 前开后闭
					
					rt.push_back(run_task(new_s,new_e,t.p));
					mi = mt.erase(mi); //删除旧节点					
					wt.pop(); //删除头,表示已经处理完毕
					available = true;
					break;
				}else{
					++mi;
				}
			}

			if(!available) //队列里面有不能分出的部分
			{
				break;
			}
		}

		//可以处理task队列了
		for(vector<task>::iterator i=vt.begin();i!=vt.end();)
		{
			if(i->t != tick)
				break;

			bool available=false;
			for(map<int,int>::iterator j=mt.begin();j!=mt.end();)
			{
				if(i->p == 0)
				{
					available = true;
					break;
				}else if(j->second - j->first >= i->m)
				{
					if(j->second - j->first > i->m) //把剩余的加入map
						mt[j->first+i->m]=j->second;

					available = true;
					rt.push_back(run_task(j->first,j->first+i->m,i->p));
					j = mt.erase(j); //删除已经用过的节点

					break;
				}else{
					++j;
				}
			}

			if(!available) //不满足,则压入等待队列
			{
				++cnt;
				wt.push(*i); //压入
			}

			//删除任务序列
			i=vt.erase(i);
		}

	}
	
	cout<<(tick>0?(tick-1):0)<<endl<<cnt<<endl;

}

#endif 