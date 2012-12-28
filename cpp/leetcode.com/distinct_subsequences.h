#ifndef _TEST_
#define _TEST_

// distinct_subsequences
// Copyright (c) 2012/12/26
// Author: xdutaotao (xdutaotao@gmail.com)
//

/*
Given a string S and a string T, count the number of distinct subsequences of T in S.

A subsequence of a string is a new string which is formed from the original string by
deleting some (can be none) of the characters without disturbing the relative positions
 of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).

Here is an example:
S = "rabbbit", T = "rabbit"

Return 3.
*/

//思路:求T是S的多少种不同的的子串,换个思路,实际是求有多少种不同的方式(删或者不删)可以通过T得到S
//递归,对源字符串的每个字符进行枚举,选择和不选择

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

struct Contexts
{
	int visible;
	string str;
	Contexts():visible(0),str(""){}
	Contexts(int v,string& s): visible(v),str(s) {}
};

class Solution {
	vector<Contexts> stk;

public:
	int numDistinct(string S, string T) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		if(S.length() < T.length())
			return 0;

		stk.clear();

		int len=S.length(),cnt(0);
		while(1)
		{
			int sz=stk.size();

			if( sz == len) // all into stack
			{
			    Contexts& top=stk[sz-1];
				//check string
				if(top.str == T)
					++cnt;

				//backtrace (pop top) till cannot do it
				while(1)
				{
                    if(stk.empty()) //finished
                        return cnt;

                    int cur_sz = stk.size();
                    if(stk[cur_sz-1].visible == 0)
                    {
                        int tmp_len=stk[cur_sz-1].str.length();
                        if(tmp_len==0 || (T[tmp_len] == S[cur_sz-1]))
                        {
                            //meet, and continue
                            stk[cur_sz-1].visible = 1;
                            stk[cur_sz-1].str += (char)S[cur_sz-1];
                            break;
                        }
                    }
					stk.pop_back();
				}

			}else{
			    string cur_str("");
			    if(sz > 0)
                    cur_str = stk[sz-1].str;

				//continue push
				Contexts ctx(0,cur_str);
				stk.push_back(ctx);
			}
		}

		return cnt;
	}
};

void solve()
{
    Solution s;
    cout<<s.numDistinct(string("rabbbit"),string("rabbit"))<<endl;
}

#endif
