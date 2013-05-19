#ifndef _TEST_
#define _TEST_

// spiral_matrix
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

/*
旋转打印,主要是设定好左上角和右下角的坐标,然后先打印第一行(注意从第一个元素到最后一个元素,)然后最后一列(不包含头和尾的元素),然后再打印最下面一行的元素(从尾到头,包含头尾),然后再打印第一列(不包含头尾)

Run Status: Accepted!
Program Runtime: 8 milli secs
Progress: 21/21 test cases passed.
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
public:
	vector<int> spiralOrder(vector<vector<int> > &matrix) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function	
		vector<int> v;
		int l(0),t(0),r,b,num;
		b=matrix.size()-1;
		if(b < 0) return v;
		r=matrix[0].size()-1;
		if(r < 0 ) return v;

		num = (b+1)*(r+1);

		while(v.size()< num)
		{ 
			for(int i=l;i<=r;++i) //多打一个
				v.push_back(matrix[t][i]);

			for(int i=t+1;i<b;++i)
				v.push_back(matrix[i][r]);

			if(t<b) //如果前面已经打印过了,就不必再打印了
			for(int i=r;i>=l;--i) //多打一个
				v.push_back(matrix[b][i]);
			if(l<r) //如果前面已经打印过了,就不必再打印了
			for(int i=b-1;i>t;--i) //少打一个
				v.push_back(matrix[i][l]);

			//更新l r t b
			++l,++t,--r,--b;
		}
	}
};


void solve()
{
	vector<vector<int> > v;
	vector<int> v2(1);
	v2[0]=1;
	v.push_back(v2);

	Solution s;
	s.spiralOrder(v);

}

#endif