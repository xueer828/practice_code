#ifndef _TEST_
#define _TEST_

// word_ladder
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

/*����1:
����ͼ��˼��,һ�����ʿ��Կ�����һ���ڵ�,��ĳһ���ڵ�(���)������һ���ڵ�(�յ�)�����·��

С���ݹ���,�������ڴ泬��,��������~~ ˵������������,�����ع���һ��Dijkstra�㷨,Ҳ�㲻��
Run Status: Memory Limit Exceeded
*/

/*
����2: dfs��ռ�������
С�������ɹ�,�����ݳ�ʱ,���Լ�֦����

Run Status: Time Limit Exceeded
*/

/*
����3: ��Ϊ�����ռ�������С�߶�,����Ӧ����BFS��������,���Ҳ��õݹ�,ֱ���ö���

��Ӧ��ֱ���滻string,�����ǽ��бȽ�,��������ʡ�ܶ��ʱ��

Run Status: Accepted!
Program Runtime: 1996 milli secs
Progress: 37/37 test cases passed.
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
#include <unordered_set>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution1 {
	const static int MAX_INT=0x7fffffff;
	int get_edge(const string& s1, const string& s2)
	{
		if(s1 == s2)
			return MAX_INT;

		int i=s1.length();
		int cnt=0;
		while(i>=0)
		{
			if(s1[i]!=s2[i])
				++cnt;
			--i;
		}

		if(cnt <= 1)
			return 1;
		else
			return MAX_INT;
	}

	int dijkstra(vector<vector<int> >& v,vector<int>& pre, int nstart, int nend)
	{
		int sz = v.size();
		vector<bool> b(sz,false); //����ڵ��Ƿ��Ѿ��������
		vector<int> dis(sz,MAX_INT); //�����start�ڵ㵽i�ڵ�ľ���

		//�����һ��start�ڵ�
		b[nstart] = true;

		for(int i=0;i<sz;++i)
		{
			if(v[nstart][i]!=MAX_INT) //��ʼ������
			{
				dis[i]=v[nstart][i];
				pre[i]=nstart;
			}
		}

		for(int i=0;i<sz;++i)
		{
			if(i==nstart) //������ʼ�ڵ�
				continue;

			int min_dis=0x7fffffff,min_node=-1;

			//�õ���ǰ��С�ľ���Ľڵ�
			for(int j=0;j<sz;++j)
			{
				if(!b[j] && min_dis > dis[j])
				{
					min_dis = dis[j];
					min_node = j;
				}
			}

			//����Ѿ��ó�start �� end�Ľ��,�򷵻�
			if(b[nend])
				return dis[nend]+1;
			else if(min_node == -1)
				return 0; //���߱�

			//��min_node�����Ѵ������С������
			b[min_node] = true;

			for(int k=0;k<sz;++k)
			{
				if(!b[k] && v[min_node][k]!=MAX_INT) //��С�ڵ㵽δ�������еĽڵ�k������ͨ��
				{
					if(dis[k] > v[min_node][k] + dis[min_node]) //���ͨ��min_node�ܹ��õ���С�ľ���,�����dis����
					{
						dis[k] = v[min_node][k] + dis[min_node];
						pre[k] = min_node;
					}
				}
			}
		}

		if(b[nend])
			return dis[nend]+1;
		else
			return 0;
	}
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(start == end)
			return 2;

		int sz = dict.size();
		if(sz <= 0)
			return false;

		unordered_set<string> mdict(dict);
		mdict.insert(start);
		mdict.insert(end);

		//szΪstart��end���뼯��֮��
		sz = mdict.size();

		vector<vector<int> > matrix(sz,vector<int>(sz,-1)); //��ʼ����ά����

		int nCount=0;

		//���start ��end ����
		int nstart,nend;
		//Ԥ����
		unordered_set<string>::iterator i(mdict.begin()),j(i);
		int ii,jj;
		for(ii=0,i=mdict.begin();i!=mdict.end();++i,++ii)
		{
			if(*i==start)
				nstart = ii;
			if(*i==end)
				nend = ii;

			for(jj=0,j=mdict.begin();j!=mdict.end();++j,++jj)
			{
				matrix[ii][jj]=get_edge(*i,*j);
			}
		}

		
		//dijkstra�㷨
		vector<int> pre(sz,-1);
		return dijkstra(matrix,pre,nstart,nend);
	}
};

//dfs
class Solution2 {
	bool one_char_diff(const string& s1,const string& s2)
	{
		int l=s1.length(),cnt(0);
		while(l--)
		{
			if(s1[l]!=s2[l])
				++cnt;
		}

		if(cnt > 1)
			return false;
		else
			return true;
	}

	bool dfs(const string& s,const string& e,unordered_map<string,bool>& b, 
		unordered_set<string>& dict, int curLen, int& minLen)
	{
		if(curLen +1 >= minLen) //�Ѿ���Խ��,�Ͳ��ټ�����
			return false;

		if(one_char_diff(s,e))
		{
			if(minLen > curLen+2)
				minLen = curLen + 2;
			return true;
		}

		unordered_set<string>::iterator i=dict.begin();
		bool ret=false;
		for(;i!=dict.end();++i)
		{
			if((b.count(*i) == 0 || !b[*i]) && one_char_diff(s,*i)) //������ǰ�ݹ�
			{
				b[*i]=true;
				ret |= dfs(*i,e,b,dict,curLen+1,minLen);
				b[*i]=false; //restore
			}
		}

		return ret;
	}
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int sz=dict.size();
		if(sz <=0) return 0;

		int mn=0x7fffffff;
		unordered_map<string,bool> b;
		if(dfs(start,end,b,dict,0,mn))
			return mn;
		else
			return 0;

	}
};


//BFS, ���ַ����е�ÿ���ַ������滻,O(26*N), ��Ҫȥ�Ƚ������ַ����ĳ���,�����ͱ����O(M*N),�ͻᳬʱ��

class Solution {
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int sz=dict.size();
		if(sz <=0) return 0;

		queue<string> sq;
		unordered_set<string> processed;

		sq.push(start);
		processed.insert(start);
		

		int lv1(1),lv2(0),lv_cnt(0);

		while(!sq.empty())
		{
			string s=sq.front();
			sq.pop();
			--lv1; //��ǰ��ε���Ŀ

			for(int i=0;i<s.length();++i)
			{
				for(int j=0;j<26;++j)
				{
					string t(s);
					t[i]='a'+j;
					
					if(t == s) continue; //������ȵĴ���

					if(t==end)
					{
						return lv_cnt + 2;
					}else if(processed.count(t) <= 0 && dict.count(t)) //����
					{
						processed.insert(t); //��֤�������û�б������
						sq.push(t);
						++lv2; //��һ���(�Ӳ�)�Ľڵ���Ŀ
					}
				}
			}
			

			if(lv1==0) //����ǰ�����
			{
				++lv_cnt; //��μ�1��
				lv1=lv2; //���в���л�
				lv2=0;
			}
		}

		return 0;
	}
};

void solve()
{
	unordered_set<string> us;
	us.insert("ted");
	us.insert("tex");
	us.insert("red");
	us.insert("tax");
	us.insert("tad");
	us.insert("den");
	us.insert("rex");
	us.insert("pee");

	Solution s;
	cout<<s.ladderLength("red","tax",us)<<endl;
}

#endif