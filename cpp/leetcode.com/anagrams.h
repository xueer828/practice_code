#ifndef _TEST_
#define _TEST_

// anagrams
// Copyright (c) 2012/12/20 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/


/*
Solution 1
Run Status: Accepted!
Program Runtime: 232 milli secs
Progress: 95/95 test cases passed.
*/

/*
Solution 2
Run Status: Accepted!
Program Runtime: 216 milli secs
Progress: 95/95 test cases passed.
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

class Solution1 {
public:
	vector<string> anagrams(vector<string> &strs) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		map<string, vector<int> > tub;

		vector<string> copied(strs);
		vector<string> result;

		for(int i=0;i<copied.size();++i)
		{
			sort(copied[i].begin(),copied[i].end());
			tub[copied[i]].push_back(i);
		}

		map<string, vector<int> >::iterator it=tub.begin();
		for(;it!=tub.end();++it)
		{
			if(it->second.size()>1) // at least more than 1 strings
			{
				vector<int> &t=it->second;
				for(int j=0;j<t.size();++j)
				{
					result.push_back(strs[t[j]]);
				}
			}
		}

		return result;
	}
};

class Solution2 {
	//string hash function
	unsigned int BKDRHash(string str)
	{
		unsigned int seed=131;
		unsigned int hash=0;

		int idx=0;
		while(idx<str.size())
		{
			hash = hash*seed + (str[idx++]);
		}

		return (hash&0x7fffffff);
	}

public:
	vector<string> anagrams(vector<string> &strs) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		map<unsigned, vector<int> > tub;

		vector<string> copied(strs);
		vector<string> result;

		for(int i=0;i<copied.size();++i)
		{
			sort(copied[i].begin(),copied[i].end());
			tub[BKDRHash(copied[i])].push_back(i);
		}

		map<unsigned, vector<int> >::iterator it=tub.begin();
		for(;it!=tub.end();++it)
		{
			if(it->second.size()>1) // at least more than 1 strings
			{
				vector<int> &t=it->second;
				for(int j=0;j<t.size();++j)
				{
					result.push_back(strs[t[j]]);
				}
			}
		}

		return result;
	}
};

void solve()
{
	Solution1 s1;
	Solution2 s2;

}

#endif