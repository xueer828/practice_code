#ifndef _TEST_
#define _TEST_

// path_sum2
// Copyright (c) 2013/4/28 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
5
/ \
4   8
/   / \
11  13  4
/  \    / \
7    2  5   1
return

[
[5,4,11,2],
[5,8,4,5]
]
 */

/*
Run Status: Accepted!
Program Runtime: 76 milli secs
Progress: 114/114 test cases passed.
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
class Solution {
	vector<vector<int> > my_vec;
	void pathSum_recusive(TreeNode* root, vector<int>& v, int sum)
	{
		if(!root->left && !root->right) //到达叶子节点
		{
			if(sum == root->val){
				v.push_back(root->val);
				my_vec.push_back(v); //满足结果,压入
				v.pop_back(); //恢复后回溯
			}

			return; //回溯
		}

		v.push_back(root->val); //压入当前节点
		if(root->left)
			pathSum_recusive(root->left,v,sum-root->val);

		if(root->right)
			pathSum_recusive(root->right,v,sum-root->val);

		v.pop_back(); //当前节点处理完毕,恢复后回溯
	}
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
       
		my_vec.clear();

		if(!root)
			return my_vec;

		vector<int> tmp;
		pathSum_recusive(root,tmp,sum);

		return my_vec;
    }
};

void solve()
{
}

#endif 