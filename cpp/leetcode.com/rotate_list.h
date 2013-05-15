#ifndef _TEST_
#define _TEST_

// rotate_list
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
*/

/*
右移k个位置,其实就是把最末尾的k个节点移动到最开始
Run Status: Accepted!
Program Runtime: 64 milli secs
Progress: 229/229 test cases passed.
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
	ListNode*next;
	ListNode(int x=0):val(x),next(NULL){};
};
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head || k==0) return head;

		ListNode *pre(head),*post(head);

		int len=0;
		while(pre)
		{
			pre=pre->next;
			++len;
		}

		k %= len;
		pre=head;

		while(post->next && k--)
		{
			post = post->next;
		}

		if(k > 0) //右移位置不够,则不移动
			return head;

		while(post->next)
		{
			post = post->next;
			pre = pre->next;
		}

		post->next = head;
		head = pre->next;
		pre->next = NULL;

		return head;
    }
};
void solve()
{

}

#endif