#ifndef _TEST_
#define _TEST_

// zigzag_conversion
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

/*
Run Status: Accepted!
Program Runtime: 104 milli secs
Progress: 1158/1158 test cases passed.
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
	string convert(string s, int nRows) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function    
		int sz=s.length();
		if(sz <= 0 || nRows <= 1)
			return s;

		vector<string> v(nRows,"");

		int cnt=0;
		for(;cnt < sz;)
		{
			int i=0;
			for(i=0;i<=nRows-1 && cnt < sz;++i)
				v[i] += s[cnt++];

			int j=0;
			for(j=nRows-2;j>0 && cnt < sz; --j)
				v[j] += s[cnt++];

		}

		string r("");
		for(int i=0;i<nRows;++i)
			r += v[i];

		return r;
	}
};

void solve()
{
	Solution s;
	cout<<s.convert("PAYPALISHIRING", 2)<<endl;
}

#endif