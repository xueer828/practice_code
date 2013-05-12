#ifndef _TEST_
#define _TEST_

// remove_duplicates_from_sorted_list2
// Copyright (c) 2013/5/8 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
 */

//��������һ�ⲻһ��,Ҫ��ɾ�������ظ����Ľڵ�

/*
Run Status: Accepted!
Program Runtime: 56 milli secs
Progress: 166/166 test cases passed.
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
	ListNode(int x):val(x),next(NULL){};
};

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head) return head;

		ListNode *to_write,*last,*to_check,*res(NULL);
		last = NULL;
		to_write = head;
		to_check = head->next;


		while(1)
		{
			to_check = to_write->next;

			//һֱ����Ѱ�ҵ���һ���仯��Ԫ��
			while(to_check && to_check->val == to_write->val) to_check = to_check->next; 

			//���û���ظ�,��δ����ѭ��,����뵽last��
			if(to_check == to_write->next)
			{
				if(!last)
					res=last = to_write;
				else
				{
					last=last->next;
					last->val = to_write->val;
				}
			}
			//������һ����ͬԪ���ٽ��м��
			if((to_write = to_check) == NULL)
				break;
		}

		if(last)
			last->next = NULL;
		return res;

    }
};

void solve()
{
	ListNode l(1),l2(1);
	l.next = &l2;
	Solution s;
	s.deleteDuplicates(&l);
}

#endif 