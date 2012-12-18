#ifndef _TEST_
#define _TEST_

// 3_sum 
// Copyright (c) 2012/12/17 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ¡Ü b ¡Ü c)
The solution set must not contain duplicate triplets.
For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:
(-1, 0, 1)
(-1, -1, 2)
*/

//O(nlgn+n^2) = O(n^2)

//AC:
/*
Run Status: Accepted!
Program Runtime: 968 milli secs
Progress: 311/311 test cases passed.
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cassert>
#include <algorithm>
#include <vector>
using namespace std;

template<class T>
void print(T t)
{
	cout<<t<<" ";
}

class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		vector<vector<int> > ret;

		if(num.size()<3)
			return ret;

		//sort 1stly
		sort(num.begin(),num.end());

		vector<int>::const_reverse_iterator i1;
		vector<int>::const_iterator i2,i3;
		//loop the mid value from begin to the end (not included)
		for(i2=num.begin()+1;i2!=num.end()-1;++i2)
		{
			int sum=0; 
			//i1 is reverse iterator,with same pointer to i2, but its value is previous of *i2;
			i1=static_cast<vector<int>::const_reverse_iterator> (i2); 
			i3=i2+1; //

			while(i1 != num.rend() && i3 != num.end()) //not reach limitation
			{
				sum = *i1 + *i2 + *i3;
				if(sum == 0)
				{
					vector<vector<int> >::const_iterator tmp_it=ret.begin();
					bool flag=true;
					for(;tmp_it!=ret.end();++tmp_it)
					{
						vector<int>::const_iterator tmp_it2=tmp_it->begin();

						if(*i1 == (*tmp_it2) && *i2==*(tmp_it2+1) && *i3==*(tmp_it2+2))
						{
							flag=false;
							break;
						}
					}
					if(flag)
					{
						vector<int> tmp;
						tmp.push_back(*i1);
						tmp.push_back(*i2);
						tmp.push_back(*i3);
						ret.push_back(tmp);
					}

					++i3,++i1;
				}else if(sum < 0)
				{
					//i3 right shift
					++i3;
				}else{
					//i1 left shift if sum is more than 0
					++i1;
				}
			}
		}

		//for_each(num.begin(),num.end(),print<int>);

		return ret;
	}
};

void solve()
{
	vector<int> in;
	in.push_back(-1);
	in.push_back(0);
	in.push_back(1);
	in.push_back(2);
	in.push_back(-1);
	in.push_back(-1);
	in.push_back(-4);
	Solution s;
	

	vector<vector<int> > t=s.threeSum(in);
	vector<vector<int> >::const_iterator it;
	for(it=t.begin();it!=t.end();++it)
	{
		for_each(it->begin(),it->end(),print<int>);
		cout<<endl;
	}
}

#endif