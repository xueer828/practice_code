#ifndef _TEST_
#define _TEST_

// longest_palindromic_substring
// Copyright (c) 2013/01/07 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

//��Ļ����ַ���,manacher�㷨��ֱ��,��׺����ⷨ���

//����ʹ��manacher�㷨 (����㷨��ţ��)
/*
������mancher�㷨��Ҫ��,�㷨���Ӷ�ΪO(n), ��ǰ�Ѿ����������Զ�Ļ��Ĵ�������Ϊλ��id, ����Ĵ�����ΪP[id], ��ô��֪�Ļ��Ĵ����ǵ����ұߵ�λ����Ϊmx=id+P[id]; 
1) �㷨�Ļ���: ���Ѿ�����Ļ��Ĵ��Ļ�����,������Զ�Ƶ�
2) �����Ҫ���λ��i����mx�ĸ��Ƿ�Χ��,��ô�Ͳ��ܽ����Ƶ�,ֻ������ʵʵ��iΪ����һ��һ���Ƚϵó�P[i]��ֵ
3) �����mx�ķ�Χ֮��,��ô�Ϳ��Խ��������Ƶ�;
    �����ܵõ�i��idΪ���ĵĶԳƵ���Ϊj = (2*id - i), ���ʱ����ΪP[j]�Ѿ�������� (j<id<i)
	3a) ���mx-i >= P[j] Ҳ����˵ j��Ӧ��i�Ļ��ĳ���P[i]=P[j] ��Ϊj�������Գ�ƥ�䳤�ȶ���mx���ǵķ�Χ����
	3b) ���mx-i < P[j] ��ô, ��P[i]=(mx-i), Ȼ���ټ�����������ʵʵ��jΪ���Ľ���ƥ��
	3�ܽ�) ʵ���Ϲ۲����֪�� P[i] = min{(mx-i), P[j]}; ���P[i]==mx-i Ȼ���ټ���������ʵƥ��
 */

/*
Run Status: Accepted!
Program Runtime: 52 milli secs
Progress: 86/86 test cases passed.
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

class Solution {
public:
	string longestPalindrome(string s) {
		int sz=s.length();
		if(sz <= 0)
			return string("");

		string new_str="?"; //��'?'�ַ�Ϊ��,��ֹԽ��,��Ϊ���ַ��϶���ֻ���ֹ�һ�� :-)

		for(int i=0;i<sz;++i)
		{
			new_str += "#";
			new_str += s[i];
		}
		new_str += "#";

		//��ʼ�����,�ʼ�����һ��ֻ����һ�ε��ַ�, Ȼ���ַ���ת��Ϊ���������ַ���

		//�ӵ�һ���ַ���ʼ
		int sz2=new_str.length();
		vector<int> p;
		p.resize(sz2); //������ĳ�������

		int mx=0,id=0,mx_s=0,mx_p=0;
		for(int i=1;i<sz2;++i) //����i��1��ʼ,����Ϊ�˱���Խ��
		{
			if(mx > i) //�����Զλ��mx�ܹ�cover��Ҫ���iλ��,��ô���Ƚ����Ƶ�
				p[i]=min(p[2*id-i],mx-i); //p[i]=min{p[j],mx-i};
			else
				p[i]=1;

			while(i+p[i]<sz2 && new_str[i+p[i]] == new_str[i-p[i]]) ++p[i]; //����ʵʵ����ƥ��

			if(mx < i+p[i]) //����mxΪ���Ĵ���Զ�ܹ������λ��
			{
				mx = i+p[i]; //����mx�Ͷ�Ӧ��id
				id=i;
			}

			if(mx_s < p[i]) //��Ļ��Ĵ���ΪP[i]-1
			{
				mx_s = p[i];
				mx_p = i;
			}
		}

		string ret;
		//cout<<mx_s<<":"<<mx_p<<":"<<new_str<<endl;
		//�Ϊmx_s-1,λ��Ϊ���ַ�����mx_p
		if(new_str[mx_p]!='#' && new_str[mx_p]!='*' && new_str[mx_p]!='?')
			ret = new_str[mx_p];
		else
			ret = "";
		for(int i=mx_p+1;i<mx_p+mx_s;++i)
		{
			if(new_str[i]!='#' && new_str[i]!='?')
				ret = new_str[i] + ret + new_str[i];
		}
		return ret;
	}
};

void solve()
{
	Solution s;
	cout<<s.longestPalindrome("ababababa")<<endl;
}

#endif