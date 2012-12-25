#ifndef _TEST_
#define _TEST_

// construct_binary_tree_from_preorder_and_inorder_traversal
// Copyright (c) 2012/12/25 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given preorder and inorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
*/

//ǰ�������,�����,ͬǰһ���㷨

/*
Run Status: Accepted!
Program Runtime: 248 milli secs
Progress: 202/202 test cases passed.
*/

//ע��߽�����,�����õ��ǵ�����,���������ܳ�Խ�߽�,����ᱨ��


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
	typedef vector<int>::iterator intor;
	TreeNode* buildTree_recusive(intor beg1, intor end1, intor beg2, intor end2)
	{
		if(beg1 == end1 || beg2 == end2)
			return NULL;

		int elem=*beg1; //���ڵ�Ϊ�����һ��Ԫ��

		intor it2=beg2,it1=++beg1;
		for(;it2!=end2;++it1,++it2)
		{
			if(*it2 == elem)
				break;
		}

		assert(it2!=end2);

		TreeNode* root=new TreeNode(elem);
		
			root->left = buildTree_recusive(beg1,it1,beg2,it2);
		
			root->right = buildTree_recusive(it1,end1,it2+1,end2);
		

		return root;
	}
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        assert(preorder.size()==inorder.size());

		if(preorder.size()<0)
			return NULL;

		return buildTree_recusive(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());
    }
};

void solve()
{
	Solution s;

	vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);

	vector<int> b;
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);

	s.buildTree(a,b);
}

#endif