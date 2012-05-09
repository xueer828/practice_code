// ACM_Entrance_WhiteBook_ch2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include "time.h"

using namespace std;

/************************************************************************/
/* ch2 第二章 循环结构程序设计
/************************************************************************/

//eg.2-1,计算形如aabb的4位完全平方数，即前两个数相同和后两个数相同的平方数(7744问题)
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

//eg.2_2,对于任意大于1的自然数n，若n为奇数，则将n变为3n+1,否则变为n的一半，经过若干次变化
//一定会将n变为1，输入n，输出变换次数，n<10^9
void eg_2_2_N_transfer(int num)
{
	//因为3*10^9会溢出，但是因为3n+1是偶数，所以可以立马对3n+1除2 （技巧）
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

//eg.2-3, 输入n,计算S=1!+2!+...+n!的末6位（不含前导0），n<=10^6. 例如输入10,则输出37913
void eg_2_3_factorial(int n)
{
	int ret=1;
	int sum=ret;
	const int MOD=1000000;
	//在计算阶乘之后，最多只保留最后的6位，因为大于6位的数不会影响低6位的值
	for(int i=2;i<=n && i < 25;++i)
	{
		ret *= i;
		ret = ret < MOD? ret : ret%MOD;
		sum = sum+ret < MOD ? sum + ret : (sum + ret)%MOD;
	}

	//其实，25！最后会有6个零，所以n>25之后，结果就不会再变了

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

