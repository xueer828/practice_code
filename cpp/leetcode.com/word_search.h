#ifndef _TEST_
#define _TEST_

// word_search
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
["ABCE"],
["SFCS"],
["ADEE"]
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/

/*
很明显具有子问题特征,递归 (只是忘了记录已经走过的格子,这样路径会反转,要避免这种情况)

Run Status: Accepted!
Program Runtime: 56 milli secs
Progress: 76/76 test cases passed.
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
	bool exist_recusive(vector<vector<char> >&b,int x,int y, 
		string& w, int z, vector<vector<int> >& visit)
	{
		if(w.length() <= z)
			return true;

		int m=b.size();
		int n=b[0].size();

		visit[x][y]=1;

		//右
		if(x+1 < m && visit[x+1][y] == 0 && b[x+1][y] == w[z] && exist_recusive(b,x+1,y,w,z+1,visit))
			return true;

		//下
		if(y+1 < n && visit[x][y+1] == 0 && b[x][y+1] == w[z] && exist_recusive(b,x,y+1,w,z+1,visit))
			return true;

		//左
		if(x > 0 && visit[x-1][y] == 0 && b[x-1][y] == w[z] && exist_recusive(b,x-1,y,w,z+1,visit))
			return true;

		//上
		if(y > 0 && visit[x][y-1] == 0 && b[x][y-1] == w[z] && exist_recusive(b,x,y-1,w,z+1,visit))
			return true;

		visit[x][y]=0;

		return false;
	}
public:
	bool exist(vector<vector<char> > &board, string word) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int sz=board.size();
		if(sz <= 0)
			return false;
		int cl=board[0].size();
		if(cl <= 0)
			return false;

		if(word.length() == 0)
			return true;

		vector<vector<int> > e(sz,vector<int>(cl,0));

		for(int i=0;i<sz;++i)
			for(int j=0;j<cl;++j)
				if(board[i][j] == word[0] && exist_recusive(board,i,j,word,1,e))
					return true;

		return false;
	}
};

void solve()
{
	vector<vector<char> > v(1,vector<char>(1,'a'));

	Solution s;
	cout<<s.exist(v,"ab")<<endl;;
}

#endif