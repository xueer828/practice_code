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
˼·:�������,����ǰ�ڵ��ǰ���ڵ���жԱ�,���������˳��,����ڵ��¼����,�������֮��,�ٽ��н���
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

		//��ڵ� ��ǰ����,С�ڵ�ź�����..
		//�϶���������ڵ�,�ȳ��� > root���,��ʱpre�ڵ�������,
		//�����ٳ��� x >��pre�����Ľڵ� �����,��ʱ��root�ڵ㼴Ϊǰ�潻���Ľڵ�
		if(pre && pre->val > root->val)
		{
			//��ʱpre�ڵ��root�ڵ�������
			if(n1 == NULL)
				n1 = pre,n2=root;
			if(n2)
				n2 = root;
		}

		pre = root; //�����ʹ��Ľڵ㽫(�������������˳��)���α���¼����,������һ�εı���

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
		//����������Եõ����������,ֻҪ�ҳ�������������Ľڵ�,������val�Ϳ�����
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