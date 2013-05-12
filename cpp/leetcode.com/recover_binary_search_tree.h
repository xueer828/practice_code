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

/*
思路:中序遍历,将当前节点跟前驱节点进行对比,如果不满足顺序,则将其节点记录下来,整个完成之后,再进行交换
*/

/*
Run Status: Accepted!
Program Runtime: 332 milli secs
Progress: 2516/2516 test cases passed.
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
	void recoverTree_recursion(TreeNode* root, TreeNode*& pre, TreeNode*& n1, TreeNode*& n2)
	{
		if(!root)
			return;

		if(root->left)
			recoverTree_recursion(root->left,pre,n1,n2);

		//大节点 放前面了,小节点放后面了..
		//肯定先遇到大节点,先出现 > root情况,此时pre节点有问题,
		//后面再出现 x >跟pre交换的节点 的情况,此时的root节点即为前面交换的节点
		if(pre && pre->val > root->val)
		{
			//此时pre节点和root节点有问题
			if(n1 == NULL)
				n1 = pre,n2=root;
			if(n2)
				n2 = root;
		}

		pre = root; //被访问过的节点将(按照中序遍历的顺序)依次被记录下来,用于下一次的遍历

		if(root->right)
			recoverTree_recursion(root->right,pre,n1,n2);

	}
public:
    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root)
			return;

		TreeNode *pre(NULL),*n1(NULL),*n2(NULL);
		//中序遍历可以得到有序的排列,只要找出两个符合排序的节点,交换其val就可以了
		recoverTree_recursion(root,pre,n1,n2);

		if(n1 && n2)
		{
			int tmp=n1->val;
			n1->val = n2->val;
			n2->val = tmp;
		}
    }
};

void solve()
{
	TreeNode v[3];
	v[0].val = 2;
	v[0].left = &v[1];
	v[1].val = 1;
	v[1].right = &v[2];
	v[2].val = 3;

	Solution s;
	s.recoverTree(&v[0]);
}

#endif 