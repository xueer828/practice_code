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

	cout<<begin<<"|"<<mid<<"|"<<end<<"|"<<t<<"|"<<pivot<<endl;

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

	_swap(*p_pivot,*(t+lo)); //����Ԫ�������ʼ

	while(hi<=end)
	{
		while(t[hi]>t[begin]) ++hi;
		//����lo��hi��ֵ��lo�����ƶ���hiҲ�����ƶ�
		if(lo != hi)
			_swap(t[lo],t[hi]);
		++lo, ++hi;
	}
	//��ʱ����begin��ֵ��loλ�õ�ֵ���н���
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

