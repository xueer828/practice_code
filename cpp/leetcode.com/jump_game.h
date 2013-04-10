#ifndef _TEST_
#define _TEST_

// jump_game
// Copyright (c) 2013/01/07 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/

//ע������:�������,Ҳ����˵���Դ�1����Ӧ��������,dfs�������

/*
Solution1 dfs ������� �����ݳ�ʱ
*/

/*
Solution2 һάDP ��ʱ
*/

/*
˼·3: �������ϵ����۲�����,��ʵ�����Ǹ�̰������,����ÿһ��,���Կ�Խ[1..val],����ܹ�����λ��k,��ô��������Ե���kǰ������һ��λ��,����,û��Ҫdfs����DP,����̰���㷨,ÿ�ζ�ѡȡ���ֵ,������Ƿ����>=���һ��λ��,����
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
	bool jump2end(int A[], int n, int cur)
	{
		if(cur == n-1)
			return true;

		if(cur >= n)
			return false;

		int max_next=A[cur];

		for(int i=1;i<=max_next;++i)
		{
			if(jump2end(A,n,cur+i))
				return true;
		}
		return false;
	}
public:
	bool canJump(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n<=0)
			return false;

		return jump2end(A,n,0);		
	}
};

//˼·2: DP
class Solution2 {
public:
	bool canJump(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n<=0)
			return false;

		//vector<bool> DP(n); //��ʱ
		bool *DP=new bool[n];
		

		DP[0]=true;

		for(int i=1;i<n;++i)
		{
			DP[i] = false; //��ʼ��
			for(int j=i-1;j>=0;--j)
			{
				if(DP[j] && A[j] >= (i-j)) //������ת
				{
					DP[i]=true;
					continue;
				}
			}
		}
		bool tmp=DP[n-1];
		delete[] DP;
		return tmp;

	}
};

//̰��
class Solution {
public:
	bool canJump(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(n <= 0)
			return false;

		int max_val=A[0],cur_pos=0;
		while(1)
		{
			//��ȡ��������
			for(int i=1;i<=max_val;++i)
			{

			}
		}
	}
};

void solve()
{
	Solution s;
	int d[]={2,0};
	cout<<s.canJump(d,sizeof(d)/sizeof(d[0]))<<endl;
}

#endif