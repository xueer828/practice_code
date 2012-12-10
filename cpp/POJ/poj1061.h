#ifndef _TEST_
#define _TEST_

// poj1061
// Copyright (c) 2012/12/09 
// Author: xdutaotao (xdutaotao@gmail.com)
// ���ܵ�Լ�ᣬ��ֻ���ֱܷ�λ��x��y���괦��һֱ����һ����������A һ��m�ף�Bһ��n�ף�γ�����ܳ�L�ף����������κ�������棨ע�����������ͬһ���ϣ������������"Impossible"

//˼·��ò����ͬ�෽�����⣬���̣�(x+km)%L=(y+kn)%L (kΪ���Ĵ���) ��ô x+k*m �� y+k*n ͬ��L
//PS˼·��ͬ�෽�̵���չ����
//(x+k*m)-(y+k*n)=L*p (kΪ������pΪ�ܳ���������)������� (x-y)=(m-n)*k+L*p ����, x,y,m,n,L����֪
// ��k��pδ֪����Ҫ������⣬��ô�������̵����ʵ��������չŷ��������

/*o,�ðɣ���������������չŷ���������㷨������ŷ������㷨��շת��� [ gcd(a,b) = gcd(b,a%b) ]���Ͳ��������
��Ϊ a*x+b*y=c Ϊһ�����չŷ�������⣬(PS. ��չŷ����·��̵�һ����ʽ a*x+b*y=gcd(a,b) һ���н� )
�Է���ʽ�����߾�����gcd(a,b)�õ�
a'*x+b'y=c/gcd(a,b) ���֪��gcd(a,b)Ϊa��b�����Լ������ôa��b��Ȼ�ܱ�gcd(a,b)��������Ϊa'��b'
(1) ����a'��b'��������������c/gcd(a,b)����ͬΪ���������򲻿����н⣬�������c���ܱ�gcd(a,b)��������ô����Impossible
(2) ����ܹ���������ô�����a'*x+b'y=c/gcd(a,b)�ķ��̽�x��y֮������ͬ��gcd(a,b)���ɵõ�a*x+b*y=c��x��y�������
a*x+b*y=gcd(a,b) ==>> a*(c/gcd(a,b)*x')+b*(c/gcd(a,b)*y')=c ==>>
��ô�ɵ� c/gcd(a,b)*x' = x0, c/gcd(a,b)*y'=y0 (x0��y0Ϊa*x+b*y=gcd(a,b)�Ļ�����)
��������չŷ����·��̽�x'=x0*gcd(a,b)/c , y'=y0*gcd(a,b)/c
*/

/*
������������չŷ����·��̵Ľⷨ��a*x+b*y=gcd(a,b)Ϊ���̵�һ����ʽ����֤���˷���һ���н�
��Ϊgcd(a,b)=gcd(b,a%b) �� gcd(b,a%b)=b*x+(a%b)*y �� a%b = a-(a/b)*b (����a/b������ȡ������)
���У�b*x+(a-(a/b)*b)*y=b*x+a*y-(a/b)*b*y=a*y+b*(x-(a/b)*y)=gcd(a,b)
��ô�Աȿɷ��֣���x=y' y=x��-(a/b)*y�� �����ĵݹ���ʽ��
��a,b���ϵݹ�����룬��ŷ����¶������֪��ת��һ����ֹͣ��������gcd(a,0)�����(��ʱbΪ0),��ʱ�������յķ�����ʽ��a*x��+0*y��=gcd(a,0),���ʱ��Ļ�����Ϊx'=1,y'=0;(��ʵy'����Ϊ�κ������������ǻ�����)��Ȼ��ʼ����
���յõ�a*x+b*y=gcd(a,b)�Ļ�����x0,y0
*/

/*
More, ͬ�෽�� ax=b(mod c) ����ת��Ϊ ax - cy = b, (yΪ������) �� b|gcd(a,-c)�������,�н�,����������,���޽�
ģ���Է���ax��b(mod m)�Ĳ�������:
1) ��d=gcd(a,c) 2)��� b���ܱ�d����,���޽�,���� 3) ��� a*x0 + c*y0 = gcd(a,c) �Ļ�����x0��y0
4) ��ax + cy = b���ؽ� x=(b/gcd(a,c))*x0; y=(b/gcd(a,c))*y0; 
5) ��ô�ɴ˿ɵ����еĽ�ռ�: x = (x0*(b/gcd(a,c)) + i* (c/gcd(a,c))) (mod c) i=0,1,2....d-1, һ��d����
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

//��չŷ����·������ a*x+b*y=gcd(a,b)
//x=y' y=x'-(a/b)*y'  ����a/bΪȡ������
__int64 ext_gcd(__int64 a, __int64 b, __int64& x, __int64& y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a; //��������0��a
	}

	__int64 d = ext_gcd(b,a%b,x,y);
	__int64 tmp=x; //�ȱ�����һ�ε�����xֵ�����ں������yֵ
	x = y;	  // x'=y;
	y=tmp-a/b*x;   //y' = x - a/b * y;  ����x,yΪ��һ�ε����Ľ����x'��y'Ϊ���ν��
		
	return d;
}

void solve()
{
	int x,y,m,n,L;
	cin>>x>>y>>m>>n>>L;

	int d; //gcd

	if(m==n) //�ٶ�һ��,��Զ������
	{
		printf("Impossible\n");
		return;
	}

	//��ʽ x+m*k=y+n*k (mod L),�� (x-y) + (m-n)*k = p*L; 
	//(m-n)*k + p*L = (y-x) 

	__int64 tx,ty; //��׼ŷ����±�׼��

	d = ext_gcd(m-n,L,tx,ty);

	if((y-x)%d != 0)
		printf("Impossible\n");
	else{

		//����ؽ�,��������k��

		tx=(y-x)/d * tx;
		ty=(y-x)/d * ty;

		L=L /d; //��L�ֳ�d��

		if(tx > 0)
			tx %= L;
		else
			tx = tx%L + L;

		printf("%I64d\n",tx);

	}


}

#endif