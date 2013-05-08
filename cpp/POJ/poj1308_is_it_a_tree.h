#ifndef _TEST_
#define _TEST_

// poj1308_is_it_a_tree
// Copyright (c) 2013/05/07 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
http://poj.org/problem?id=1308
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

struct node 
{
	int degree,parent;
	node(int d=0,int p=-1):degree(d),parent(p){};
};

int findp(map<int,node>& mp,int c, int next)
{
	if(mp[next].parent < 0)
		return next;
	else if(mp[next].parent != c)
		return (mp[next].parent = findp(mp,c,mp[next].parent));
	return c;
}

void solve()
{
	map<int,node> mp;

	int m,n;
	int count=0;
	bool isTree=false;
	for(;;)
	{
		while(cin>>m>>n)
		{
			if(m==-1 && n==-1) //完成所有批次
				return;

			if(m==0 && n==0) //完成一个批次
			{
				//start new
				++count;

				map<int,node>::iterator it=mp.begin();
				int root=-1;
				isTree = true;
				for(;it!=mp.end();++it)
				{
					if(it->second.degree == 0)
					{
						if(root > 0)
						{
							isTree = false;
							break;
						}else{
							root = it->first; //确定根节点
						}
					}

					if(it->second.degree >= 2)
					{
						isTree = false;
						break;
					}						
				}

				if(root < 0)
					isTree =false;

				//空树是一颗完整的树
				if(mp.size()==0)
					isTree=true;

				//判断是否存在 环 + 树 的森林存在
				if(isTree && root > 0)
				{
					it=mp.begin();
					for(;it!=mp.end();++it)
					{
						if(findp(mp,it->first,it->first) != root)
						{
							isTree = false;
							break;
						}
					}
				}


				cout<<"Case "<<count<<" is "<<(isTree?"a tree.":"not a tree.")<<endl;
				isTree = false;
				mp.clear();
				continue;
			}

			if(mp.count(m)<=0)
				mp[m]=node(0);

			if(mp.count(n)<=0)
				mp[n]=node(1,m);
			else{
				mp[n].parent=m; //不论是否存在两个父节点,均进行覆盖,两个父节点情况通过入度来确定
				++mp[n].degree;
			}
		}
	}
}


#endif