#ifndef _TEST_
#define _TEST_

// poj1061
// Copyright (c) 2012/12/09 
// Author: xdutaotao (xdutaotao@gmail.com)
// 青蛙的约会，两只青蛙分别位于x和y座标处，一直朝着一个方向跳，A 一次m米，B一次n米，纬度线总长L米，求跳出几次后才能碰面（注意必须是跳到同一点上），不可能输出"Impossible"

//思路，貌似是同余方程问题，方程：(x+km)%L=(y+kn)%L (k为跳的次数) 那么 x+k*m 和 y+k*n 同余L
//PS思路：同余方程的扩展问题
//(x+k*m)-(y+k*n)=L*p (k为步数，p为周长的整数倍)，整理得 (x-y)=(m-n)*k+L*p 这里, x,y,m,n,L均已知
// 而k和p未知，需要进行求解，那么整个方程的求解实际上是扩展欧几里德求解

/*o,好吧，继续巴拉巴拉扩展欧几里德求解算法，对于欧几里德算法的辗转相除 [ gcd(a,b) = gcd(b,a%b) ]，就不多介绍了
形为 a*x+b*y=c 为一般的扩展欧几里德求解，(PS. 扩展欧几里德方程的一般形式 a*x+b*y=gcd(a,b) 一定有解 )
对方程式的两边均除以gcd(a,b)得到
a'*x+b'y=c/gcd(a,b) 大家知道gcd(a,b)为a和b的最大公约数，那么a，b必然能被gcd(a,b)整除，设为a'和b'
(1) 这里a'和b'都是整数，所以c/gcd(a,b)必须同为整数，否则不可能有解，所以如果c不能被gcd(a,b)整除，那么就是Impossible
(2) 如果能够整除，那么在求得a'*x+b'y=c/gcd(a,b)的方程解x和y之后，两边同乘gcd(a,b)即可得到a*x+b*y=c的x和y的求解了
a*x+b*y=gcd(a,b) ==>> a*(c/gcd(a,b)*x')+b*(c/gcd(a,b)*y')=c ==>>
那么可得 c/gcd(a,b)*x' = x0, c/gcd(a,b)*y'=y0 (x0和y0为a*x+b*y=gcd(a,b)的基本解)
这线性扩展欧几里德方程解x'=x0*gcd(a,b)/c , y'=y0*gcd(a,b)/c
*/

/*
继续吧啦下扩展欧几里德方程的解法，a*x+b*y=gcd(a,b)为方程的一般形式，可证明此方程一定有解
因为gcd(a,b)=gcd(b,a%b) 而 gcd(b,a%b)=b*x+(a%b)*y 而 a%b = a-(a/b)*b (这里a/b是向下取整除法)
则有，b*x+(a-(a/b)*b)*y=b*x+a*y-(a/b)*b*y=a*y+b*(x-(a/b)*y)=gcd(a,b)
那么对比可发现，解x=y' y=x‘-(a/b)*y’ 的求解的递归形式了
在a,b不断递归的深入，由欧几里德定理可以知道转换一定会停止，收敛到gcd(a,0)的情况(此时b为0),此时，这最终的方程形式是a*x‘+0*y‘=gcd(a,0),这个时候的基本解为x'=1,y'=0;(其实y'可以为任何数，这里这是基本解)，然后开始回溯
最终得到a*x+b*y=gcd(a,b)的基本解x0,y0
*/

/*
More, 同余方程 ax=b(mod c) 可以转换为 ax - cy = b, (y为整数倍) 在 b|gcd(a,-c)的情况下,有解,否则不能整除,则无解
模线性方程ax≡b(mod m)的步骤如下:
1) 求d=gcd(a,c) 2)如果 b不能被d整除,则无解,否则 3) 求解 a*x0 + c*y0 = gcd(a,c) 的基本解x0和y0
4) 则ax + cy = b的特解 x=(b/gcd(a,c))*x0; y=(b/gcd(a,c))*y0; 
5) 那么由此可得所有的解空间: x = (x0*(b/gcd(a,c)) + i* (c/gcd(a,c))) (mod c) i=0,1,2....d-1, 一共d个解
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

//扩展欧几里德方程求解 a*x+b*y=gcd(a,b)
//x=y' y=x'-(a/b)*y'  这里a/b为取下整除
__int64 ext_gcd(__int64 a, __int64 b, __int64& x, __int64& y)
{
	if(b==0)
	{
		x=1;
		y=0;
		return a; //返回最后非0的a
	}

	__int64 d = ext_gcd(b,a%b,x,y);
	__int64 tmp=x; //先保存上一次迭代的x值，用于后面计算y值
	x = y;	  // x'=y;
	y=tmp-a/b*x;   //y' = x - a/b * y;  这里x,y为上一次迭代的结果，x'，y'为本次结果
		
	return d;
}

void solve()
{
	int x,y,m,n,L;
	cin>>x>>y>>m>>n>>L;

	int d; //gcd

	if(m==n) //速度一样,永远不可能
	{
		printf("Impossible\n");
		return;
	}

	//公式 x+m*k=y+n*k (mod L),则 (x-y) + (m-n)*k = p*L; 
	//(m-n)*k + p*L = (y-x) 

	__int64 tx,ty; //标准欧几里德标准解

	d = ext_gcd(m-n,L,tx,ty);

	if((y-x)%d != 0)
		printf("Impossible\n");
	else{

		//获得特解,步数就是k步

		tx=(y-x)/d * tx;
		ty=(y-x)/d * ty;

		L=L /d; //将L分成d份

		if(tx > 0)
			tx %= L;
		else
			tx = tx%L + L;

		printf("%I64d\n",tx);

	}


}

#endif