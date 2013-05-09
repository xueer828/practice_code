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

//思路,利用trie树,因为限制只有小写字母

struct node{
	node* mp[26];
	string t;
	node():t(""){memset(mp,0,sizeof(node*)*26);}
};

void add_node(node* dict,string s)
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
}

int correct(node* dict, string& in, int n, bool fixed, vector<string>& vs)
{
	assert(dict);
	if(n >= in.size())
	{
		if(dict->t == "" && fixed) //如果字符已经完毕,但是还剩余一个字符可以改,则继续下去
			return 0;
		else if(dict->t != "") 
		{
			vs.push_back(dict->t);
			if(fixed)
				return 1;
			else
				return 2;
		}else{ //not node, and fixed == false
			for(int i=0;i<26;++i)
			{
				node* p=dict->mp[i];
				if(p && p->t != "")
				{
					vs.push_back(p->t);
				}
			}
			return 1;
		}		
	}

	//如果本层存在对应的字符,则匹配
	node* p;
	if(p=dict->mp[in[n]-'a'])
	{
		if(correct(p,in,n+1,fixed,vs))
			return true;
	}else{
		for(int i=0;i<26;++i)
		{
			p=dict->mp[i];
			bool flag;
			if(!fixed) //存在字符,且未做过任何修改,则进行修改
			{
				//删除
				if(correct(dict,in,n+1,true,vs))
					break;

				if(p){
					//增加
					if(correct(p,in,n,true,vs))
						break;
					//改
					if(correct(p,in,n+1,true,vs))
						break;
				}
			}
		}
	}

	return false;
}

void solve()
{
	string tmp;
	node dict; //字典
	while(cin>>tmp)
	{
		if(tmp == "#")
			break;

		add_node(&dict,tmp);		
	}

	//dict is ready.

	while(cin>>tmp)
	{
		if(tmp == "#")
			break;

		vector<string> ts;
		if(correct(&dict,tmp,0,false,ts))
		{
			cout<<tmp<<" is correct"<<endl;
		}else{
			cout<<tmp<<":";
			for(int i=0;i<ts.size();++i)
				cout<<" "<<ts[i];
			cout<<endl;
		}
	}
}

#endif 