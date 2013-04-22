#ifndef _TEST_
#define _TEST_

// letter_combinations_of_a_phone_number
// Copyright (c) 2013/01/07 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

no graph

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

/*
Run Status: Accepted!
Program Runtime: 12 milli secs
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

const string strmap[]={" ","@","abc","def","ghi","jkl","mno",
	"pqrs","tuv","wxyz"};

class Solution {

private:
	vector<string> recusive_letter_combin(string digits,int i)
	{
		if(i >= digits.length()){
			vector<string> tmp;
			tmp.push_back("");
			return tmp;
		}

		vector<string> t=recusive_letter_combin(digits,i+1);

		string mp=strmap[digits[i]-'0'];
		int len=mp.length();
		vector<string> ret(t.size()*len);

		vector<string>::iterator it=t.begin();
		int cnt=0;
		for(;it!=t.end();++it)
		{
			for(int i=0;i<len;++i)
			{
				ret[cnt++]=(mp[i]+*it);
			}
		};

		return ret;
	}
	
public:
	vector<string> letterCombinations(string digits) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		return recusive_letter_combin(digits,0);

	}
};

void solve()
{
	Solution s;
	vector<string> tmp = s.letterCombinations("23");
}

#endif