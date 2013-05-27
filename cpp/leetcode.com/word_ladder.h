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

/*
类似图的思想,一个单词可以看做是一个节点,求某一个节点(起点)到另外一个节点(终点)的最短路径
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
	int get_edge(string& s1, string& s2)
	{
		int i=sz.length();
		int cnt=0;
		while(--i)
		{
			if(s1[i]!=s2[i])
				++cnt;
		}

		if(cnt <= 1)
			return 1;
		else
			return 0;
	}

	void dijkstra(vector<vector<int> >& v,vector<int>& pre)
	{

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

		vector<vector<int> > matrix(sz,vector<int>(sz,0)); //初始化二维数组

		//预处理
		for(int i=0;i<sz;++i)
			for(int j=i;j<sz;++j)
			{
				matrix[i][j]=matrix[i][sz-i]=get_edge(dict[i],dict[j]);
			}

		
		dict.
		
		//dijkstra算法
		
	}
};


void solve()
{

}

#endif