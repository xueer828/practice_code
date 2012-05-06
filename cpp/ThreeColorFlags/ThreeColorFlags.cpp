#include "stdafx.h"
/************************************************************************/
/*��̽����ɫ�����⣬һ���ַ�������color������ÿ��Ԫ��ֵΪ'R'��'W'��'B'��
/*��֮һ������졢��������ɫ�����ʵ�ְ�������Ԫ���������У�������ɫ��ǰ��
/*��ɫ��󣬺�ɫ������磺ԭ����RWRRWBBRWRWR�����ź�BBBWWWRRRRR��
/*
/*��ת��Ϊ���Ƶ�һ�����⣬�������������������������ɸ�0���������������ǰ
/*0���м䣬�����ں��棬Ҫ�����⿪�ٿռ�
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

//��ɫ�������׼�㷨�����Ӷ�O(n)
int OrderFlags(char flags[], int size)
{
	int bM, wM, rM;
	bM = wM = 0;
	rM= size - 1;

	int count=0;

	while(wM <= rM) //�����ɫ�ͺ�ɫ��־�غ�
	{
		if(flags[wM] == WHITE)  //���Ϊ��ɫ�����ɫ��־����
		{
			++ wM;
		}
		else if(flags[wM] == BLUE) //���Ϊ��ɫ�������һ����ɫ���н���
		{
			swap(flags[wM],flags[bM]);
			++ count;
			++wM, ++bM; //��ɫ����ɫ������һ��
		}else{
			//����Ǻ�ɫ�����β����ǰѰ�ҵ�һ���Ǻ�ɫ���ַ�������ַ��滻
			while(wM < rM && flags[rM] == RED) --rM; //ǰ��
			my_swap(flags[wM],flags[rM]); 
			++ count;

			--rM; //��һ����ɫ��λ��
		}
	}

	return count;
}

/************************************************************************/
/* ������������Ĺ滯����,������ɫ��ⷨ
/* �㷨���Ӷȣ�����Ҳֻ��ɨ��һ�飬������O(n)
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
		if (arrNum[nZero] == 0) //�����0����0��־λ++
		{
			++nZero;
		}else if (arrNum[nZero] < 0) //����Ǹ���������Ҫ�������ĵ�һ��0���н���
		{
			if(nZero != nNeg)
			{	
				my_swap(arrNum[nZero],arrNum[nNeg]);
				++count;
			}
			++nZero;
			++nNeg;
		}else{ //������������Ҫ���������������һ�����������н���
			while (nZero < nPos && arrNum[nPos] > 0 ) --nPos; //��ǰ����
			my_swap(arrNum[nPos],arrNum[nZero]); //ͬ�����Ľ��н���
			++count;
			--nPos; //��������������ֶ���һ��
		}
	}
	return count;
}

/************************************************************************/
/* �������������Ե�ʱ����뷨�����ÿ��ŵ�partion��ʹ�����㷨���Ӷ�ҲӦ����O(n) ??��ȷ��
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
		if (arrNum[nLeft] && arrNum[nRight]) //���߾���Ϊ0���򽻻�
		{
			my_swap(arrNum[nLeft],arrNum[nRight]);
			++count;
			++nLeft,--nRight;
		}else if (arrNum[nLeft] == 0 ) //���Ϊ0�������ұ���ǰѰ��һ����0����
		{
			int tLeft,tRight;
			tLeft=nLeft,tRight=nRight;
			while(tLeft < tRight && arrNum[tRight] == 0) --tRight;
			if(tLeft == tRight) return count;
			my_swap(arrNum[tLeft],arrNum[tRight]);
			++count;
		}else{ //��߲�Ϊ0���ұ�Ϊ0�����,�������һ����0�Ľ��н���
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

	//Ҫע��for_each��ǰ�պ�
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



