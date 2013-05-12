#ifndef _TEST_
#define _TEST_

// remove_duplicates_from_sorted_array2
// Copyright (c) 2013/5/8 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
 */

/*
Run Status: Accepted!
Program Runtime: 88 milli secs
Progress: 164/164 test cases passed.
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
	int removeDuplicates(int A[], int n) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function
		if(!A || n<=0) return 0;

		int p1=0,p2=1,ct=1;
		while(p2 < n)
		{
			if(A[p1]!=A[p2] || ct < 2)
			{
				if(A[p1]!=A[p2])
					ct = 0;
				++p1;
				A[p1]=A[p2];
				++ct;
			}
			++p2;
		}
		return p1+1;
	}
};

void solve()
{
	int a[]={1,1,1,2,2,3};
	Solution s;
	s.removeDuplicates(a,6);
}

#endif 