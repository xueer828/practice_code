#ifndef _TEST_
#define _TEST_

// symmetric_tree
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

1
/ \
2   2
/ \ / \
3  4 4  3
But the following is not:

1
/ \
2   2
\   \
3    3
Note:
Bonus points if you could solve it both recursively and iteratively.
*/

/*
µ›πÈÀ„∑®:
Run Status: Accepted!
Program Runtime: 24 milli secs
Progress: 190/190 test cases passed.

∑«µ›πÈÀ„∑®:

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
	TreeNode(int x=0):val(x),left(NULL),right(NULL){}
};
class Solution {

	bool isSymmetric_recursive(TreeNode* lroot,TreeNode* rroot)
	{
		if(!lroot && !rroot) 
			return true;
		else if(lroot && rroot)
		{
			if(lroot->val != rroot->val)
				return false;
			else if(!isSymmetric_recursive(lroot->left,rroot->right) ||
				!isSymmetric_recursive(lroot->right,rroot->left))
				return false;
			return true;
		}else{
			return false;
		}
	}
public:
    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return true;

		return isSymmetric_recursive(root->left,root->right);
    }
};

void solve()
{

}

#endif