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

似乎还不是那么容易一下子就完全写对呢...faint
Run Status: Accepted!
Program Runtime: 36 milli secs
Progress: 207/207 test cases passed.
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
		while(p1->next && n--) //两指针之间相差n,后一个指针的后一个节点即为移除节点
		{
			p1 = p1->next;
		}

		if(n == 1) //此时移除的是头结点
		{
			//应该处理下最开始的要删除掉的头结点

			return (head=head->next);
		}else if (n > 1)
		{
			return head;
		}

		while(p1->next)
		{
			p1 = p1->next;
			p2 = p2->next;
		}

		//应该处理掉删除的节点
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