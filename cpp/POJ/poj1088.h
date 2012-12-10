#ifndef _TEST_
#define _TEST_

// poj1088
// Copyright (c) 2012/12/09 
// Author: xdutaotao (xdutaotao@gmail.com)
// ��ѩ ��M*N�ؿ����Ļ��£�����������4�������н�����������ϴ��ڸ߶Ȳ�����£�

//DP: f[i][j] = max{f[i][j-1]+1,f[i-1][j]+1,f[i+1][j]+1,f[i][j+1]}

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

int map[130][130]={0};
//DP[i][j]��ʾ�㣨i,j��������Ļ���
int DP[130][130]={0};

int cal(const int& r,const int& c)
{
	if(DP[r][c] >= 0)
		return DP[r][c];

	int max = -1;
	if(map[r][c] > map[r-1][c]) //����
	{
		if(DP[r-1][c] < 0)
			DP[r-1][c] = cal(r-1,c);
		if(max < DP[r-1][c]+1)
			max = DP[r-1][c]+1;
	}

	if (map[r][c] > map[r+1][c]) //��
	{
		if (DP[r+1][c] < 0)
			DP[r+1][c] = cal(r+1,c);
		if(max < DP[r+1][c]+ 1)
			max = DP[r+1][c] + 1;
	}

	if (map[r][c] > map[r][c-1]) //��
	{
		if (DP[r][c-1] < 0)
			DP[r][c-1] = cal(r,c-1);
		if(max < DP[r][c-1]+ 1)
			max = DP[r][c-1] + 1;
	}

	if (map[r][c] > map[r][c+1]) //��
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

	//�ֽ�mapȫ��λ0xffffffff,��-1��DP���Ϊ0
	memset(map,0xff,sizeof(map));
	memset(DP,0,sizeof(DP));
	
	//DP��Ч����δ�������Ϊ-1
	for(int i=1;i<=ct_row;++i)
		for(int j=1;j<=ct_col;++j)
			DP[i][j]=-1;

	//����map
	for(int i=1;i<=ct_row;++i)
		for(int j=1;j<=ct_col;++j)
			cin>>map[i][j];
		
	int maxL=-1,tmp=-1;
	for(int i=1;i<=ct_row;++i)
		for(int j=1;j<=ct_col;++j)
		{
			if(maxL < cal(i,j))
				maxL = cal(i,j); //�����Ѿ�����ֵ�ˣ����Բ���ݹ�
		}

	printf("%d",maxL<0?0:maxL);
				

}

#endif