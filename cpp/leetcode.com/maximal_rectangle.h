#ifndef _TEST_
#define _TEST_

// maximal_rectangle
// Copyright (c) 2013/4/25 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
 */

//最原始的算法: 选取一点(x,y)作为左上角,选取另外一点(m,n)作为右下角,探测构成的矩形是否全由1构成; 算法复杂度O(m^3*n^3)

/*
最好的方法: 最外层循环遍历行,在遍历的内层,固定行,然后将问题转化为histogram直方图的最大矩形面积问题
 */

/*
一次性AC, 直方图最大矩形,利用单调栈
Run Status: Accepted!
Program Runtime: 68 milli secs
Progress: 57/57 test cases passed.
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
	struct gram 
	{
		int h,s;
		gram():h(0),s(0){};
		gram(int nh,int ns):h(nh),s(ns){};
	};
	int max_histogram(vector<int>& arr)
	{
		int mx_area=0;
		stack<gram> sg;
		sg.push(gram(0,0));

		int i=0;
		for(;i<arr.size();++i)
		{
			//大于压入
			if(arr[i] > sg.top().h)
			{
				sg.push(gram(arr[i],i));
				continue;
			}

			//等于,忽略
			if(arr[i]==sg.top().h)
				continue;

			//小于,弹出,计算面积,知道不小于为止
			int start_point = i;
			while(arr[i] < sg.top().h)
			{
				gram tmp=sg.top();
				sg.pop();

				int area=(i-tmp.s)*tmp.h;
				if(area > mx_area)
					mx_area = area;

				start_point = tmp.s; //更新start_point
			}

			//此时可以压入新的节点了
			sg.push(gram(arr[i],start_point));
		}

		//最后弹出单调栈内所有,并进行计算
		while(sg.size()>0)
		{
			gram tmp=sg.top();
			sg.pop();

			int area=(i-tmp.s)*tmp.h; //此时i为直方图最末尾标号
			if(area > mx_area)
				mx_area = area;
		}

		return mx_area;
	}
public:
	int maximalRectangle(vector<vector<char> > &matrix) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		int row_sz=matrix.size();
		if(row_sz <=0) return 0;

		int col_sz=matrix[0].size();
		if(col_sz <=0) return 0;

		vector<vector<int> > arr;
		arr.resize(row_sz);
		for(int i=0;i<row_sz;++i)
			arr[i].resize(col_sz,0); //全部初始化为0

		//填充第一行
		for(int i=0;i<col_sz;++i)
			arr[0][i]=matrix[0][i]-'0';

		for(int i=1;i<row_sz;++i)
			for(int j=0;j<col_sz;++j)
				//如果本格为0,则值为0,若本格为1,而上一个为0,则本格为1,若本格为0,上一个大于0,则本格为上一个值加1
				arr[i][j]=(matrix[i][j]=='1')?arr[i-1][j]+1:0; 
		
		//构造完毕

		int mx_area=0;
		
		for(int i=0;i<row_sz;++i)
		{
			int area=max_histogram(arr[i]);
			if(area > mx_area)
				mx_area = area;
		}

		return mx_area;
	}
};

void solve()
{
}

#endif 