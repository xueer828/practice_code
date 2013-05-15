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
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head || k<=1) return head;

		ListNode *beg(head),*end(head),*last(NULL);
		ListNode *pre=NULL,*cur,*post;
		for(;;)
		{
			int cnt=k;
			while(end->next && --cnt)
			{
				end = end->next;
			}

			//beg和end为逆转区间 [beg,end]
			if(cnt > 1) //如果不够k,则跳出loop,不再逆转
				break;

			//逆转[beg,end]区间			
			cur = beg; //cur为要逆转的一个节点
			pre=end->next; //pre为下一组的起始节点
			ListNode* next=end->next;
			while(cur!=next)
			{
				post=cur->next;
				cur->next = pre;
				pre=cur;
				cur=post;
			}

			if(beg==head) //如果beg是头结点,
				head = pre; //那么置头结点为第一组k的逆转后头节点pre
			else //如果不是,那么把前面已经逆转完毕的节点加上逆转后的节点pre
				end->next = pre;


			//更新新的beg和end节点
			beg = next;
			end = beg;

			if(!beg)
				break;
		}

		return head;
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
	l[1].next = &l[2];
	l[2].next = &l[3];



	Solution s;
	s.reverseKGroup(l,2);
}

#endif