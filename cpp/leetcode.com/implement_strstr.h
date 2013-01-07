#ifndef _TEST_
#define _TEST_

// implement_strstr
// Copyright (c) 2013/01/05 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Implement strStr().

Returns a pointer to the first occurrence of needle in haystack, or null if needle is not part of haystack.
*/

/*
Solution 1 С���ݿ��Թ�,�����ݲ�㳬ʱ, ��ʵѭ����ֹ���жϿ��Ը���
��ǰ�жϵ��ַ����ĳ��Ⱥ�ģʽ���ĳ���ֱ����ֹ�ж�,�Ӷ��ܿ�TLE��ʱ,������
����һ���㷨Sunday�㷨,һ������±�KMP�㷨�ܶ౶

Run Status: Accepted!
Program Runtime: 24 milli secs
Progress: 67/67 test cases passed.
*/

/*
Sunny�ַ�ƥ���㷨
Run Status: Accepted!
Program Runtime: 20 milli secs
Progress: 67/67 test cases passed.
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <cstdlib>
using namespace std;

class Solution1 {
public:
	char *strStr(char *haystack, char *needle) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!haystack || !needle)
			return NULL;

		if(*needle == 0) return haystack;

		int len_str=strlen(haystack);
		int len_pat=strlen(needle);
		if(len_str < len_pat) return NULL;

		char* cur=haystack, *inner=cur,*pat=needle;
		
		do{
			while(1)
			{
				if(*pat == 0)
					return cur;

				if(*inner != *pat)
					break;
				++inner,++pat;
			}
			++cur;
			inner=cur;
			pat=needle;
		}while(*cur != 0 && strlen(cur) >= len_pat);
		//}while(*cur != 0) //����ĸ��ݵ�ǰ�ַ�����ģʽ���ĳ��ȴ�С�Ƚ�֮��Ϳ�����ֹѭ�����ܹ�TLE��ʱ��

		return NULL;
	}
};


//Sunday �㷨,ƥ���ٶȿ�,���Ҽ��׶�
class Solution {
	const static int charsz=128;
public:
	char *strStr(char *haystack, char *needle) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		int len_txt=strlen(haystack),len_pat=strlen(needle);

		if(len_pat == 0)
			return haystack;

		char *txt=haystack, *pat=needle;

		//�����ַ�������ת��
		int jump[charsz];
		for(int i=0;i<charsz;++i)
			jump[i] = len_pat + 1; //��ʼ�������ַ�Ϊģʽ����+1,���ڲ�ƥ���ʱ��,������ģʽ������ȥ

		for(int i=0;i<len_pat;++i)
			jump[pat[i]]=len_pat - i; //��������

		//��ʼƥ��
		int j=0;
		while(j<=len_txt-len_pat)
		{
			int i=0;
			while(i<len_pat && txt[j+i] == pat[i]) ++i; //��ǰ����,ֱ�����Ȼ��� ƥ�����

			if(i==len_pat) // found
			{
				return txt + j;
			}

			//not found
			j += jump[txt[j+len_pat]]; //j��󻬶�,ע������̽�����ԭ����ģʽ������ĺ�һ���ַ�
		}

		return NULL;
	}
};


void solve()
{
	Solution s;
	char a[100]={0},b[100]={0};
	strcpy(a,"mississippi");
	strcpy(b,"issi");
	s.strStr(a,b);
}

#endif

