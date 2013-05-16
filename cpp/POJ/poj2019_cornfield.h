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
�漰������һ�δ���,���query������,��������RMQ����������,�Ͼ�O(1)�Ĳ�ѯЧ�ʲ��Ǹǵ�
��һ���Ƕ�ά��RMQ����,ST�㷨�������, F[k][i][j] ����ʾ(i,j)Ϊ���Ͻ�,2^kΪ��ȵ������ε����ֵ����Сֵ

��Ϊ�����ǹ̶���,����Ҳ���Լ��ô����ڵĵ�������������������
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

//��log2�ĺ���
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

//mx��mn���������: mx[i][x][y] ��ʾ��(x,y)Ϊ�����2^iΪ��ȵķ�������������Сֵ
int mx[8][W][W]; //���ST����
int mn[8][W][W]; //��СST����

//�Ƶ���ʽ:mx[i][x][y]=max{mx[i-1][x][y],mx[i-1][x+(1<<(i-1))][y],mx[i-1][x][y+(1<<(i-1))],mx[i-1][x+(1<<(i-1))][y+(1<<(i-1))]}
//��:���߳�Ϊ2^i����(x,y)Ϊ���Ͻǵķ���,����Ϊ��2^(i-1)Ϊ�߳����ĸ�����


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
				//��max��min
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