// ACM_Entrance_WhiteBook_ch5.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"

/************************************************************************/
/* ch 5 ������Ŀѡ��
/************************************************************************/

#include <iostream>
#include <cassert>
#include <string>
#include <vector>

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

	//�߼�����
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
	if(a1.neg && !a2.neg && a1.len !=1 && a2.len != 1 && a1.s[0]!=0 && a2.s[0]!=0) //���Ų�ͬ���ҳ��Ȳ�Ϊ0�����治Ϊ+0 ���� -0
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

//eg.5.3.1 6174���⣬������ͬ��4λ�����������ִӴ�С���еõ�a����С�������еõ�b
//Ȼ��a-b�õ��µ�4λ����Ȼ���������
//4321-1234=3087,8730-0378=8352,8532-2358=6174,7614-1467=6174�����һ��6174���ֹ��������
//����һ��nλ����������У�ֱ������ѭ��

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

		//���ַ������մӴ�С˳�����򣬲�������
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
		//��ת���õ���С����
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

//eg.5.3.2 ��ĸ���ţ�����һ���ֵ䣬��***��β�����������ɵ��ʣ�û����һ������w������Ҫ���ֵ����ҳ�
//���п�����w����ĸ���ŵõ��ĵ��ʣ��������ֵ����С�����������������������������:()��ÿ������
//��������6��Сд��ĸ��ע���ֵ��еĵ��ʲ�һ�������ֵ�������

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

	//�Ե������ֵ�������
	qsort(dict,count,sizeof(char)*7,dict_inner_sort);
	for(int i=0;i<count;++i)
	{
		strcpy(sorted[i],dict[i]);
		//��ÿ���ڲ���������
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

//eg.5.4.2 ���Ӻͽ׳� (2<=n<=100)�� ��n!�ֽ�Ϊ1*2*3....*n,��С�����������������2,3,5,7....)��ָ��
//���磬825=3*5^2*11,���ʾΪ(0,1,2,0,1)��ʾ��0,1,2,0,1��2,3,5,7,11. 
//������Ӧ�ú��Ա�������Ӹ��������(����������������0)
//��������
//5 ��� 5!= 3 1 1
//52 ��� 53!=49 23 12  4 4 3 2 2 1 1 1 1 1 1 1
void eg_5_3_2_factor_prime_indices() //TODO:
{
	int n;
	//ע�⵽n<=100���������n!��������󲻻ᳬ��100,
	//��ô��Ҫ��ʼ��100���ڵ�����

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

	//�õ�����֮��Ȼ���n!�߳˱߳�
	while(cin>>n)
	{
		memset(p_num,0,sizeof(p_num));
		int max_pos=0;

		//ʵ����ÿ�������ܻ�Ϊ���������ָ���˻�
		//���Զ��ڽ׳˵�ÿ�������Ӷ��������ֽ�
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

//���⣬��n!�����һλ��0��

//��n!��5�����Ӹ���
//�㷨��n!=1*2*3*4*5*6*7*8*9*10*....*n,��ôÿ��5��������һ��5�����ӣ�����5֮�󣬱����1*2*3....*n/5��ô�������n/5����5�����Ӹ���
int get_factor_5(int num)
{
	if(num < 5) return 0;
	return num/5 + get_factor_5(num/5);
}

//�ǵݹ��㷨
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

//��׳˵����lastNλ��0���� ��lastN����̫��<6��
void practice_last_N_non_zero_digit(int lastN)
{
	
	int n,fac=1,res=1;
	cin>>n;

	while(lastN -- > 0)
		res *= 10;

	int numZero=get_factor_5_non_recusive(n);

	cout<<"Zero Number:"<<numZero<<endl;

	//Ӧ�ô����ֵ��ʼ���³ˣ���������ǰ��ͰѶ���λ��ȥ��
	for(int num=n;num>1;--num)
	{
		int tmp=num;
		//�׵�����Ӧ���׵���2������
		while(tmp%2 == 0 && numZero > 0)
		{
			tmp /= 2;
			numZero --;
		}
		
		//�׵����е�5������
		while(tmp%5==0)
			tmp /= 5;
		
		fac *= tmp;

		cout<<"+"<<fac<<":"<<numZero<<endl;
		//����������Nλ
		if (numZero == 0)
			fac %= res;
		cout<<"-"<<fac<<endl;

	}
	
	cout<<"last non zero digit of n! is "<<fac<<endl;
}

//��n���׳˵���ߵڶ�λ����
//�㷨��һ��Ҫ��double����������Ϊ���ں�������ֵľ�ȷ��
//ֻ��֤�ʼ��NΪ�Ǿ�ȷ�ģ�������������������
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
			number /= 10; //���������ʼ��beginNλ
		}
	}

	cout<<"the begin N number is: "<<(int)number<<endl;
}


//��ϰ���ж�m�Ƿ��ܹ���n!����
//�㷨�����m==0 ����m<=n��϶����Ա�����
//������Ҫ��һ������

//��ȡ��ͨ��������n�ĸ���
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

//��ȡ�׳�num!������n�ĸ���
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
	
	//��m�����������ӷֽ⣬Ȼ���ж�n!���Ӧ�������������Ƿ����m������������
	int prime[100]={2}; //����100������
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

	//����������������
	for(idx=0;idx<100 && m >= prime[idx]; ++idx )
	{
		if (get_factor_n_of_num(prime[idx],m) > get_factor_n_of_fac_num(prime[idx],n))
			return false;
	}

	if(idx < 100 ) //����mС�ڵ�ǰ��������
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

	for(int i=1;i<=1463;++i) //1463!�ǳ��ӽ�4000λ��
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

	//��������
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

