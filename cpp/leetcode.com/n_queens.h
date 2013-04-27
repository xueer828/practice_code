#ifndef _TEST_
#define _TEST_

// n_queens
// Copyright (c) 2013/4/25 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.



Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example,
There exist two distinct solutions to the 4-queens puzzle:

[
[".Q..",  // Solution 1
"...Q",
"Q...",
"..Q."],

["..Q.",  // Solution 2
"Q...",
"...Q",
".Q.."]
]
 */

//思路: DFS深度遍历

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
	void NQueens(vector<string>& v,bool b[], int c, int n)
	{
		if(c == n)
		{
			if(v.size() == n)
				res.push_back(v);
			return;
		}

		for(int i=0;i<n;++i)
		{
			if(b[i])
			{
				string s(tpl);
				s[i]='Q'; 
				b[i]=false;
				v.push_back(s);
				NQueens(v,b,c+1,n);

				//恢复
				b[i]=true;
				v.pop_back();
			}
		}

	}

	string tpl;
	vector<vector<string> > res;
public:
	vector<vector<string> > solveNQueens(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		res.clear();

		if(n<=0) return res;

		

		vector<string> v;
		bool *b=new bool[n];

		tpl.clear();
		for(int i=0;i<n;++i)
		{
			tpl += ".";
			b[i]=true;
		}

		NQueens(v,b,0,n);

		return res;
	}
};

void solve()
{
	Solution s;
	s.solveNQueens(4);
}

#endif 