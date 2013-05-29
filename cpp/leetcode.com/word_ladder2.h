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
因为要返回所有的最短的解决方案,所以BFS,把一层都处理完,P.S.似乎BFS不太好,DFS似乎更好
*/

/*
DFS方案
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
			--lv1; //弹出一个,那么这一层就少一个节点
			
			for(int i=0;i<len;++i)
			{
				for(int j=0;i<26;++i)
				{
					string t(s);
					t[i] = 'a' + j; //尝试'a'~'z',看是否在dict中

					if(t == end)
					{
						//可以相等了

					}
					if(dict.count(t))
					{
						sq.push(t);
						++lv2; //下一层节点数量更新

					}
				}
			}

			if(lv1 == 0) //层次到下一层了
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
		if(cLen > mn) //比最小还大,则剪枝
			return;
		if(start == end)
		{
			//满足
			if(cLen < mn)
			{
				r.clear(); //前面的都不满足,因为最小的是当前cLen大小
				mn = cLen;
			}

			//arr.push_back(end);
			r.push_back(arr);
			//arr.pop_back();

			return;
		}

		int sz=start.length();
		for(int i=0;i<sz;++i) //对每一个字符进行替换
		{
			string t(start);
			for(int j=0;j<26;++j)
			{				
				t[i] = 'a' + j;

				if(t!=start && dict.count(t) && !exist(arr,t)) //字典里面有,则继续递归
				{
					arr.push_back(t);
					dfs(r,arr,t,end,dict,cLen+1,mn);
					arr.pop_back(); //恢复
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