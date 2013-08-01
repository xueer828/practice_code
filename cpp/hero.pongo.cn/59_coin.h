#ifndef _TEST_
#define _TEST_

// 59_coin
// Copyright (c) 2013/7/25 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
http://hero.pongo.cn/OnlineCompiler/Index?ID=59&ExamID=57

���룺A��B��C��D��������0<=A,B<50��0<=C,D<= 100��p1�Ǹ����� 0<=p1<=1��
�����Ϊ��֤������������������Сa��ʤ�ĸ��ʳ���100������ȡ����ֱ�ӽضϺ����λ�����Ľ����
���磬�����0.125�����12
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

//���Ʊ�������
//P[v]=P[v-C]*p1 + P[v+D]*(1-p1)
//��ʼֵ, P[B]=1,����=0
int win(int A,int B,int C,int D,double p1) {

	int mx=A+B;

	//P[][v]��ʾ��ֵΪvʱ�ĸ���
	double P[2][101];

	//����ʼֵ
	for(int i=0;i<=100;++i)
		P[0][i]=P[1][i]=0;
	P[0][B]=1;

	double p2=1-p1;

	int cur(0),nxt(1);

	int cnt = 100000; //10^6

	while(cnt--){
		for(int i=0;i<mx;++i)
		{
			double t = 0;

			if(i-C >= 0 && P[cur][i-C]>0)
				t += p1*P[cur][i-C];

			if(i+D <= mx && P[cur][i+D]>0)
				t += p2*P[cur][i+D];
			
			if(t > 0)
				P[nxt][i] = t;
		}

		cur=nxt;
		nxt =(nxt+1)%2;
	}

	double result = P[cur][0];
	for(int i=1;i<D;++i)
		result += P[cur][i]*p2;
	return (int)(result*100);
}

void solve()
{
	cout<<win(36,18,33,10,0.360000)<<endl;
}

#endif 