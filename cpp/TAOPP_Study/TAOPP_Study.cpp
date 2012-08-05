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

	//cout<<begin<<"|"<<mid<<"|"<<end<<"|"<<t<<"|"<<pivot<<endl;

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

	if(p_pivot != t+begin)
		_swap(*p_pivot,*(t+begin)); //将主元放置在最开始

	for(hi=begin+1;;)
	{
		while(hi<=end && t[hi] > t[begin]) ++hi;
		if(hi>end) break;
		//交换lo和hi的值，lo往后移动，hi也往后移动
		_swap(t[++lo],t[hi]);
		++hi; //在hi被替换后，hi必须往后移动
	}

	//system("pause");
	
	//此时，将begin的值与lo位置的值进行交换
	if(lo != begin)
		_swap(t[lo],t[begin]);

	cout<<begin<<"|"<<lo<<"|"<<end<<"|"<<t<<"|"<<t[lo]<<endl;
	
	if(begin < lo -1)
		_qsort_v2(t,begin,lo-1);
	if(lo+1 < end)
		_qsort_v2(t,lo+1,end);
}

//优化版本3，其实跟版本2类似,最好的方法
template<class T>
void _qsort_v3(T t[],int begin, int end)
{
	assert(t);
	if(begin >= end) return;

	T *p_pivot=const_cast<T*>(_get_mid(t+begin,t+(begin+end)/2,t+end));
	//将pivot放在数组最后
	if(p_pivot != t+end)
		_swap(t[end],*p_pivot);
	int lo=begin,hi;
	for(hi=begin;hi<end;++hi)
	{
		if (t[hi]<t[end]) //t[end]是pivot
			_swap(t[hi],t[lo++]);
	}

	//将pivot与lo的位置进行交换
	_swap(t[lo],t[end]);

	if(begin < lo-1)
		_qsort_v3(t,begin,lo-1);
	if(lo+1 < end)
		_qsort_v3(t,lo+1,end);
}

bool _str_included_v1(string str1,string str2)
{
	//先对俩字符进行排序O(nlgn)
	char *s1=const_cast<char*>(str1.c_str());
	char* s2=const_cast<char*>(str2.c_str());

	_qsort_v3(s1,0,strlen(s1)-1);
	_qsort_v3(s2,0,strlen(s2)-1);

	int istr1=0,istr2=0;

	for(istr2=0;s2[istr2]!='\0';)
	{
		if(s1[istr1]>s2[istr2])
			return false;
		else if(s1[istr1]==s2[istr2] && str1[istr1]!='\0')
			++istr2, ++ istr1;
		else
			++istr1;
	}

	return true;	
}

//方法2，当然最简单的，O(n+m)的hashtable算法

bool _str_included_v2(const string& str1, const string& str2)
{
	bool exists[256]={0};
	bool ret=true;
	memset(exists,0,sizeof(exists)*sizeof(bool));
	for(const char *ch=&str1[0];*ch != '\0';++ch)
	{
		exists[*ch]=true;
	}

	for(const char *ch=&str2[0];*ch != '\0'; ++ch)
	{
		if (!exists[*ch])
		{
			ret=false;
			return ret;
		}
	}
	return ret;
}

void ch2_str_included()
{
	string longstr,shortstr;

	cout<<"Input long string and short string:";
	cin>>longstr>>shortstr;

	/*
	cout<<"long_str:"<<longstr<<",short_str:"<<shortstr;
	cout<<",Result:"<<(_str_included_v1(longstr,shortstr)?"Included":"Not Included")<<endl;
	*/

	cout<<"long_str:"<<longstr<<",short_str:"<<shortstr;
	cout<<",Result:"<<(_str_included_v2(longstr,shortstr)?"Included":"Not Included")<<endl;

}

/************************************************************************/
/* 第三章，寻找最小的第K个数，或者最小的K个数
/* 方案1，构造K大顶堆，算法复杂度O(klgk)+O((n-k)lgk)=O(nlgk)
/* 方案2，类似快排的patition和selection，算法复杂度最好接近O(n),例如,
/* 随机主元选取法，或者中值的中间值选择法
/************************************************************************/

//方案1，构造大顶堆

