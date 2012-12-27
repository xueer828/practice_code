#ifndef _TEST_
#define _TEST_

// decode_ways
// Copyright (c) 2012/12/26 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
*/

//思路:应该是递推,公式: 
// f(n) 代表计算第n个的时候的数目 = 求和{
// f(n-2)*1 | 与前面连接而成的和数 小于等于 26 大于 0, 且第一个数字不为0
// f(n-1)*1 | 此数大于0
// }

/*
Run Status: Accepted!
Program Runtime: 8 milli secs
Progress: 255/255 test cases passed.
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
	int numDecodings(string s) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int len=s.length();
		if(len <=0 || s[0]=='0')
			return 0;

		int pre_f,pre_f2,cur;
		//对于非0开头
		pre_f = 1;
		pre_f2 = 0;
		
		for(int i=1;i<len;++i)
		{
			cur = 0;
			//combin previous digit
			if(s[i-1]!='0')
			{
				int dig=(s[i-1]-'0')*10+s[i]-'0';
				if(dig > 0 && dig <= 26) //ok
				{
					if(i==1)
						pre_f2 = 1;
					
					cur += pre_f2*1;
				}else{
					cur += pre_f2*0;
				}
			}

			//singe digit
			if(s[i]>'0')
			{
				cur += pre_f * 1; 
			}else{
				cur += pre_f * 0;
			}

			pre_f2 = pre_f;
			pre_f = cur;
		}

		return pre_f;
	}
};

void solve()
{
	Solution s;
	cout<<s.numDecodings("12");
}

#endif