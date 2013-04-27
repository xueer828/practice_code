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

//˼·: ���Ƚ�interval����,�Ե�һ����Ϊ��һ����Ҫ��,�ڶ���Ϊ�ڶ�����Ҫ��,Ȼ��������ڶεĺϲ�

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
        
		//��������
		vector<Interval> iv(intervals);
		vector<Interval> rs;

		sort(iv.begin(),iv.end(),sort_intervals);

		int cur_start=iv[0].start;
		int cur_end=iv[0].end;
		for(int i=0;i<iv.size()-1;++i)
		{
			if(cur_end >= iv[i+1].start) //����һ����overlap
			{
				if(cur_end < iv[i+1].end) //���end�ӳ���,����������
					cur_end = iv[i+1].end;

			}else{ //���ظ�
				rs.push_back(Interval(cur_start,cur_end));

				//����
				cur_start = iv[i+1].start;
				cur_end = iv[i+1].end;
			}
		}
		rs.push_back(Interval(cur_start,cur_end)); //���һ��


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