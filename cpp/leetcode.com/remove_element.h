#ifndef _TEST_
#define _TEST_

// remove_element
// Copyright (c) 2013/5/8 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
 */

/*
因为不要求顺序,那么我们可以用数组后面的元素填补前面被踢掉的元素的空洞
*/

/*
Run Status: Accepted!
Program Runtime: 28 milli secs
Progress: 112/112 test cases passed.
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
	int removeElement(int A[], int n, int elem) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!A || n <= 0)
			return 0;

		int nw(0),end(n-1);

		//需要注意判断=的情况
		while(nw <= end)
		{
			while(A[nw]!=elem && nw <= end) ++nw;

			while(A[end]==elem && nw <= end) --end;

			if(nw < end)
				A[nw++]=A[end--];
		}
		return end+1;
	}
};

void solve()
{
}

#endif 