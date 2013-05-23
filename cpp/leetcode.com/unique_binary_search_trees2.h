#ifndef _TEST_
#define _TEST_

// unique_binary_search_trees2
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

1         3     3      2      1
\       /     /      / \      \
3     2     1      1   3      2
/     /       \                 \
2     1         2                 3
*/

/*
以x节点为root节点, 1..x-1为左子树, x+1..n为右子树,然后1..x-1构成树和x+1..n构成树又转换为子问题,递归!

Run Status: Accepted!
Program Runtime: 124 milli secs
Progress: 9/9 test cases passed.
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
	TreeNode(int x):val(x),left(NULL),right(NULL){};
};

class Solution {
	vector<TreeNode*> creatBTree(int start,int end)
	{
		vector<TreeNode*> v;
		if(start > end)
			v.push_back(NULL); //空树

		for(int i=start;i<=end;++i)
		{
			vector<TreeNode*> v1=creatBTree(start,i-1);
			vector<TreeNode*> v2=creatBTree(i+1,end);

			for(int j=0;j<v1.size();++j)
			{
				for(int k=0;k<v2.size();++k)
				{
					TreeNode *t=new TreeNode(i);
					t->left = v1[j];
					t->right = v2[k];
					v.push_back(t);
				}
			}
		}

		return v;
	}
public:
    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode*> v;

		if(n <= 0){
			v.push_back(NULL);
			return v;
		}

		return creatBTree(1,n);
    }
};

void solve()
{

}

#endif