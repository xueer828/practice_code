#ifndef _TEST_
#define _TEST_

// generate_parentheses
// Copyright (c) 2013/1/4 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"
*/

//˼·:���Ų��,dfs����? �������+��֦

/*
Run Status: Accepted!
Program Runtime: 16 milli secs
Progress: 8/8 test cases passed.
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
#include <iterator>
using namespace std;

class Solution {
	vector<string> entry;
	int total;

	void mydfs(string& exp,int n, int lcnt, int rcnt)
	{
		if(lcnt == total && rcnt == total)
		{
			entry.push_back(exp);
		}

		//���ܼ�����������
		if(lcnt < total) 
		{
			string exp1 = exp+ "(";
			//���ﲻreturn,��ô�Ϳ��Ա��������п��ܵĽ��
			mydfs(exp1,n+1,lcnt+1,rcnt); 
		}

		//���ܼ�����������
		if(rcnt < total && lcnt > rcnt) 
		{
			string exp2=exp+")";
			//���ﲻreturn,��ô�Ϳ��Ա��������п��ܵĽ��
			mydfs(exp2,n+1,lcnt,++rcnt); 
		}

	}

public:
	vector<string> generateParenthesis(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		entry.clear();
		total = n;
		string init("");

		mydfs(init,0,0,0);

		return entry;
	}
};

void solve()
{
	Solution s;

	vector<string> tmp=s.generateParenthesis(3);

	copy(tmp.begin(),tmp.end(),(ostream_iterator<string>(cout," ")));
}

#endif 
