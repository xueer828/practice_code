#ifndef _TEST_
#define _TEST_

// subsets
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a set of distinct integers, S, return all possible subsets.

Note:

Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
[3],
[1],
[2],
[1,2,3],
[1,3],
[2,3],
[1,2],
[]
]
*/

/*
˼·:����Ƚ�set����,Ȼ���ٽ������dfs

Run Status: Accepted!
Program Runtime: 40 milli secs
Progress: 10/10 test cases passed.
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
		if(n >= s.size())
		{
			v.push_back(t);
			return;
		}

		//ѡ���n��Ԫ��
		t.push_back(s[n]);
		gen_subsets(v,s,t,n+1);
		//��ѡ��n��Ԫ��
		t.pop_back();
		gen_subsets(v,s,t,n+1);

	}
public:
	vector<vector<int> > subsets(vector<int> &S) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<vector<int> > v;
		int sz=S.size();
		if(sz <= 0)
			return v;

		vector<int> t;
		sort(S.begin(),S.end());
		gen_subsets(v,S,t,0);

		return v;
	}
};

void solve()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	Solution s;
	vector<vector<int> >& a = s.subsets(v);
}

#endif