#ifndef _TEST_
#define _TEST_

// 20130124_Cicle_Pans_In_Well
// Copyright (c) 2013/01/25 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
考虑一个圆柱形的井，它从上到下每隔1米，半径会变化一次。（也就说说井的空间可以理解为高度为1的若干个圆柱堆叠而成）。假设井高n米（整数），从上到下的半径都给定。现在要往下逐个扔m个圆柱铁盘，铁盘的高度也是1米。当井内部的半径不小于（包括等于）铁盘的半径时，铁盘可以通过。每个铁盘或者被卡在井的某个高度上（或落到井地）或者落到上一次扔的铁盘上（无论半径大小都会被下面的挡住），问井中最多可以容纳多少个铁盘。
例如 给定井的高度是n = 7 从从上到下的半径分别为A[0..6] = {5，6，4，3，6，2，3}。给定圆盘m = 5, 半径分别为B[0..4] = {2，3，5，2，4}。则第一个圆盘可落到井底A[6]，第二个圆盘会落在A[4]处（因为A[5]半径比它小)，第三个圆盘落在A[1]处，第4个圆盘落在A[0]处。所以只能容纳4个圆盘。

输入:数组(或者vector)A B。
输出：一个int值表示能容纳圆盘个数。

不能变顺序 “逐个”
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

//思路:首先初始化数组cap[]用来表示井的每个位置能容纳的最大的圆盘半径
//然后,根据已经初始化的cap[],从cap[]尾,开始放圆盘,知道井满或者圆盘放完位置
int max_discs_into_well(int well[], int sz_well, int disc[], int sz_disc)
{
	if(sz_well <=0 || sz_disc <= 0)
		return 0;

	int cap=new int[sz_well];
	cap[0]=well[0];
	for(int i=1;i<sz_well;++i)
		cap[i]=cap[i-1] < well[i] ? cap[i-1]: well[i];

	int nWell=sz_well-1, nDisc=0;
	while(nWell >= 0 && nDisc < sz_disc)
	{
		if( disc[nDisc] <= cap[nWell] )
		{	//can put into
			++nDisc,--nWell;
		}else{
			//cannot
			--nWell;
		}
	}
	
	return nDisc;
}

void solve()
{

}

#endif