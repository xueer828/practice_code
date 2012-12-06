#ifndef _TEST_
#define _TEST_


/***********************************************************************
/*   Sliding Window     
/*   http://poj.org/problem?id=2823
/* 不大于10^6大小的数组，给定一个k大小的滑动窗口，从最左边到最右边，从窗口中仅仅能见到
/* k个数，每次移动一个位置。现在任务是求出每次滑动窗口中能够看到的最小和最大值
/************************************************************************/

//解决思路：单调队列，算法复杂度平均下来是O(n),空间O(n)

/************************************************************************/
/* 用cin、cout超时，换成scanf、printf AC                                                                     */
/************************************************************************/

#include <iostream>
using namespace std;

const int maxN=1000001;

int data[maxN];
//单调递减和单调递增队列,用来存放
int maxQ[maxN],minQ[maxN];
int xhead,xtail,nhead,ntail;

int len,k;

void solve()
{
	scanf("%d %d",&len,&k);
	
	for(int i=0;i<len;++i)
		scanf("%d",&data[i]);

	xhead=xtail=nhead=ntail=0;
	//处理单调递增队列，输出最小值
	for(int i=0;i<len;++i)
	{
		//移动队尾使得插入元素在队尾保存单调递增
		while(nhead <= ntail && data[i] <= data[minQ[ntail]] ) --ntail;
		
		//判断对头是否在[i-k-1,i]范围内
		while(nhead <= ntail && minQ[nhead] <= i-k) ++nhead;

		//此时可以在队尾插入新的元素了
		minQ[++ntail] = i; //插入的是数据的index

		//此时对头即为最小值
		if(i>=k-1)
			printf("%d ",data[minQ[nhead]]);
	}

	cout<<"\n"; 

	//处理单调递减队列，获取最大值
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