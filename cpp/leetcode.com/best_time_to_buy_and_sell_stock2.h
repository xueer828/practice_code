#ifndef _TEST_
#define _TEST_

// best_time_to_buy_and_sell_stock2
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
#include <stack>
using namespace std;

typedef struct node{
    int val;
    int idx;
    node(int v,int i):val(v),idx(i){}
}node;

class Solution {

    stack<node> queue1,queue2;

public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

        if (prices.size()<=0)
            return 0;
    	
        //push 1st element into q1
        node tmp(prices[0],0);
        queue1.push(tmp);

        int 
    }
};


void solve()
{
	Solution s;
}

#endif