#include "stdafx.h"
/************************************************************************/
/*编程解决三色旗问题，一个字符型数组color，其中每个元素值为'R'，'W'，'B'三
/*者之一（代表红、蓝、白三色）编程实现把数组中元素重新排列：所有蓝色在前，
/*白色其后，红色最后。例如：原数组RWRRWBBRWRWR，重排后，BBBWWWRRRRR。
/*
/*可转换为类似的一个问题，现有若干正数，负数，和若干个0，求排完序后负数在前
/*0在中间，正数在后面，要求不另外开辟空间
/************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

enum{
	BLUE='B',
	WHITE='W',
	RED='R'
};

template<class T>
inline void my_swap(T& f, T& e)
{
	cout<<f<<"<->"<<e<<endl;
	T tmp=f; f=e; e=tmp;
}

template<class T>
inline void out(const T& t)
{
	cout<<t<<" ";
}

//三色旗问题标准算法，复杂度O(n)
int OrderFlags(char flags[], int size)
{
	int bM, wM, rM;
	bM = wM = 0;
	rM= size - 1;

	int count=0;

	while(wM <= rM) //必须白色和红色标志重合
	{
		if(flags[wM] == WHITE)  //如果为白色，则白色标志后移
		{
			++ wM;
		}
		else if(flags[wM] == BLUE) //如果为蓝色，则跟第一个白色进行交换
		{
			swap(flags[wM],flags[bM]);
			++ count;
			++wM, ++bM; //白色和蓝色各增加一个
		}else{
			//如果是红色，则从尾部向前寻找第一个非红色的字符跟这个字符替换
			while(wM < rM && flags[rM] == RED) --rM; //前溯
			my_swap(flags[wM],flags[rM]); 
			++ count;

			--rM; //有一个红色归位了
		}
	}

	return count;
}

/************************************************************************/
/* 负数零和正数的规化问题,利用三色旗解法
/* 算法复杂度：最坏情况也只是扫描一遍，所以是O(n)
/************************************************************************/
int Partion_Numbers(int arrNum[], int size)
{
	int nPos,nNeg,nZero;
	nNeg=nZero=0;
	nPos = size - 1;
	int count=0;
	while(nZero <= nPos)
	{
		//for test
		for_each(arrNum,arrNum+size,out<int>);
		cout<<endl;
		if (arrNum[nZero] == 0) //如果是0，则0标志位++
		{
			++nZero;
		}else if (arrNum[nZero] < 0) //如果是负数，则需要跟零区的第一个0进行交换
		{
			if(nZero != nNeg)
			{	
				my_swap(arrNum[nZero],arrNum[nNeg]);
				++count;
			}
			++nZero;
			++nNeg;
		}else{ //是正数，则需要跟正数区搜索最后一个非正数进行交换
			while (nZero < nPos && arrNum[nPos] > 0 ) --nPos; //向前搜索
			my_swap(arrNum[nPos],arrNum[nZero]); //同零区的进行交换
			++count;
			--nPos; //交换完后，正数区又多了一个
		}
	}
	return count;
}

/************************************************************************/
/* 这里我用我面试的时候的想法，利用快排的partion来使有序，算法复杂度也应该是O(n) ??不确定
/************************************************************************/
int QuickSort_Partion_Numbers(int arrNum[],int size)
{
	int nLeft=0;
	int nRight=size-1;
	int count=0;
	while(nLeft < nRight)
	{
		//for test
		for_each(arrNum,arrNum+size,out<int>);
		cout<<endl;

		while(nLeft < nRight && arrNum[nLeft] < 0) ++nLeft;
		while(nLeft < nRight && arrNum[nRight] > 0) --nRight;
		if (arrNum[nLeft] && arrNum[nRight]) //两者均不为0，则交换
		{
			my_swap(arrNum[nLeft],arrNum[nRight]);
			++count;
			++nLeft,--nRight;
		}else if (arrNum[nLeft] == 0 ) //左边为0，则在右边往前寻找一个非0交换
		{
			int tLeft,tRight;
			tLeft=nLeft,tRight=nRight;
			while(tLeft < tRight && arrNum[tRight] == 0) --tRight;
			if(tLeft == tRight) return count;
			my_swap(arrNum[tLeft],arrNum[tRight]);
			++count;
		}else{ //左边不为0，右边为0的情况,从左边找一个非0的进行交换
			int tLeft,tRight;
			tLeft=nLeft,tRight=nRight;
			while(tLeft < tRight && arrNum[tLeft] == 0) ++tLeft;
			if(tLeft == tRight) return count;
			my_swap(arrNum[tLeft],arrNum[tRight]);
			++count;
		}
	}
	return count;
}




int _tmain(int argc, _TCHAR* argv[])
{
	char ctest[]="RWRRWBBRWRWR";
	int len=strlen(ctest);

	//要注意for_each是前闭后开
	for_each(ctest,ctest+len,out<char>);
	cout<<endl;
	cout<<"swap times:"<<OrderFlags(ctest,len)<<endl;
	for_each(ctest,ctest+len,out<char>);
	cout<<endl;

	int ntest[]={1,-2,0,0,4,-5,0,3,2,5,0};
	len=sizeof(ntest)/sizeof(int);
	for_each(ntest,ntest+len,out<int>);
	cout<<endl;
	cout<<"swap times:"<<Partion_Numbers(ntest,len)<<endl;
	cout<<"-----------------\n";
	int ntest2[]={1,-2,0,0,4,-5,0,3,2,5,0};
	len=sizeof(ntest2)/sizeof(int);
	cout<<"swap times:"<<QuickSort_Partion_Numbers(ntest2,len)<<endl;
	for_each(ntest2,ntest2+len,out<int>);
	cout<<endl;

	return 0;
}



