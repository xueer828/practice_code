// TAOPP_Study.cpp : Defines the entry point for the console application.
//

#include "..\CommonHeader.h"

//http://www.cnblogs.com/v-July-v/archive/2011/06/02/2091171.html
//TAOPP ǰ10�½�

/************************************************************************
��һ�¡�����ת�ַ���
�ڶ��¡��ַ����Ƿ��������
�����¡�Ѱ����С��k����
����������Top K�㷨�����ʵ��
����������������ѡ��SELECT�㷨�����������ʵ��
��֮�������������и����±������ڵĵ�KС����Ԫ��
�����¡��ֳ���д����strstr/strcpy/strpbrk�ĺ���
�����¡�Ѱ����������������������
�����¡����500�����ڵ��׺���
�����¡������������������
�ڰ��¡���ͷ��β��̸�麯��
�ھ��¡��л�����׷������
��ʮ�¡���θ�10^7���������Ĵ����ļ�����
/************************************************************************/


/************************************************************************/
/* ��һ�¡�����ת�ַ���
/************************************************************************/
//mΪ�����ַ������ȣ�nΪ��Ҫ��ת��ǰn���ַ�
//˼·1���ֳ������𲽽�����O(m+n)�����ڽ�������
void rotate_string1(char str[],int m, int n)
{
	assert(str);
	int k=(m+n)%m;
	if (k == 0) return; //����Ҫ��ת

	int beg1=0,beg2=k,mid=k;
	for(;;)
	{
		_swap(str[beg1++],str[beg2++]);
		if (beg2 == m) //���浽�����
		{
			if(beg1 == mid)
				return; //�����ת
			else
				//ǰ������̣�������beg1����,beg2���mid��
				beg2 = mid;
		}else if(beg1 == mid) //ǰ�浽��mid�����Ǻ���û�е���last
		{
			mid=beg2; //����midλ��
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

//˼·2���������ȸ����ڲ���ת��Ȼ���ⲿ���巴ת��O(2n),�����ڽ�������
void rotate_string2(char str[], int m, int n)
{
	assert(str);
	int k=(m+n)%m;

	if(k==0) return;

	_reverse(str,str+k-1);
	_reverse(str+k,str+m-1);
	_reverse(str,str+m-1);
}

//�����Լ��
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

//˼·3��random iterater������STL rotate�㷨
//�㷨���Ӷ�O(n)
void rotate_string3(char str[],int m, int n)
{
	assert(str);
	int k=(m+n)%m; //ͳһnΪ��������n>m�����
	int groups=_gcd(m,k);
	while(groups--)
	{
		//���ڵ�ǰgroups��ѭ���������и�ֵ
		char tmp=str[groups];
		int last=groups;
		for(int j=(groups+k)%m;j!=groups;j=(j+k)%m)
		{
			str[last] = str[j];
			last = j; //ѭ������ֵ
		}
		str[last] = tmp; //�ʼ��ֵ����ѭ����ĩβ��λ��

	}
}

//�����ַ�����һ����3��˼·
void ch1_rotate_string()
{
	char test_str[]="abcdefghijk";

	int k;
	cout<<"Input Number of Left Rotate Chars:";
	cin>>k;

	//˼·1����ָ���𲽽���
	rotate_string1(test_str,sizeof(test_str)-1,k);
	cout<<test_str<<endl;

	rotate_string2(test_str,sizeof(test_str)-1,k);
	cout<<test_str<<endl;

	rotate_string3(test_str,sizeof(test_str)-1,k);
	cout<<test_str<<endl;

}


/************************************************************************/
/* �ڶ��¡��ַ����Ƿ��������
/************************************************************************/

//����1������+���ƹ鲢�ıȽ�

//�����ǿ���

// T ��������֧�� operator <
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
	//ȡ�ʼ�����β���м�Ԫ�ص���ֵ,�������Ա�֤lo,hi����Խ��
	T *p_pivot=const_cast<T*>(_get_mid(t+lo,t+((lo+hi)>>1),t+hi));

	//����������Ԫ�ŵ�����endλ����(�������endλ����)
	if(p_pivot!=t+end)
		_swap(*p_pivot,*(t+end));
	T pivot=t[end];
	//cout<<"MID:"<<t[lo]<<"|"<<t[((lo+hi)>>1)]<<"|"<<t[hi]<<":"<<pivot<<endl;
	--hi;
	while(true)
	{
		while(t[lo]<pivot) ++lo; //�ҵ�>=pivot��Ԫ�ؾ�ͣ����
		while(pivot<t[hi]) --hi; //�ҵ�<=pivot��Ԫ�ؾ�ͣ����

		if(lo >= hi) { mid=lo; break; } //�Ѿ���ɱ��λ���
		_swap(t[lo],t[hi]); //����

		++lo,--hi;
	}
	//������ǰmidԪ�غ���Ԫ
	_swap(t[mid],t[end]);

	//cout<<begin<<"|"<<mid<<"|"<<end<<"|"<<t<<"|"<<pivot<<endl;

	if(begin<mid-1)
		_qsort_v1(t,begin,mid-1);
	if(mid+1<end)
		_qsort_v1(t,mid+1,end);	
}

//�Ż��汾2
template<class T>
void _qsort_v2(T t[],int begin, int end)
{
	assert(t);
	if(begin >= end) return;

	int lo=begin,hi=begin,mid=((begin+end)>>1);
	//ȡ��ʼ����β���м���ֵ����ֵ���Ա���ƽ��
	T *p_pivot=const_cast<T*>(_get_mid(t+begin,t+mid,t+end));

	if(p_pivot != t+begin)
		_swap(*p_pivot,*(t+begin)); //����Ԫ�������ʼ

	for(hi=begin+1;;)
	{
		while(hi<=end && t[hi] > t[begin]) ++hi;
		if(hi>end) break;
		//����lo��hi��ֵ��lo�����ƶ���hiҲ�����ƶ�
		_swap(t[++lo],t[hi]);
		++hi; //��hi���滻��hi���������ƶ�
	}

	//system("pause");
	
	//��ʱ����begin��ֵ��loλ�õ�ֵ���н���
	if(lo != begin)
		_swap(t[lo],t[begin]);

	cout<<begin<<"|"<<lo<<"|"<<end<<"|"<<t<<"|"<<t[lo]<<endl;
	
	if(begin < lo -1)
		_qsort_v2(t,begin,lo-1);
	if(lo+1 < end)
		_qsort_v2(t,lo+1,end);
}

//�Ż��汾3����ʵ���汾2����,��õķ���
template<class T>
void _qsort_v3(T t[],int begin, int end)
{
	assert(t);
	if(begin >= end) return;

	T *p_pivot=const_cast<T*>(_get_mid(t+begin,t+(begin+end)/2,t+end));
	//��pivot�����������
	if(p_pivot != t+end)
		_swap(t[end],*p_pivot);
	int lo=begin,hi;
	for(hi=begin;hi<end;++hi)
	{
		if (t[hi]<t[end]) //t[end]��pivot
			_swap(t[hi],t[lo++]);
	}

	//��pivot��lo��λ�ý��н���
	_swap(t[lo],t[end]);

	if(begin < lo-1)
		_qsort_v3(t,begin,lo-1);
	if(lo+1 < end)
		_qsort_v3(t,lo+1,end);
}

bool _str_included_v1(string str1,string str2)
{
	//�ȶ����ַ���������O(nlgn)
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

//����2����Ȼ��򵥵ģ�O(n+m)��hashtable�㷨

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
/* �����£�Ѱ����С�ĵ�K������������С��K����
/* ����1������K�󶥶ѣ��㷨���Ӷ�O(klgk)+O((n-k)lgk)=O(nlgk)
/* ����2�����ƿ��ŵ�patition��selection���㷨���Ӷ���ýӽ�O(n),����,
/* �����Ԫѡȡ����������ֵ���м�ֵѡ��
/************************************************************************/

//����1������󶥶�

//��0λ��Ϊ�����������ӽڵ�Ϊ2*i+1 �� 2*(i+1)
//i�ڵ�ĸ��ڵ�Ϊ(i-1)/2
//idxΪҪ�����Ľڵ��±�
//�������¿�ʼ������Ԫ�أ�ʹ����������
template<class T>
void heap_adjust(T arr[], int size, int idx)
{
	assert(arr);
	T tmp=arr[idx]; //��ʱ����
	int left=2*idx +1, right= 2*idx +2;
	int next;
	T *pChg=0;
	while(left < size) //ֱ�����ӽڵ����
	{
		pChg = &arr[left];
		next = left;
		if((left+1) < size && arr[left+1] > arr[left]) //������ӽڵ�Ҳ����,�Ҵ������ӽ��
		{
			pChg = &arr[left+1];
			next = left+1;
		}

		if(tmp >= *pChg) //����󶥶Ѷ���
			break;
		
		//������󶥶�������������ɸ
		arr[idx] = *pChg;
		idx = next;
		left = 2*idx + 1;
	}
	//�˳�֮�����ڵ�pChg Ϊtmp
	arr[idx] = tmp;

	for (int i=0;i<size;++i)
		cout<<arr[i]<<" ";
	cout<<endl;
}

//��size/2��ʼ��Ҳ���Ǵӵ�һ�����ڵ㿪ʼ���ϵ��öѵ�������
template<class T>
void heap_init(T arr[], int size)
{
	//�����һ�����ڵ���ǰֱ����
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

//����2�����ƿ��ŵ�partition�㷨,��k��Ҳ���Ǵ�С������
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
		int pivot=arr[end]; //ѡ���һ��ֵΪpivot
		for(;mid1<end;)
		{
			if(arr[mid1]<=pivot) //���С��pivot����begin++,end++
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


//���k���������ô���ǹ���k��С����
//���Ƿ����������kС����������k�Ĵ󶥶�
void ch3_kth_elem()
{
	int t[]={3,-2,5,7,8,2,4,6,4,0,2,12,-21,3,9,10,-1,7,-6};
	//int t[]={-21,3, 4, 3, 2, 2, 4, -2, -1, 0, -6};
	int cache[20]={0};
	int k=-1;
	cout<<"����k:"<<endl;
	cin>>k;

	heap_sort(t,sizeof(t)/sizeof(int));

	for (int i=0;i<sizeof(t)/sizeof(int);++i)
		cout<<t[i]<<" ";
	cout<<endl;

	cout<<"����2: partition:";
	int t2[]={3,-2,5,7,8,2,4,6,4,0,2,12,-21,3,9,10,-1,7,-6};
	cout<<kth_elem_partition(t2,sizeof(t2)/sizeof(int),k)<<endl;
	for(int i=0;i<=k;i++)
		cout<<t2[i]<<" ";
	cout<<endl;
}


/************************************************************************/
/* ��4�� �ֳ���д����strstr/strcpy/strpbrk�ĺ���
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

