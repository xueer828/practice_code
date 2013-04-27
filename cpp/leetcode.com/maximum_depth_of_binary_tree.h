#ifndef _TEST_
#define _TEST_

// maximum_depth_of_binary_tree
// Copyright (c) 2013/4/25 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 */

/*
Ò»´ÎÐÔAC easy
Run Status: Accepted!
Program Runtime: 48 milli secs
Progress: 38/38 test cases passed.
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

struct TreeNode 
{
	int val;
	TreeNode *left, *right;
	TreeNode(int x):val(x),left(NULL),right(NULL) {};
};

class Solution {
public:
    int maxDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if(!root) return 0;

		int Dep_left=maxDepth(root->left);
		int Dep_right=maxDepth(root->right);

		return (Dep_left>Dep_right?Dep_left:Dep_right)+1;
    }
};


void solve()
{
}

#endif 