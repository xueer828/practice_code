#ifndef _TEST_
#define _TEST_

// minimum_window_substring
// Copyright (c) 2013/4/25 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).

For example,
S = "ADOBECODEBANC"
T = "ABC"

Minimum window is "BANC".

Note:
If there is no such window in S that covers all characters in T, return the emtpy string "".

If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.
 */

/*
思路: 维护T数组中字符对应的最小的字符的位置,扫描S数组,碰到一个在T中的字符,就更新对应的字符的位置,并更新维护的最小字符的位置
算出当前的最大位置-最小位置的距离,求出最小的距离值

这里维护数组T的最小位置,一般可以用小顶堆来实现
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

class Solution {
	struct node{
		char c;
		int pos;
		node(char ch=0,int p=0):c(ch),pos(p){};
	};

	node mp[256]; //mapping for related chars
	int total_T;
	vector<node*> vt;

	void init(string T)
	{
		total_T = 0;
		for(int i=0;i<T.length();++i)
		{
			if(mp[T[i]] != 0)
				continue;
			mp[T[i]]=T[i];
			++total_T;
		}
	}

	bool add()

public:
	string minWindow(string S, string T) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int slen=S.length();
		int tlen=T.length();

		
	}
};

void solve()
{
}

#endif 