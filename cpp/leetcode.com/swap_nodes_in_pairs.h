#ifndef _TEST_
#define _TEST_

// swap_nodes_in_pairs
// Copyright (c) 2013/05/08 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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

/*
指针处理基本功
Run Status: Accepted!
Program Runtime: 20 milli secs
Progress: 55/55 test cases passed.
*/

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x=0):val(x),next(NULL){}
};
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head) return head;

		ListNode *pre(NULL),*p1(NULL),*p2(NULL),*post(NULL);
		p1=head; p2 = p1->next;
		while(p1 && p2)
		{
			post = p2->next;
			p2->next = p1;
			p1->next = post;
			if(pre){
				pre->next = p2; // 跟前面串联起来
				pre = p1;	
			}else{
				pre = p1; //此时处理第一个pair
				head = p2;
			}
			p1 = post;
			if(p1)
				p2 = p1->next;
			else
				p2 = NULL;			
		}

		return head;
    }
};

void solve()
{
	ListNode A[5];

}

#endif