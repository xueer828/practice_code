#ifndef _TEST_
#define _TEST_

// longest_substring_without_repeating_characters
// Copyright (c) 2013/01/07 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/

//一前一后,两个指针,空间复杂度O(256)字符串词典数,时间复杂度O(n)

/*
Run Status: Accepted!
Program Runtime: 56 milli secs
Progress: 1001/1001 test cases passed.
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
	int lengthOfLongestSubstring(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		int sz=s.length();
		if(sz<=0)
			return 0;

		int beg(0),end(0);

		int strmap[256];
		for(int i=0;i<256;++i)
			strmap[i]=-1;

		int cnt=0;
		for(;end<sz;++end)
		{
			char t=s[end];
			if(strmap[t]!=-1) //已经在前面的子字符串中了,那么beg指针就要后跳到原来这个字符串之后,并更新新的字符串位置
			{
				int i=beg;
				beg = strmap[t]+1;
				for(;i<strmap[t]+1;++i)
					strmap[s[i]]=-1; //清除标记
			}

			strmap[t] = end; //更新

			if(cnt < end-beg + 1)
			{
				//cout<<beg<<":"<<end<<endl;
				cnt = end - beg + 1;
			}
		}

		return cnt;
	}
};

void solve()
{
	Solution s;
	cout<<s.lengthOfLongestSubstring("abbabababa")<<endl;
	cout<<s.lengthOfLongestSubstring("")<<endl;
	cout<<s.lengthOfLongestSubstring("bbbbb")<<endl;
}

#endif