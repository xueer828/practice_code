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

void solve()
{
	map<int,int> mp;

	int m,n;
	int count=0;
	bool isTree=false;
	for(;;)
	{
		while(cin>>m>>n)
		{
			if(m==-1 && n==-1)
				return;

			if(m==0 && n==0)
			{
				//start new
				++count;

				map<int,int>::iterator it=mp.begin();
				int root=-1;
				isTree = true;
				for(;it!=mp.end();++it)
				{
					if(it->second == 0)
					{
						if(root > 0)
						{
							isTree = false;
							break;
						}else{
							root = it->first; //确定根节点
						}
					}

					if(it->second >= 2)
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


				cout<<"Case "<<count<<" is "<<(isTree?"a tree.":"not a tree.")<<endl;
				isTree = false;
				mp.clear();
				continue;
			}

			if(mp.count(m)<=0)
				mp[m]=0;
			
			if(mp.count(n)<=0)
				mp[n]=1;
			else
				++mp[n];
		}
	}
}

#endif