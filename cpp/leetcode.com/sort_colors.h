#ifndef _TEST_
#define _TEST_

// sort_colors
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/

/*
�ҵķ���: (Ҫ�ų� �� �� �� ��ɫ˳��)
1) ���Ȱ�ָ��ָ��ͷ,��ָ��ָ��ĩβ,��ָ��Ҳָ��ͷ
2) �����ָ��ָ��Ϊ��ɫ,���ָ��++
3) �����ָ��ָ��Ϊ��ɫ,����Ҫ��ĩβ��ָ����ָ,��������,��ָ��--
4) �����ָ��ָ��Ϊ��ɫ,����Ҫ����ָ����ָ�Ͱ�ָ����ָ���н���, ��ɫ++ ��ɫ++
Run Status: Accepted!
Program Runtime: 24 milli secs
Progress: 86/86 test cases passed.
*/

/*
�������и�������code
Run Status: Accepted!
Program Runtime: 28 milli secs
Progress: 86/86 test cases passed.
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
	void sortColors(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!A || n<=0) return;

		//0 ��, 1 �� , 2 ��
		int red(0),white(0),blue(n-1);

		while(white <= blue)
		{
			if(A[white]==1) //��ָ�����
				++white; 
			else if(A[white] == 2) //��ָΪ��ɫ
			{
				//����������ɫ��ָ
				swap(A[white],A[blue]);
				--blue;
			}else{ //����Ǻ�ɫ
				swap(A[white],A[red]);
				++red,++white;
			}
		}
	}
};

class Solution {
public:
	void sortColors(int A[], int n) {
		int p0 = 0, p2 = n; //p0 Ϊͷָ��, p2Ϊβָ��
		for (int i = 0; i < p2; ++i) {
			// put zeros at the beginning
			if (A[i] == 0) { //�����ָΪ��ɫ,�򽻻���ǰ��p0ָ�� (p0Ϊ��ָ��,ʵ��i�ɿ�����ָ��)
				swap(A[i], A[p0++]); //��ָ��++, ��ָ�����ж�������++
			}
			// put twos at the end
			else if (A[i] == 2) { //�������ɫ,��iָ�����ɫ���н���,��ʱi--��Ϊ�˺��ж������ϵ�++���е���
								  //��Ϊ��ʱ��ָ�벻�ܱ仯; ��ָ��ǰ��
				swap(A[i--], A[--p2]);
			}
		}
	}
};

void solve()
{
	int A[]={0,1,1};
	Solution s;
	s.sortColors(A,3);
}

#endif