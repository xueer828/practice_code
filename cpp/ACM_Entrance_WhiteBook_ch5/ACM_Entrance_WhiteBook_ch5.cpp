// ACM_Entrance_WhiteBook_ch5.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

/************************************************************************/
/* ch 5 基础题目选解
/************************************************************************/

#include <iostream>
#include <cassert>
#include <string>
#include <vector>

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

char* _itoa(unsigned int n, char* out)
{
	assert(out);
	char* ret=out;
	do 
	{
		*out++ = n%10 + '0';
		n/=10;
	} while (n>0);
	*out = '\0';

	//reverse
	char* start=ret;
	--out;
	for(;start<out;++start,--out)
	{
		char tmp;
		tmp = *start;
		*start=*out;
		*out = tmp;
	}
	return ret;
}

int _atoi(const char* in)
{
	assert(in);
	const char* start=in;
	while(*start == ' ') ++start; //skip spaces
	int flag=1;
	int num=0;
	if(*start == '-' || *start == '+')
	{
		if (*start == '-')
			flag = -1;
		++start;
	}

	while(*start!='\0' && *start >= '0' && *start <= '9')
	{
		num = num * 10 + *start - '0';
		++start;
	}

	num *= flag;

	return num;	
}



void eg_5_3_1_6174_problem()
{
	int n;
	char strn[256];
	cin>>n;
	vector<int> store;

	cout<<n;

	while (1)
	{
		_itoa(n,strn);
		int len=strlen(strn);

		//对字符串按照从大到小顺序排序，插入排序
		for(int i=1;i<len;++i)
		{
			char v=strn[i];
			int j=i-1;
			for(;j>=0;--j)
			{
				if(v > strn[j])
					strn[j+1] = strn[j];
				else
					break;
			}
			strn[j+1] = v;
		}

		int first_n=_atoi(strn);
		//逆转，得到从小到大
		for(int i=0;i<len;i++,len--)
		{
			char tmp=strn[len-1];
			strn[len-1]=strn[i];
			strn[i]=tmp;
		}

		int second_n=_atoi(strn);

		int third_n=first_n - second_n;

		bool inflag=false;
		for (int i=0;i<store.size();++i)
		{
			if(third_n == store[i])
			{
				inflag = true;
				break;
			}
		}	
		cout<<"->"<<third_n;
		if(!inflag)
			store.push_back(third_n);
		else
			break;

	

		n = third_n;
	}

	cout<<endl;
	
}

//eg.5.3.2 字母重排，输入一个字典，以***结尾，在输入若干单词，没输入一个单词w，都需要从字典中找出
//所有可以用w的字母重排得到的单词，并按照字典序从小到大排列输入出，如果不存在则输出:()，每个单词
//都不超过6个小写字母，注意字典中的单词不一定按照字典序排列

int dict_inner_sort(const void* a, const void* b)
{
	return strcmp((char*)a,(char*)b);
}

int str_inner_sort(const void* a,const void* b)
{
	return *((char*)a) - *((char*)b);
}


void eg_5_3_2_alpha_reorder()
{
	char dict[200][7]={0};
	char sorted[200][7]={0};

	char tmp[7];
	int count=0;
	while(cin>>tmp)
	{
		if (tmp[0]=='*') break;
		
		strcpy(dict[count++],tmp);
	}

	//对单词以字典序排序
	qsort(dict,count,sizeof(char)*7,dict_inner_sort);
	for(int i=0;i<count;++i)
	{
		strcpy(sorted[i],dict[i]);
		//对每个内部进行排序
		qsort(sorted[i],strlen(sorted[i]),1,str_inner_sort);
	}

	
	while(cin>>tmp){
		qsort(tmp,strlen(tmp),1,str_inner_sort);

		for(int i=0;i<count;++i)
		{
			if (strcmp(sorted[i],tmp)==0)
			{
				cout<<dict[i]<<" ";
			}
		}
		cout<<endl;
	}

}

//eg.5.4.2 因子和阶乘 (2<=n<=100)， 把n!分解为1*2*3....*n,从小到大输出各个素数（2,3,5,7....)的指数
//例如，825=3*5^2*11,则表示为(0,1,2,0,1)表示有0,1,2,0,1个2,3,5,7,11. 
//程序中应该忽略比最大因子更大的素数(否则后面会有无数个0)
//测试用例
//5 输出 5!= 3 1 1
//52 输出 53!=49 23 12  4 4 3 2 2 1 1 1 1 1 1 1
void eg_5_3_2_factor_prime_indices() //TODO:
{
	int n;
	//注意到n<=100，所以这个n!的因子最大不会超过100,
	//那么需要初始化100以内的素数

	int prime[100]={2},count=1;
	int p_num[100]={0};
	for(int i=3;i<=100;++i)
	{
		int j=0;
		for(;j<count;++j)
		{
			if (!(i%prime[j]))
				break;
		}
		if (j==count)
			prime[count++]=i;
	}

	//得到素数之后，然后把n!边乘边除
	while(cin>>n)
	{
		memset(p_num,0,sizeof(p_num));
		int max_pos=0;

		//实际上每个数都能化为多个素数的指数乘积
		//所以对于阶乘的每个乘因子都做素数分解
		for(int cur_n=2;cur_n<=n;++cur_n)
		{
			int tmp=cur_n;
			for(int i=0;i<count && tmp > 1;)
			{
				if(tmp%prime[i]==0)
				{
					p_num[i]++;
					if(max_pos < i) max_pos = i;
					tmp /= prime[i];
				}else
					++i;
			}		
		}

		cout<<n<<"!=";
		for(int i=0;i<=max_pos;i++)
		{
			cout<<p_num[i]<<" ";
		}
		cout<<endl;

	}
}

