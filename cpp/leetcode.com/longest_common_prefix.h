#ifndef _TEST_
#define _TEST_

// longest_common_prefix
// Copyright (c) 2013/01/07 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Write a function to find the longest common prefix string amongst an array of strings.
*/

/*
最长公共前缀,可以用trie树来实现,后面再看看是不是还有更好的方法来实现,例如后缀数组
*/

/*
Run Status: Accepted!
Program Runtime: 36 milli secs
Progress: 117/117 test cases passed.
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

//trie树的实现方案
class Solution {

	struct node{
		struct node* d[256];
		int mark;
		node():mark(0){
			memset(d,0,sizeof(struct node*)*256);
		}
	};
public:
	string longestCommonPrefix(vector<string> &strs) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		int sz=strs.size();
		if(sz <= 0)
			return string("");

		struct node* root=new struct node;
		
		vector<string>::iterator it=strs.begin();
		for(;it!=strs.end();++it)
		{
			int len=it->length();
			string str=*it;
			struct node *cur=root;
			for(int j=0;j<len;++j)
			{
				if(!cur->d[str[j]])
					cur->d[str[j]]=new struct node;
				cur = cur->d[str[j]];
				++ cur->mark;
			}
		}

		//finished.
		string ret("");
		for(node* cur = root;;)
		{
			int i=0;
			for(;i<256;++i)
			{
				if(cur->d[i] && cur->d[i]->mark == sz)
				{
					cur = cur->d[i]; //下一个节点
					ret += char(i);
					break;
				}
			}

			if(i==256)
				return ret;
		}
		return ret;
	}
};

void solve()
{
	Solution s;
	vector<string> t;
	t.push_back("aa");
	t.push_back("aa");
	cout<<s.longestCommonPrefix(t)<<endl;
}

#endif