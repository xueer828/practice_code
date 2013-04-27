#ifndef _TEST_
#define _TEST_

// path_sum
// Copyright (c) 2013/4/28 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
5
/ \
4   8
/   / \
11  13  4
/  \      \
7    2      1
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

/*
Run Status: Accepted!
Program Runtime: 56 milli secs
Progress: 114/114 test cases passed.
 */

struct TreeNode{
	int val;
	TreeNode *left,*right;
	TreeNode(int x):val(x),left(NULL),left(NULL){};
};

/*
需要注意的几点:
1) 要求的是从跟节点到叶子节点, 所以叶子节点的要求就是 root->left == root-> right == NULL
2) if root == NULL,那就要返回false,因为递归不会产生root == nULL的情况
 */
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) 
			return false;
		if(!root->left && !root->right) //到达叶子节点,判断此时和是否等于root的值
			return sum==root->val;

		if(root->left && hasPathSum(root->left,sum-root->val)) //需要判断root->left是否非空
			return true;
		if(root->right && hasPathSum(root->right,sum-root->val))
			return true;
    }
};

void solve()
{
}

#endif 