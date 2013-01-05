#ifndef _TEST_
#define _TEST_

// insert_interval
// Copyright (c) 2013/01/05 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

//˼·:�ǳ�����͵��߶���

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

struct Interval{
	int start;
	int end;
	Interval():start(0),end(0){}
	Interval(int s, int e):start(s),end(e){}
};

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<Interval> entry(intervals);
		//��������,���Ѿ�������ʼʱ���ź�����,����Ҫ
		//����new����ʼʱ��,Ҳ����һ����ȥ
		vector<Interval>::iterator it=entry.begin();
		for(;it != entry.end();++it)
		{
			if(it->start > newInterval.start || 
				(it->start==newInterval.start && it->end < newInterval.end ))
			{
				break;
			}
		}

		entry.insert(it,newInterval); //�����½ڵ���

		//�ж��Ƿ��и���
		


    }
};

void solve()
{

}

#endif