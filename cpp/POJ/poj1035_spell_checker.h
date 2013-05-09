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

void solve()
{
	string tmp;
	node* dict[26];
	while(cin>>tmp)
	{
		if(tmp == "#")
			break;

		add_node(dict[tmp[0]]-'0',tmp);		
	}

	//dict is ready.

	while(cin>>tmp)
	{
		if(tmp == "#")
			break;


	}
}

#endif 