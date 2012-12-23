#ifndef _TEST_
#define _TEST_

// binary_tree_inorder_traversal
// Copyright (c) 2012/12/22 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
1
\
2
/
3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?

confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/

//�������,�ݹ�ͷǵݹ�

/*
�ݹ��㷨һ��ͨ��
Run Status: Accepted!
Program Runtime: 16 milli secs
Progress: 67/67 test cases passed.
*/

/*
�ǵݹ��㷨,���ư�,�޸��˺ܶ��
Run Status: Accepted!
Program Runtime: 16 milli secs
Progress: 67/67 test cases passed.
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
#include <stack>
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
	void inorder_recusive(TreeNode* root, vector<int>& result)
	{
		if(!root)
			return;
		if(root->left)
			inorder_recusive(root->left,result);
		result.push_back(root->val);
		if(root->right)
			inorder_recusive(root->right,result);
	}

	void inorder_non_recusive(TreeNode* root, vector<int>& result)
	{
		if(!root)
			return;

		TreeNode* t_root=root;

		stack<TreeNode*> stk;

		while(t_root||!stk.empty())
		{
			//һֱ����֦��
			while(t_root)
			{
				stk.push(t_root);
				t_root = t_root->left;
			}

			//��֦����,��ʱ�������ѹ��Ľڵ�,����
			if(!stk.empty())
			{
				t_root=stk.top();
				stk.pop();
				result.push_back(t_root->val);

				//�˵����ڵ�Ϊ��,Ȼ������������
				// goto right branch
				t_root = t_root->right;
			}
		}
	}
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<int> t;
		//inorder_recusive(root,t);
		inorder_non_recusive(root,t);
		return t;
    }
};

void solve()
{
	Solution s;
}

#endif