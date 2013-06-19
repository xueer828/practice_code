#ifndef _TEST_
#define _TEST_

// valid_sudoku
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'
*/

/*
Run Status: Accepted!
Program Runtime: 32 milli secs
Progress: 500/500 test cases passed.
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

//输入是二维数组,注意题目只是验证已经填完的数独是否有效
//可以用位来表示

class Solution {
	inline bool is_set(int v, int n)
	{
		return (v & (1<<n)) != 0;
	}
	inline void set_bit(int& v,int n)
	{
		v |= (1<<n);
	}
public:
	bool isValidSudoku(vector<vector<char> > &board) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		int row_sz = board.size();
		if(row_sz != 9)
			return false;
		int col_sz = board[0].size();
		if(col_sz != 9)
			return false;

		vector<int> row_mark(row_sz,0);
		vector<int> col_mark(col_sz,0);
		vector<int> block_mark(9,0);

		for(int i=0;i<row_sz;++i)
		{
			for(int j=0;j<col_sz;++j)
			{
				if(board[i][j]=='.')
					continue;

				int n=board[i][j]-'1';

				if(is_set(row_mark[i],n) || is_set(col_mark[j],n) || is_set(block_mark[i/3*3+j/3],n))
					return false;

				set_bit(row_mark[i],n);
				set_bit(col_mark[j],n);
				set_bit(block_mark[i/3*3+j/3],n);
			}
		}

		return true;

	}
};

void solve()
{

}

#endif