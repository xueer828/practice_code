// ACM_Entrance_WhiteBook_ch2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include "time.h"

using namespace std;

/************************************************************************/
/* ch2 �ڶ��� ѭ���ṹ�������
/************************************************************************/

//eg.2-1,��������aabb��4λ��ȫƽ��������ǰ��������ͬ�ͺ���������ͬ��ƽ����(7744����)
void eg_2_1_out_perfect_pow()
{
	int _min=sqrt(1000.0);
	int _max=sqrt(10000.0);
	for(;_min<_max;++_min)
	{
		int acc=_min*_min;
		if(acc < 1000) continue;
		if(acc/100/10 == acc/100%10 && acc%100/10 == acc%100%10)
			cout<<acc<<" ";
	}
	cout<<endl;
}

//eg.2_2,�����������1����Ȼ��n����nΪ��������n��Ϊ3n+1,�����Ϊn��һ�룬�������ɴα仯
//һ���Ὣn��Ϊ1������n������任������n<10^9
void eg_2_2_N_transfer(int num)
{
	//��Ϊ3*10^9�������������Ϊ3n+1��ż�������Կ��������3n+1��2 �����ɣ�
	int count=0;
	unsigned int n = num;
	while(n != 1)
	{
		if (n % 2 == 0)
		{
			n /= 2; 
			++count;
		} 
		else
		{
			n = (3*n +1 )/2;
			count += 2;
		}
	}
	cout<<count<<endl;
}

//eg.2-3, ����n,����S=1!+2!+...+n!��ĩ6λ������ǰ��0����n<=10^6. ��������10,�����37913
void eg_2_3_factorial(int n)
{
	int ret=1;
	int sum=ret;
	const int MOD=1000000;
	//�ڼ���׳�֮�����ֻ��������6λ����Ϊ����6λ��������Ӱ���6λ��ֵ
	for(int i=2;i<=n && i < 25;++i)
	{
		ret *= i;
		ret = ret < MOD? ret : ret%MOD;
		sum = sum+ret < MOD ? sum + ret : (sum + ret)%MOD;
	}

	//��ʵ��25��������6���㣬����n>25֮�󣬽���Ͳ����ٱ���

	cout<<sum<<endl;
	printf("%.3lf\n",(double)clock()/CLOCKS_PER_SEC);
}


int _tmain(int argc, _TCHAR* argv[])
{
	//eg_2_1_out_perfect_pow();
	//eg_2_2_N_transfer(987654321);
	eg_2_3_factorial(51200);
	return 0;
}

