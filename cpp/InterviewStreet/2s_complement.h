#ifndef _TEST_
#define _TEST_

// 2s_complement
// Copyright (c) 2013/01/16 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*

https://www.hackerrank.com/challenges/2s-complement

my code: http://ideone.com/ryb9AE

One of the basics of Computer Science is knowing how numbers are represented in 2’s complement. Imagine that you write down all numbers between A and B inclusive in 2’s complement representation using 32 bits. How many 1’s will you write down in all ?

Input:
The first line contains the number of test cases T (<1000). Each of the next T lines contains two integers A and B.

Output:
Output T lines, one corresponding to each test case.

Constraints:
-2^31 <= A <= B <= 2^31 - 1

Sample Input:
3
-2 0
-3 4
-1 4

Sample Output:
63
99
37

Explanation:
For the first case, -2 contains 31 1’s followed by a 0, -1 contains 32 1’s and 0 contains 0 1’s. Thus the total is 63.
For the second case, the answer is 31 + 31 + 32 + 0 + 1 + 1 + 2 + 1 = 99
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

负数的特殊处理: 
我们知道一个负数的补码=abs(负数)取反,然后再加1,那么我们能够求出abs(负数)中1的个数,也就是说,abs(负数)取反之后,1的个数等于取反之前0的个数 (暂不考虑符号位)
|-X|补码 = |abs(-X)|反 + 1, 那么两边都减去1, 
的到|-X-1|补码 = |abs(-X)| 那么,-(X+1)的补码中1的个数,为abs(-X)对应的0的个数,那么可以用{31-abs(-X)中1的个数}即为要求的|-(X+1)|补码对应的1的个数
那么如果要求数-X-1的1的个数 即等于 {31-abs(-X)中1的个数 + 符号位1} = 32 - abs(-X)中1的个数
也就是说, -X的1的个数 = {32 - abs(-(X-1))的1的个数}

考虑到abs(-(X-1))中 X最小为1,那么 f[-X..-1] = 32*X - sum(abs(-(X-1)))

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
		return 1ULL + ((a-1)>>1) + ((get_1_sum_counts((a-1)>>1))<<1);
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
		if(b < -1) // here the max(b)=-2
			// here range = [a..(b+1)] b<-1
			//return ((32ULL*(-a) - get_1_sum_counts(-a-1) - (32ULL*(-(b+1)) - get_1_sum_counts(-(b+1)-1))
			//即为 return (32ULL*(b+1-a) + get_1_sum_counts(-(b+1)-1) - get_1_sum_counts(-a-1));
			return (32ULL*(b+1-a) + get_1_sum_counts(-(b+2)) - get_1_sum_counts(-(a+1)));
		else if(b==-1) //here b == -1, it's the start point
			return 32ULL*(-a)-get_1_sum_counts(-(a+1));
		else{ //b is non-negetive value
			return 32ULL*(-a)-get_1_sum_counts(-(a+1)) + get_1_sum_counts(b);
		}
	}
}

 
void solve()
{
	//ifstream cin("a.txt");
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