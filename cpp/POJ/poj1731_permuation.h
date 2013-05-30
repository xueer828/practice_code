#ifndef _TEST_
#define _TEST_

// poj1731_permuation
// Copyright (c) 2013/05/03 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

//����һ�ַ���,�������е�������,����ȥ���ظ�

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

int sz=0;

//����1
void permuation1(string& v,int n)
{
	if(n >= sz)
	{
		cout<<v<<endl;
		return;
	}

	for(int i=n;i<sz;++i)
	{
		//ȥ���ظ�
		if(n!=i && v[i]==v[n])
			continue;

		char tmp=v[n];
		v[n]=v[i];
		v[i]=tmp;
			permuation1(v,n+1);
		tmp = v[n];
		v[n]=v[i];
		v[i]=tmp;
		
	}
}

//����2
void permuation2(string&o, string&v, vector<int>& b, int n)
{
	if(n >= sz)
	{
		cout<<v<<endl;
		return;
	}

	//���ڵ�n��λ��,��δѡ����ַ���ѡ���ַ������
	for(int i=0;i<o.size();++i)
	{
		if(b[i])
		{

			--b[i];
			v[n]=o[i];
			permuation2(o,v,b,n+1);
			++b[i];
		}
	}
}

void solve()
{
	string s;
	cin>>s;
	
	{

		sort(s.begin(),s.end());
		sz=s.length();

		vector<int> b(sz,1); //��ʾ�������ж��ٸ�

		string t;
		int len=0;
		for(int i=0;i<sz;++i)
		{
			if(i==0 || s[i]!=s[i-1])
			{
				t += s[i];
				++len;
			}
			else
				++b[len-1];
		}
		
		//permuation1(s,0);
		permuation2(t,s,b,0);
	}
}


/*
int main()
{
solve();
return 0;
}
*/
#endif