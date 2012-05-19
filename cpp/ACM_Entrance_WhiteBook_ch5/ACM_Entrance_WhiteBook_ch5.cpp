// ACM_Entrance_WhiteBook_ch5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/************************************************************************/
/* ch 5 基础题目选解
/************************************************************************/

#include <iostream>
#include <cassert>
#include <string>

using namespace std;

//eg.5_2_2 计算阶乘的精确值，n不超过1000，因为1000！~= 4*10^2567，所以用3000数组来表示阶乘值

const int MLen=3001;
void eg_5_2_2_get_fanci(int n)
{
	int num[MLen]={0};
	num[0]=1;
	int cur_m=1;
	for(int i=2;i<=n;i++)
	{
		//高精度计算
		//第一步，每一位分布计算
		for(int j=0;j<MLen;++j)
		{
			if(j>0)
			{
				num[j] = i*num[j] + num[j-1]/10; //进位处理
				num[j-1] = num[j-1]%10;
			}else
				num[j] *= i;
		}
	}

	//反转输出
	bool flag=false;
	for(int j=MLen-1;j>=0;--j)
		if (num[j]!=0 || flag)
		{
			cout<<num[j];
			flag = true;
		}
	
	cout<<endl;
}

//eg.5.2.3，高精度计算类
struct BigN 
{
	//构造函数
	BigN():len(0),neg(false){memset(s,0,sizeof(int)*maxn);};
	BigN(int n)
	{
		*this = n;
	}
	BigN(const char* str)
	{
		*this = str; //调用下面赋值函数
	}

	//析构函数
	~BigN(){}

	//拷贝构造函数
	BigN(const BigN& b)
	{
		len=b.len;
		neg=b.neg;
		memset(s,0,maxn*sizeof(int)); 
		memcpy(s,b.s,sizeof(int)*(len+1));
	}

	//赋值函数
	BigN operator=(const BigN& b)
	{
		if(this == &b) return *this;
		len=b.len;
		neg=b.neg;
		memset(s,0,maxn*sizeof(int)); 
		memcpy(s,b.s,sizeof(int)*(len+1));
		return *this;
	}

	BigN operator=(int n)
	{
		if (n < 0) { neg = true; n = -n; }
		else {neg = false;}
		len = 0;
		//memset一般只对char字符数组操作，不过这里reset成0，可以用在任何内存
		memset(s,0,maxn*sizeof(int)); 
		while(n>0)
		{
			s[len++] = n%10;
			n /= 10;
		}

		return *this;
	}

	BigN operator=(const char* str)
	{
		//memset一般只对char字符数组操作，不过这里reset成0，可以用在任何内存
		memset(s,0,maxn*sizeof(int));
		len = strlen(str);
		if (str[0] == '-')
		{
			neg = true;
			len -= 1;
			for(int i=0;i<len;++i) //必须反过来用
				s[i]=str[len-i]-'0';

		}else{
			neg = false;
			for(int i=0;i<len;++i) //必须反过来用
				s[i]=str[len-i-1]-'0';
		}
		return *this;
	}	

	// +
	friend BigN operator+(const BigN& a1, const BigN& a2);
	friend BigN operator-(const BigN& a1, const BigN& a2);
	friend BigN operator*(const BigN& a1, const BigN& a2);
	friend BigN operator/(const BigN& a1, const BigN& a2);

	friend ostream& operator<<(ostream& out, const BigN& b);
	friend istream& operator>>(istream& in, BigN& b);

	//逻辑运算
	friend bool operator<(const BigN& a1, const BigN& a2);
	friend bool operator>(const BigN& a1, const BigN& a2) {return a2<a1;}
	friend bool operator<=(const BigN& a1, const BigN& a2) {return !(a2<a1);}
	friend bool operator>=(const BigN& a1, const BigN& a2) {return !(a1<a2);}
	friend bool operator==(const BigN& a1, const BigN& a2) {return !(a1<a2) && !(a2<a1);}
	friend bool operator!=(const BigN& a1, const BigN& a2) {return !(a1==a2);}

	int length(){return len;}

private:
	const static int maxn=4000;
	int len, s[maxn];
	bool neg;
};

bool operator<(const BigN& a1, const BigN& a2)
{
	if(a1.neg && !a2.neg && a1.len !=1 && a2.len != 1 && a1.s[0]!=0 && a2.s[0]!=0) //符号不同，且长度不为0，表面不为+0 或者 -0
	{
		return true; 
	}

	if(a1.neg && a2.neg)
	{
		bool ret=false;
		if(a1.len == a2.len)
		{
			for(int i=a1.len-1;i>=0;--i)
			{
				if (a1.s[i] > a2.s[i])
				{
					ret = true;
					break;
				}else if(a1.s[i] < a2.s[i])
				{
					ret = false;
					break;
				}
			}
		}else{
			ret = (a1.len > a2.len);
		}

		return ret;
	}else if(!a1.neg && !a2.neg){
		bool ret=false;
		if(a1.len == a2.len)
		{
			for(int i=a1.len-1;i>=0;--i)
			{
				if (a1.s[i] < a2.s[i])
				{
					ret = true;
					break;
				}else if(a1.s[i] > a2.s[i])
				{
					ret = false;
					break;
				}
			}
		}else{
			ret = (a1.len < a2.len);
		}

		return ret;
	}
	return false;
}

