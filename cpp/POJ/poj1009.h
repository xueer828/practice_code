#ifndef _TEST_
#define _TEST_

// poj1009
// Copyright (c) 2012/12/19 
// Author: xdutaotao (xdutaotao@gmail.com)
// Edge Detection �߽���,���ܱ���,�����ع�! 
//
// ʹ����γ�
//

//����:ֻ�迼��ԭͼ����ֵ�仯�ĵ㣬������ı����������ĵ���ͬ
//�Ա��뵥������ĵ�,����Ԥ�ȱ��,
// 1) ��ֵ�仯�ĸ�����Χ��8������,��Ҫ���¼���,ע��,����仯�ĸ��ӵĺ�һ�����Ӳ����Ƿ�����һ��,����Ҫ���¼�����


#include <cstdio>
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

//�����˼���ṹ
typedef struct check_point{
	int pos;
	unsigned char val;
	check_point():pos(-1),val(0){}
}CkPnt;

CkPnt ckpnt[9000];
int num_ckpnt=0;

int arr[1010][2];

void solve()
{
	int width;
	while(1)
	{
		cin>>width;
		if(width == 0)
			break;

		cout<<pairs;

		//input pairs
		int idx = 0;
		num_ckpnt = 0;
		while(1)
		{
			cin>>arr[idx][1]>>arr[idx][0];

			if(arr[idx][0]==0)
				break; //�������

			ckpnt[num_ckpnt].pos = arr[idx][0];





		}
	}
}

#endif