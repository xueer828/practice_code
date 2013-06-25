#ifndef _TEST_
#define _TEST_

// substring_with_concatenation_of_all_words
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
You are given a string, S, and a list of words, L, that are all of the same length. Find all starting indices of substring(s) in S that is a concatenation of each word in L exactly once and without any intervening characters.

For example, given:
S: "barfoothefoobarman"
L: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

/*
����ֱ�ӵķ���
С����ͨ��,������ TLE ͨ����
Run Status: Accepted!
Program Runtime: 8 milli secs
Progress: 18/18 test cases passed.

Run Status: Time Limit Exceeded
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

class Solution1 {
public:
	vector<int> findSubstring(string S, vector<string> &L) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> v;

		int slen=S.length();
		int llen=L.size();
		if(slen<=0 || llen <= 0)
			return v;

		int plen=L[0].size();
		int last_len=slen-llen*plen;
		if(last_len < 0) //not long enough to match pattern
			return v;

		//��ģʽ������
		sort(L.begin(),L.end());		

		for(int i=0;i<=last_len;++i) //ͷ����ƥ�䵽 �ַ��� - ģʽ������ ��λ��
		{
			vector<int> flag(llen,0);
			//ͷƥ��
			int head=i;
			for(int j=0;j<llen;++j)
			{
				if(L[j][0] > S[head]) //û��ƥ�����,ֱ������
					break;
				else if(L[j][0] < S[head]) //̫С,��������ƥ��
					continue;

				if(flag[j]==1) //��ģʽ�Ѿ�ƥ�����
					continue;

				//ͷƥ����,������ǰƥ����
				int k=1;
				for(;k<plen;++k)
				{
					if(S[head+k]!=L[j][k])
						break;
				}

				if(k == plen) //match
				{
					flag[j]=1;
					head += plen;
					j=-1;
				}
			}

			bool ok=true;
			for(int j=0;j<llen;++j)
			{
				if(flag[j]!=1)
				{
					ok = false;
					break;
				}
			}

			if(ok) v.push_back(i);
		}
		
		return v;
	}
};

class Solution {
	inline bool cmp(string& str1, int s1, string& str2, int s2, int n)
	{
		for(int i=0;i<n;++i)
			if(str1[s1+i]!=str2[s2+i])
				return false;

		return true;
	}
public:
	vector<int> findSubstring(string S, vector<string> &L) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		vector<int> ret;
		int sz=S.length();
		int lsz=L.size();
		if(sz<=0 || lsz <= 0)
			return ret;

		int str_sz=L[0].size();
		if(str_sz <= 0)
			return ret;

		//������ʽ:�г����п��ܵ��Ӵ�,��Ϊ�Ӵ��ĳ����ǹ̶���,���Կ����϶���O(len(str1)-len(str2_array))������
		//���Ӵ�,���������֮��ֱ�ӽ��бȶ�

		for(int i=0;i<=sz-str_sz*lsz;++i) //���п��ܵ��Ӵ�
		{
			vector<int> used(lsz,0);
			int j=i;
			for(;j<i+lsz*str_sz;j+=str_sz)
			{
				int k=0;
				for(;k<lsz;++k)
				{
					if(used[k]==0 && cmp(S,j,L[k],0,str_sz))
					{
						used[k] = 1;
						break;
					}
				}

				if(k == lsz) //no same
					break;
			}
			
			int m=0;
			for(m=0;m<lsz;++m)
			{
				if(used[m]==0)
					break;
			}

			if(m==lsz)
				ret.push_back(i);
		}

		return ret;
	}
};

void solve()
{
	Solution s;
	vector<string> t(1);
	t[0]="a";
	//t[1]="bar";
	s.findSubstring("a",t);
}

#endif