//额外，求n!的最后一位非0数

//求n!中5的因子个数
//算法：n!=1*2*3*4*5*6*7*8*9*10*....*n,那么每隔5个数会有一个5的因子，都除5之后，变成了1*2*3....*n/5那么变成了求n/5！的5的因子个数
int get_factor_5(int num)
{
	if(num < 5) return 0;
	return num/5 + get_factor_5(num/5);
}

//非递归算法
int get_factor_5_non_recusive(int num)
{
	int count =0;
	while(num >= 5)
	{
		count += num/5;
		num /= 5;
	}
	return count;
}

//求阶乘的最后lastN位非0的数 （lastN不能太大<6）
void practice_last_N_non_zero_digit(int lastN)
{
	
	int n,fac=1,res=1;
	cin>>n;

	while(lastN -- > 0)
		res *= 10;

	int numZero=get_factor_5_non_recusive(n);

	cout<<"Zero Number:"<<numZero<<endl;

	//应该从最大值开始往下乘，这样可以前面就把多余位数去掉
	for(int num=n;num>1;--num)
	{
		int tmp=num;
		//抛掉所有应该抛掉的2的因子
		while(tmp%2 == 0 && numZero > 0)
		{
			tmp /= 2;
			numZero --;
		}
		
		//抛掉所有的5的因子
		while(tmp%5==0)
			tmp /= 5;
		
		fac *= tmp;

		cout<<"+"<<fac<<":"<<numZero<<endl;
		//仅保留最后的N位
		if (numZero == 0)
			fac %= res;
		cout<<"-"<<fac<<endl;

	}
	
	cout<<"last non zero digit of n! is "<<fac<<endl;
}

//求n！阶乘的左边第二位数字
//算法，一定要用double类型来求，因为不在乎最后数字的精确度
//只保证最开始的N为是精确的，并保留在最后的数字中
void practice_Begin_N_non_zero_digit(int beginN)
{
	double number=1;
	int n;
	cin>>n;

	int fac=1;
	while(beginN-- > 0)
		fac *= 10;

	cout<<fac<<endl;

	for(int i=n;i>1;--i)
	{
		number *= i;
		while (number > fac)
		{
			number /= 10; //仅仅保留最开始的beginN位
		}
	}

	cout<<"the begin N number is: "<<(int)number<<endl;
}


//练习，判断m是否能够被n!整除
//算法，如果m==0 或者m<=n则肯定可以被整除
//否则需要进一步计算

//获取普通数的因子n的个数
inline int get_factor_n_of_num(int n, int num)
{
	int count=0;
	//cout<<num<<"!~="<<n<<"^";
	while(num%n==0)
	{
		num /= n;
		++count;
	}
	//cout<<count<<endl;
	return count;
}

//获取阶乘num!的因子n的个数
inline int get_factor_n_of_fac_num(int n, int num)
{
	int count=0;
	//cout<<num<<"!~="<<n<<"^";
	while(num > n)
	{
		num /= n;
		count += num;
	}
	//cout<<count<<endl;
	return count;
}

bool practice_Fac_N_Devided_by_M(int m, int n)
{
	if(m<0) return false;
	if(m <n) return true; 
	
	//将m进行素数因子分解，然后判断n!里对应的素数因子数是否大于m的素数因子数
	int prime[100]={2}; //先算100个素数
	int idx=1,num=3;
	while(idx < 100)
	{
		int i;
		for (i=0;i<idx;++i)
		{
			if(num%prime[i]==0)
				break;
		}
		if(i==idx)
			prime[idx++]=num;
		num++;
	}

	//搜索所有素数因子
	for(idx=0;idx<100 && m >= prime[idx]; ++idx )
	{
		if (get_factor_n_of_num(prime[idx],m) > get_factor_n_of_fac_num(prime[idx],n))
			return false;
	}

	if(idx < 100 ) //表明m小于当前最大的素数
		return true;
	else
		assert(0);

}



int main(int argc, char* argv[])
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

	//eg_5_3_1_6174_problem();

	//测试用例
	//tarp given score refund only trap work earn course pepper part ****
	//resco nfudre aptr sett oresuc
	//eg_5_3_2_alpha_reorder();

	//eg_5_3_2_factor_prime_indices();

	//practice_last_N_non_zero_digit(6);

	//practice_Begin_N_non_zero_digit(10);

	int m,n;
	cin>>m>>n;
	cout<<m<<(practice_Fac_N_Devided_by_M(m,n)?" can ":" cannot ")<<"divided "<<n<<"!"<<endl;

	return 0;
}

