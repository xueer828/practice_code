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
思路:最大和的路径的和,实际上是递归判断每个节点,
1) 如果本节点的两子节点返回的最大和均为正,则 两支之和+根节点 与最大和进行比较,更新最大和
2) 如果本节点的两子节点,仅仅一支>0 另一枝 <0 则 仅仅判断 >0这支+根节点 与最大和比较,更新最大和
3) 如果两子节点均<0, 则相当于丢弃掉本枝下的两子树, 仅仅 判断 根节点 与最大和, 更新最大和
另外,递归返回某节点最大和 要注意,返回两子支中大的那支+根节点的和,如果大的那支为非正数,则仅仅返回根节点的值作为本枝的最大值
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

		
		//如果左右子树均大于0,则可以连起来,判断是否大于当前最大值
		if(lsum > 0 && rsum > 0)
		{
			if(lsum+rsum+root->val > total_sum) //两支+根节点
				total_sum = lsum+rsum+root->val;
			larger = lsum > rsum?lsum:rsum;
		}else{ 
			//如果左右子树任何一个 <= 0 则可以丢弃,因为不会对最后结果造成正能量
			larger=lsum>rsum?lsum:rsum;
			if(larger <= 0 && root->val > total_sum)  //如果两支都小于等于0,则仅仅判断根节点
				total_sum = root->val;
			if(larger <= 0)
				larger = 0; //如果此时两支都小于0,则两支的和都不返回,后面仅仅返回根节点

			//大的一枝 >0 则连上根节点,判断大小
			if(larger>0 && larger+root->val > total_sum) //仅仅判断根节点+正节点
				total_sum = larger+root->val;
		}

		return larger+root->val; //返回大的一支+根节点的和 (注意,这里larger可能是0,不包含任何一支)
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