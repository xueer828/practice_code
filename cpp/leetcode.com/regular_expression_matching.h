#ifndef _TEST_
#define _TEST_

// regular_expression_matching
// Copyright (c) 2013/5/8 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") ? false
isMatch("aa","aa") ? true
isMatch("aaa","aa") ? false
isMatch("aa", "a*") ? true
isMatch("aa", ".*") ? true
isMatch("ab", ".*") ? true
isMatch("aab", "c*a*b") ? true
 */

/*
Run Status: Accepted!
Program Runtime: 64 milli secs
Progress: 439/439 test cases passed.

//��һ��,�ǳ�������,����ƥ��not so easy.
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

//����ʽƥ��һ���õݹ���ʵ��,��Ϊ������������̰��ƥ��,�Ӻ���ǰƥ��

class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function    
		if(!s || !p) return false;

		if(*p == 0) return *s==0;

		if(*(p+1) == '*') //���� .* �� x* �������
		{
			while(*p==*s || (*p=='.' && *s)) //����ÿ����ȵ��ַ������г��Աȶ�
			{
				if(isMatch(s++,p+2))  //
					return true;	
			}
			return isMatch(s,p+2); //�ڳ��Դ���֮��,���в���չƥ��
		}else{
			if(*p == *s || (*p == '.' && *s))
				return isMatch(++s,++p);
		}

		return false;
	}
};

void solve()
{
	Solution s;
	s.isMatch("aaa","a*a");
}

#endif 