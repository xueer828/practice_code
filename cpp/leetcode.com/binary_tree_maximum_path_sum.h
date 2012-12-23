#ifndef _TEST_
#define _TEST_

// binary_tree_maximum_path_sum
// Copyright (c) 2012/12/22 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

1
/ \
2   3
Return 6.
*/

/*
˼·:���͵�·���ĺ�,ʵ�����ǵݹ��ж�ÿ���ڵ�,
1) ������ڵ�����ӽڵ㷵�ص����;�Ϊ��,�� ��֧֮��+���ڵ� �����ͽ��бȽ�,��������
2) ������ڵ�����ӽڵ�,����һ֧>0 ��һ֦ <0 �� �����ж� >0��֧+���ڵ� �����ͱȽ�,��������
3) ������ӽڵ��<0, ���൱�ڶ�������֦�µ�������, ���� �ж� ���ڵ� ������, ��������
����,�ݹ鷵��ĳ�ڵ����� Ҫע��,��������֧�д����֧+���ڵ�ĺ�,��������֧Ϊ������,��������ظ��ڵ��ֵ��Ϊ��֦�����ֵ
*/

/*
Run Status: Accepted!
Program Runtime: 264 milli secs
Progress: 92/92 test cases passed.
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
	TreeNode(int x):val(x),left(NULL),right(NULL){}
	TreeNode():val(0),left(NULL),right(NULL){}
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
	int get_larger_sum_of_childs(TreeNode *root, int& total_sum)
	{
		if(!root)
			return 0;

		int lsum(0),rsum(0),larger(0);
		if(root->left)
			lsum = get_larger_sum_of_childs(root->left, total_sum);
		
		if(root->right)
			rsum = get_larger_sum_of_childs(root->right,total_sum);

		
		//�����������������0,�����������,�ж��Ƿ���ڵ�ǰ���ֵ
		if(lsum > 0 && rsum > 0)
		{
			if(lsum+rsum+root->val > total_sum) //��֧+���ڵ�
				total_sum = lsum+rsum+root->val;
			larger = lsum > rsum?lsum:rsum;
		}else{ 
			//������������κ�һ�� <= 0 ����Զ���,��Ϊ�������������������
			larger=lsum>rsum?lsum:rsum;
			if(larger <= 0 && root->val > total_sum)  //�����֧��С�ڵ���0,������жϸ��ڵ�
				total_sum = root->val;
			if(larger <= 0)
				larger = 0; //�����ʱ��֧��С��0,����֧�ĺͶ�������,����������ظ��ڵ�

			//���һ֦ >0 �����ϸ��ڵ�,�жϴ�С
			if(larger>0 && larger+root->val > total_sum) //�����жϸ��ڵ�+���ڵ�
				total_sum = larger+root->val;
		}

		return larger+root->val; //���ش��һ֧+���ڵ�ĺ� (ע��,����larger������0,�������κ�һ֧)
	}

public:
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if(!root)
			return 0;

		int total(root->val);
		get_larger_sum_of_childs(root,total);

		return total;
    }
};



void solve()
{
	Solution s;

	TreeNode n[2];

	n[0].left=&(n[1]);
	n[0].val=1;
	n[1].val=2;

	cout<<s.maxPathSum(n)<<endl;
}

#endif