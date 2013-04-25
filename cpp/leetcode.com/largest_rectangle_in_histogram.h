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

/*
Solution2 AC, Solution 1 LTE
Run Status: Accepted!
Program Runtime: 92 milli secs
Progress: 94/94 test cases passed.
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

//简单解法1, 超时,算法复杂度O(n^2)
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

//算法2, 利用单调栈特性,算法复杂度O(n)
/*
单调递增栈
 */

class Solution {
	struct rec 
	{
		int h,p;
		rec():h(0),p(0){};
		rec(int nh,int np):h(nh),p(np){};
	};
public:
	int largestRectangleArea(vector<int> &height) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int sz=height.size();
		if(sz <=0)
			return 0;

		stack<rec> srec;
		srec.push(rec()); //压入一个0作为最低,防止下溢
		int i=0,mx_area=0;
		for(i=0;i<sz;++i)
		{
			if(height[i] > srec.top().h)
			{
				srec.push(rec(height[i],i));
				continue;
			}
			
			int start_point=i;
			//如果当前height小于顶端,则弹出顶端,并进行计算
			while(height[i] < srec.top().h)
			{
				rec tmp=srec.top();
				srec.pop();
				int area=(i-tmp.p)*tmp.h;
				if(area > mx_area)
					mx_area = area;
				start_point = tmp.p;
			}

			//压入当前的height
			srec.push(rec(height[i],start_point));
		}

		//在压入完成之后,还需检查在单调栈内的剩余面积
		while(srec.size()>0)
		{
			rec tmp=srec.top();
			srec.pop();
			int area=(i-tmp.p)*tmp.h;
			if(area > mx_area)
				mx_area = area;
		}

		return mx_area;
	}
};

void solve()
{
	Solution s;
	vector<int> t;
	t.push_back(5);
	t.push_back(4);
	t.push_back(1);
	t.push_back(2);
	cout<<s.largestRectangleArea(t);
}

#endif