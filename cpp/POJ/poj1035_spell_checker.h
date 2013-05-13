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

void solve1()
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


//����2,��һ���Ĵ洢�ṹ

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
		
		//�����Գ���Ϊlen���ֵ����ȫ�ȽϺ��޸ıȽ�
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
		//��ͬ�ȳ��Ƚ��л��ַ��Ƚ�
		bool is_ok(false),is_changed(false);
		for(i=0;i<bucket[len].size();++i)
		{
			string& tmp=bucket[len][i]->str;
			is_ok=true,is_changed=false;
			
			//kΪ�����ַ������ַ�λ��
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

		//�� ����Сһ�������Ӳ�ͬ�ַ��ж�, �ֵ䳤�� < ������
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
						--j; //�Լ�һ��
					}
			}

			if(is_ok)
				res.push_back(bucket[len-1][i]);
		}

		//�� ���ȴ�һ���ַ������ж�,�ֵ䳤�� > ������
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

		//��res��������
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