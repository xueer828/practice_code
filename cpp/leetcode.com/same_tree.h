#ifndef _TEST_
#define _TEST_

// same_tree
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*/

/*
Run Status: Accepted!
Program Runtime: 12 milli secs
Progress: 52/52 test cases passed.
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
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!p && !q) 
			return true;
		else if(p && q)
		{
			if(p->val != q->val)
				return false;

			return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
		}else
			return false;
    }
};


void solve()
{

}

#endif