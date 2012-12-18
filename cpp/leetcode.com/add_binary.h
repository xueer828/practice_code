#ifndef _TEST_
#define _TEST_

// add_binary
// Copyright (c) 2012/12/18 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/

/*
Run Status: Accepted!
Program Runtime: 28 milli secs
Progress: 294/294 test cases passed.
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
using namespace std;

class Solution {
	
	unsigned b2i(const string& in)
	{
		unsigned int ret=0;
		int idx=0;
		while(idx<in.length())
		{
			ret = (ret<<1) + (in[idx]=='1'?1:0);
			++idx;
		}
		return ret;
	}

	string i2b(unsigned in)
	{
		string ret;

		while(in)
		{
			ret = (in%2==0?"0":"1")+ret;
			in >>= 1;
		}

		return ret.length()==0?"0":ret;
	}

public:
	string addBinary(string a, string b) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		//cannot use unsigned int for add, as it always overflow.
		/*
		unsigned tmp=b2i(a)+b2i(b);
		return i2b(tmp);
		*/

		int len_a(a.length()),len_b(b.length());

		
		int len_c = len_a>len_b?(len_a+1):(len_b+1);
		vector<unsigned char> arr_a(len_a),arr_b(len_b),arr_c(len_c);

		int idx=0;
		while(idx<len_a)
		{
			arr_a[len_a-idx-1]=a[idx]-'0';
			++idx;
		}
		idx=0;
		while(idx<len_b)
		{
			arr_b[len_b-idx-1]=b[idx]-'0';
			++idx;
		}

		//add
		int i=0;
		for(;i<len_a && i<len_b; ++i)
		{
			arr_c[i] += arr_a[i] + arr_b[i];
			arr_c[i+1] = arr_c[i]/2;
			arr_c[i] %= 2;
		}

		while(i<len_a)
		{
			arr_c[i] += arr_a[i];
			arr_c[i+1] = arr_c[i]/2;
			arr_c[i] %= 2;
			++i;
		}

		while(i<len_b)
		{
			arr_c[i] += arr_b[i];
			arr_c[i+1] = arr_c[i]/2;
			arr_c[i] %= 2;
			++i;
		}

		string ret;
		i=0;
		idx=0;
		bool flag=true;
		for(i=0;i<len_c;++i)
		{
			if(flag && arr_c[len_c-i-1]==0)
			{
				continue;
			}
			flag = false;
			ret += arr_c[len_c-i-1]+'0';
		}
		
		return (ret.length()==0?"0":ret);
	}
};

void solve()
{
	Solution s;
	cout<<"result:"<<s.addBinary("11","1")<<endl;
}

#endif