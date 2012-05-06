// Shot.cpp : Defines the entry point for the console application.
//
//一个射击运动员打靶,靶一共有10环,连开10枪打中90环的可能性有多少种
//
//算法：递归

#include "stdafx.h"
#include "iostream"

using namespace std;

/************************************************************************/
/* times 表示第几次射击，lost表示从这一次到后面需要丢失的环数
/************************************************************************/
int shot(int times, int lost)
{
	//如果剩余次数的总环数不够丢了，返回0
	if(times*10 < lost)
		return 0;
	//如果最后一次或者，以后没有要丢的环数了，直接返回1
	if(times <= 1 || lost == 0)
		return 1;
	int sum=0;
	//对于本次，枚举可以丢失的环数
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

