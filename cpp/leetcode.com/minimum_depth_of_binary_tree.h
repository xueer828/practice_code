#ifndef _TEST_
#define _TEST_

// minimum_depth_of_binary_tree
// Copyright (c) 2013/4/25 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 */

//注意题目要求的是最近的叶子叶节点

/*
Run Status: Accepted!
Program Runtime: 56 milli secs
Progress: 41/41 test cases passed.
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
	TreeNode *left, *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {};
	TreeNode() : val(0), left(NULL), right(NULL) {};
};

//递归
class Solution1 {
	void min_depth(TreeNode* root, int c_dep, unsigned int& mn)
	{
		if(!root->left && !root->right)
		{
			if(mn > c_dep)
				mn = c_dep;
			return;
		}

		if(root->left)
			min_depth(root->left,c_dep+1,mn);
		if(root->right)
			min_depth(root->right,c_dep+1,mn);
	}
public:
    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
      
		if(!root)
			return 0;

		unsigned int mind=~0;

		min_depth(root,1,mind);

		return mind;
    }
};

//非递归,前序遍历

/*
Run Status: Accepted!
Program Runtime: 60 milli secs
Progress: 41/41 test cases passed.
 */
class Solution {
	struct NodeInf 
	{
		TreeNode *p;
		int d;
		NodeInf(TreeNode* pp, int nd):p(pp),d(nd){};
	};
public:
	int minDepth(TreeNode *root) {
		// Start typing your C/C++ solution below
		// DO NOT write int main() function

		if(!root) return 0;

		stack<NodeInf> st; 
		st.push(NodeInf(root,1));

		int depth=0;
		unsigned int mn=~0;
		while(st.size()>0)
		{
			NodeInf t=st.top();
			st.pop();

			if(!t.p->left && !t.p->right) //叶子节点
			{
				if(mn > t.d)
					mn = t.d;
				continue;
			}

			if(t.p->right) //先压入右节点
				st.push(NodeInf(t.p->right,t.d+1));

			if(t.p->left) //后压入左节点
				st.push(NodeInf(t.p->left,t.d+1));
		}

		return mn;
	}
};

void solve()
{
	TreeNode t[2];
	t[0].left = &t[1];
	Solution s;
	cout<<s.minDepth(t);

}

#endif 