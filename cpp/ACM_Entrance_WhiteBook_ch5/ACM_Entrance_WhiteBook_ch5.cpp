// ACM_Entrance_WhiteBook_ch5.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

/************************************************************************/
/* ch 5 ������Ŀѡ��
/************************************************************************/

#include <iostream>
#include <cassert>
#include <string>

using namespace std;

//eg.5_2_2 ����׳˵ľ�ȷֵ��n������1000����Ϊ1000��~= 4*10^2567��������3000��������ʾ�׳�ֵ

const int MLen=3001;
void eg_5_2_2_get_fanci(int n)
{
	int num[MLen]={0};
	num[0]=1;
	int cur_m=1;
	for(int i=2;i<=n;i++)
	{
		//�߾��ȼ���
		//��һ����ÿһλ�ֲ�����
		for(int j=0;j<MLen;++j)
		{
			if(j>0)
			{
				num[j] = i*num[j] + num[j-1]/10; //��λ����
				num[j-1] = num[j-1]%10;
			}else
				num[j] *= i;
		}
	}

	//��ת���
	bool flag=false;
	for(int j=MLen-1;j>=0;--j)
		if (num[j]!=0 || flag)
		{
			cout<<num[j];
			flag = true;
		}
	
	cout<<endl;
}

//eg.5.2.3���߾��ȼ�����
struct BigN 
{
	//���캯��
	BigN():len(0),neg(false){memset(s,0,sizeof(int)*maxn);};
	BigN(int n)
	{
		*this = n;
	}
	BigN(const char* str)
	{
		*this = str; //�������渳ֵ����
	}

	//��������
	~BigN(){}

	//�������캯��
	BigN(const BigN& b)
	{
		len=b.len;
		neg=b.neg;
		memset(s,0,maxn*sizeof(int)); 
		memcpy(s,b.s,sizeof(int)*(len+1));
	}

	//��ֵ����
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
		//memsetһ��ֻ��char�ַ������������������reset��0�����������κ��ڴ�
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
		//memsetһ��ֻ��char�ַ������������������reset��0�����������κ��ڴ�
		memset(s,0,maxn*sizeof(int));
		len = strlen(str);
		if (str[0] == '-')
		{
			neg = true;
			len -= 1;
			for(int i=0;i<len;++i) //���뷴������
				s[i]=str[len-i]-'0';

		}else{
			neg = false;
			for(int i=0;i<len;++i) //���뷴������
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

	int length(){return len;}

private:
	const static int maxn=4000;
	int len, s[maxn];
	bool neg;
};

ostream& operator<<(ostream& out, const BigN& b)
{
	string s("");
	if(b.neg && b.len) s += '-';
	for(int i=b.len;i>0;)
		s += b.s[--i] + '0';
	if(s.size() == 0) s="0";
	out<<s;
	return out; //���뷵�أ����ڴ�ʽ����
}

istream& operator>>(istream& in, BigN& b)
{
	string s;
	in>>s;
	b = s.c_str(); //���ø�ֵ����
	return in;  //���뷵�أ����ڴ�ʽ����
}

BigN operator+(const BigN& a1, const BigN& a2)
{
	BigN b,_a1(a1),_a2(a2);
	//���a1Ϊ����������a2Ϊ����
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

	//���½�����������������Ϊ���������
	
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

	//���´��� a1 a2��Ϊ���������
	if (_a1.len < _a2.len) //���������С�ڼ��������Ƚ���
	{
		b = _a2 - _a1;
		b.neg = true;
		return b;
	}else if(_a1.len == _a2.len)
	{
		//�Ƚ��Ƿ�_a1��_a2С���������
		int j=_a1.len-1;
		for(;j>=0;--j)
		{
			if(_a1.s[j]<_a2.s[j])
				break;
			else if(_a1.s[j]>_a2.s[j])
				break;
		}

		if (j < 0) //��ʾ���
		{
			return "0";
		}else if(_a1.s[j] < _a2.s[j]) //�������ͼ�������
		{
			b = _a2 - _a1;
			b.neg = true;
			return b;
		}

	}

	//������������������ڼ��������
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
			b.s[i+j] += a1.s[i]*a2.s[j]; //��Ӧ�ĳ˻���� 
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


int _tmain(int argc, char* argv[])
{

	//eg_5_2_2_get_fanci(999);
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

	for(int i=1;i<=1463;++i) //1463!�ǳ��ӽ�4000λ��
	{
		sum = sum * i;
	}

	cout<<sum<<":"<<sum.length()<<endl;
	return 0;
}

