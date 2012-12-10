// InterviewBible.cpp : 定义控制台应用程序的入口点。
//
#include "..\CommonHeader.h"

//8.3打靶
//----------------------------------------
//靶上一共10环，连开10枪，求打中90环的可能性
void gun_trial(int n, int lost, int& total)
{
	//没有能够丢失的环数，是一种成功，直接返回
	if (lost == 0) 
	{
		//success
		++total;
		return;
	}else if(n==10) //已经是第10枪了，可是丢的环数不够
	{
		return;
	}


	//for N, will lost point from 0 to 10 for trial
	for(int i=0;i<=10;++i)
	{
		if(lost-i>=0)
			gun_trial(n+1,lost-i,total);
		else
			break;
	}
	
}

void ch_8_3_1_gun()
{
	int total=0;
	gun_trial(0,10,total);
	cout<<total<<endl;
}
//----------------------------------------
//8.4 字符串
//把字符串中所有字符串的各种组合形式全部显示出来，不论顺序
//例如：hart， ha 和har是不同组合，但是ha和ah则是相同组合

//组合
void put_n_char_componets(int n, const string& in, string out, bool dict[])
{
	if(n>=in.size())
	{
		if(out.size()>0)
			cout<<out<<endl;
		return;
	}
	if(dict[in[n]]) //如果字符前面已经处理，则跳过
		put_n_char_componets(n+1,in,out,dict);

	
	dict[in[n]]=true;
	put_n_char_componets(n+1,in,out+in[n],dict);
	//回溯,不选择这个字符
	//out[out.size()-1]='\0';
	//dict[in[n]]=false;
	put_n_char_componets(n+1,in,out,dict);
	dict[in[n]]=false; //回溯，必须恢复
}

//排列,就地排列
void put_n_char_part(int n, string in)
{
	if(n>=in.size())
	{
		cout<<in<<endl;
		return;
	}

	//首先固定第n个字符，对第n+1以后的字符进行全排列
	put_n_char_part(n+1,in);
	//依次将第n字符跟后面的每个字符进行交换，然后进行全排列
	for(int i=n+1;i<in.size();++i)
	{
		//这里可以加一个判断，如果交换字符一样，可以不排列,去除相同情况下的排列数
		//if(in[n]==in[i]) continue;
		_swap(in[n],in[i]);
		put_n_char_part(n+1,in);
		_swap(in[n],in[i]); //恢复，进行下一次交换
	}
}

void ch_8_4_1_chars_component()
{
	string tmp="hart";
	string out;
	bool dict[255]={false};
	cout<<"组合:\n";
	put_n_char_componets(0,tmp,out,dict);
	cout<<"排列:\n";
	put_n_char_part(0,tmp);
}

//----------------------------------------
//8.6 0-1背包问题
//给定两个数m和n，从数列1,2,3,4....n中随意取几个数，使其和为m，要求
//得出所有可能的组合
void packed_M(const int& m, const int& n, int idx, vector<int>& arr, int sum)
{
	if (idx > n)
		return;

	if(sum == m)
	{
		//输出结果
		for_each(arr.begin(),arr.end(),out<int>);
		cout<<endl;
		return;
	}
	
	//选择idx
	arr.push_back(idx);
	packed_M(m,n,idx+1,arr,sum+idx);
	//不选择idx
	arr.pop_back();
	packed_M(m,n,idx+1,arr,sum);
}

void ch_8_6_package_MN()
{
	vector<int> a;
	packed_M(26,17,1,a,0); //起始
}

//----------------------------------------
//破碎的砝码：
//一个质量40磅的砝码，破碎成整数磅的的4块，而且质量各不相同，
//并且这4块砝码能够在天平上称出1到40磅之间的所有重量（整数重量）
//求这四块砝码的质量各是多少

//方法：穷举：解空间有限，最多，40^3
//令分别为a,b,c,d重量4块，且a<b<c<d,且互不相等，这样可以减少解空间重复

void ch_non_40bund()
{
	for(int a=1;a<=40;++a)
		for(int b=a+1;b<=40-a;++b)
			for(int c=b+1;c<=40-a-b;++c)
				{
					int d=40-a-b-c;
					if(d<=0)
						continue;
					//判断，a b c d组合的可能性

					//由天平特性可知，对于每个a b c d,其有3种可能，
					//对所称物体起正面作用，反面作用，不起作用
					//所以最后能称的重量，必然是每个重量，取正，取负，和0的结果
					bool arr[41]={0};
					for(int ia=-1;ia<=1;++ia)
						for(int ib=-1;ib<=1;++ib)
							for(int ic=-1;ic<=1;++ic)
								for(int id=-1;id<=1;++id)
								{
									int height=ia*a+ib*b+ic*c+id*d;
									if(height > 0)
										arr[ia*a+ib*b+ic*c+id*d]=1;
									
								}
					int i=1;
					for(i=1;i<=40;++i)
					{
						if(arr[i]==0)
							break;
					}
					if(i==41)
					{
						//已经得到一组解，返回
						cout<<"(a,b,c,d)="<<a<<","<<b<<","<<c<<","<<d<<endl;
						return;
					}
				}
	cout<<"No result!"<<endl;
}

