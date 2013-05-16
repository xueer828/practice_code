#ifndef _TEST_
#define _TEST_

// poj2019_cornfield
// Copyright (c) 2013/5/14 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
http://poj.org/problem?id=2019
 */

/*
涉及到这种一次处理,多次query的问题,都可以往RMQ问题上来想,毕竟O(1)的查询效率不是盖的
这一题是二维的RMQ问题,ST算法可以求解, F[k][i][j] 来表示(i,j)为左上角,2^k为宽度的正方形的最大值和最小值

因为窗口是固定的,所以也可以简化用带窗口的单调队列来解决这个问题
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

//求log2的函数
int lg2(int v)
{
	int cnt=0;
	while(v)
	{
		v >>= 1;
		++cnt;
	}
	return cnt;
}

const int W=250;

//mx和mn数组的意义: mx[i][x][y] 表示以(x,y)为顶点的2^i为宽度的方格中最大或者最小值
int mx[8][W][W]; //最大ST数组
int mn[8][W][W]; //最小ST数组

//推导公式:mx[i][x][y]=max{mx[i-1][x][y],mx[i-1][x+(1<<(i-1))][y],mx[i-1][x][y+(1<<(i-1))],mx[i-1][x+(1<<(i-1))][y+(1<<(i-1))]}
//即:将边长为2^i的以(x,y)为左上角的方格,划分为以2^(i-1)为边长的四个方格


void solve()
{

	int wid,qwid,qnum;
	cin>>wid>>qwid>>qnum;

	int tmp;
	for(int i=0;i<wid;++i)
	{
		for(int j=0;j<wid;++j)
		{
			cin>>tmp;
			mx[0][i][j]=mn[0][i][j]=tmp;
		}
	}

	int z=lg2(wid);
	for(int k=1;k<=z;++k)
	{
		for(int i=0;i<wid;i += (1<<k))
		{
			for(int j=0;j<wid;j+= (1<<k))
			{
				//求max和min
				int tmx,tmn;
				tmx=tmn=mx[k-1][i][j];

				if(mx[k-1][i+(1<<(k-1))][j] > tmx)
					tmx = mx[k-1][i+(1<<(k-1))][j];
				if(mn[k-1][i+(1<<(k-1))][j] < tmn)
					tmn = mn[k-1][i+(1<<(k-1))][j];

				if(mx[k-1][i][j+(1<<(k-1))] > tmx)
					tmx = mx[k-1][i][j+(1<<(k-1))];
				if(mn[k-1][i][j+(1<<(k-1))] < tmn)
					tmn = mn[k-1][i][j+(1<<(k-1))];

				if(mx[k-1][i+(1<<(k-1))][j+(1<<(k-1))] > tmx)
					tmx = mx[k-1][i+(1<<(k-1))][j+(1<<(k-1))];
				if(mn[k-1][i+(1<<(k-1))][j+(1<<(k-1))] < tmn)
					tmn = mn[k-1][i+(1<<(k-1))][j+(1<<(k-1))];


				mx[k][i][j] = tmx;
				mn[k][i][j] = tmn;

			}
		}
	}

	int w=lg2(qwid)-1;
	int x,y,tmx,tmn;
	for(int i=0;i<qnum;++i)
	{
		
		cin>>x>>y;
		x -= 1;
		y -= 1;
		tmx=mx[w][x][y];
		tmn = mn[w][x][y];

		if(mx[w][x+qwid-(1<<w)][y] > tmx)
			tmx = mx[w][x+qwid-(1<<w)][y];
		if(mn[w][x+qwid-(1<<w)][y] < tmn)
			tmn = mn[w][x+qwid-(1<<w)][y];

		if(mx[w][x][y+qwid-(1<<w)] > tmx)
			tmx = mx[w][x][y+qwid-(1<<w)];
		if(mn[w][x][y+qwid-(1<<w)] < tmn)
			tmn = mn[w][x][y+qwid-(1<<w)];

		if(mx[w][x+qwid-(1<<w)][y+qwid-(1<<w)] > tmx)
			tmx = mx[w][x+qwid-(1<<w)][y+qwid-(1<<w)];
		if(mn[w][x+qwid-(1<<w)][y+qwid-(1<<w)] < tmn)
			tmn = mn[w][x+qwid-(1<<w)][y+qwid-(1<<w)];

		cout<<tmx-tmn<<endl;
	}
	
}

#endif 