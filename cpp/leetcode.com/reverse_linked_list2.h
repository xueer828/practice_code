#ifndef _TEST_
#define _TEST_

// reverse_linked_list2
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ? m ? n ? length of list.
*/

/*
//一定要掌握逆转链表的步骤和思想
Run Status: Accepted!
Program Runtime: 24 milli secs
Progress: 44/44 test cases passed.
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if(!head || m == n) return head;

		//因为题意能够保证 0<=m<=n<=length of list, 这里就不检测了
		ListNode *pm(head),*pn(head),*beg(NULL),*end;
		while(pm->next && --m)
		{
			beg = pm;
			pm = pm->next;
		}

		while(pn->next && --n)
			pn = pn->next;

		end=(pn && pn->next)?pn->next:NULL;

		/*
		逆转思路: 定义三个指针, pre表示已经逆转的链表部分,pre为已经逆转部分的头
		cur为当前要逆转的节点,post为后面未逆转部分的链表,post为未逆转的头
		步骤 1)cur赋值为当前要逆转的第一个节点,　２) post=cur->next
		3) cur->next = pre 3) 转移, pre = cur 4) cur = post
		这样原cur就成了pre即新的已反转链表的头,cur赋值为post要逆转的节点
		*/

		//注意,这里pre表示已经逆转的节点的头,
		ListNode *pre=end,*cur,*post;
		cur=pm;
		while(cur!=end) //一直逆转到pn节点(包含pn节点)
		{
			post=cur->next;
			cur->next = pre;
			pre=cur;
			cur=post;
		}

		if(beg)
			beg->next = pre;
		else
			head = pre; //头结点即为逆转后的头结点

		return head;
    }
};


void solve()
{
	ListNode l[2];
	l[0].val = 1;
	l[1].val = 2;
	l[0].next = & l[1];

	Solution s;
	s.reverseBetween(l,1,2);
}

#endif