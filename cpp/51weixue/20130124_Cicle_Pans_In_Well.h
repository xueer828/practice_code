#ifndef _TEST_
#define _TEST_

// 20130124_Cicle_Pans_In_Well
// Copyright (c) 2013/01/25 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
����һ��Բ���εľ��������ϵ���ÿ��1�ף��뾶��仯һ�Ρ���Ҳ��˵˵���Ŀռ�������Ϊ�߶�Ϊ1�����ɸ�Բ���ѵ����ɣ������辮��n�ף������������ϵ��µİ뾶������������Ҫ���������m��Բ�����̣����̵ĸ߶�Ҳ��1�ס������ڲ��İ뾶��С�ڣ��������ڣ����̵İ뾶ʱ�����̿���ͨ����ÿ�����̻��߱����ھ���ĳ���߶��ϣ����䵽���أ������䵽��һ���ӵ������ϣ����۰뾶��С���ᱻ����ĵ�ס�����ʾ������������ɶ��ٸ����̡�
���� �������ĸ߶���n = 7 �Ӵ��ϵ��µİ뾶�ֱ�ΪA[0..6] = {5��6��4��3��6��2��3}������Բ��m = 5, �뾶�ֱ�ΪB[0..4] = {2��3��5��2��4}�����һ��Բ�̿��䵽����A[6]���ڶ���Բ�̻�����A[4]������ΪA[5]�뾶����С)��������Բ������A[1]������4��Բ������A[0]��������ֻ������4��Բ�̡�

����:����(����vector)A B��
�����һ��intֵ��ʾ������Բ�̸�����

���ܱ�˳�� �������
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

//˼·:���ȳ�ʼ������cap[]������ʾ����ÿ��λ�������ɵ�����Բ�̰뾶
//Ȼ��,�����Ѿ���ʼ����cap[],��cap[]β,��ʼ��Բ��,֪����������Բ�̷���λ��
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