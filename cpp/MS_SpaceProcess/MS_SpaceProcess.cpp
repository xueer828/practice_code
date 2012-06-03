// MS_SpaceProcess.cpp : Defines the entry point for the console application.
//
/************************************************************************/
/* ��֪һ���ַ���, ֻ�������ɴ�ӡascii�ַ��Լ��ո�ͻ���, Ҫ��������¹���:
1, ���˵�ǰ���հ׺ͺ󵼿հ�;
2, �м�������հ��ַ�, ֻ����һ��;
3, ɾ������ǰ��Ŀհ��ַ�;                                                  
/************************************************************************/

#include "stdafx.h"
#include "iostream"

using namespace std;

void SpaceProcess(char* pstr)
{
	//assert(pstr);
	cout<<pstr<<":";
	char pre_ch=0,*p=pstr,*later=pstr;
	bool space=false;
	while(*p != '\0')
	{
		if(*p == ' ')//skip�ո�
		{ 
			p++; 
			space = true;
		} 
		else if(*p == '\n') //����\n������Ҫ��ӿո�
		{
			space = false;
			pre_ch = '\n';
			*later++ = *p++;
		}else{
			if(space && pre_ch != '\n' && pre_ch != 0) //���������ַ������ǰ��ǿ��ַ�����\n�����ַ���ǰ��������油��һ���ո�
			{
				*later++ = ' ';
			}
			space = false;
			pre_ch = *p;
			*later ++ = *p++;
			
		}
	}
	*later = 0;

	cout<<pstr<<"|"<<endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char a1=-106;
	char b1= -128;
	cout<<(int)((char)0xff)<<endl;
	
	return 0;
	//testing
	// Test cases for leading & trailing spaces.
	char arr00[] = "hello_world";
	char arr01[] = "hello world";
	char arr02[] = "  hello world";
	char arr03[] = "hello world  ";
	char arr04[] = "  hello world  ";
	// Test cases for consecutive  spaces.
	char arr05[] = "hello    world";
	char arr06[] = "  hello    world  ";
	// Test cases for spaces around new-lines.
	char arr07[] = "hello  \n   world  ";
	char arr08[] = "  hello    world   \n ";
	char arr09[] = "\n  hello    world   \n ";
	// Corner cases
	char arr10[] = "   ";
	char arr11[] = "\n";
	char arr12[] = "  \n  ";

	SpaceProcess(arr00);
	SpaceProcess(arr01);
	SpaceProcess(arr02);
	SpaceProcess(arr03);
	SpaceProcess(arr04);
	SpaceProcess(arr05);
	SpaceProcess(arr06);
	SpaceProcess(arr07);
	SpaceProcess(arr08);
	SpaceProcess(arr09);
	SpaceProcess(arr10);
	SpaceProcess(arr11);
	SpaceProcess(arr12);
	
	unsigned short a=0xABCD;

	cout<<hex<<(((a>>8)&0x00ff)|((a<<8)&0xff00))<<endl;
	
	return 0;
}

