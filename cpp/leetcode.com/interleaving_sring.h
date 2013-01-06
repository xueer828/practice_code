#ifndef _TEST_
#define _TEST_

// interleaving_sring
// Copyright (c) 2013/01/05 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

//判断是否可以被交叉构成,可递归搜索判断

/*
小数据通过,大数据超时了TLE
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
	bool isInterleave(string s1, string s2, string s3) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function    

		int len_s1=s1.length(),len_s2=s2.length(),len_s3=s3.length();

		if(len_s1+len_s2 != len_s3)
			return false;

		if(len_s1 == 0)
			return s2==s3;

		if(len_s2 == 0)
			return s1==s3;

		string s1_tmp=s1,s2_tmp=s2,s3_tmp=s3;
		//以下均为非0
		if(s1[0] == s3[0])
		{
			if(isInterleave(s1_tmp.erase(0,1),s2_tmp,s3_tmp.erase(0,1)))
				return true;
		}

		s1_tmp=s1,s2_tmp=s2,s3_tmp=s3;

		if(s2[0] == s3[0])
		{
			if(isInterleave(s1_tmp,s2_tmp.erase(0,1),s3_tmp.erase(0,1)))
				return true;
		}

		return false;
	}
};

void solve()
{
	Solution s;
	cout<<s.isInterleave(string("aabcc"),string("dbbca"),string("aadbbcbcac"))<<endl;
	cout<<s.isInterleave(string("aabcc"),string("dbbca"),string("aadbbbaccc"))<<endl;
}

#endif