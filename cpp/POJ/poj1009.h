#ifndef _TEST_
#define _TEST_

// poj1009
// Copyright (c) 2012/12/19 
// Author: xdutaotao (xdutaotao@gmail.com)
// Edge Detection 边界检测,不能暴力,暴力必挂! 
//
// 痛苦的游程
//

//方法:只需考虑原图中数值变化的点，其他点的编码与其左侧的点相同
//对必须单独计算的点,进行预先标记,
// 1) 数值变化的格子周围的8个格子,都要重新计算,注意,这个变化的格子的后一个格子不论是否另起一行,均需要重新计算结果


#include <cstdio>
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

//定义了检查点结构
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
				break; //完成输入

			ckpnt[num_ckpnt].pos = arr[idx][0];





		}
	}
}

#endif