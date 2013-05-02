#ifndef _TEST_
#define _TEST_

// 20130310_Min_SumOfDistance
// Copyright (c) 2013/03/12 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
http://51weixue.com/thread-638-1-1.html
X������N���㣬ÿ������˰���һ��λ������X��������һ��ȨֵW���õ㵽������Ĵ�Ȩ���� = ʵ�ʾ��� * Ȩֵ����X����һ��ʹ������N����Ĵ�Ȩ����֮����С����������С�Ĵ�Ȩ����֮�͡�

���� N��Ȩֵ
��� ��С��Ȩֵ֮�͡�
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

const int NUM=10;
int pos[NUM];
int val[NUM];

//��ÿһ����,��Ȩ�����=(�˵����ĵ��λ�ú�-�˵�ǰ��ĵ�λ�õĺ�+ǰ�������*�˵�λ��)*Ȩֵ
//�ٶ�����ȨֵΪ��,��͵ĵط�������longlong,�����������

long long solve(int pos[],int val[],int sz)
{
	long long pre(0),post(0);
	for(int i=1;i<sz;++i)
		post += pos[i];

	int num_of_pre(0),num_of_post(sz-1);

	//��һ����
	long long result=(post-pre+(num_of_pre-num_of_post)*pos[0])*val[0]; 

	for(int j=1;j<sz;++j)
	{
		if(j==sz-1) //�������һ����
			post = 0;
		else
			post -= pos[j+1];

		pre += pos[j-1];

		++num_of_pre,--num_of_post; 

		long long tmp_res=(post-pre+(num_of_pre-num_of_post)*pos[j])*val[j];
		if(tmp_res < result)
			result = tmp_res;
	}

	return result;
}

#endif