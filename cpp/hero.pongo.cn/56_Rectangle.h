#ifndef _TEST_
#define _TEST_

// 56_Rectangle
// Copyright (c) 2013/7/26 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
http://hero.pongo.cn/OnlineCompiler/Index?ID=58&ExamID=56
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



int largestRectangleArea(vector<int> &height) {
	//wirte your code hero

	if(height.size()<0)
		return 0;

	int n = height.size();

	struct node{
		int val;
		int pos;
		node(int n,int p):val(n),pos(p){}
	};

	stack<node> st;

	int mx_area=0;
	for(int idx=0;idx<n;++idx)
	{
		if(st.empty() || st.top().val < height[idx]) //larger incoming than top
		{
			st.push(node(height[idx],idx));
		}else if(st.top().val > height[idx]) // less than top, pop top and calculate value
		{
			int pos=st.top().pos;
			while(!st.empty() && st.top().val > height[idx]){ //弹出计算直到不大于当前要压入的值
				int area=(idx-st.top().pos)*st.top().val; 
				pos = st.top().pos;
				if(area > mx_area)
					mx_area = area; 
				st.pop();
			}

			if(st.empty() ||st.top().val < height[idx])
				st.push(node(height[idx],pos));
		}
	}

	//计算剩余部分
	while(!st.empty())
	{
		node& t=st.top();
		cout<<t.val<<":"<<t.pos<<endl;
		st.pop();
		int area = t.val*(n-t.pos);
		if(mx_area < area)
			mx_area = area;
	}

	return mx_area;
}

void solve()
{
	//int k[]={2,1,5,6,2,3};
	vector<int> v(4,0);
	v[0]=2;
	v[1]=1;
	v[2]=1;
	v[3]=2;

	//v[3]=2;
	//v[4]=2;
	//v[5]=2;
	cout<<largestRectangleArea(v)<<endl;
}

#endif 