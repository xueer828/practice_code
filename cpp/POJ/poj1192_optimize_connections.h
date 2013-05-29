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

//��״DP
void DP(vector<Node>& v,vector<int>& n,int root)
{
	if(v[root].c.size() <= 0) //���Ǹ�Ҷ�ӽڵ�
	{
		n[root] = v[root].v; //Ҷ�ӽڵ��Ȩֵ
		return;
	}

	n[root] = 0;
	for(int i=0;i<v[root].c.size();++i)
	{
		DP(v,n,v[root].c[i]);	//�ݹ�����Ե�i�ڵ�Ϊ���ڵ������
								//��ô��Ӧ�������Ľڵ��ֵ�Ѿ�������n������

		if(n[v[root].c[i]] > 0)
			n[root] += n[v[root].c[i]]; //ֻ�е���ǰ������ֵ����0,�ż��뵽���������Ľ����,���С�������
	}

	//���ϵ�ǰ�ĸ��ڵ�
	n[root] += v[root].v;
}

void solve()
{
	int n;
	cin>>n;
	vector<Node> nodes(n);
	set<int> b; //�����˽ڵ��Ƿ��Ѿ����뵽����

	for(int i=0;i<n;++i)
		cin>>nodes[i].x>>nodes[i].y>>nodes[i].v;
	
	//���������ڽӾ���,���һ����Ϊ���ڵ�
	b.insert(0);//��0Ϊ�Ѿ������

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