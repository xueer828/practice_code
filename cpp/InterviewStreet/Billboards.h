#ifndef _TEST_
#define _TEST_

// Billboards
// Copyright (c) 2013/01/27 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
https://www.hackerrank.com/challenges/billboards

广告牌

Billboards
Billboards(20 points)

ADZEN is a very popular advertising firm in your city. In every road you can see their advertising billboards. Recently they are facing a serious challenge , MG Road the most used and beautiful road in your city has been almost filled by the billboards and this is having a negative effect on the natural view.

On people’s demand ADZEN has decided to remove some of the billboards in such a way that there are no more than K billboards standing together in any part of the road.



You may assume the MG Road to be a straight line with N billboards.Initially there is no gap between any two adjecent billboards.



ADZEN’s primary income comes from these billboards so the billboard removing process has to be done in such a way that the billboards remaining at end should give maximum possible profit among all possible final configurations.Total profit of a configuration is the sum of the profit values of all billboards present in that configuration.



Given N,K and the profit value of each of the N billboards, output the maximum profit that can be obtained from the remaining billboards under the conditions given.



Input description 

Ist line contain two space seperated integers N and K. Then follow N lines describing the profit value of each billboard i.e ith line contains the profit value of ith billboard.

Sample Input
6 2 
1
2
3
1
6
10 

Sample Output
21

Explanation

In given input there are 6 billboards and after the process no more than 2 should be together.
So remove 1st and 4th billboards giving a configuration _ 2 3 _ 6 10 having a profit of 21. No other configuration has a profit more than 21.So the answer is 21.

Constraints
1 <= N <= 1,00,000(10^5)
1 <= K <= N
0 <= profit value of any billboard <= 2,000,000,000(2*10^9) //很有可能超int最大值
*/

//思路,DP问题, DP 公式: 
//f(n) = max{ a[n] + f(n-2) | 空着 n-1; a[n] + a [n-1] + f(n-3) | 空着 n-2; 
// 一直到满足a[n..n-(k-1)]}
//f(n) 表示 n 为最后一个的情况下,满足要求的 最大值

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

void solve()
{
	int n,k,max_val(0);
	cin>>n>>k;
	vector<unsigned long long> arr(n);
	for(int i=0;i<n;++i)
		cin>>arr[i];

	vector<unsigned long long> DP(n,0);

	DP[0]=arr[0];
	for(int i=1;i<n;++i)
	{
		unsigned long long tmp=0;
		DP[i] = DP[i-1];

		int j=i;
		for(;j>=0 && j>=i-k+1;--j)
		{
			tmp += arr[j];
			unsigned long long tmp2=tmp;
			if(j >= 2)
				tmp2 += DP[j-2];

			if(tmp2 > DP[i])
				DP[i]=tmp2;
			if(max_val < DP[i])
				max_val = DP[i];			
		}
	}

	cout<<max_val<<endl;
}

#endif