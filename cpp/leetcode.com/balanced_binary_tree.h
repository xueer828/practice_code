#ifndef _TEST_
#define _TEST_

// balanced_binary_tree
// Copyright (c) 2012/12/21 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/

/*
Run Status: Accepted!
Program Runtime: 108 milli secs
Progress: 226/226 test cases passed.
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <cstdlib>
using namespace std;

typedef struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
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

	bool isBalancedTree(TreeNode *root, int& height)
	{
		height = 0;
		if(!root)
			return true;
		
		int lheight(0),rheight(0);
		if(root->left)
			if(!isBalancedTree(root->left,lheight))
				return false;
		if(root->right)
			if(!isBalancedTree(root->right,rheight))
				return false;

		height = ((lheight > rheight)?lheight:rheight) + 1;

		if(lheight - rheight >= -1 && lheight - rheight <= 1)
			return true;
		else
			return false;
	}
public:
    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		int height;
		return isBalancedTree(root,height);        
    }
};

void solve()
{
	Solution s;
}

#endif