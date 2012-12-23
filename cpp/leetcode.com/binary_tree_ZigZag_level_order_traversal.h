#ifndef _TEST_
#define _TEST_

// binary_tree_ZigZag_level_order_traversal
// Copyright (c) 2012/12/23 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree {3,9,20,#,#,15,7},
3
/ \
9  20
/  \
15   7
return its zigzag level order traversal as:
[
[3],
[20,9],
[15,7]
]
*/

//������ӡ,˼·,˫�����

/*
Run Status: Accepted!
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

struct TreeNode{
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
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > entry;

		if(!root)
			return entry;

		deque<TreeNode*> tq;
		tq.push_back(root);

		bool print_order=true;

		int cnt_cur(1),cnt_next(0);
		vector<int> tmp;
		
		while(!tq.empty())
		{
			TreeNode* n;

			//�����е���

			if(print_order) //��ǰ��ȡ��ʱ��,��β�������ӽڵ�,��������,ѹ��ڵ��������
			{
				n=tq.front();
				tq.pop_front();
				--cnt_cur;

				if(n->left)
				{
					tq.push_back(n->left);
					++cnt_next;
				}

				if(n->right)
				{
					tq.push_back(n->right);
					++cnt_next;
				}
			}else{ //��β��ȡ��ʱ��,�ӽڵ����ǰ��,����,ѹ��˳��,���Һ���,��֤�´�ȡ��ʱ���������
				n=tq.back();
				tq.pop_back();
				--cnt_cur;

				if(n->right)
				{
					tq.push_front(n->right);
					++cnt_next;
				}

				if(n->left)
				{
					tq.push_front(n->left);
					++cnt_next;
				}
			}

			tmp.push_back(n->val);

			if(cnt_cur == 0)
			{
				print_order = !print_order;
				entry.push_back(tmp);
				tmp.clear();
				cnt_cur = cnt_next;
				cnt_next = 0;
			}

		}

		return entry;
    }
};



void solve()
{
	Solution s;
}

#endif