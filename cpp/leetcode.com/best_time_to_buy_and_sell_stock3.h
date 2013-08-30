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
Solution 1 ��ʱ TLE, small test ȫͨ��
*/

//˼·ͬbest_time_to_buy_and_sell_stock2, ���ÿ��һֱ��������ͨ���ܵõ������ֵ,Ȼ��ȡ�͵�ǰ2��

//˼·2, ��Ϊ����ܹ���2��,Ҳ����˵����һ�λ�������,�������γ��й�Ʊ��ʱ�䲻�ص�,��ôһ��ֱ�ӵ�˼·����
//�ֳ�����,�ֱ�����ε���һ�����ܻ�õ����ֵ,Ȼ��������(����ͷ����β���һ��)�ĺ͵����ֵ,��Ϊ����

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
			//���µ�ǰ�ܻ�õ����ֵ=max{prices[i-1],a[i]-tmn}
			if(prices[i] - tmn > psum[i-1])
				psum[i]=prices[i]-tmn;
			else
				psum[i]=psum[i-1];

			//����minֵ
			if(tmn > prices[i])
				tmn = prices[i];
		}

		int mx=psum[sz-1];
		int tmx = prices[sz-1],pmx=0;
		//��һ��Ӻ���ǰ
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