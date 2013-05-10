#ifndef _TEST_
#define _TEST_

// poj1035_spell_checker
// Copyright (c) 2013/5/9 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
http://poj.org/problem?id=1035
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

//˼·,����trie��,��Ϊ����ֻ��Сд��ĸ

struct node{
	node* mp[26];
	string t;
	int seq;
	node():seq(0),t(""){memset(mp,0,sizeof(node*)*26);}
};

//����trie��
void add_node(node* dict,string s, int seq)
{
	if(s.length()<=0)
		return;
	node* t=dict;
	for(int i=0;i<s.length();++i)
	{
		if(t->mp[s[i]-'a']==NULL)
			t->mp[s[i]-'a']=new node;
		t = t->mp[s[i]-'a'];
	}
	t->t = s;
	t->seq = seq;
}

bool correct(node* dict, string& in, int n, bool fixed, map<int,string>& vs)
{
	assert(dict);
	if(n >= in.size())
	{
		if(dict->t == "" && fixed) //��ɾ��ʹ�����,����δƥ��
			return false;
		else if(dict->t != "")//����ƥ��,���ƥ��
		{
			if(vs.count(dict->seq) <= 0)
				vs[dict->seq]=dict->t;
			return (!fixed);
		}else{ //not node, and fixed == false
			for(int i=0;i<26;++i)
			{
				node* p=dict->mp[i];
				if(p && p->t != "")
				{
					if(vs.count(p->seq)<=0)
						vs[p->seq]=p->t;
				}
			}
			return false;
		}		
	}

	//���������ڶ�Ӧ���ַ�,��ƥ����ȥ
	node* p;
	if(p=dict->mp[in[n]-'a'])
	{
		if(correct(p,in,n+1,fixed,vs))
			return true;
	}
	
	if(!fixed){ //���δ������ɾ��
		//���ȳ���ɾ��,�����ƥ����ַ�
		correct(dict,in,n+1,true,vs);

		//Ȼ���Բ������ַ����޸�Ϊ���ַ�
		for(int i=0;i<26;++i)
		{
			bool flag;
			if(p=dict->mp[i]){
				//����
				correct(p,in,n,true,vs);
				//��
				correct(p,in,n+1,true,vs);
			}
		}
	}

	return false;
}

void solve()
{
	string tmp;
	node dict; //�ֵ�
	int ct=0;
	while(cin>>tmp)
	{
		if(tmp == "#")
			break;

		add_node(&dict,tmp,++ct);		
	}

	//dict is ready.

	while(cin>>tmp)
	{
		if(tmp == "#")
			break;

		map<int,string> ts;
		if(correct(&dict,tmp,0,false,ts))
		{
			cout<<tmp<<" is correct"<<endl;
		}else{
			cout<<tmp<<":";
			map<int,string>::iterator i=ts.begin();
			for(;i!=ts.end();++i)
				cout<<" "<<i->second;
			cout<<endl;
		}
	}
}

#endif 