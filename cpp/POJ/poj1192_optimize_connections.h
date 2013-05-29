#ifndef _TEST_
#define _TEST_

// poj1192_optimize_connections
// Copyright (c) 2013/05/29 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
http://poj.org/problem?id=1192
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
#include <set>
using namespace std;

struct Node{
	int x,y,v;
	vector<int> c;
	Node(int nx=0,int ny=0,int nv=0):x(nx),y(ny),v(nv){}
};

//树状DP
void DP(vector<Node>& v,vector<int>& n,int root)
{
	if(v[root].c.size() <= 0) //这是个叶子节点
	{
		n[root] = v[root].v; //叶子节点的权值
		return;
	}

	n[root] = 0;
	for(int i=0;i<v[root].c.size();++i)
	{
		DP(v,n,v[root].c[i]);	//递归访问以第i节点为根节点的子树
								//那么对应的子树的节点的值已经存在了n数组中

		if(n[v[root].c[i]] > 0)
			n[root] += n[v[root].c[i]]; //只有当当前子树的值大于0,才加入到整个子树的结果中,如果小于则废弃
	}

	//加上当前的根节点
	n[root] += v[root].v;
}

void solve()
{
	int n;
	cin>>n;
	vector<Node> nodes(n);
	set<int> b; //表明此节点是否已经加入到树上

	for(int i=0;i<n;++i)
		cin>>nodes[i].x>>nodes[i].y>>nodes[i].v;
	
	//构建树的邻接矩阵,令第一个点为根节点
	b.insert(0);//置0为已经处理过

	for(int i=0;i<n;++i)
		for(int j=0;j<n;++j)
		{
			if(i==j || b.count(j) > 0) continue;
			if(abs(nodes[i].x-nodes[j].x) + abs(nodes[i].y-nodes[i].y) == 1)
			{
				nodes[i].c.push_back(j);
				b.insert(j);
			}
		}

	vector<int> dp(n,0);
	DP(nodes,dp,0);

	cout<<dp[0]<<endl;
}

#endif