#ifndef _TEST_
#define _TEST_

// combination_sum
// Copyright (c) 2012/12/23 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.

The same repeated number may be chosen from C unlimited number of times.

Note:
All numbers (including target) will be positive integers.
Elements in a combination (a1, a2, �� , ak) must be in non-descending order. (ie, a1 �� a2 �� �� �� ak).
The solution set must not contain duplicate combinations.
For example, given candidate set 2,3,6,7 and target 7, 
A solution set is: 
[7] 
[2, 2, 3] 
*/

//˼·,�ݹ�

/*
Run Status: Accepted!
Program Runtime: 124 milli secs
Progress: 168/168 test cases passed.
*/

//��Ȼͨ����,���Ǿ���ʵ�ֵķǳ�����,��Ҫ����̽�����������

/*
̽���ջ�: (����ǵݹ�ͻ�����Ҫע��ĵط�)
1) �������ֻ��Ҫ���һ���,��ôֻ��Ҫ�ڵݹ����,�ж��Ƿ��Ѿ��ó����,����ó��Ϳ��Է�����;�����Ҫ�������н��,��ô�ڵݹ���ϾͲ��ܷ���,����ָ����ν�ռ��趨,Ȼ����������п��ܵĽ�, (��ν�ݹ����ǵݹ�ĺ������õĵط�)
2) ����ÿһ�δӱ������巵�ص���һ�����,�������������Ĭ�ϵķ���,����Ҫ�Ա��ε��ù��������趨�Ľ�ռ�������.(����Ҫ)
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

class Solution {
	typedef vector<vector<int> > vvint;
	void combin_recusive(vector<int>& c,int target,  vector<int>& r, int n, int sum, vvint& entry)
	{
		if(sum == target)
		{
			//�ѽ��ѹ��
			vector<int> tmp;
			for(int i=0;i<c.size();++i)
				for(int j=0;j<r[i];++j)
					tmp.push_back(c[i]);
			//ѹ�������
			entry.push_back(tmp);

			//r[n-1]=0;
			return;
		}		

		if(n>= c.size()) //�Ѿ�ö�ٵ������һ��Ԫ��,����δ�ﵽĿ��,����ݵ���һ��
		{
			//r[n-1]=0;
			return;
		}

		//ö�ٿ��ܵ�����,��0�����Ŀ���ֵ
		for(int i=0;i<=target/c[n];++i)
		{
			r[n]=i;
			if(sum+c[n]*r[n]<=target)
				combin_recusive(c,target,r,n+1,sum+c[n]*r[n],entry);
		}
		//�ڴ˻��ݵ�(���ص���һ�����),��Ҫ������ε��ù�����״̬���趨
		r[n]=0;
	}

public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		vvint entry;
		sort(candidates.begin(),candidates.end());

		vector<int> status(candidates.size());
		combin_recusive(candidates,target,status,0,0,entry);
		
		return entry;
	}
};

void solve()
{
	Solution s;

	vector<int> test;
	test.push_back(2);
	test.push_back(3);
	

	s.combinationSum(test,6);
}

#endif