#ifndef _TEST_
#define _TEST_

// sum_root_to_leaf_numbers
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

1
/ \
2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
*/

/*
Run Status: Accepted!
Program Runtime: 20 milli secs
Progress: 109/109 test cases passed.
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

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode{
	int val;
	TreeNode *left,*right;
	TreeNode(int x):val(x),left(NULL),right(NULL){};
};

class Solution {
	int sum_recusive(TreeNode* root, int n)
	{
		if(!root->left && !root->right) //it's a leaf
		{
			return n*10+root->val;
		}

		int s1=0;
		if(root->left)
			s1 += sum_recusive(root->left,n*10+root->val);

		if(root->right)
			s1 += sum_recusive(root->right,n*10+root->val);

		return s1;
	}
public:
    int sumNumbers(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return 0;

		return sum_recusive(root,0);
    }
};

void solve()
{

}

#endif