#ifndef _TEST_
#define _TEST_

// validate_binary_search_tree
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/

/*
判断一颗二叉树是否是二叉搜索树: 即判断当前节点大于前驱节点 (中序遍历)
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
	TreeNode *left,*right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};
class Solution {
	bool is_valid_BST_recusive(TreeNode *root,TreeNode* pre, TreeNode* post)
	{
		TreeNode *ppre,*ppost;
		if(root->left && !is_valid_BST_recusive(root->left,ppre,ppost))
			return false;
		
		if(root->val < ppre->val)
			return false;
		if(root->right && !is_valid_BST_recusive(root->right,ppre,ppost))
			return false;

		return true;
	}
public:
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return true;


    }
};

void solve()
{

}

#endif