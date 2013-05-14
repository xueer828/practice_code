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
//һ��Ҫ������ת����Ĳ����˼��
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

		//��Ϊ�����ܹ���֤ 0<=m<=n<=length of list, ����Ͳ������
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
		��ת˼·: ��������ָ��, pre��ʾ�Ѿ���ת��������,preΪ�Ѿ���ת���ֵ�ͷ
		curΪ��ǰҪ��ת�Ľڵ�,postΪ����δ��ת���ֵ�����,postΪδ��ת��ͷ
		���� 1)cur��ֵΪ��ǰҪ��ת�ĵ�һ���ڵ�,����) post=cur->next
		3) cur->next = pre 3) ת��, pre = cur 4) cur = post
		����ԭcur�ͳ���pre���µ��ѷ�ת�����ͷ,cur��ֵΪpostҪ��ת�Ľڵ�
		*/

		//ע��,����pre��ʾ�Ѿ���ת�Ľڵ��ͷ,
		ListNode *pre=end,*cur,*post;
		cur=pm;
		while(cur!=end) //һֱ��ת��pn�ڵ�(����pn�ڵ�)
		{
			post=cur->next;
			cur->next = pre;
			pre=cur;
			cur=post;
		}

		if(beg)
			beg->next = pre;
		else
			head = pre; //ͷ��㼴Ϊ��ת���ͷ���

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