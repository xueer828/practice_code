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
����һ���㷨BM�㷨,һ������±�KMP�㷨��3~5��

Run Status: Accepted!
Program Runtime: 24 milli secs
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



void solve()
{

}

#endif




