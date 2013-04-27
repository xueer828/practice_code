#ifndef _TEST_
#define _TEST_

// merge_two_sorted_lists
// Copyright (c) 2013/4/25 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 */

//合并两个已经排序的链表

/*
还要继续努力啊,不是一次性AC
Run Status: Accepted!
Program Runtime: 56 milli secs
Progress: 208/208 test cases passed.
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

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x=0):val(x),next(NULL){};
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!l1) // l1为空,则返回l2
			return l2;

		if(!l2) //l2空,返回l1, 已经考虑 l1 l2 同为空情况,返回空
			return l1;

		ListNode* head=NULL,*cur=NULL,*next=NULL;
		ListNode *p1=l1, *p2=l2;

		while(p1 && p2) //p1 p2 未到链表末尾
		{
			if(p1->val < p2->val){
				next = p1;
				p1 = p1->next;
			}
			else{
				next = p2;
				p2=p2->next;
			}

			if(!cur)
			{
				cur = next;
				head = cur;
			}
			else
			{
				cur->next = next;
				cur = cur->next;
			}
		}

		if(p1)
			cur->next = p1;

		if(p2)
			cur->next = p2;

		return head;

    }
};

void solve()
{
	ListNode n[2];
	n[0].val=1;
	n[1].val=2;

	Solution s;
	s.mergeTwoLists(&n[0],&n[1]);
}

#endif 