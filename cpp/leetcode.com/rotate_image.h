#ifndef _TEST_
#define _TEST_

// rotate_image
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/

/*
思路: 宽n的矩阵, 顺时针 90度, 且原位置变换
其实可以看做,由外到内,每一层的对应的4个节点进行交换

Run Status: Accepted!
Program Runtime: 32 milli secs
Progress: 20/20 test cases passed.
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
	void rotate(vector<vector<int> > &matrix) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		
		int sz=matrix.size();

		if(sz <=0 )
			return;

		int lt(0),rb(sz-1),tmp;

		int i,j;
		while(lt < rb)
		{
			for(i=lt,j=rb;i<rb&&j>lt;++i,--j) //这里要小心,不要用=,用了=会造成节点属于那一边不统一
			{
				tmp=matrix[lt][i];
				matrix[lt][i]=matrix[j][lt];
				matrix[j][lt]=matrix[rb][j];
				matrix[rb][j]=matrix[i][rb];
				matrix[i][rb]=tmp;
			}
			++lt,--rb;
		}

	}
};

void solve()
{

}

#endif