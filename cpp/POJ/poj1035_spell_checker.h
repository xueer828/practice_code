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
	int seq;
	node():seq(0),t(""){memset(mp,0,sizeof(node*)*26);}
};

//构建trie树
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
		if(dict->t == "" && fixed) //增删改使用完毕,但是未匹配
			return false;
		else if(dict->t != "")//存在匹配,添加匹配
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

	//如果本层存在对应的字符,则匹配下去
	node* p;
	if(p=dict->mp[in[n]-'a'])
	{
		if(correct(p,in,n+1,fixed,vs))
			return true;
	}
	
	if(!fixed){ //如果未经过增删改
		//首先尝试删除,这个不匹配的字符
		correct(dict,in,n+1,true,vs);

		//然后尝试插入新字符和修改为新字符
		for(int i=0;i<26;++i)
		{
			bool flag;
			if(p=dict->mp[i]){
				//增加
				correct(p,in,n,true,vs);
				//改
				correct(p,in,n+1,true,vs);
			}
		}
	}

	return false;
}

void solve1()
{
	string tmp;
	node dict; //字典
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


//方法2,不一样的存储结构

struct word
{
	string str;
	int seq;
	word(string s,int l=0):seq(l),str(s){};
};

bool sort_comp(word* w1, word* w2)
{
	return w1->seq < w2->seq;
}

void solve()
{
	vector<vector<word*> > bucket(21);
	string in;
	int cnt=0;
	while(cin>>in)
	{
		if(in == "#")
			break;

		int n=in.length();
		assert(n>0 && n<=20);

		word* w=new word(in,++cnt);
		bucket[n].push_back(w);
	}

	vector<word*> res;
	while(cin>>in)
	{
		if(in == "#")
			break;

		int len=in.length();
		bool total_equal=false;
		
		//仅仅对长度为len的字典进行全比较和修改比较
		for(int i=0;i<bucket[len].size();++i)
		{
			if(bucket[len][i]->str == in)
			{
				cout<<in<<" is correct"<<endl;
				total_equal = true;
				break;
			}
		}

		if(total_equal) continue;

		res.clear();
		int i,j,k;
		//对同等长度进行换字符比较
		bool is_ok(false),is_changed(false);
		for(i=0;i<bucket[len].size();++i)
		{
			string& tmp=bucket[len][i]->str;
			is_ok=true,is_changed=false;
			
			//k为输入字符串的字符位置
			for(j=0,k=0;j<tmp.length();++j,++k)
			{
				if(tmp[j] != in[k])
					if(is_changed)
					{
						is_ok = false;
						break;
					}else
					{
						is_changed = true;
					}
			}

			if(is_ok)
				res.push_back(bucket[len][i]);
		}

		//对 长度小一进行增加不同字符判断, 字典长度 < 串长度
		for(i=0;i<bucket[len-1].size();++i)
		{
			string& tmp=bucket[len-1][i]->str;
			is_ok=true,is_changed=false;

			for(j=0,k=0;k<in.length();++j,++k)
			{
				if(j >= tmp.length() && !is_changed) //ok can be added
					break;

				if(tmp[j] != in[k])
					if(is_changed)
					{
						is_ok = false;
						break;
					}else{
						is_changed=true;
						--j; //自减一次
					}
			}

			if(is_ok)
				res.push_back(bucket[len-1][i]);
		}

		//对 长度大一的字符进行判断,字典长度 > 串长度
		for(i=0;i<bucket[len+1].size();++i)
		{
			string& tmp=bucket[len+1][i]->str;
			is_ok=true,is_changed=false;
			for(j=0,k=0;j<tmp.length();++j,++k)
			{
				if(k >= in.length() && !is_changed) //ok
					break;

				if(tmp[j] != in[k]){
					if(is_changed)
					{
						is_ok = false;
						break;
					}else
					{
						is_changed = true;
						--k;
					}
				}
			}

			if(is_ok)
				res.push_back(bucket[len+1][i]);
		}

		//对res进行排序
		sort(res.begin(),res.end(),sort_comp);
		
		cout<<in<<":";
		for(i=0;i<res.size();++i)
		{
			cout<<" "<<res[i]->str;
		}
		cout<<endl;
	}
}

#endif 