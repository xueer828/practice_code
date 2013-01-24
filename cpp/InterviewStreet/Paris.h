#ifndef _TEST_
#define _TEST_

// Paris
// Copyright (c) 2013/01/25 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
https://www.interviewstreet.com/challenges/dashboard/#problem/4e14b83d5fd12

Given N numbers , [N<=10^5] we need to count the total pairs of numbers that have a difference of K. [K>0 and K<1e9]

Input Format:
1st line contains N & K (integers).
2nd line contains N numbers of the set. All the N numbers are assured to be distinct.
Output Format:
One integer saying the no of pairs of numbers that have a diff K.

Sample Input #00:
5 2
1 5 3 4 2

Sample Output #00:
3
*/

//一次通过,感想,最简单的方法最有效,别整没用的

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
	int n,k;
	cin>>n>>k;
	vector<int> arr(n);

	for(int i=0;i<n;++i)
		cin>>arr[i];

	sort(arr.begin(),arr.end());

	int beg(0),end(0),count(0);
	while(beg < n && end < n)
	{
		int tmp=arr[beg]+k;
		while(end < n && tmp > arr[end]) ++end;

		if(end >= n)
			break;

		if(tmp==arr[end])
		{
			++count,++beg,++end;
		}
		else{
			++beg;
		}
	}

	cout<<count<<endl;

}

#endif