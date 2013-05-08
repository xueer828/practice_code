#ifndef _TEST_
#define _TEST_

// recover_binary_search_tree
// Copyright (c) 2013/5/8 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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
	TreeNode(int x=0):val(x),left(NULL),right(NULL){};
};

class Solution {
	void recoverTree_recursion(TreeNode* root, TreeNode*& mn, TreeNode*& mx, TreeNode*& n1, TreeNode *& n2)
	{
		if(!root)
			return;

		if(n1 && n2)
		{
			//已经找到了,直接return,外面处理
			return;
		}

		TreeNode *lmn(NULL),*lmx(NULL),*rmn(NULL),*rmx(NULL);
		if(root->left)
			recoverTree_recursion(root->left,lmn,lmx,n1,n2);

		if(root->right)
			recoverTree_recursion(root->right,rmn,rmx,n1,n2);

		if(lmx && root->val < lmx->val)
			n1 = lmx;
		if(rmn && root->val > rmn->val)
			n2 = rmn;

		//确定max和min
		mx = rmx?rmx:root;
		mn = lmn?lmn:root;

	}
public:
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root)
			return;

		TreeNode *n1(NULL),*n2(NULL),*mn(NULL),*mx(NULL);
		//中序遍历可以得到有序的排列,只要找出两个符合排序的节点,交换其val就可以了
		recoverTree_recursion(root,mn,mx,n1,n2);

		int tmp=n1->val;
		n1->val = n2->val;
		n2->val = n1->val;

    }
};

void solve()
{
	TreeNode v[2];
	v[0].val = 0;
	v[0].left = &v[1];
	v[1].val = 1;

	Solution s;
	s.recoverTree(&v[0]);
}

#endif 