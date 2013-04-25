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

//�򵥽ⷨ1, ��ʱ,�㷨���Ӷ�O(n^2)
//���,�յ�

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
			int cur_height=height[i]; //��ʼ����iΪ��ʼ�߶�
			for(int j=i;j<height.size();++j)
			{
				//����ѭ���ó���ǰ��С�ĸ߶�,���������,�Ƚ����ֵ
				if(cur_height > height[j])
					cur_height = height[j];

				int cur_area=(j-i+1)*cur_height;
				if(cur_area > max_area) //���ݼ����ֵ�������ľ������
					max_area = cur_area;
			}
		}

		return max_area;
	}
};

//�㷨2, ���õ���ջ����,�㷨���Ӷ�O(n)
/*
��������ջ
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
		srec.push(rec()); //ѹ��һ��0��Ϊ���,��ֹ����
		int i=0,mx_area=0;
		for(i=0;i<sz;++i)
		{
			if(height[i] > srec.top().h)
			{
				srec.push(rec(height[i],i));
				continue;
			}
			
			int start_point=i;
			//�����ǰheightС�ڶ���,�򵯳�����,�����м���
			while(height[i] < srec.top().h)
			{
				rec tmp=srec.top();
				srec.pop();
				int area=(i-tmp.p)*tmp.h;
				if(area > mx_area)
					mx_area = area;
				start_point = tmp.p;
			}

			//ѹ�뵱ǰ��height
			srec.push(rec(height[i],start_point));
		}

		//��ѹ�����֮��,�������ڵ���ջ�ڵ�ʣ�����
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