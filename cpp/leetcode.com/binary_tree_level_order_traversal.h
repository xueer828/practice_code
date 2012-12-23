#ifndef _TEST_
#define _TEST_

// binary_tree_level_order_traversal
// Copyright (c) 2012/12/22 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
3
/ \
9  20
/  \
15   7
return its level order traversal as:
[
[3],
[9,20],
[15,7]
]
*/

/*
Run Status: Accepted! 一次通过
Program Runtime: 28 milli secs
Progress: 33/33 test cases passed.
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

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x), left(NULL),right(NULL){}
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
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		vector<vector<int> > result;

		if(!root) 
			return result;

		queue<TreeNode*> tq;
		int cnt_cur=0,cnt_next=0;
		tq.push(root);
		++cnt_cur;

		vector<int> entry;

		while(!tq.empty())
		{
			TreeNode* n=tq.front();
			tq.pop();
			--cnt_cur;
			
			entry.push_back(n->val);

			if(n->left)
			{
				tq.push(n->left);
				++cnt_next;
			}

			if(n->right)
			{
				tq.push(n->right);
				++cnt_next;
			}

			if(cnt_cur==0)
			{
				result.push_back(entry);
				entry.clear();
				cnt_cur = cnt_next;
				cnt_next = 0;
			}
		}

    }
};

void solve()
{
	Solution s;
}

#endif