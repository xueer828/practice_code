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
			if(m==-1 && n==-1) //�����������
				return;

			if(m==0 && n==0) //���һ������
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
							root = it->first; //ȷ�����ڵ�
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

				//������һ����������
				if(mp.size()==0)
					isTree=true;

				//�ж��Ƿ���� �� + �� ��ɭ�ִ���
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
				mp[n].parent=m; //�����Ƿ�����������ڵ�,�����и���,�������ڵ����ͨ�������ȷ��
				++mp[n].degree;
			}
		}
	}
}


#endif