//----------------------------------------
//计算24的问题
//从屏幕上输入1到10范围以内的4个整数，可以重复，对它们进行+-*/四则运算
//可以加括号限定计算的优先级，但是不能改变四个数的顺序，寻求所有结果为24的运算表达式
//解题思路：
//1> 首先不考虑+-*/四个运算，先考虑加括号的优先级问题,令4个数分别为A B C D,则运算优先级模式就有一下几种
/*
	((A B) C) D
	(A (B C)) D
	A ((B C) D)
	A (B (C D))
	(A B) (C D)
*/
//2> 再考虑A B C D之间的运算符号，+-*/

enum op{
	_ADD=0,
	_SUB,
	_MUL,
	_DIV
};

bool dividebyzero=false;

inline float cal_op(float d1, float d2, op x)
{
	switch (x)
	{
	case _ADD:	return d1+d2;break;
	case _SUB:	return d1-d2;break;
	case _MUL:	return d1*d2;break;
	case _DIV:	return d1/d2;break; //因为是float，不考虑除零的情况，如果是int，需要考虑，异常处理更好??
	}
}

char opchar[]={
	'+','-','*','/'
};

inline char getop(int x)
{
	return opchar[x];
}

inline float cal_pattern1(float a, float b, float c, float d, op x, op y, op z)
{
	return cal_op(cal_op(cal_op(a,b,x),c,y),d,z);	//（(A B) C) D
}

inline float cal_pattern2(float a, float b, float c, float d, op x, op y, op z)
{
	return cal_op(cal_op(a,cal_op(b,c,y),x),d,z);	//（A (B C)) D
}

inline float cal_pattern3(float a, float b, float c, float d, op x, op y, op z)
{
	return cal_op(a,cal_op(cal_op(b,c,y),d,z),x);	//A ((B C) D)
}

inline float cal_pattern4(float a, float b, float c, float d, op x, op y, op z)
{
	return cal_op(a,cal_op(b,cal_op(c,d,z),y),z);	//A (B (C D))
}

inline float cal_pattern5(float a, float b, float c, float d, op x, op y, op z)
{
	return cal_op(cal_op(a,b,x),cal_op(c,d,z),y);	//(A B) (C D)
}

typedef float (*cal_pattern)(float,float,float,float,op,op,op);

cal_pattern cp[] = {
	cal_pattern1,
	cal_pattern2,
	cal_pattern3,
	cal_pattern4,
	cal_pattern5
};

char* print_pattern[]={
	"((%d %c %d) %c %d) %c %d = 24\n",
	"(%d %c (%d %c %d)) %c %d = 24\n",
	"%d %c ((%d %c %d) %c %d) = 24\n",
	"%d %c (%d %c (%d %c %d)) = 24\n",
	"(%d %c %d) %c (%d %c %d) = 24\n",
};

void ch_non_24sum()
{
	int va,vb,vc,vd;
	cin>>va>>vb>>vc>>vd;

	bool result=false;

	for(int o=_ADD;o<=_DIV;o=o+1)
		for(int p=_ADD;p<=_DIV;p=p+1)
			for(int q=_ADD;q<=_DIV;q=q+1)
				for(int i=0;i<sizeof(cp)/sizeof(cal_pattern);++i)
				{
					if(cp[i](va,vb,vc,vd,(op)o,(op)p,(op)q)==24)
					{
						result = true;
						printf(print_pattern[i],va,getop(o),vb,getop(p),vc,getop(q),vd);
					}
				}

	if(!result)
		printf("No expression equal to 24!\n");
}


//----------------------------------------
void exit_n()
{
	exit(0);
}

typedef void (*func)();

#define _F(x) x, #x

struct type_func
{
	func f;
	char* str_f;
};

type_func FUNC[]={
	_F(exit_n),
	_F(ch_8_3_1_gun),
	_F(ch_8_4_1_chars_component),
	_F(ch_8_6_package_MN),
	_F(ch_non_40bund),
	_F(ch_non_24sum)
};


int main(int argc, char* argv[])
{
	int num;
	while(1)
	{
		cout<<"\n--------------------------\nEnter test func:"<<endl;
		for(int i=0;i<sizeof(FUNC)/sizeof(FUNC[0]);++i)
			cout<<i<<":"<<FUNC[i].str_f<<endl;
		cin>>num;
		if(num==0)
			break;
		FUNC[num].f();
	}
	return 0;
}

