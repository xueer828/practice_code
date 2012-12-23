#ifndef _TEST_
#define _TEST_

// best_time_to_buy_and_sell_stock3
// Copyright (c) 2012/12/21 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

/*
Solution 1 超时 TLE, small test 全通过
*/

//思路同best_time_to_buy_and_sell_stock2, 求出每个一直单调上升通道能得到的最大值,然后取和的前2名



#include <cstdio>
#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <deque>
using namespace std;

class Solution1 {

	int maxProfitPart(vector<int>& prices, int beg, int end)
	{
		if(beg >= end)
			return 0;

		int max_profit=0;
		int min_buy=prices[beg];
		for(int i=beg+1;i<=end;++i)
		{
			if(prices[i]-min_buy>max_profit)
				max_profit = prices[i]-min_buy;
			if(min_buy > prices[i])
				min_buy = prices[i];
		}

		return max_profit;
	}
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		int max_profit=0;
		int len=prices.size();
        for(int i=0;i<len;++i)
		{
			int t=maxProfitPart(prices,0,i) + maxProfitPart(prices,i,len-1);
			if(max_profit < t)
				max_profit = t;
		}

		return max_profit;
    }
};

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		int len=prices.size();

		if(len <= 1)
			return 0;

		vector<int> sections; //saving every single ascend queue section
		int sec_min=prices[0],sec_max=prices[0];

		for(int i=1;i<len;++i)
		{
			if(sec_max < prices[i]) //ascend
			{
				sec_max = prices[i];
				if(i==len-1) //last one
				{
					int tmp=sec_max - sec_min;
					if(tmp > 0)
						sections.push_back(tmp);
				}
			}else{ //non-ascend
				int tmp=sec_max - sec_min;
				if(tmp > 0)
					sections.push_back(tmp);
				sec_max = sec_min = prices[i];
			}
		}

		len = sections.size();
		if( len <= 0)
			return 0;

		sort(sections.begin(),sections.end());

		if(len >=2)
		{
			return sections[len-1]+sections[len-2];
		}else{
			return sections[len-1];
		}
	}
};


void solve()
{
	Solution s;
	vector<int> a(5);
	a[0]=2;
	a[1]=1;
	a[2]=2;
	a[3]=0;
	a[4]=1;

	cout<<s.maxProfit(a)<<endl;
}

#endif