//第0位置为顶，其左右子节点为2*i+1 和 2*(i+1)
//i节点的父节点为(i-1)/2
//idx为要调整的节点下标
//由上自下开始调整堆元素，使其满足条件
template<class T>
void heap_adjust(T arr[], int size, int idx)
{
	assert(arr);
	T tmp=arr[idx]; //临时保存
	int left=2*idx +1, right= 2*idx +2;
	int next;
	T *pChg=0;
	while(left < size) //直到左子节点存在
	{
		pChg = &arr[left];
		next = left;
		if((left+1) < size && arr[left+1] > arr[left]) //如果右子节点也存在,且大于左子结点
		{
			pChg = &arr[left+1];
			next = left+1;
		}

		if(tmp >= *pChg) //满足大顶堆定义
			break;
		
		//不满足大顶堆条件，则往下筛
		arr[idx] = *pChg;
		idx = next;
		left = 2*idx + 1;
	}
	//退出之后，最后节点pChg 为tmp
	arr[idx] = tmp;

	for (int i=0;i<size;++i)
		cout<<arr[i]<<" ";
	cout<<endl;
}

//从size/2开始，也就是从第一个父节点开始往上调用堆调整函数
template<class T>
void heap_init(T arr[], int size)
{
	//从最后一个父节点往前直到顶
	for(int root=(size-1-1)/2;root>=0;--root)
		heap_adjust(arr,size,root);
}

template<class T>
void heap_sort(T arr[], int size)
{
	heap_init(arr,size);
	while(size>0)
	{
		_swap(arr[0],arr[size-1]);
		--size;
		heap_adjust(arr,size,0);
	}
}

//方案2，类似快排的partition算法,第k大，也就是从小到大排
template<class Type>
Type kth_elem_partition(Type arr[], int size, int k)
{
	assert(arr);	

	int begin=0,end=size-1;

	while(begin < end)
	{
#if 0
		for(int i=0;i<size;++i)
			cout<<arr[i]<<" ";
		cout<<endl;
#endif
		int mid1=begin,mid2=begin;
		int pivot=arr[end]; //选最后一个值为pivot
		for(;mid1<end;)
		{
			if(arr[mid1]<=pivot) //如果小于pivot，则begin++,end++
			{
				_swap(arr[mid1++],arr[mid2++]);
				continue;
			}
			++mid1;
		}
		
		_swap(arr[mid2],arr[end]);

		if(mid2 == k) return pivot;
		else if(mid2 < k)
		{
			begin=mid2 + 1;
		}else{
			end = mid2 - 1;
		}
	}
}


//求第k大的数，那么就是构造k的小顶堆
//咱们反过来，求第k小的数，构造k的大顶堆
void ch3_kth_elem()
{
	int t[]={3,-2,5,7,8,2,4,6,4,0,2,12,-21,3,9,10,-1,7,-6};
	//int t[]={-21,3, 4, 3, 2, 2, 4, -2, -1, 0, -6};
	int cache[20]={0};
	int k=-1;
	cout<<"输入k:"<<endl;
	cin>>k;

	heap_sort(t,sizeof(t)/sizeof(int));

	for (int i=0;i<sizeof(t)/sizeof(int);++i)
		cout<<t[i]<<" ";
	cout<<endl;

	cout<<"方案2: partition:";
	int t2[]={3,-2,5,7,8,2,4,6,4,0,2,12,-21,3,9,10,-1,7,-6};
	cout<<kth_elem_partition(t2,sizeof(t2)/sizeof(int),k)<<endl;
	for(int i=0;i<=k;i++)
		cout<<t2[i]<<" ";
	cout<<endl;
}


/************************************************************************/
/* 第4章 现场编写类似strstr/strcpy/strpbrk的函数
/************************************************************************/

typedef void (*run_problem)();

run_problem solutions[]=
{
	ch1_rotate_string,
	ch2_str_included,
	ch3_kth_elem,
};


int main(int argc, char * argv[])
{

#if 0
	char str[]="opqrstuvwxyzjihgfedcba";
	cout<<str<<endl;
	_qsort_v1(str,0,sizeof(str)-2);
	cout<<str<<endl;


	char str2[]="opqrstuvwxyzjihgfedcba";
	cout<<str2<<endl;
	_qsort_v2(str2,0,sizeof(str2)-2);
	cout<<str2<<endl;


	
	char str3[]="opqrstuvwxyzjihgfedcba";
	cout<<str3<<endl;
	_qsort_v3(str3,0,sizeof(str3)-2);
	cout<<str3<<endl;
	

#endif

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

