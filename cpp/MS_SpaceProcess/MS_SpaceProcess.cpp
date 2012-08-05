// MS_SpaceProcess.cpp : Defines the entry point for the console application.
//
/************************************************************************/
/* 已知一个字符串, 只含常见可打印ascii字符以及空格和换行, 要求进行如下过滤:
1, 过滤掉前导空白和后导空白;
2, 中间的连续空白字符, 只保留一个;
3, 删除换行前后的空白字符;                                                  
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
		if(*p == ' ')//skip空格
		{ 
			p++; 
			space = true;
		} 
		else if(*p == '\n') //碰到\n，不需要添加空格
		{
			space = false;
			pre_ch = '\n';
			*later++ = *p++;
		}else{
			if(space && pre_ch != '\n' && pre_ch != 0) //对于其它字符，如果前面非空字符不是\n或者字符串前导，则后面补上一个空格
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

