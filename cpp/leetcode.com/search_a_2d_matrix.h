#ifndef _TEST_
#define _TEST_

// search_a_2d_matrix
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
[1,   3,  5,  7],
[10, 11, 16, 20],
[23, 30, 34, 50]
]
Given target = 3, return true.
*/

/*
思路1: 类似二维的二分法,先确定到一维上面,然后再一维上面再二分搜索(需要处理好边界问题)
算法复杂度 matrix如果是MxN,那么复杂度就是 O(lgM + lgN)
Run Status: Accepted!
Program Runtime: 64 milli secs
Progress: 134/134 test cases passed.
*/

/*
更牛x的思路2: 数组[i][j], j为后指针,i为行指针,首先通过target跟最后一个元素进行比较,得到行的位置,
然后从行的最后一个元素一直到第一个元素,开始遍历查询
算法复杂度O(M+N)
Run Status: Accepted!
Program Runtime: 68 milli secs
Progress: 134/134 test cases passed.
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

class Solution1 {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int row_sz=matrix.size();
		if(row_sz <=0) return false;
		int col_sz=matrix[0].size();
		if(col_sz <=0) return false;

		//确定行
		int s(0),e(row_sz-1),m;
		while(s < e)
		{
			m = (s + e) >>1;
			if(matrix[m][0] > target) 
				e = m-1;
			else if(matrix[m][col_sz-1] < target )
				s = m+1;
			else{
				s = m;
				break;
			}
		}

		int t_row=s;
		//然后对选出的row,进行二分搜索
		s = 0, e=col_sz-1;
		while(s <= e)
		{
			m = (s+e)>>1;
			if(matrix[t_row][m] > target)
				e = m-1;
			else if(matrix[t_row][m] < target)
				s = m+1;
			else
				return true;
		}

		return false;
	}
};

class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		int i=0;
		if(matrix.size() <= 0) return false;
		int j=matrix[0].size()-1;
		if(j < 0) return false;

		while(i < matrix.size() && j >= 0)
		{
			if(matrix[i][j] == target)
				return true;
			else if(matrix[i][j] > target) //这时候说明target在第i行上面,后面i会一直保持不变,j会一直向前
				--j;
			else //此时j依然是每行的最后一个元素,i为慢慢往后加
				++i; 
		}
		return false;
	}
};

void solve()
{
	vector<vector<int> > t;
	vector<int> a,b,c;
	a.push_back(1);
	b.push_back(3);
	c.push_back(5);

	t.push_back(a);
	t.push_back(b);
	t.push_back(c);

	Solution s;
	cout<<s.searchMatrix(t,3)<<endl;
}

#endif