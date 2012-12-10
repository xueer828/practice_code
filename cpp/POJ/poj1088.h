#ifndef _TEST_
#define _TEST_

// poj1088
// Copyright (c) 2012/12/09 
// Author: xdutaotao (xdutaotao@gmail.com)
// 滑雪 求M*N地块的最长的滑坡（可上下左右4个方向滑行仅当这个方向上存在高度差的下坡）

//DP: f[i][j] = max{f[i][j-1]+1,f[i-1][j]+1,f[i+1][j]+1,f[i][j+1]}

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

int map[130][130]={0};
//DP[i][j]表示点（i,j）处的最长的滑坡
int DP[130][130]={0};

int cal(const int& r,const int& c)
{
	if(DP[r][c] >= 0)
		return DP[r][c];

	int max = -1;
	if(map[r][c] > map[r-1][c]) //向上
	{
		if(DP[r-1][c] < 0)
			DP[r-1][c] = cal(r-1,c);
		if(max < DP[r-1][c]+1)
			max = DP[r-1][c]+1;
	}

	if (map[r][c] > map[r+1][c]) //下
	{
		if (DP[r+1][c] < 0)
			DP[r+1][c] = cal(r+1,c);
		if(max < DP[r+1][c]+ 1)
			max = DP[r+1][c] + 1;
	}

	if (map[r][c] > map[r][c-1]) //左
	{
		if (DP[r][c-1] < 0)
			DP[r][c-1] = cal(r,c-1);
		if(max < DP[r][c-1]+ 1)
			max = DP[r][c-1] + 1;
	}

	if (map[r][c] > map[r][c+1]) //右
	{
		if (DP[r][c+1] < 0)
			DP[r][c+1] = cal(r,c+1);
		if(max < DP[r][c+1]+ 1)
			max = DP[r][c+1] + 1;
	}

	return(DP[r][c]=(max>=0?max:1)); 

}

void solve()
{

	int ct_row,ct_col;
	cin>>ct_row>>ct_col;

	//现将map全置位0xffffffff,即-1，DP清空为0
	memset(map,0xff,sizeof(map));
	memset(DP,0,sizeof(DP));
	
	//DP有效部分未计算出置为-1
	for(int i=1;i<=ct_row;++i)
		for(int j=1;j<=ct_col;++j)
			DP[i][j]=-1;

	//输入map
	for(int i=1;i<=ct_row;++i)
		for(int j=1;j<=ct_col;++j)
			cin>>map[i][j];
		
	int maxL=-1,tmp=-1;
	for(int i=1;i<=ct_row;++i)
		for(int j=1;j<=ct_col;++j)
		{
			if(maxL < cal(i,j))
				maxL = cal(i,j); //这里已经保存值了，所以不会递归
		}

	printf("%d",maxL<0?0:maxL);
				

}

#endif