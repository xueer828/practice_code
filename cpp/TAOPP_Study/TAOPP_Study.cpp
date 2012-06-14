// TAOPP_Study.cpp : Defines the entry point for the console application.
//

#include "..\CommonHeader.h"

//http://www.cnblogs.com/v-July-v/archive/2011/06/02/2091171.html
//TAOPP 前10章节

/************************************************************************
第一章、左旋转字符串
第二章、字符串是否包含问题
第三章、寻找最小的k个数
第三章续、Top K算法问题的实现
第三章再续：快速选择SELECT算法的深入分析与实现
三之三续、求数组中给定下标区间内的第K小（大）元素
第四章、现场编写类似strstr/strcpy/strpbrk的函数
第五章、寻找满足条件的两个或多个数
第六章、求解500万以内的亲和数
第七章、求连续子数组的最大和
第八章、从头至尾漫谈虚函数
第九章、闲话链表追赶问题
第十章、如何给10^7个数据量的磁盘文件排序
/************************************************************************/


/************************************************************************/
/* 第一章、左旋转字符串
/************************************************************************/
//m为整个字符串长度，n为需要旋转的前n个字符
//思路1，分成两段逐步交换，O(m+n)，基于交换操作
void rotate_string1(char str[],int m, int n)
{
	assert(str);
	int k=(m+n)%m;
	if (k == 0) return; //不需要旋转

	int beg1=0,beg2=k,mid=k;
	for(;;)
	{
		_swap(str[beg1++],str[beg2++]);
		if (beg2 == m) //后面到达最后
		{
			if(beg1 == mid)
				return; //完成旋转
			else
				//前长，后短，调整（beg1不变,beg2变成mid）
				beg2 = mid;
		}else if(beg1 == mid) //前面到达mid，但是后面没有到达last
		{
			mid=beg2; //调整mid位置
		}
	}

}

template<class T>
void _reverse(T* t1, T* t2)
{
	while(t1<t2)
	{
		T tmp=*t1;
		*t1 = *t2;
		*t2 = tmp;
		++t1, --t2;
	}
}

//思路2，分两段先各自内部反转，然后外部整体反转，O(2n),最差，基于交换操作
void rotate_string2(char str[], int m, int n)
{
	assert(str);
	int k=(m+n)%m;

	if(k==0) return;

	_reverse(str,str+k-1);
	_reverse(str+k,str+m-1);
	_reverse(str,str+m-1);
}

//求最大公约数
int _gcd(int m,int n)
{
	while(n != 0)
	{
		int tmp = m%n;
		m = n;
		n = tmp;		
	}
	return m;
}

//思路3，random iterater，基于STL rotate算法
//算法复杂度O(n)
void rotate_string3(char str[],int m, int n)
{
	assert(str);
	int k=(m+n)%m; //统一n为负数或者n>m的情况
	int groups=_gcd(m,k);
	while(groups--)
	{
		//对于当前groups的循环链，进行赋值
		char tmp=str[groups];
		int last=groups;
		for(int j=(groups+k)%m;j!=groups;j=(j+k)%m)
		{
			str[last] = str[j];
			last = j; //循环链赋值
		}
		str[last] = tmp; //最开始的值赋给循环链末尾的位置

	}
}

//左旋字符串，一共有3种思路
void ch1_rotate_string()
{
	char test_str[]="abcdefghijk";

	int k;
	cout<<"Input Number of Left Rotate Chars:";
	cin>>k;

	//思路1，两指针逐步交换
	rotate_string1(test_str,sizeof(test_str)-1,k);
	cout<<test_str<<endl;

	rotate_string2(test_str,sizeof(test_str)-1,k);
	cout<<test_str<<endl;

	rotate_string3(test_str,sizeof(test_str)-1,k);
	cout<<test_str<<endl;

}


/************************************************************************/
/* 第二章、字符串是否包含问题
/************************************************************************/

//方法1，快排+类似归并的比较

//首先是快排

