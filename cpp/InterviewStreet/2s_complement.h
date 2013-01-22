#ifndef _TEST_
#define _TEST_

// 2s_complement
// Copyright (c) 2013/01/16 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
https://www.interviewstreet.com/challenges/dashboard/#problem/4e91289c38bfd
*/

//˼·, ���nΪ����,�����ƶϳ�(0..n)��1�ĸ���
//���nΪ����,(-n) = ~(x) + 1, 

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

/*˼·:
�Ƶ�:��һ����N�Ķ����Ʊ�ʾ��1�ĸ���Ϊf(N),
��ôf(N)=(N&1)+f(N/2), �Դ�����,f(N-1)=((N-1)&1)+f((N-1)/2) ...
... f(3)=1+f(3/2)=1+f(1), f(2)=0+f(2/2)=0+f(1),
f(1)=1+f(1/2)=1+f(0),f(0)=0+f(0/2)=0+f(0)
��ô����ߵļ���������[0..N]�������Ķ�������1����Ŀ,��ΪS(N)=sum(f(i)) i=0..N
�ұ߼�����,�и�����
���NΪ����,��ôS(N)=1+0+1+0..+1+0 + f(N/2)+f((N-1)/2)+f((N-2)/2) + ... +f(1)+f(0)
��ΪNΪ����,N/2 == (N-1)/2, ��ô��ʽS(N)=1+(N-1)/2 + 2*(f(N-1)/2)+f(N-3)/2+...+f(1)+f(0))
ע��N-1,N-3,N-5Ϊż��,��Ȼ���Ա�2����,
���� S(N)=1+(N-1)/2 + 2*(f((N-1)/2) + f((N-1)/2 - 1) + f((N-1)/2 -2) + .. f(1) +f (0)
= 1 + (N-1)/2 + 2*S((N-1)/2) 
ͬ�����NΪż��,S(N)=f(N)+S(N-1), ��Ϊ�����Ѿ��Ƶ���S(N-1)������ʽ,���ǿ���ֱ������

������������P����Q��1�ĸ���,����ֱ����S(Q)-S(P-1)�Ӷ��ó����

���������⴦��: 
����֪��һ�������Ĳ���=abs(����)ȡ��,Ȼ���ټ�1,��ô�����ܹ����abs(����)��1�ĸ���,Ҳ����˵,abs(����)ȡ��֮��,1�ĸ�������ȡ��֮ǰ0�ĸ��� (�ݲ����Ƿ���λ)
|-X|���� = |abs(-X)|�� + 1, ��ô���߶���ȥ1, 
�ĵ�|-X-1|���� = |abs(-X)| ��ô,-(X+1)�Ĳ�����1�ĸ���,Ϊabs(-X)��Ӧ��0�ĸ���,��ô������{31-abs(-X)��1�ĸ���}��ΪҪ���|-(X+1)|�����Ӧ��1�ĸ���
��ô���Ҫ����-X-1��1�ĸ��� ������ {31-abs(-X)��1�ĸ��� + ����λ1} = 32 - abs(-X)��1�ĸ���
Ҳ����˵, -X��1�ĸ��� = {32 - abs(-(X-1))��1�ĸ���}

���ǵ�abs(-(X-1))�� X��СΪ1,��ô f[-X..-1] = 32*X - sum(abs(-(X-1)))

*/

//------------------------------------------/
//��ĳ������1�ĸ���,�汾1,���Ӷ�������1�ĸ���
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

//�汾2, �۵�,���ַ�,����λ��ӣ��ظ�������̣�ֱ��ֻʣ��һλ
int get_1count2(int n)
{
	//��һ����(0101 0101 0101...)2 ��ʽ,������λ��ż��λ���ӵ�����λ��
	n = (n&0x55555555) + ((n>>1)&0x55555555);
	//�ڶ�������λ��λһ����� (0011 0011 0011 0011 ... )2 ��ʽ,���ͼӵ��ʹ�����λ��
	n =(n&0x33333333) + ((n>>2)&0x33333333);
	//����������λ��λһ����� (0000 1111 0000 1111 0000 ..)2 ��ʽ,���ͷŵ���4Ϊ��
	n=(n&0x0f0f0f0f) + ((n>>4)&0x0f0f0f0f);
	//���Ĵΰ�λ��λһ����� (0000 0000 1111 1111 0000 ... )2 ��ʽ, ���ͷŵ���8λ��
	n=(n&0x00ff00ff) + ((n>>8)&0x00ff00ff);
	//�����,16λ16λ����,���ͷŵ���͵�16λ��
	n=(n&0x0000ffff) + ((n>>16)&0x0000ffff);
	return n;
}

//�汾3, ��̬���,���������ٶ����,�������㷨�Ƚ�����
int get_1count3(int n)
{
	int tab256[256]={0};
	for(int i=0;i<=255;++i)
	{
		tab256[i]=(n&1) + tab256[(n>>1)];
		//���߿���дΪ
		//tab256[i]=(n&1) + tab[n/2];
		//����,n&1���ǿ����λ�Ƿ�Ϊ1,Ҳ����˵���
		//�������ż��,��ô1�ĸ����������λ�Ƶ��������1�ĸ���һ��
		//�����ż��,��ô�����Ƶ��������1�ĸ���+1
	}

	unsigned char* t=(unsigned char*) &n;
	return (tab256[t[0]]+tab256[t[1]],tab256[t[2]],tab256[t[3]]);
}

//�汾4,��̬��,ʵ���Ͼ��ǰ�����tab256�Ķ�̬��,��̬��,����ֻ��Ҫ��ѯ����

//------------------------------------------/

//������a��f(a)
unsigned long long get_1_sum_counts(int a)
{
	if(a==0)
		return 0;
	if(a&1) //aΪ����
		return 1ULL + ((a-1)>>1) + ((get_1_sum_counts((a-1)>>1))<<1);
	else //aΪż��
		return get_1count1(a) + get_1_sum_counts(a-1);
}

//�� a~b���� ��1�ĸ���
unsigned long long get_1counts_range(int a, int b)
{
	if(a>0) //a �����Ǵ���0 ������sum(n-1)
	{
		return get_1_sum_counts(b)-get_1_sum_counts(a-1);
	}else if(a==0)
		return get_1_sum_counts(b);
	else{ //���a�Ǹ���,��Ҫ��b��������������ж�
		if(b < -1) // here the max(b)=-2
			// here range = [a..(b+1)] b<-1
			//return ((32ULL*(-a) - get_1_sum_counts(-a-1) - (32ULL*(-(b+1)) - get_1_sum_counts(-(b+1)-1))
			//��Ϊ return (32ULL*(b+1-a) + get_1_sum_counts(-(b+1)-1) - get_1_sum_counts(-a-1));
			return (32ULL*(b+1-a) + get_1_sum_counts(-(b+2)) - get_1_sum_counts(-(a+1)));
		else if(b==-1) //here b == -1, it's the start point
			return 32ULL*(-a)-get_1_sum_counts(-a-1);
		else{ //b is non-negetive value
			return 32ULL*(-a)-get_1_sum_counts(-a-1) + get_1_sum_counts(b);
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