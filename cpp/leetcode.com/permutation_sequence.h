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
//solution1 大数据 TLE 
/*
Run Status: Time Limit Exceeded
Last executed input
9, 296662
*/

/*
思路2: 直接递归调用,已知不可能重复
Run Status: Accepted!
Program Runtime: 1684 milli secs
Progress: 200/200 test cases passed.
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
	int cnt;
	bool used[10];
	//str表示当前状态, c是当前填充位置,n是最高位置,k是所求位置
	bool get_permutation_cursive(string& str,int c,int n, int k)
	{
		if(c >= n) //排列完成
		{
			++cnt;
			//cout<<cnt<<":"<<str<<endl;
			if(cnt == k) //满足
			{
				return true;
			}
			return false;
		}

		//从1到n 尝试填入位置c
		for(int i=0;i<n;++i)
		{
			if(!used[i]){ //未用过,则使用它
				used[i]=true;
				str[c]='0'+i+1;
				if(get_permutation_cursive(str,c+1,n,k)) //剪枝,只需要一个结果,满足则回溯
					return true;
				used[i]=false;
			}
		}
		
		return false;
	}
public:
	string getPermutation(int n, int k) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		cnt = 0;
		string str;
		for(int i=0;i<n;++i)
		{
			str += '0';
			used[i]=false;
		}

		if(get_permutation_cursive(str,0,n,k))
		{
			return str;
		}
		
		return "";
	}
};

void solve()
{
	Solution s;
	cout<<s.getPermutation(3,4)<<endl;
}

#endif 