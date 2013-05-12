#ifndef _TEST_
#define _TEST_

// remove_duplicates_from_sorted_list
// Copyright (c) 2013/5/8 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
 */

/*
一次性AC, 未编译
Run Status: Accepted!
Program Runtime: 76 milli secs
Progress: 164/164 test cases passed.
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

		ListNode* p1=head, *p2=head->next;

		while(p2)
		{
			if(p1->val != p2->val)
			{
				p1 = p1->next;
				p1->val = p2->val;
			}
			p2 = p2->next;
		}

		//此处应该讲p1->next到结尾的节点free掉
		//然后置p1->next=NULL

		p1->next = NULL;
		return head;
    }
};

void solve()
{
}

#endif 