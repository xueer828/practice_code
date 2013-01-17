#ifndef _TEST_
#define _TEST_

// 2s_complement
// Copyright (c) 2013/01/16 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
https://www.interviewstreet.com/challenges/dashboard/#problem/4e91289c38bfd
*/

//思路, 如果n为正数,可以推断出(0..n)的1的个数
//如果n为负数,(-n) = ~(x) + 1, 

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <cstdlib>
using namespace std;

/*思路:
推导:令一个数N的二进制表示中1的个数为f(N),
那么f(N)=(N&1)+f(N/2), 以此类推,f(N-1)=((N-1)&1)+f((N-1)/2) ...
... f(3)=1+f(3/2)=1+f(1), f(2)=0+f(2/2)=0+f(1),
f(1)=1+f(1/2)=1+f(0),f(0)=0+f(0/2)=0+f(0)
那么把左边的加起来就是[0..N]所有数的二进制中1的数目,记为S(N)=sum(f(i)) i=0..N
右边加起来,有个规律
如果N为奇数,那么S(N)=1+0+1+0..+1+0 + f(N/2)+f((N-1)/2)+f((N-2)/2) + ... +f(1)+f(0)
因为N为奇数,N/2 == (N-1)/2, 那么上式S(N)=1+(N-1)/2 + 2*(f(N-1)/2)+f(N-3)/2+...+f(1)+f(0))
注意N-1,N-3,N-5为偶数,必然可以被2整除,
所以 S(N)=1+(N-1)/2 + 2*(f((N-1)/2) + f((N-1)/2 - 1) + f((N-1)/2 -2) + .. f(1) +f (0)
= 1 + (N-1)/2 + 2*S((N-1)/2) 
同理如果N为偶数,S(N)=f(N)+S(N-1), 因为上面已经推导出S(N-1)奇数公式,我们可以直接利用

本题求解的是数P到数Q的1的个数,可以直接用S(Q)-S(P-1)从而得出结果

负数的特殊处理: 我们知道对应的 数值的正数的表达式 (-X)10 = (二进制数值部分)2 取反 然后加1, 
这里要求 (二进制数值部分)2 中1的个数
那么可以知道 (二进制数值部分)2 = ~( ((-X)10 -1 ) ) = 十进制的正数部分 减 1 然后取反 
进而,可以知道, 负数的f(N)=为其中(abs(N)-1)的0的个数+符号位1=(-N-1)的0的个数+1
那么Sum(N)=sum(f(N)+f(N+1)+f(N+2)+...f(-1))=(31-f(-N-1)+1 + 31-f(-N-2)+1 ... + 31-f(0)+1)
=(32-f(-N-1)+32-f(-N-2)+...+32+f(0))
=(32*(-N)-S(-N-1)) 注意这里N为负数,那么-N则为正数

*/

//------------------------------------------/
//求某个数中1的个数,版本1,复杂度依赖于1的个数
int get_1count1(int n)
{
	int cnt=0;
	while(n)
	{
		n=n & (n-1);
		++cnt;
	}
	return cnt;
}

//版本2, 折叠,二分法,相邻位相加，重复这个过程，直到只剩下一位
int get_1count2(int n)
{
	//第一次是(0101 0101 0101...)2 格式,将奇数位和偶数位叠加到奇数位上
	n = (n&0x55555555) + ((n>>1)&0x55555555);
	//第二次是两位两位一起叠加 (0011 0011 0011 0011 ... )2 格式,将和加到低处的两位上
	n =(n&0x33333333) + ((n>>2)&0x33333333);
	//第三次是四位四位一起叠加 (0000 1111 0000 1111 0000 ..)2 格式,将和放到低4为上
	n=(n&0x0f0f0f0f) + ((n>>4)&0x0f0f0f0f);
	//第四次八位八位一起叠加 (0000 0000 1111 1111 0000 ... )2 格式, 将和放到低8位上
	n=(n&0x00ff00ff) + ((n>>8)&0x00ff00ff);
	//第五次,16位16位叠加,将和放到最低的16位上
	n=(n&0x0000ffff) + ((n>>16)&0x0000ffff);
	return n;
}

//版本3, 动态查表法,大量数据速度最快,构造表的算法比较巧妙
int get_1count3(int n)
{
	int tab256[256]={0};
	for(int i=0;i<=255;++i)
	{
		tab256[i]=(n&1) + tab256[(n>>1)];
		//或者可以写为
		//tab256[i]=(n&1) + tab[n/2];
		//这里,n&1就是看最低位是否为1,也就是说如果
		//这个数是偶数,那么1的个数跟把最低位移调后的数的1的个数一致
		//如果是偶数,那么就是移掉后的数的1的个数+1
	}

	unsigned char* t=(unsigned char*) &n;
	return (tab256[t[0]]+tab256[t[1]],tab256[t[2]],tab256[t[3]]);
}

//版本4,静态表,实际上就是把上面tab256的动态表,静态化,这样只需要查询即可

//------------------------------------------/

//求正数a的f(a)
unsigned long long get_1_sum_counts(int a)
{
	if(a==0)
		return 0;
	if(a&1) //a为奇数
		return 1 + ((a-1)>>1) + ((get_1_sum_counts((a-1)>>1))<<1);
	else //a为偶数
		return get_1count1(a) + get_1_sum_counts(a-1);
}

//求 a~b区间 内1的个数
unsigned long long get_1counts_range(int a, int b)
{
	if(a>0) //a 必须是大于0 才能求sum(n-1)
	{
		return get_1_sum_counts(b)-get_1_sum_counts(a-1);
	}else if(a==0)
		return get_1_sum_counts(b);
	else{ //如果a是负数,还要对b分正负数情况来判断
		if(b < -1)
			//return ((32ULL*(-a) - get_1_sum_counts(-a-1) - (32ULL*(-b-1) + get_1_sum_counts(-b-1-1))
			return (32ULL*(b-1-a) + get_1_sum_counts(-b) - get_1_sum_counts(-a-1));
		else if(b==-1)
			return 32ULL*(-a)-get_1_sum_counts(-a-1);
		else{ //b为正数
			return 32ULL*(-a)-get_1_sum_counts(-a-1) + get_1_sum_counts(b);
		}
	}
}

 
void solve()
{
	ifstream cin("a.txt");
	int runs;
	cin>>runs;
	while(runs--)
	{
		int a,b;
		cin>>a>>b;
		cout<<get_1counts_range(a,b)<<endl;
	}
}

#endif