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
小数据通过,大数据超时了TLE,递归算法肯定还是有点问题
*/

//思路2, DP? 公式: DP[i][j] = 
// OR { DP[i-1][j] if s1[i]==s3[i+j] 
//      DP[i][j-1] if s2[i]==s3[i+j] }

/*
DP pass 大数据也过了 DP
Run Status: Accepted!
Program Runtime: 16 milli secs
Progress: 99/99 test cases passed.
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

		string s1_tmp,s2_tmp,s3_tmp;
		//以下均为非0
		if(s1[0] == s3[0])
		{
			s1_tmp=s1,s2_tmp=s2,s3_tmp=s3;
			if(isInterleave(s1_tmp.erase(0,1),s2_tmp,s3_tmp.erase(0,1)))
				return true;
		}	

		if(s2[0] == s3[0])
		{
			s1_tmp=s1,s2_tmp=s2,s3_tmp=s3;
			if(isInterleave(s1_tmp,s2_tmp.erase(0,1),s3_tmp.erase(0,1)))
				return true;
		}

		return false;
	}
};

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		//DP
		int len_s1=s1.length(),len_s2=s2.length(),len_s3=s3.length();
		if(len_s1 + len_s2 != len_s3)
			return false;

		if(len_s1==0)
			return s2==s3;

		if(len_s2 == 0)
			return s1==s3;

		vector<vector<int> > DP(len_s1+1,vector<int>(len_s2+1));

		//初始化
		DP[0][0]=1;

		//初始化s1前缀和s3前缀相等的DP数组
		for(int i=1;i<=len_s1;++i)
		{
			if(s1[i-1]==s3[i-1])
				DP[i][0]=DP[i-1][0]*1;
			else
				DP[i][0]=0;
		}

		//初始化s2前缀和s3前缀相等的DP数组
		for(int i=1;i<=len_s2;++i)
		{
			if(s2[i-1]==s3[i-1])
				DP[0][i]=DP[0][i-1]*1;
			else
				DP[0][i]=0;
		}

		//进行DP推断
		for(int i=1;i<=len_s1;++i)
			for(int j=1;j<=len_s2;++j)
			{
				DP[i][j]=0;
				if(s1[i-1]==s3[i+j-1] && DP[i-1][j])
					DP[i][j]=1;

				if(s2[j-1]==s3[i+j-1] && DP[i][j-1])
					DP[i][j]=1;
			}

		return (DP[len_s1][len_s2]==1);

	}
};

void solve()
{
	Solution s;
	cout<<s.isInterleave(string("aa"),string("ab"),string("abaa"))<<endl;
	cout<<s.isInterleave(string("aabcc"),string("dbbca"),string("aadbbbaccc"))<<endl;
}

#endif