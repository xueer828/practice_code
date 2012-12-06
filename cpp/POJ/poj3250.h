#ifndef _TEST_
#define _TEST_
/************************************************************************/
/* poj 3250 Bad Hair Day
/* 大致题意：一群牛站一排，有高有低，都面向一个方向，假设东边，那么高的牛能看到东边所有比
它低的牛的头直到有头牛比它自己高，现在求，所有能被看到头顶的数量的集合
输入：1>牛的数量，2>顺次每头牛的高度，输出：sum(c1到cN看到的牛的头顶的数量)
/************************************************************************/

//思路1：逆序对，所有逆序对的数量即为所求
//思路2：单调递减队列

#include "stdio.h"
#include "stdlib.h"

//解决思路：每加入一头牛，维护当前的单调递减队列，将每次维护好的数量相加

const int maxN=80010;
int data[maxN];

struct SQ{
	int pos;
	int val;
	SQ(int p, int h):pos(p),val(h){};
	SQ():pos(0),val(0){};
}sq[maxN];



void solve()
{
	int N,idx(0);
	scanf("%d",&N);
	while(idx < N)
	{
		scanf("%d",&data[idx]);
		++idx;
	}

	int front(0),rear(0);
	unsigned long count(0);

	for(int i=0;i<N;++i)
	{
		//处理尾部,这里注意原题意中如果两头牛有相同高度，则看不见，所以相等的情况应该剔除
		while(front <= rear && data[i] >= sq[rear].val) --rear;

		//在尾部加入新元素
		sq[++rear]=SQ(i,data[i]);

		//因为没有滑动窗口，不用清理头

		//此时队列肯定不为空
		count += rear - front; //能够看到的牛头发的和
	}

	printf("%u",count);
}



#endif

