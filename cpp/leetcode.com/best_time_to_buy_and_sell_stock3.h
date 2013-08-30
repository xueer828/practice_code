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

//思路2, 因为最多能够买2次,也就是说能买一次或者两次,并且两次持有股票的时间不重叠,那么一个直接的思路就是
//分成两段,分别求各段的买一次所能获得的最大值,然后求两段(或最头起最尾起的一段)的和的最大值,即为所求

/*
Run Status: Accepted!
Program Runtime: 64 milli secs
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
		
		int sz=prices.size();
		if(sz <= 0)
			return 0;

		vector<int> psum(sz,0);
		
		int tmn(prices[0]);
		psum[0]=0;

		for(int i=1;i<sz;++i)
		{
			//更新当前能获得的最大值=max{prices[i-1],a[i]-tmn}
			if(prices[i] - tmn > psum[i-1])
				psum[i]=prices[i]-tmn;
			else
				psum[i]=psum[i-1];

			//更新min值
			if(tmn > prices[i])
				tmn = prices[i];
		}

		int mx=psum[sz-1];
		int tmx = prices[sz-1],pmx=0;
		//另一半从后往前
		for(int i=sz-1;i>=0;--i)
		{
			if(tmx - prices[i] > pmx)
				pmx = tmx - prices[i];
			
			if(mx < pmx + psum[i])
				mx = pmx + psum[i];

			if(prices[i] > tmx)
				tmx = prices[i];
		}

		return mx;
	}
};


void solve()
{
	Solution s;
	vector<int> a(3);
	a[0]=1;
	a[1]=4;
	a[2]=3;
	//a[3]=0;
	//a[4]=1;

	cout<<s.maxProfit(a)<<endl;
}

#endif