#ifndef _TEST_
#define _TEST_

// longest_palindromic_substring
// Copyright (c) 2013/01/07 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

//最长的回文字符串,manacher算法最直接,后缀数组解法最广

//这里使用manacher算法 (这个算法很牛掰)
/*
以下是mancher算法的要点,算法复杂度为O(n), 另当前已经能算出的最远的回文串的中心为位置id, 其回文串长度为P[id], 那么已知的回文串覆盖到最右边的位置令为mx=id+P[id]; 
1) 算法的基础: 在已经算出的回文串的基础上,进行最远推导
2) 如果将要求的位置i不在mx的覆盖范围内,那么就不能进行推导,只能老老实实以i为中心一步一步比较得出P[i]的值
3) 如果在mx的范围之内,那么就可以进行如下推导;
    我们能得到i以id为中心的对称点令为j = (2*id - i), 这个时候因为P[j]已经算出来了 (j<id<i)
	3a) 如果mx-i >= P[j] 也就是说 j对应点i的回文长度P[i]=P[j] 因为j的整个对称匹配长度都在mx覆盖的范围以内
	3b) 如果mx-i < P[j] 那么, 令P[i]=(mx-i), 然后再继续往后老老实实以j为中心进行匹配
	3总结) 实际上观察可以知道 P[i] = min{(mx-i), P[j]}; 如果P[i]==mx-i 然后再继续往后老实匹配
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

		string new_str="?"; //以'?'字符为首,防止越界,因为此字符肯定是只出现过一次 :-)

		for(int i=0;i<sz;++i)
		{
			new_str += "#";
			new_str += s[i];
		}
		new_str += "#";

		//初始化完毕,最开始添加了一个只出现一次的字符, 然后将字符串转换为奇数长度字符串

		//从第一个字符开始
		int sz2=new_str.length();
		vector<int> p;
		p.resize(sz2); //构造回文长度数组

		int mx=0,id=0,mx_s=0,mx_p=0;
		for(int i=1;i<sz2;++i) //这里i从1开始,就是为了避免越界
		{
			if(mx > i) //如果最远位置mx能够cover所要求的i位置,那么就先进行推导
				p[i]=min(p[2*id-i],mx-i); //p[i]=min{p[j],mx-i};
			else
				p[i]=1;

			while(i+p[i]<sz2 && new_str[i+p[i]] == new_str[i-p[i]]) ++p[i]; //老老实实进行匹配

			if(mx < i+p[i]) //更新mx为回文串最远能够到达的位置
			{
				mx = i+p[i]; //更新mx和对应的id
				id=i;
			}

			if(mx_s < p[i]) //最长的回文串即为P[i]-1
			{
				mx_s = p[i];
				mx_p = i;
			}
		}

		string ret;
		//cout<<mx_s<<":"<<mx_p<<":"<<new_str<<endl;
		//最长为mx_s-1,位置为新字符串中mx_p
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