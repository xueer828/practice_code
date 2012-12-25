#ifndef _TEST_
#define _TEST_

// construct_binary_tree_from_inorder_and_postorder_traversal
// Copyright (c) 2012/12/25 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/

//中序和后序 得到前序
//思路,递归处理,后序的最后一个是根节点,可以把中序分成左右子树两部分
//然后再对两部分,分别递归得到前序遍历序列

/*
Run Status: Accepted!
Program Runtime: 108 milli secs
Progress: 202/202 test cases passed.
*/

//感想:一定要界定好边界;PS.assert()里面的条件只有成立的情况下才不会报错!!!要小心

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

	TreeNode* buildTree_recusive(vector<int> &inorder, int beg1, int end1, 
								vector<int> &postorder, int beg2, int end2)
	{
		if(beg1>end1 || beg2>end2)
			return NULL;

		int elem=postorder[end2];

		int i=beg1;
		for(;i<=end1;++i)
		{
			if(elem==inorder[i])
				break;
		}

		assert(i<=end1); //未找到

		int sz = i-1-beg1;

		TreeNode* root = new TreeNode(elem);
		root->left = buildTree_recusive(inorder,beg1,i-1,postorder,beg2,beg2+sz);
		root->right = buildTree_recusive(inorder,i+1,end1,postorder,beg2+sz+1,end2-1);

		return root;
	}
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		assert(inorder.size()==postorder.size());

		int len = inorder.size();

		return buildTree_recusive(inorder,0,len-1,postorder,0,len-1);

    }
};

void solve()
{
	Solution s;

	vector<int> a;
	a.push_back(-1);
	vector<int> b(a);

	s.buildTree(a,b);
}

#endif