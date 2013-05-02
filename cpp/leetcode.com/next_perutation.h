#ifndef _TEST_
#define _TEST_

// next_perutation
// Copyright (c) 2013/4/25 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 �� 1,3,2
3,2,1 �� 1,2,3
1,1,5 �� 1,5,1
 */

/*
��һ�����е��㷨:
1) �Ӻ���ǰ��Ѱ����Ԫ��: �ҵ���һ��i���� a[i] < a[i+1],���i��0,��ʾ,�����ǵ����ݼ�����,Ҳ����˵�������һ������,��һ����ȫ����ת�Ϳ�����
2) �Ӻ���ǰ����a[j]: ʹ�� a[i] < a[j] (iΪ��һ�׶��ҵ���Ԫ��, jΪ�������е����index), ������ʱa[i]��a[j]λ��
3) ��i����,����Ԫ����ת,������i (Ҳ���Ǵ�i+1��ʼ���������Ԫ��,ȫ����ת)

*/

/*
Run Status: Accepted!
Program Runtime: 76 milli secs
Progress: 265/265 test cases passed.
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
	void swap(vector<int>& v, int s,int e)
	{
		int tmp;
		for(;s<=e;++s,--e)
		{
			tmp=v[s];
			v[s]=v[e];
			v[e]=tmp;
		}
	}
public:
	void nextPermutation(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		int i=num.size()-2;
		for(;i>=0;--i)
		{
			if(num[i] < num[i+1])
				break;
		}

		if(i >= 0) //��δ�������ʼ
		{
			//������β��ǰ���ҵ�һ��a[j] ʹ a[i]<a[j]
			int j=num.size()-1;
			for(;j>=i;--j)
			{
				if(num[i] < num[j])
					break;
			}

			//���� a[i]��a[j]
			int tmp=num[i];
			num[i]=num[j];
			num[j]=tmp;
		}

		//��i+1��ʼ�����,ȫ����ת
		swap(num,i+1,num.size()-1);
	}

	/*����prev Permutation,�㷨��nextPermutation��һ�µ�,
	Ψһ�������:
	prevPermuation�Ƚϴ�С����a[i] > a[i+1], (����)
	nextPermutation�Ƚϴ�С��a[i] < a[i+1] (����)*/
	void prevPermutation(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
	
		int sz=num.size();
		if(sz<= 1)
			return;

		int i=sz-2;
		for(;i >=0;--i)
		{
			if(num[i] > num[i+1])
				break;
		}

		if(i >= 0) //i��δԽ��
		{
			//�Ӻ���ǰ���ҵ�һ������num[i]����num[j]����
			int j=sz-1;
			for(;j > i;--j)
			{
				if(num[i] > num[j]) //��Ȼ�Ǵ�����ôһ��ֵ��
					break;
			}

			//����
			int tmp=num[j];
			num[j]=num[i];
			num[i]=tmp;
		}

		//�ӵ�һ����iΪֹ(������i)ȫ����ת
		swap(num,i+1,sz-1);
	}
};

void solve()
{
	vector<int> v(10);
	v[0]=3;
	v[1]=7;
	v[2]=2;
	v[3]=3;
	v[4]=5;
	v[5]=1;
	v[6]=7;
	v[7]=9;
	v[8]=4;
	v[9]=8;
	Solution s;
	s.prevPermutation(v);
}

#endif 