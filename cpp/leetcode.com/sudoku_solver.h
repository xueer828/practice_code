#ifndef _TEST_
#define _TEST_

// sudoku_solver
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.



A sudoku puzzle...



...and its solution numbers marked in red.
*/

/*
输入是棋盘格式,递归搜索解空间
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
	inline bool is_set(int v,int n)
	{
		return (v & (1<<n)) != 0;
	}
	inline void set_bit(int&v, int n)
	{
		v |= (1<<n);
	}
	inline void reset_bit(int& v,int n)
	{
		v &= ~(1<<n); //异或 清除
	}
	bool sudoku_recusive(vector<vector<char> >&board, vector<int>& row_m,vector<int>& col_m,
		vector<int>& block_m, int nI,int nJ)
	{
		if(nJ >= 9)
		{
			nJ = 0;
			++nI;
		}

		if(nI >= 9)
		{
			return true;
		}


		while(board[nI][nJ]!='.')
		{
			++nJ; 
			if(nJ==9)
			{
				nJ=0;
				++nI;
			}
		}

		if(nI >= 9)
		{
			return true;
		}


		for(int i=0;i<9;++i)
		{
			if(is_set(row_m[nI],i) || is_set(col_m[nJ],i) || is_set(block_m[nI/3+nJ/3],i))
				continue;

			set_bit(row_m[nI],i);
			set_bit(col_m[nJ],i);
			set_bit(block_m[nI/3+nJ/3],i);

			board[nI][nJ] = i+'1';

			if(sudoku_recusive(board,row_m,col_m,block_m,nI,nJ+1))
				return true;

			reset_bit(row_m[nI],i);
			reset_bit(col_m[nJ],i);
			reset_bit(block_m[nI/3+nJ/3],i);
		}

		return false;
	}
public:
	void solveSudoku(vector<vector<char> > &board) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> row(9,0);
		vector<int> col(9,0);
		vector<int> block(9,0);

		for(int i=0;i<9;++i)
			for(int j=0;j<9;++j)
			{
				if(board[i][j]=='.')
					continue;
				int n=board[i][j]-'0';
				set_bit(row[i],n);
				set_bit(col[j],n);
				set_bit(block[i/3+j/3],n);
			}


		sudoku_recusive(board,row,col,block,0,0);
	}
};

void solve()
{
	//["53..7....","6..195...",".98....6.","8...6...3","4..8.3..1",
	//"7...2...6",".6....28.","...419..5","....8..79"]

	vector<vector<char> > v(9,vector<char>(9,'.'));

	vector<string> input;

	input.push_back("53..7....");
	input.push_back("6..195...");
	input.push_back(".98....6.");
	input.push_back("8...6...3");
	input.push_back("4..8.3..1");
	input.push_back("7...2...6");
	input.push_back(".6....28.");
	input.push_back("...419..5");
	input.push_back("....8..79");

	for(int i=0;i<9;++i)
		for(int j=0;j<9;++j)
		{
			v[i][j] = input[i][j];
		}


	Solution s;
	s.solveSudoku(v);
}

#endif