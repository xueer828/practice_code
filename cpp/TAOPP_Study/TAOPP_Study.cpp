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

	int m,k;
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

