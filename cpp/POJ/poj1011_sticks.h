#ifndef _TEST_
#define _TEST_

// poj1011_sticks
// Copyright (c) 2013/05/06 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

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

bool dfs(vector<int>& v, vector<int>& b,int clen,int len, int cn)
{
	if(cn<=0 && clen<=0)
		return true;

	int sz = b.size();
	for(int i=0;i<sz;++i)
	{
		if(b[i]) //可以考虑是否被访问过
			continue;

		if(v[i]<clen) //满足当前
		{
			b[i]=1; //选中
			if(dfs(v,b,clen-v[i],len,cn))
			{
				//b[i]=0; //虽然没意义,仍然恢复
				return true;
			}else{
				b[i]=0; //恢复,尝试下一条
				//return false;
			}
		}else if(v[i]==clen)
		{
			b[i]=1;
			if(dfs(v,b,0,len,cn-1))
				return true;
			
			b[i]=0;
		}
		
	}

	return false;
}

void mem_clear(int it)
{
	it = 0;
}

bool sort_cmp(int a,int b)
{
	return a>b;
}

void solve()
{
	vector<int> v;
	vector<int> b;
	v.reserve(100);
	b.reserve(100);
	
	int num,dig,sum;
	for(;;)
	{
		v.clear();
		b.clear();
		sum=0;
		cin>>num;
		if(num==0)
			return;

		for (int i=0;i<num;++i)
		{
			cin>>dig;
			v.push_back(dig);
			b.push_back(0);
			sum += dig;
		}

		//sort
		sort(v.begin(),v.end(),sort_cmp);

		//int dv = sum/v[num-1]; //最大的可能分段数

		int dv;

		for (dv = sum/v[num-1];dv > 1; --dv) //dv最不济就是整个1根
		{
			if(sum % dv == 0) //如果能够整除,表示可以构成最后结果
			{
				int len_each=sum/dv;
				for_each(b.begin(),b.end(),mem_clear);

				if (dfs(v,b,len_each,len_each,dv-1))
				{
					cout<<len_each<<endl;
					break;
				}
				
			}
		}

		if(dv ==1 )
			cout<<sum<<endl;

	}
}

#endif