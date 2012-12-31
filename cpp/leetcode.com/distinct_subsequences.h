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

//˼·:��T��S�Ķ����ֲ�ͬ�ĵ��Ӵ�,����˼·,ʵ�������ж����ֲ�ͬ�ķ�ʽ(ɾ���߲�ɾ)����ͨ��T�õ�S
//�ݹ�,��Դ�ַ�����ÿ���ַ�����ö��,ѡ��Ͳ�ѡ��

/*
Solution 1: С�����ܹ�,�����ݹ�����
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

struct Contexts
{
	int visible;
	string str;
	Contexts():visible(0),str(""){}
	Contexts(int v,string& s): visible(v),str(s) {}
};

class Solution1 {
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

class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        int slen=S.length();
        int tlen=T.length();
        if(slen < tlen)
            return 0;
        if(slen == tlen)
			return 1;

        int cnt=0;
        vector<vector<int> > DP(slen+1,vector<int>(tlen+1));

        //��ʼ��
        for(int i=0;i<=slen;++i)
            for(int j=0;j<tlen,++j)
                DP[i][j]=0;






        return cnt;
    }
};

void solve()
{
    Solution s;
    cout<<s.numDistinct(string("rabbbit"),string("rabbit"))<<endl;
}

#endif
