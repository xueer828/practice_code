#ifndef _TEST_
#define _TEST_


/***********************************************************************
/*   Sliding Window     
/*   http://poj.org/problem?id=2823
/* ������10^6��С�����飬����һ��k��С�Ļ������ڣ�������ߵ����ұߣ��Ӵ����н����ܼ���
/* k������ÿ���ƶ�һ��λ�á��������������ÿ�λ����������ܹ���������С�����ֵ
/************************************************************************/

//���˼·���������У��㷨���Ӷ�ƽ��������O(n),�ռ�O(n)

/************************************************************************/
/* ��cin��cout��ʱ������scanf��printf AC                                                                     */
/************************************************************************/

#include <iostream>
using namespace std;

const int maxN=1000001;

int data[maxN];
//�����ݼ��͵�����������,�������
int maxQ[maxN],minQ[maxN];
int xhead,xtail,nhead,ntail;

int len,k;

void solve()
{
	scanf("%d %d",&len,&k);
	
	for(int i=0;i<len;++i)
		scanf("%d",&data[i]);

	xhead=xtail=nhead=ntail=0;
	//�������������У������Сֵ
	for(int i=0;i<len;++i)
	{
		//�ƶ���βʹ�ò���Ԫ���ڶ�β���浥������
		while(nhead <= ntail && data[i] <= data[minQ[ntail]] ) --ntail;
		
		//�ж϶�ͷ�Ƿ���[i-k-1,i]��Χ��
		while(nhead <= ntail && minQ[nhead] <= i-k) ++nhead;

		//��ʱ�����ڶ�β�����µ�Ԫ����
		minQ[++ntail] = i; //����������ݵ�index

		//��ʱ��ͷ��Ϊ��Сֵ
		if(i>=k-1)
			printf("%d ",data[minQ[nhead]]);
	}

	cout<<"\n"; 

	//�������ݼ����У���ȡ���ֵ
	for(int i=0;i<len; ++i)
	{
		while(xhead <= xtail && data[i] >= data[maxQ[xtail]]) --xtail;
		while(xhead <= xtail && maxQ[xhead] <= i-k) ++xhead;
		maxQ[++xtail] = i;

		if(i>=k-1)
			printf("%d ",data[maxQ[xhead]]);
	}
	
	cout<<endl;
}

#endif