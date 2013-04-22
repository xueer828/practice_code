#ifndef _TEST_
#define _TEST_

// longest_consecutive_sequence
// Copyright (c) 2013/4/20 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
*/

//先将元素放置于hash表中,然后,遍历元素,对相邻元素进行合并

/*
Run Status: Accepted!
Program Runtime: 100 milli secs
Progress: 67/67 test cases passed.
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
#include <unordered_map>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int sz=num.size();
		if(sz<=0)
			return 0;

		unordered_map<int,int> range; //利用hash map记录可能的最长range
		//第一个参数和第二个参数互为pair

		unordered_map<int,int> exists; //表面此数字是否已经考虑过了

		int cnt=0;

		for(int i=0;i<sz;++i)
		{
			if(exists.count(num[i]))
				continue;
			exists[num[i]] = 1;
			int left(num[i]),right(num[i]);
			//判断num[i]的前一个元素是否已经在map中,且其对应range小于num[i]-1
			while(range.count(left-1) && range[left-1] <= left-1)
			{
				int new_left=range[left-1]; //更新
				//剔除原来range里对应 num[i]-1 的值
				range.erase(left-1);
				if(left-1 != new_left) //避免重复删除
					range.erase(new_left);
				left=new_left;
			}

			//判断num[i]的后一个元素是否已经在map中,且对应range大于num[i]+1
			while(range.count(num[i]+1) && range[num[i]+1] >= num[i]+1)
			{
				int new_right=range[right+1]; //更新
				//
				range.erase(right+1);
				if(right+1 != new_right) //避免重复删除
					range.erase(new_right);
				right=new_right;
			}

			range[left]=right;
			if(right != left) //避免重复插入
				range[right]=left;

			if(cnt < right - left + 1)
				cnt = right - left + 1;
		}

		return cnt;
	}
};


void solve()
{
	Solution s;
	vector<int> t;
	/*t.push_back(100);
	t.push_back(4);
	t.push_back(200);
	t.push_back(1);
	t.push_back(3);
	t.push_back(2);*/

	t.push_back(-7);
	t.push_back(-7);
	t.push_back(-1);
	t.push_back(3);
	t.push_back(-9);
	t.push_back(-4);
	t.push_back(7);t.push_back(-3);t.push_back(2);t.push_back(4);t.push_back(9);t.push_back(4);
	t.push_back(-9);t.push_back(8);t.push_back(-7);t.push_back(5);t.push_back(-1);t.push_back(-7);


	cout<<s.longestConsecutive(t)<<endl;

	sort(t.begin(),t.end());


}

#endif 