ostream& operator<<(ostream& out, const BigN& b)
{
	string s("");
	if(b.neg && b.len) s += '-';
	for(int i=b.len;i>0;)
		s += b.s[--i] + '0';
	if(s.size() == 0) s="0";
	out<<s;
	return out; //必须返回，便于串式操作
}

istream& operator>>(istream& in, BigN& b)
{
	string s;
	in>>s;
	b = s.c_str(); //调用赋值函数
	return in;  //必须返回，便于串式操作
}

BigN operator+(const BigN& a1, const BigN& a2)
{
	BigN b,_a1(a1),_a2(a2);
	//如果a1为负数，或者a2为负数
	if(a1.neg && a2.neg)
	{
		_a1.neg = _a2.neg = false;
		b = _a1 + _a2;
		b.neg = ! b.neg;
		return b;
	}else if(a1.neg)
	{
		_a1.neg = false;
		b=_a2 - _a1;
		return b;
	}else if(a2.neg)
	{
		_a2.neg = false;
		b = _a1 - _a2;
		return b;
	}

	//以下仅仅处理两操作数均为正数的情况
	
	b.s[0]=a1.s[0]+a2.s[0];
	if(b.s[0]!=0) b.len = 1;
	for(int i=1;i<BigN::maxn;++i)
	{
		b.s[i]=a1.s[i]+a2.s[i]+b.s[i-1]/10;
		b.s[i-1] %= 10;
		if(b.s[i]!=0) b.len = i+1;
	}
	return b;
}

BigN operator-(const BigN& a1, const BigN& a2)
{
	BigN b,_a1(a1),_a2(a2);

	if( _a1.neg && _a2.neg)
	{
		_a1.neg = _a2.neg = false;
		b=_a2 - _a1;
		return b;
	}else if(_a1.neg)
	{
		_a1.neg = false;
		b = _a1 + _a2;
		b.neg = ! b.neg;
		return b;
	}else if(_a2.neg)
	{
		_a2.neg = false;
		b = _a1 + _a2;
		return b;
	}

	//以下处理 a1 a2均为正数的情况
	if (_a1.len < _a2.len) //如果被减数小于减数，则先交换
	{
		b = _a2 - _a1;
		b.neg = true;
		return b;
	}else if(_a1.len == _a2.len)
	{
		//比较是否_a1比_a2小，或者相等
		int j=_a1.len-1;
		for(;j>=0;--j)
		{
			if(_a1.s[j]<_a2.s[j])
				break;
			else if(_a1.s[j]>_a2.s[j])
				break;
		}

		if (j < 0) //表示相等
		{
			return "0";
		}else if(_a1.s[j] < _a2.s[j]) //被减数和减数交换
		{
			b = _a2 - _a1;
			b.neg = true;
			return b;
		}

	}

	//其他情况，被减数大于减数的情况
	b.neg = false;
	for(int j=0;j<_a1.len;++j)
	{
		if (_a1.s[j] < _a2.s[j])
		{
			assert(j+1<a1.len); 
			_a1.s[j+1] -= 1;
			b.s[j] = _a1.s[j] + 10 - _a2.s[j];
		}else{
			b.s[j] = _a1.s[j] - _a2.s[j];
		}
		if(b.s[j] != 0) b.len = j+1;
	}

	return b;
}

BigN operator*(const BigN& a1, const BigN& a2)
{
	assert(a1.len+a2.len < BigN::maxn);

	BigN b;

	if((a1.neg && !a2.neg)||(a2.neg && !a1.neg))
		b.neg = true;

	for(int i=0;i<a1.len;++i)
	{
		for(int j=0;j<a2.len;++j)
		{
			b.s[i+j] += a1.s[i]*a2.s[j]; //对应的乘积相加 
		}
	}

	for(int i=1;i<BigN::maxn;++i)
	{
		b.s[i] = b.s[i] + b.s[i-1]/10;
		b.s[i-1] %= 10;
		if(b.s[i-1]!=0) b.len = i;
	}
	
	return b;
}

//eg.5.3.1 6174问题，互不相同的4位数，所有数字从大到小排列得到a，从小到大排列得到b
//然后a-b得到新的4位数，然后继续操作
//4321-1234=3087,8730-0378=8352,8532-2358=6174,7614-1467=6174，最后一个6174出现过，则结束
//输入一个n位数，输出序列，直到出现循环
void eg_5_3_1_6174_problem()
{
	int n;
	cin>>n;


}



int _tmain(int argc, _TCHAR* argv[])
{

	//eg_5_2_2_get_fanci(999);

	//eg_ Big Number test
	/*
	BigN a("1123456789876543211");
	BigN b("-2222222222222222");

	cout<<a<<":"<<b<<endl;

	cout<<a-b<<endl;

	BigN c(234560),d(-221353462);
	cout<<c<<":"<<d<<endl;
	cout<<"c+d="<<c+d<<endl;
	cout<<"c*d="<<c*d<<endl;
	cout<<"c-d="<<c-d<<endl;

	BigN sum(1);

	for(int i=1;i<=1463;++i) //1463!非常接近4000位了
	{
		sum = sum * i;
	}

	cout<<sum<<":"<<sum.length()<<endl;

	BigN e1,e2;
	while(1){
	cin>>e1>>e2;
	cout<<e1<<"-"<<e2<<"="<<e1-e2<<endl;
	cout<<e1<< ((e1>e2)?">":"<=")<<e2<<endl;
	cout<<e1<< (e1==e2?"==":"!=")<<e2<<endl;
	}
	*/


	return 0;
}

