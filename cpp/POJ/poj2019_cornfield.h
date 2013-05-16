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

	cout<<lg2(250)<<endl;
}

#endif 