#ifndef _TEST_
#define _TEST_

// plus_one
// Copyright (c) 2013/4/28 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a number represented as an array of digits, plus one to the number.
 */

/*
一次性AC, 水题
Run Status: Accepted!
Program Runtime: 16 milli secs
Progress: 108/108 test cases passed.
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
	vector<int> plusOne(vector<int> &digits) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		assert(digits.size() > 0);

		int sz=digits.size(),i=sz-1;
		for(;i>=0;--i)
		{
			digits[i] += 1;
			if(digits[i] < 10)
				break;
			else
				digits[i] %= 10;
		}

		if(i < 0) //表示还需要继续进位
			digits.insert(digits.begin(),1);

		return digits;
	}
};

void solve()
{
}

#endif 