// Shot.cpp : Defines the entry point for the console application.
//
//һ������˶�Ա���,��һ����10��,����10ǹ����90���Ŀ������ж�����
//
//�㷨���ݹ�

#include "stdafx.h"
#include "iostream"

using namespace std;

/************************************************************************/
/* times ��ʾ�ڼ��������lost��ʾ����һ�ε�������Ҫ��ʧ�Ļ���
/************************************************************************/
int shot(int times, int lost)
{
	//���ʣ��������ܻ����������ˣ�����0
	if(times*10 < lost)
		return 0;
	//������һ�λ��ߣ��Ժ�û��Ҫ���Ļ����ˣ�ֱ�ӷ���1
	if(times <= 1 || lost == 0)
		return 1;
	int sum=0;
	//���ڱ��Σ�ö�ٿ��Զ�ʧ�Ļ���
	for(int i=lost;i>=0;i--)
	{
		if(10-i <= 10)
			sum += shot(times-1,i);
	}
	return sum;
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<shot(2,9)<<endl;
	return 0;
}

