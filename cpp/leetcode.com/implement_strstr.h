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
Solution 1 小数据可以过,大数据差点超时, 其实循环终止的判断可以根据
当前判断的字符串的长度和模式串的长度直接终止判断,从而避开TLE超时,后面会给
另外一种算法Sunday算法,一般情况下比KMP算法很多倍

Run Status: Accepted!
Program Runtime: 24 milli secs
Progress: 67/67 test cases passed.
*/

/*
Sunny字符匹配算法
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
		//}while(*cur != 0) //这里的根据当前字符串和模式串的长度大小比较之后就可以终止循环而避过TLE超时了

		return NULL;
	}
};


//Sunday 算法,匹配速度快,而且简单易懂
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

		//构造字符滑动跳转表
		int jump[charsz];
		for(int i=0;i<charsz;++i)
			jump[i] = len_pat + 1; //初始化所有字符为模式串长+1,即在不匹配的时候,将整个模式串划过去

		for(int i=0;i<len_pat;++i)
			jump[pat[i]]=len_pat - i; //滑动距离

		//开始匹配
		int j=0;
		while(j<=len_txt-len_pat)
		{
			int i=0;
			while(i<len_pat && txt[j+i] == pat[i]) ++i; //从前往后,直到不等或者 匹配完成

			if(i==len_pat) // found
			{
				return txt + j;
			}

			//not found
			j += jump[txt[j+len_pat]]; //j向后滑动,注意这里探查的是原串跟模式串对齐的后一个字符
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

