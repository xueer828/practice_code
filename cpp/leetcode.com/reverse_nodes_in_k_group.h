#ifndef _TEST_
#define _TEST_

// reverse_nodes_in_k_group
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
*/

/*
Run Status: Accepted!
Program Runtime: 140 milli secs
Progress: 81/81 test cases passed.
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
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x=0):val(x),next(NULL){};
};

class Solution {
	ListNode *reverse_iterative(ListNode *start, ListNode *end)
	{
		ListNode *pre(end),*cur(start),*post;
		while(cur!=end)
		{
			post = cur->next;
			cur->next = pre;
			pre=cur;
			cur=post;
		}

		ListNode* n=pre;

		return pre;
	}

	ListNode* reverse_recursive(ListNode *start, ListNode *end, ListNode*& head)
	{
		if(start == end || start->next == end)
		{
			head = start;
			return head;
		}

		ListNode* n=reverse_recursive(start->next,end,head);
		n->next = start;

		return start;
	}
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head || k<=1) return head;

		ListNode *s(head),*e(head),*new_head(NULL),*last(NULL);
		while(e)
		{
			int ct=k;
			while(ct && e)
			{
				e = e->next;
				--ct;
			}

			if(ct == 0)
			{
				ListNode *h;
				//方法1:调用非递归的逆转链表
				//h=reverse_iterative(s,e);

				//方法2:调用递归的逆转链表
				reverse_recursive(s,e,h);

				if(!new_head)
					new_head = h;
				else
					last->next = h;
				last = s;
				s = e;
			}else{
				if(!new_head)
					new_head = s;
				break;
			}
		}

		return new_head;
    }
};


void solve()
{
	ListNode l[4];
	l[0].val = 1;
	l[1].val = 2;
	l[2].val = 3;
	l[3].val = 4;
	l[0].next = &l[1];
	l[1].next = NULL;//&l[2];
	l[2].next = &l[3];



	Solution s;
	s.reverseKGroup(l,2);
}

#endif