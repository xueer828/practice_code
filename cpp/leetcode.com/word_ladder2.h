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
DFS����
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
	void bfs(vector<vector<string> >& r, string& start, string& end, unordered_set<string>& dict)
	{
		int lv1=1,lv2=0;
		queue<string> sq;
		sq.push(start);

		vector<string> vs;
		int len=start.length();

		while(!sq.empty())
		{
			string s=sq.front();
			sq.pop();
			--lv1; //����һ��,��ô��һ�����һ���ڵ�
			
			for(int i=0;i<len;++i)
			{
				for(int j=0;i<26;++i)
				{
					string t(s);
					t[i] = 'a' + j; //����'a'~'z',���Ƿ���dict��

					if(t == end)
					{
						//���������

					}
					if(dict.count(t))
					{
						sq.push(t);
						++lv2; //��һ��ڵ���������

					}
				}
			}

			if(lv1 == 0) //��ε���һ����
			{
				lv1 = lv2;
				lv2 = 0; 
			}
		}
	}

	bool exist(vector<string>& v, string& s)
	{
		for(int i=0;i<v.size();++i)
		{
			if(v[i]==s)
				return true;
		}
		return false;
	}

	void dfs(vector<vector<string> >& r, vector<string>& arr, 
		string& start, string& end, 
		unordered_set<string>& dict, int cLen,int& mn)
	{
		if(cLen > mn) //����С����,���֦
			return;
		if(start == end)
		{
			//����
			if(cLen < mn)
			{
				r.clear(); //ǰ��Ķ�������,��Ϊ��С���ǵ�ǰcLen��С
				mn = cLen;
			}

			//arr.push_back(end);
			r.push_back(arr);
			//arr.pop_back();

			return;
		}

		int sz=start.length();
		for(int i=0;i<sz;++i) //��ÿһ���ַ������滻
		{
			string t(start);
			for(int j=0;j<26;++j)
			{				
				t[i] = 'a' + j;

				if(t!=start && dict.count(t) && !exist(arr,t)) //�ֵ�������,������ݹ�
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
		int mn=0x7fffffff;
		dfs(res,v,start,end,dict,0,mn);

		return res;
	}
};

void solve()
{
	Solution s;
	unordered_set<string> dict;
	dict.insert("a");
	dict.insert("b");
	dict.insert("c");

	s.findLadders("a","c",dict);

}

#endif