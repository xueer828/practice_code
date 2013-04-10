#ifndef _TEST_
#define _TEST_

// largest_rectangle_in_histogram
// Copyright (c) 2013/01/07 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

no graph

Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

no graph

The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
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

//简单解法1
//起点,终点

class Solution1 {
public:
	int largestRectangleArea(vector<int> &height) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		if(height.size()<= 0)
			return 0;
		int max_area=0;
		for(int i=0;i<height.size();++i)
		{
			int cur_height=height[i]; //起始点以i为起始高度
			for(int j=i;j<height.size();++j)
			{
				//依次循环得出当前最小的高度,并计算面积,比较最大值
				if(cur_height > height[j])
					cur_height = height[j];

				int cur_area=(j-i+1)*cur_height;
				if(cur_area > max_area) //根据计算的值更新最大的矩形面积
					max_area = cur_area;
			}
		}

		return max_area;
	}
};


class Solution2 {
public:
	int largestRectangleArea(vector<int> &height) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

	}
};

void solve()
{

}

#endif