// ACM_Entrance_WhiteBook_ch3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

/************************************************************************/
/* ch3 数组和字符串
/************************************************************************/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
using namespace std;

//e.g.3-2 蛇形填数,在n*n方阵里面填入1~n*n的数，要求蛇形，例如n=4如下， （n<=8)
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
		for(i=lefttop_row;i<rightbot_row;++i) data[i][rightbot_col]=++idx; //最右边
		for(i=rightbot_col;i>lefttop_col;--i) data[rightbot_row][i]=++idx; //最下边
		for(i=rightbot_row;i>lefttop_row;--i) data[i][lefttop_row]=++idx; //最左边
		for(i=lefttop_col;i<rightbot_col;++i) data[lefttop_row][i]=++idx; //最上边
		++lefttop_row, ++lefttop_col;
		--rightbot_row,--rightbot_col; //缩小外框
	}
	
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<n;++j)
			cout<<data[i][j]<<" ";
		cout<<endl;
	}

}

//额外，S型打印,从最左上角一直打印到最右下角
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
	while(col < n) //先打印左上半边
	{
		//先打印从上往下的斜线
		while(col >= 0) data[row++][col--]= ++idx;
		//超界了,恢复回来
		++col;
		//打印从下往上的斜线
		while(row >= 0) data[row--][col++]= ++idx;
		++row;
	}

	--col,++row;

	while(1)
	{
		//从上往下打印
		while(row <= bot) data[row++][col--] = ++idx;
		--row;col+=2;
		//从下往上
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

//额外2，螺旋队列, 例如1左边(0,0),x方向向右为正，反之为负，
//如下，7坐标为(-1,-1),编程实现输入任意点的坐标，输出对应的数字
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
	//每一层的最后一个数是固定的n*n, n为层数
	//如果坐标(x,y) 内层数目m=(2*(max(x,y)+1)-1)^2   (即2*n+1的平方数)
	//右边为m+(x1-x),下边，m+x+(y1-y)


	int m = max(abs(x),abs(y)); //边长

	int n=(2*(m-1)+1)*(2*(m-1)+1); //内层最大的数

	//最右边
	if(x == m) return n + m + y;

	n += m+1;

	//最下边

	if(y==m) return n + m - x;

	n += m+1;

	//最左边

	if(x == -m) return n + m - y;

	n+= m+1;

	//最上边

	if(y == -m) return n + m  + x;	

}

//eg3_5 最长回文子串 (不完美解法)
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

	len = j; //更新为有效的字符长度

	for(int i=0;i<len;++i) //起始位置
	{
		for(int j=i;j<len;++j) //子串终止位置
		{
			bool flag=true;
			//判断字符(i,j)是否为回文
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

//eg3_5, 最长回文串，完美解法，根据中间游标往两边比较，然后得出最长回文串
//注意从中间往两边要考虑奇数和偶数情况

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

	for(i=0;i<len;++i) //回文串的中间游标
	{
		for(int j=0;i>j && i+j<len; ++j) //探测回文子串为奇数长度的情况
		{
			if(data[i-j]!=data[i+j])
				break;
			else if(max_len < 2*j + 1)
				max_len = 2*j + 1;
		}

		for(int j=0;i>j && i+j+1<len;++j) //探测偶数长度的情况
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

//课后题3-4,计算器
//一行恰好包含一个加号，减号或者乘号的表达式，输出它的值（运算数位非负整数，运算符为2元）
void practice_3_4_Cacl()
{
	int op1,op2;
	char op[256];
	while(1)
	{
		scanf("%d%s%d\n",&op1,op,&op2); //!错误，这样读入"1+1"是不对的，仅仅读入1 和 +1, 后面的1被当做字符处理了
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

