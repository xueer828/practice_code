#ifndef _TEST_
#define _TEST_

// best_time_to_buy_and_sell_stock
// Copyright (c) 2012/12/21 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Say you have an array for which the i-th element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

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

    	if(prices.size()<= 0)
    		return 0;

    	int max_diff(0),min_val(prices[0]);
        for(int i=1;i<prices.size();++i)
        {
        	if(max_diff < prices[i]-min_val)
        	{
        		max_diff = prices[i]-min_val;
        	}

        	if(min_val > prices[i])
        	{
        		min_val = prices[i];
        	}
        }

        return max_diff;        
    }
};


void solve()
{
	Solution s;
}

#endif