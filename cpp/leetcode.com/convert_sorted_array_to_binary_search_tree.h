#ifndef _TEST_
#define _TEST_

// convert_sorted_array_to_binary_search_tree
// Copyright (c) 2012/12/26 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/*
一次通过
Run Status: Accepted!
Program Runtime: 92 milli secs
Progress: 32/32 test cases passed.
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

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
	TreeNode* sortedArrayToBST_recusive(vector<int>& num, int beg, int end)
	{
		if(beg > end)
			return NULL;

		int mid = beg + ((end-beg) >> 1); //mid is root
		TreeNode* root=new TreeNode(num[mid]);
		root->left=sortedArrayToBST_recusive(num,beg,mid-1);
		root->right=sortedArrayToBST_recusive(num,mid+1,end);
		return root;
	}
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int len=num.size();
        if(len<0)
        	return NULL;

        return sortedArrayToBST_recusive(num,0,len-1);
    }
};

void solve()
{

}

#endif