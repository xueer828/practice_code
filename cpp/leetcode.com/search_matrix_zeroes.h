#ifndef _TEST_
#define _TEST_

// search_matrix_zeroes
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
*/

/*
����1: ��������һ�������� MxN matrix,���� ����Ԫ�� O(MN) �ռ临�Ӷ� , ����ʡ��
����2: ����O(m+n)�ռ�,���ڼ�¼��Ӧ���к������Ƿ���0Ԫ��, O(M+N)�ռ临�Ӷ�

Run Status: Accepted!
Program Runtime: 368 milli secs
Progress: 154/154 test cases passed.
*/

/*
���õķ���3:
�͵�,Ѱ��һ�л�һ��������ڵ���������¼�Ƿ��л��߱���Ӧ�ñ�0���
����Ӧ���ж�һ�µ�һ�к͵�һ���Ƿ�Ӧ��ȫ����0,Ȼ���ٽ��к��е�0����Ϣ��¼�ڵ�һ�к͵�һ��

Run Status: Accepted!
Program Runtime: 372 milli secs
Progress: 154/154 test cases passed.
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


class Solution2 {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int row_sz=matrix.size();
		if(row_sz <=0) return;
		int col_sz = matrix[0].size();
		if(col_sz <=0) return;

		vector<int> m(row_sz),n(col_sz);

		for(int i=0;i<row_sz;++i)
			for(int j=0;j<col_sz;++j)
				if(matrix[i][j]==0)
					m[i]=n[j]=1;

		for(int i=0;i<row_sz;++i)
		{
			if(m[i]==1)
			{
				for(int j=0;j<col_sz;++j)
					matrix[i][j]=0;
			}
		}

		for(int i=0;i<col_sz;++i)
		{
			if(n[i]==1)
			{
				for(int j=0;j<row_sz;++j)
					matrix[j][i]=0;
			}
		}

	}
};

class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int row_sz=matrix.size();
		if(row_sz <=0) return;
		int col_sz=matrix[0].size();
		if(col_sz <=0) return;

		bool zero_1st_row(false),zero_1st_col(false);
		for(int i=0;i<row_sz;++i)
			if(matrix[i][0] == 0)
			{
				zero_1st_col = true;
				break;
			}

		for(int i=0;i<col_sz;++i)
			if(matrix[0][i]==0)
			{
				zero_1st_row = true;
			}

		//���潫0����Ϣ��¼�ڵ�һ�к͵�һ��
		for(int i=0;i<row_sz;++i)
			for(int j=0;j<col_sz;++j)
			{
				if(matrix[i][j]==0)
				{
					matrix[i][0]=matrix[0][j]=0;
				}
			}

		//��ʼ���
		for(int i=1;i<row_sz;++i)
		{
			if(matrix[i][0]==0)
			{
				for(int j=1;j<col_sz;++j)
					matrix[i][j]=0;
			}
		}

		for(int i=1;i<col_sz;++i)
		{
			if(matrix[0][i]==0)
			{
				for(int j=1;j<row_sz;++j)
					matrix[j][i]=0;
			}
		}

		if(zero_1st_row)
		{
			for(int i=0;i<col_sz;++i)
				matrix[0][i]=0;
		}

		if(zero_1st_col)
		{
			for(int i=0;i<row_sz;++i)
				matrix[i][0]=0;
		}
	}
};

void solve()
{

}

#endif