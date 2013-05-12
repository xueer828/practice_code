#ifndef _TEST_
#define _TEST_

// remove_nth_node_from_end_of_list
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

/*
经典题目,双指针删nth节点
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

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x=0):val(x),next(NULL){};
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head) return NULL;

		ListNode *p1(head),*p2(head);
		while(n-- && p1->next) //两指针之间相差n,后一个指针的后一个节点即为移除节点
		{
			p1 = p1->next;
		}

		if (n > 1)
		{
			return head;
		}else if(n == 1)
			return(head=head->next);

		while(p1->next)
		{
			p1 = p1->next;
			p2 = p2->next;
		}

		p2->next = p2->next->next;
		
		return head;
    }
};

void solve()
{
	ListNode l[2];
	l[0]=1;
	//l[0].next = &l[1];
	l[1]=2;
	l[1].next = NULL;

	Solution s;
	s.removeNthFromEnd(l,1);
}

#endif