#ifndef _TEST_
#define _TEST_

// flatten_binary_tree_to_linked_list
// Copyright (c) 2013/1/4 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

1
/ \
2   5
/ \   \
3   4   6
The flattened tree should look like:
1
\
2
\
3
\
4
\
5
\
6
click to show hints.
*/

//实际上是将树变成只能先序遍历的链表

/*
Run Status: Accepted!
Program Runtime: 44 milli secs
Progress: 225/225 test cases passed.
*/

//感觉树结构还是掌握的不太好,需要继续努力啊

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

struct TreeNode{
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
	TreeNode* get_end_node(TreeNode* root)
	{
		TreeNode* left=root->left,*right=root->right, *cur=root;
		root->left = root->right = NULL; //clear
		if(left)
		{
			cur->right = left;
			cur = get_end_node(left); //cur jump to the end of left branch
			cur->left = NULL; //clear
		}

		if(right)
		{
			cur->right = right;
			cur = get_end_node(right); // jump to the end of right branch
			cur->left = NULL;
		}

		return cur;
	}
public:
    void flatten(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(!root)
			return;
        get_end_node(root);
    }
};


void solve()
{

}

#endif 
