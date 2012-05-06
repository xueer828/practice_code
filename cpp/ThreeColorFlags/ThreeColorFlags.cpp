#include "stdafx.h"
/************************************************************************/
/*编程解决三色旗问题，一个字符型数组color，其中每个元素值为'R'，'W'，'B'三
/*者之一（代表红、蓝、白三色）编程实现把数组中元素重新排列：所有蓝色在前，
/*白色其后，红色最后。例如：原数组RWRRWBBRWRWR，重排后，BBBWWWRRRRR。
/************************************************************************/

#include <iostream>
using namespace std;

enum{
	BLUE='B',
	WHITE='W',
	RED='R'
};

inline void swap(char& f, char& e)
{
	char tmp=f;	f=e; e=tmp;
}

//三色旗问题标准算法
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
			swap(flags[wM],flags[rM]); 
			++ count;

			--rM; //有一个红色归位了
		}
	}

	return count;
}



int _tmain(int argc, _TCHAR* argv[])
{
	char test[]="RWRRWBBRWRWR";
	int len=strlen(test);
	cout<<test<<" "<<len<<endl;
	cout<<OrderFlags(test,len)<<endl;
	cout<<test<<endl;
	return 0;
}



