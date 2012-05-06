#include "stdafx.h"
/************************************************************************/
/*��̽����ɫ�����⣬һ���ַ�������color������ÿ��Ԫ��ֵΪ'R'��'W'��'B'��
/*��֮һ������졢��������ɫ�����ʵ�ְ�������Ԫ���������У�������ɫ��ǰ��
/*��ɫ��󣬺�ɫ������磺ԭ����RWRRWBBRWRWR�����ź�BBBWWWRRRRR��
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

//��ɫ�������׼�㷨
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
			swap(flags[wM],flags[rM]); 
			++ count;

			--rM; //��һ����ɫ��λ��
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



