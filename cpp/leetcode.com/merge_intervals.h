#ifndef _TEST_
#define _TEST_

// merge_intervals
// Copyright (c) 2013/4/25 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
 */

//思路: 首先将interval排序,以第一个数为第一排序要素,第二数为第二排序要素,然后进行相邻段的合并

/*
Run Status: Accepted!
Program Runtime: 76 milli secs
Progress: 168/168 test cases passed.
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

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

struct Interval{
	int start,end;
	Interval():start(0),end(0){};
	Interval(int s,int e):start(s),end(e){};
};

bool sort_intervals(const Interval& i1, const Interval& i2)
{
	return i1.start < i2.start || (i1.start == i2.start && i1.end < i2.end);
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if(intervals.size()<=0)
			return intervals;
        
		//首先排序
		vector<Interval> iv(intervals);
		vector<Interval> rs;

		sort(iv.begin(),iv.end(),sort_intervals);

		int cur_start=iv[0].start;
		int cur_end=iv[0].end;
		for(int i=0;i<iv.size()-1;++i)
		{
			if(cur_end >= iv[i+1].start) //跟后一段有overlap
			{
				if(cur_end < iv[i+1].end) //如果end延长了,则做出更新
					cur_end = iv[i+1].end;

			}else{ //无重复
				rs.push_back(Interval(cur_start,cur_end));

				//更新
				cur_start = iv[i+1].start;
				cur_end = iv[i+1].end;
			}
		}
		rs.push_back(Interval(cur_start,cur_end)); //最后一个


		return rs;
    }
};

void solve()
{
	vector<Interval> v;
	v.push_back(Interval(4,5));
	v.push_back(Interval(1,4));
	v.push_back(Interval(0,1));

	Solution s;
	s.merge(v);
}

#endif 