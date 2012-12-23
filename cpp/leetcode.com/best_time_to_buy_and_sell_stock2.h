#ifndef _TEST_
#define _TEST_

// best_time_to_buy_and_sell_stock2
// Copyright (c) 2012/12/22 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

//˼·,�����(���������ܵĶ�)��������������������,�������;�보������,��һֱ������ͨ���е�ʱ��,����,һ������ƽ�Ȼ��ͷ�͹�,������,�趨��ǰ
//ֵΪ�����ͺ����ֵ,��Ѱ�ȴ���һ������ͨ��(������ͨ����ֻ�������ֵ,���ֵ����).��!

/*
Run Status: Accepted!
Program Runtime: 40 milli secs
Progress: 198/198 test cases passed.
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cstdlib>
using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int len=prices.size();
		if(len <= 1)
			return 0;

		int sec_min=prices[0],sec_max=prices[0];
		int profile=0;

		for(int i=1;i<len;++i)
		{
			if(prices[i]>prices[i-1]) // ascend 
			{
				sec_max = prices[i];
				if(i == len-1) // to the end, should sell all
					profile += sec_max - sec_min;
			}else{ // with trend of descend or non-ascend
				profile += sec_max - sec_min;
				sec_min = sec_max = prices[i];
			}
		}

		return profile;
	}
};

void solve()
{
	Solution s;
	vector<int> tmp;
	tmp.push_back(1);
	tmp.push_back(2);
	tmp.push_back(4);

	cout<<s.maxProfit(tmp)<<endl;
}

#endif