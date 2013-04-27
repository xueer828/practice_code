#ifndef _TEST_
#define _TEST_

// multiply_strings
// Copyright (c) 2013/4/25 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
 */

//思路: 大数乘法,模拟乘法进行计算

/*
//注意,这里填充计算结果的数组,必须是int类型,最开始用char类型,结果溢出了,完全没有估计到
Run Status: Accepted!
Program Runtime: 56 milli secs
Progress: 311/311 test cases passed.
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
	string reverse_string(string str)
	{
		int s=0,e=str.length()-1;
		char tmp;
		while(s < e)
		{
			tmp=str[s];
			str[s]=str[e];
			str[e]=tmp;
			++s,--e;
		}
		return str;
	}
public:
	string multiply(string num1, string num2) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		//首先逆向乘数和被乘数
		string n1=reverse_string(num1),n2=reverse_string(num2);
		vector<int> rs;
		int len=n1.length()*n2.length()+10;
		rs.resize(len); //预留长度
		for(int i=0;i<len;++i) //初始化
			rs[i]=0;

		for(int i=0;i<n1.length();++i)
			for(int j=0;j<n2.length();++j)
			{
				rs[i+j] += (n1[i]-'0')*(n2[j]-'0');
			}

		for(int i=0;i<len-1;++i) //进位处理
		{
			rs[i+1] += rs[i]/10;
			rs[i] %= 10; 
		}

		bool skip=true;
		string res;
		for(int i=len-1;i>=0;--i)
		{
			if(skip && rs[i] != 0)
			{
				skip = false;
				res += rs[i]+'0';
			}else if(!skip){
				res += rs[i] + '0';
			}
		}

		if(res == "")
			res = "0";
		
		return res;
	}
};

void solve()
{
	Solution s;
	s.multiply("999","999");
}

#endif 