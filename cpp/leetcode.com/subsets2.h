#ifndef _TEST_
#define _TEST_

// subsets2
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
[2],
[1],
[1,2,2],
[2,2],
[1,2],
[]
]
*/

/*
什么原理?
Run Status: Accepted!
Program Runtime: 52 milli secs
Progress: 19/19 test cases passed.
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
	void gen_subsets(vector<vector<int> >& v, vector<int>& s, vector<int>& t, int n)
	{
		//为什么?
		v.push_back(t);
		

		for(int i=n;i<s.size();++i)
		{
			if(i>n && s[i]==s[i-1]) //这个元素已经考虑过了,可以pass
				continue;

			t.push_back(s[i]);
			gen_subsets(v,s,t,i+1);
			t.pop_back();
		}

	}
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int sz=S.size();
		vector<vector<int> > v;
		if(sz <= 0)
			return v;

		sort(S.begin(),S.end());
		vector<int> t;
		gen_subsets(v,S,t,0);

		return v;
	}
};

void solve()
{

}

#endif