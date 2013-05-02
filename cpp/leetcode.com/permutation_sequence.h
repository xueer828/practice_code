#ifndef _TEST_
#define _TEST_

// permutation_sequence
// Copyright (c) 2013/4/28 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
 */

//求排列数,第k个排列序列,直接调用next_permuate() STL算法
//solution1 TLE 
/*
Run Status: Time Limit Exceeded
Last executed input
9, 296662
*/

/*
思路2: 感觉可以根据k的位置,先固定第一个字符
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
	string getPermutation(int n, int k) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		string s;
		for(int i=1;i<=n;++i)
			s += ('0'+i);

		int idx=0;
		while(++idx<k && next_permutation(s.begin(),s.end()));

		return s;
	}
};

class Solution {
	int factors[10];

	int get_fact(int n)
	{
		if(factors[n] !=-1)
			return factors[n];
		if(n == 0 || n==1)
			return (factors[0]=factors[1]=1);
		return (factors[n]=factors[n-1]*n);
	}
public:
	string getPermutation(int n, int k) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		for(int i=0;i<10;++i)
			factors[i]=-1;

		int start=1;
		for(;start<=9;++start)
		{
			if(get_fact(start)>=k)
				break;
		}

		--start;
		string s;
		if(start > 0)
		{
			s += ('0'+start);
		}
		
		for(int i=1;i<=n;++i)
		{
			if(start <= 0 || i != start)
				s += ('0'+i);
		}

		int idx = (start <= 0? 0: k-get_fact(start)-1);
		while(++idx<k && next_permutation(s.begin(),s.end()));

		return s;
	}
};

void solve()
{
	Solution s;
	cout<<s.getPermutation(3,2)<<endl;
}

#endif 