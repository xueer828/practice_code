#ifndef _TEST_
#define _TEST_

// convert_sorted_list_to_binary_search_tree
// Copyright (c) 2012/12/26 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/

/*
一次通过
Run Status: Accepted!
Program Runtime: 148 milli secs
Progress: 32/32 test cases passed.
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

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(NULL){}
};

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x):val(x),left(NULL),right(NULL){}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
	//we must get the mid node of one link
	ListNode* get_mid_node(ListNode* head, ListNode* tail)
	{
		ListNode* fast_node(head);
		ListNode* slow_node(head);

		while(fast_node!=tail && fast_node->next!=tail)
		{
			fast_node = fast_node->next -> next;
			slow_node = slow_node->next;
		}

		return slow_node;
	}

	TreeNode* sortedListToBST_recusive(ListNode* head, ListNode* tail)
	{
		if(!head || head == tail)
			return NULL;

		ListNode* mid=get_mid_node(head,tail);

		TreeNode* root=new TreeNode(mid->val);
		root->left=sortedListToBST_recusive(head,mid);
		mid = mid->next;
		root->right=sortedListToBST_recusive(mid,tail);

		return root;
	}

public:
    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(!head)
        	return NULL;

        return sortedListToBST_recusive(head,NULL);
    }
};

void solve()
{

}

#endif