// T 必须重载支持 operator <
template<class T>
inline const T* _get_mid(const T* t1, const T* t2, const T* t3)
{
	if(*t1<*t2)
	{
		if(*t2<*t3)
			return t2; // t1<t2<t3
		else if(*t1<*t3)
			return t3; // t1<t3<t2
		else
			return t1; // t3<t1<t2
	}else if(*t1<*t3) // t2<t1<t3
		return t1;
	else if(*t2<*t3) //t2<t3<t1
		return t3;
	else
		return t2; // t3<t2<t1
}

template<class T>
void _qsort_v1(T t[], int begin, int end)
{
	assert(t);
	if(begin >= end) return;
	int lo=begin,hi=end,mid;
	//取最开始，最结尾和中间元素的中值,这样可以保证lo,hi不会越界
	T *p_pivot=const_cast<T*>(_get_mid(t+lo,t+((lo+hi)>>1),t+hi));

	//交换，将主元放到整个end位置上(如果不在end位置上)
	if(p_pivot!=t+end)
		_swap(*p_pivot,*(t+end));
	T pivot=t[end];
	//cout<<"MID:"<<t[lo]<<"|"<<t[((lo+hi)>>1)]<<"|"<<t[hi]<<":"<<pivot<<endl;
	--hi;
	while(true)
	{
		while(t[lo]<pivot) ++lo; //找到>=pivot的元素就停下来
		while(pivot<t[hi]) --hi; //找到<=pivot的元素就停下来

		if(lo >= hi) { mid=lo; break; } //已经完成本次划分
		_swap(t[lo],t[hi]); //交换

		++lo,--hi;
	}
	//交换当前mid元素和主元
	_swap(t[mid],t[end]);

	cout<<begin<<"|"<<mid<<"|"<<end<<"|"<<t<<"|"<<pivot<<endl;

	if(begin<mid-1)
		_qsort_v1(t,begin,mid-1);
	if(mid+1<end)
		_qsort_v1(t,mid+1,end);	
}

//优化版本2
template<class T>
void _qsort_v2(T t[],int begin, int end)
{
	assert(t);
	if(begin >= end) return;

	int lo=begin,hi=begin,mid=((begin+end)>>1);
	//取开始，结尾和中间三值的中值，以便于平衡
	T *p_pivot=const_cast<T*>(_get_mid(t+begin,t+mid,t+end));

	_swap(*p_pivot,*(t+lo)); //将主元放置在最开始

	while(hi<=end)
	{
		while(t[hi]>t[begin]) ++hi;
		//交换lo和hi的值，lo往后移动，hi也往后移动
		if(lo != hi)
			_swap(t[lo],t[hi]);
		++lo, ++hi;
	}
	//此时，将begin的值与lo位置的值进行交换
	if(lo != begin)
		_swap(t[lo],t[begin]);

	cout<<begin<<"|"<<lo<<"|"<<end<<"|"<<t<<"|"<<t[lo]<<endl;
	
	if(begin < lo -1)
		_qsort_v2(t,begin,lo-1);
	if(lo+1 < end)
		_qsort_v2(t,lo+1,end);
}



typedef void (*run_problem)();

run_problem solutions[]=
{
	ch1_rotate_string,
};


int main(int argc, char * argv[])
{

	char str[]="opqrstuvwxyzjihgfedcba";
	cout<<str<<endl;
	_qsort_v1(str,0,sizeof(str)-2);
	cout<<str<<endl;

	char str2[]="opqrstuvwxyzjihgfedcba";
	cout<<str2<<endl;
	_qsort_v2(str2,0,sizeof(str2)-2);
	cout<<str2<<endl;

	return 0;
	int n;
	int len=sizeof(solutions)/sizeof(run_problem);
	cout<<"Solution Number:";
	while(cin>>n)
	{
		if(n<0 || n >= len)
		{
			cout<<"Wrong Solutions Number! Re-Enter\n";
			continue;
		}
		solutions[n]();
		cout<<"Solution Number:";
	}
	return 0;
}

