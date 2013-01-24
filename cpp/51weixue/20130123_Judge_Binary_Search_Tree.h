#ifndef _TEST_
#define _TEST_

// 20130123_Judge_Binary_Search_Tree
// Copyright (c) 2013/01/23 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*

二叉搜索树定义，空树，或者对任何非叶子节点，它左子树的所有key值严格小于根节点的key，其右子树的所有key值严格大于根节点key。

节点定义 ：
struct TreeNode {
int key;
TreeNode *left, * right;
}
输入：根节点指针。
输出：true或者false表示是否为二叉搜索树。
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

struct TreeNode {
	int key;
	TreeNode *left, * right;
};

bool dfs(TreeNode* root, TreeNode*& maxNode, TreeNode*& minNode)
{
	if(!root)
		return true;
	TreeNode *max_node,*min_node;
	bool left,right;
	maxNode=minNode=root;
	if(root->left)
	{
		left = dfs(root->left,max_node,min_node);
		if(!left || max_node->key >= root->key )
			return false;
		minNode = min_node;
	}

	if(root->right)
	{
		right = dfs(root->right,max_node,min_node);
		if(!right || min_node->key <= root->key)
			return false;
		maxNode = max_node;
	}

	return true;	
}

bool is_BST(TreeNode* root)
{
	TreeNode *l, *r;
	return dfs(root,l,r);
}



void solve()
{
	cout<<is_BST(NULL)<<endl;
}

#endif