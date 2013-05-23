#ifndef _TEST_
#define _TEST_

// unique_binary_search_trees
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given n, how many structurally unique BST's (binary search trees) that store values 1...n?

For example,
Given n = 3, there are a total of 5 unique BST's.

1         3     3      2      1
\       /     /      / \      \
3     2     1      1   3      2
/     /       \                 \
2     1         2                 3
*/

/*
������,�ǵݹ�,��Ҫ����Ƽ�·ͼ����,���ܿ�������

����:��1..n-1�����ֳ�2����,һ���ִ���λ��n�ĸ��ڵ�,һ����λ��n�����ӽڵ�
��ʽ: f(n) = sum( f(x) * f(n-1-x))  x from 0 to n-1.  ע�������и����⴦��f(0) =1

Run Status: Accepted!
Program Runtime: 12 milli secs
Progress: 14/14 test cases passed.
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
	vector<int> v;
	
public:

	int numTrees(int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		if(n > v.size())
			v.resize(n+1);

		if(v[n])
			return v[n];

		if(n<=0)
			return (v[0]=1); //��Ϊ������Ҳ������Ϊ�ǿ���
		
		if(n==1)
			return (v[n]=1);

		v[n]=0;

		for(int i=0;i<=n-1;++i)
		{
			v[n] += numTrees(i)*numTrees(n-1-i);
		}

		return v[n];
	}
};

void solve()
{
	Solution s;
	cout<<s.numTrees(4000)<<endl;
}

#endif