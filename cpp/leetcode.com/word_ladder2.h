#ifndef _TEST_
#define _TEST_

// word_ladder2
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]

Return

[
["hit","hot","dot","dog","cog"],
["hit","hot","lot","log","cog"]
]
Note:

All words have the same length.
All words contain only lowercase alphabetic characters.
*/

/*
��ΪҪ�������е���̵Ľ������,����BFS,��һ�㶼������,P.S.�ƺ�BFS��̫��,DFS�ƺ�����
*/

/*
DFS����,DFS������Ȼ�����˴�����
*/

/*
BFS��ⷽ��,��ÿ���ʱ仯ǰ��һ���ʶ��г���,����BFS���֮�����
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
using namespace std;

class Solution {
	void ext_bfs(string& start, string& end, unordered_set<string>& dict, map<string, vector<string> >& pre)
	{
		queue<string> sq;
		sq.push(start); //ѹ���һ���ַ���

		int sz=start.length();
		int lv1(1),lv2(0),height(1);

		bool reached=false;

		while(!sq.empty())
		{
			string t=sq.front();

			sq.pop(); //����
			--lv1; 

			for(int i=0;i<sz;++i)
			{
				string tmp(t);
				for(char c='a';c<='z';++c)
				{
					tmp[i] = c; //�滻
					if(tmp == end) //������С������
					{
						reached = true;
						pre[tmp].push_back(t);
					}else if(dict.count(tmp))
					{
						//����,��Ѵ�tѹ�����
						sq.push(tmp);
						++lv2; //��һ�������1
						
						pre[tmp].push_back(t);
					}
				}
			}

			if(reached) //�ҵ����·����
			{
				//��ʼ����pre�б�,
			}

			if(lv1 == 0) //��һ��lvl���
			{
				lv1 = lv2;
				lv2 = 0;
				++height; //תս��һ��
			}
		}
	}

	int bfs(string& start, string& end, unordered_set<string>& dict)
	{
		queue<string> sq;
		sq.push(start);
		int lv1(1),lv2(0),sz(start.length()),height(1);
		while(!sq.empty())
		{
			string t=sq.front();
			sq.pop();
			--lv1;

			for(int i=0;i<sz;++i)
			{
				string tmp(t);
				for(char j='a';j<='z';++j)
				{
					tmp[i] = j;
					if(tmp == end)
					{
						return height;
					}else if(dict.count(tmp) && t[i]!=j)
					{
						sq.push(tmp);
						++lv2;
					}
				}
			}

			if(lv1==0) //����л�
			{
				lv1=lv2;
				lv2 = 0;
				++height;
			}
		}

		return -1; //������
	}

	void dfs(vector<vector<string> >& r, vector<string>& arr, 
		string& start, string& end, 
		unordered_set<string>& dict, int cLen,int mn)
	{

		if(cLen > mn) //����С����,���֦
		{
			return;
		}
		if(start == end)
		{
			r.push_back(arr);
			return;
		}

		int sz=start.length();
		for(int i=0;i<sz;++i) //��ÿһ���ַ������滻
		{
			string t(start);
			for(int j='a';j<='z';++j)
			{				
				t[i] = j;

				if(dict.count(t) && start[i]!=j) //�ֵ�������,������ݹ�
				{
					arr.push_back(t);
					dfs(r,arr,t,end,dict,cLen+1,mn);
					arr.pop_back(); //�ָ�
				}
			}
		}
	}
public:
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<vector<string> > res;
		vector<string> v;
		if(dict.size()<=0) return res;

		v.push_back(start);
		int mn=bfs(start,end,dict);
		dfs(res,v,start,end,dict,0,mn);

		return res;
	}
};

void solve()
{
	Solution s;
	unordered_set<string> dict;
	dict.insert("hot");
	dict.insert("dog");
	

	s.findLadders("hot","dog",dict);

}

#endif