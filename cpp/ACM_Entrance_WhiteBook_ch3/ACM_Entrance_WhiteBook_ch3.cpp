// ACM_Entrance_WhiteBook_ch3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/************************************************************************/
/* ch3 ������ַ���
/************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

//e.g.3-2 ��������,��n*n������������1~n*n������Ҫ�����Σ�����n=4���£� ��n<=8)
/*
10 11 12 1
9  16 13 2
8  15 14 3
7  6  5  4
*/

int const MAX_N=8;
void eg_3_2_out_snake_n(int n)
{
	int data[MAX_N][MAX_N]={0};
	int last=n*n;
	int idx=0;

	int lefttop_row=0,lefttop_col=0;
	int rightbot_row=n-1,rightbot_col=n-1;

	while(idx < last )
	{
		int i;
		for(i=lefttop_row;i<rightbot_row;++i) data[i][rightbot_col]=++idx; //���ұ�
		for(i=rightbot_col;i>lefttop_col;--i) data[rightbot_row][i]=++idx; //���±�
		for(i=rightbot_row;i>lefttop_row;--i) data[i][lefttop_row]=++idx; //�����
		for(i=lefttop_col;i<rightbot_col;++i) data[lefttop_row][i]=++idx; //���ϱ�
		++lefttop_row, ++lefttop_col;
		--rightbot_row,--rightbot_col; //��С���
	}
	
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
			cout<<data[i][j]<<" ";
		cout<<endl;
	}

}

//���⣬S�ʹ�ӡ,�������Ͻ�һֱ��ӡ�������½�
/*
1 3  4  10
2 5  9  11
6 8  12 15
7 13 14 16
*/

void eg_3_ex_out_S_array(int n)
{
	int data[MAX_N][MAX_N]={0};
	int last=n*n;
	int part=last/2;
	int left=0,bot=n-1;

	int idx=0;
	int row=0,col=0;
	while(col < n) //�ȴ�ӡ���ϰ��
	{
		//�ȴ�ӡ�������µ�б��
		while(col >= 0) data[row++][col--]= ++idx;
		//������,�ָ�����
		++col;
		//��ӡ�������ϵ�б��
		while(row >= 0) data[row--][col++]= ++idx;
		++row;
	}

	--col,++row;

	while(1)
	{
		//�������´�ӡ
		while(row <= bot) data[row++][col--] = ++idx;
		--row;col+=2;
		//��������
		while(col <= bot) data[row--][col++] = ++idx;
		--col;row+=2;
		if(idx == last) break;
	}

	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
			cout<<data[i][j]<<" ";
		cout<<endl;
	}
	
}

//����2����������, ����1���(0,0),x��������Ϊ������֮Ϊ����
//���£�7����Ϊ(-1,-1),���ʵ���������������꣬�����Ӧ������
/*
21 22 23  24 25
20  7  8  9  10
19  6  1  2  11
18  5  4  3   2
17 16 15 14  13
*/
//
int eg_3_ex_out_cicle_xy(int x,int y)
{
	//ÿһ������һ�����ǹ̶���n*n, nΪ����
	//�������(x,y) �ڲ���Ŀm=(2*(max(x,y)+1)-1)^2   (��2*n+1��ƽ����)
	//�ұ�Ϊm+(x1-x),�±ߣ�m+x+(y1-y)


	int m = max(abs(x),abs(y)); //�߳�

	int n=(2*(m-1)+1)*(2*(m-1)+1); //�ڲ�������

	//���ұ�
	if(x == m) return n + m + y;

	n += m+1;

	//���±�

	if(y==m) return n + m - x;

	n += m+1;

	//�����

	if(x == -m) return n + m - y;

	n+= m+1;

	//���ϱ�

	if(y == -m) return n + m  + x;	

}

//eg3_5 ������Ӵ� (�������ⷨ)
void eg_3_5_get_max_huiwen1(const char* str)
{
	assert(str);

	int len=strlen(str);
	int max_len=0;
	int max_i=-1;

	char* data=new char[len+1];
	int i=0,j=0;
	for(i=0;i<len;i++)
	{
		if(str[i]>='a'&& str[i]<='z')
			data[j++]=str[i];
		else if(str[i]>='A'&&str[i]<='Z')
			data[j++]=str[i]+'a'-'A';
	}
	data[j]='\0';

	len = j; //����Ϊ��Ч���ַ�����

	for(int i=0;i<len;++i) //��ʼλ��
	{
		for(int j=i;j<len;++j) //�Ӵ���ֹλ��
		{
			bool flag=true;
			//�ж��ַ�(i,j)�Ƿ�Ϊ����
			for(int k=i;k<=j;++k)
				if(data[k]!=data[j+i-k]) 
				{
					flag=false;
					break;
				}
			if(flag && max_len<j-i+1)
			{
				max_len = j-i+1;
				max_i=i;
			}			
		}
	}
	
	cout<<"the max: "<<max_len<<endl;	

	delete []data;
}

//eg3_5, ����Ĵ��������ⷨ�������м��α������߱Ƚϣ�Ȼ��ó�����Ĵ�
//ע����м�������Ҫ����������ż�����

void eg_3_5_get_max_huiwen2(const char* str)
{
	assert(str);

	int len=strlen(str);
	char* data=new char[len+1];
	int i,m=0;
	for(i=0;i<len;i++)
	{
		if(str[i]>='a' && str[i]<='z')
			data[m++]=str[i];
		else if(str[i]>='A' && str[i] <= 'Z')
			data[m++]=str[i]+'a'-'A';
	}
	data[m]='\0';

	len = m;
	int max_len=0;

	for(i=0;i<len;++i) //���Ĵ����м��α�
	{
		for(int j=0;i>j && i+j<len; ++j) //̽������Ӵ�Ϊ�������ȵ����
		{
			if(data[i-j]!=data[i+j])
				break;
			else if(max_len < 2*j + 1)
				max_len = 2*j + 1;
		}

		for(int j=0;i>j && i+j+1<len;++j) //̽��ż�����ȵ����
		{
			if(data[i-j]!=data[i+j+1])
				break;
			else if(max_len < 2*(j+1))
				max_len = 2*(j+1);
		}
	}

	cout<<"the max: "<<max_len<<"\n";

	delete[] data;
}

//�κ���3-4,������
//һ��ǡ�ð���һ���Ӻţ����Ż��߳˺ŵı��ʽ���������ֵ��������λ�Ǹ������������Ϊ2Ԫ��
void practice_3_4_Cacl()
{
	int op1,op2;
	char op[256];
	while(1)
	{
		scanf("%d%s%d\n",&op1,op,&op2); //!������������"1+1"�ǲ��Եģ���������1 �� +1, �����1�������ַ�������
		if(op1==0 && strcmp(op,"")==0)
			break;
		if(strchr(op,'*'))
			cout<<op1*op2<<endl;
		else if(strchr(op,'-'))
			cout<<op1-op2<<endl;
		else if(strchr(op,'+'))
			cout<<op1+op2<<endl;
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	//eg_3_2_out_snake_n(8);
	//eg_3_ex_out_S_array(8);

	//cout<<eg_3_ex_out_cicle_xy(0,-1);

	//eg_3_5_get_max_huiwen1("Confuciuss say: Madam,I'm Adam.");
	//eg_3_5_get_max_huiwen2("Confuciuss say: Madam,I'm Adam.");

	//practice_3_4_Cacl();


	return 0;
}

