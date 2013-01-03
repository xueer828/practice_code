#ifndef _TEST_
#define _TEST_

// edit_distance
// Copyright (c) 2013/1/4 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

//���Ե�DP����
//DP[i][j], ��Ϊword1[0..i]��word2[0..j]�ı༭������ôDP�Ƶ���ʽ:DP[i][j]=min{
//1) if w1[i] == w2[j]; DP[i-1][j-1]
//2) if w1[i] != w2[j]; DP[i-1][j] + 1 //insert char on w1, OR DP[i][j-1] + 1 //delete char on w2, OR DP[i-1][j-1] + 1 //replace a char
// } ȡ���е���Сֵ

/*
Run Status: Accepted!
Program Runtime: 108 milli secs
Progress: 1145/1145 test cases passed.
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
public:
	int minDistance(string word1, string word2) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		int len1=word1.length(),len2=word2.length();
		vector<vector<int> > DP(len1+1,vector<int>(len2+1)); //����һ��DP[len1+1][len2+1]

		//��ʼ��Ϊ0
		for(int i=0;i<=len1;++i)
			for(int j=0;j<=len2;++j)
				DP[i][j]=0;

		//��ʼ�����ַ�������һ���ַ�֮��ת����DP����
		for(int i=0;i<=len1;++i)
			DP[i][0]=i;
		for(int i=0;i<=len2;++i)
			DP[0][i]=i;

		for(int i=1;i<=len1;++i)
			for(int j=1;j<=len2;++j)
			{
				if(word1[i-1]==word2[j-1])  //һ��Ҫע������: ���ﲻ����word1[i]==word2[j], ���׷���
					DP[i][j] = DP[i-1][j-1];
				else{
					//delete a char on w1
					int min = DP[i-1][j] + 1;

					//insert a char on w2
					if(min > DP[i][j-1] + 1)
						min = DP[i][j-1] + 1;

					//replace a char
					if(min > DP[i-1][j-1] + 1)
						min = DP[i-1][j-1] + 1;

					DP[i][j]=min;
				}
			}
		
		return DP[len1][len2];
	}
};

void solve()
{
	Solution s;
	s.minDistance("a","b");
}

#endif 
