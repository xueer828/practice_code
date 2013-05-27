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
�ж�һ�Ŷ������Ƿ��Ƕ���������: ���жϵ�ǰ�ڵ����ǰ���ڵ� (�������)
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
�������:��ǰһ���ڵ�Ƚ�,�Ƿ�����ǰһ���ڵ㲻���ں�һ���ڵ�

Run Status: Accepted!
Program Runtime: 68 milli secs
Progress: 54/54 test cases passed.
*/

struct TreeNode
{
	int val;
	TreeNode *left,*right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

//�������������

class Solution {
	bool is_valid_BST_recusive(TreeNode *root,TreeNode*& pre)
	{
		if(root->left && !is_valid_BST_recusive(root->left,pre))
			return false;

		if(!pre)
			pre = root;
		else if(pre->val >= root->val)
			return false;

		pre = root;

		if(root->right && !is_valid_BST_recusive(root->right,pre))
			return false;

		return true;
	}

	//��������ķǵݹ�
	bool is_valid_BST_iterative(TreeNode *root)
	{
		stack<TreeNode*> st;
		TreeNode *n(root),*pre(NULL);
		while(!st.empty() || n!=NULL)
		{
			//ѹ����ڵ�
			while(n!=NULL)
			{
				st.push(n);
				n = n->left;
			}

			//�÷����м�ڵ���
			if(!st.empty())
			{
				TreeNode *t=st.top();
				st.pop();
				if(pre && pre->val >= t->val)
					return false;
				pre = t;

				//�л�����������
				n=t->right;
			}
		}
	}
public:
    bool isValidBST(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return true;

		TreeNode*pre =NULL;
		//return is_valid_BST_recusive(root,pre);
		return is_valid_BST_iterative(root);
    }
};

void solve()
{

}

#endif