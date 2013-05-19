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
我的方法: (要排成 红 白 蓝 三色顺序)
1) 首先白指针指向头,蓝指针指向末尾,红指针也指向头
2) 如果白指针指向为白色,则白指针++
3) 如果白指针指向为蓝色,则需要将末尾蓝指针所指,交换过来,蓝指针--
4) 如果白指针指向为红色,则需要将红指针所指和白指针所指进行交换, 红色++ 白色++
Run Status: Accepted!
Program Runtime: 24 milli secs
Progress: 86/86 test cases passed.
*/

/*
还有人有更简练的code
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

		//0 红, 1 白 , 2 蓝
		int red(0),white(0),blue(n-1);

		while(white <= blue)
		{
			if(A[white]==1) //白指针后移
				++white; 
			else if(A[white] == 2) //所指为蓝色
			{
				//交换其与蓝色所指
				swap(A[white],A[blue]);
				--blue;
			}else{ //如果是红色
				swap(A[white],A[red]);
				++red,++white;
			}
		}
	}
};

class Solution {
public:
	void sortColors(int A[], int n) {
		int p0 = 0, p2 = n; //p0 为头指针, p2为尾指针
		for (int i = 0; i < p2; ++i) {
			// put zeros at the beginning
			if (A[i] == 0) { //如果所指为红色,则交换当前和p0指向 (p0为红指针,实际i可看做白指针)
				swap(A[i], A[p0++]); //红指针++, 白指针在判断条件上++
			}
			// put twos at the end
			else if (A[i] == 2) { //如果是蓝色,则将i指向和蓝色进行交换,此时i--是为了和判断条件上的++进行抵销
								  //因为此时白指针不能变化; 蓝指针前移
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