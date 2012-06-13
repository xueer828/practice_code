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

	int m,k;
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

typedef void (*run_problem)();

run_problem solutions[]=
{
	ch1_rotate_string,
};


int main(int argc, char * argv[])
{
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

