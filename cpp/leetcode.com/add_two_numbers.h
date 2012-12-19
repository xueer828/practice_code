#ifndef _TEST_
#define _TEST_

// add_two_numbers
// Copyright (c) 2012/12/20 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

/*
Run Status: Accepted!
Program Runtime: 156 milli secs
Progress: 1555/1555 test cases passed.
*/

#include <cstdio>
#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

typedef struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x):val(x),next(NULL){}
	ListNode():val(0),next(NULL){}
}ListNode;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

		if(!l1)
			return l2;
		if(!l2)
			return l1;

		ListNode *pl1=l1,*pl2=l2;
		ListNode *pret=NULL,*pret_cur=NULL;

		while(pl1 && pl2) // add
		{
			int sum=pl1->val+pl2->val;

			//self-node
			if(! pret)
			{
				pret=new ListNode(sum%10);
				pret_cur = pret;
			}else if(!pret_cur->next)
			{
				pret_cur->next = new ListNode(sum%10);
				pret_cur = pret_cur->next; //point to new added node
			}else{ //pret and pret_cur->next are exist
				sum += pret_cur->next->val;
				pret_cur->next->val = sum%10;
				pret_cur=pret_cur->next; //point to new added node
			}

			//next-node for prograde			
			if(sum/10 > 0)
			{
				pret_cur->next = new ListNode(sum/10);
			}

			pl1 = pl1->next,pl2=pl2->next;
		}

		//one link is end
		while(pl1)
		{
			if(!pret)
				return pl1;

			int sum = pl1->val;
			if(pret_cur->next)
			{
				sum += pret_cur->next->val;
				pret_cur->next->val = sum%10;
			}else{
				pret_cur->next = new ListNode(sum);
			}
			pret_cur = pret_cur->next;

			if(sum/10 > 0)
			{
				pret_cur->next = new ListNode(sum/10);
			}
			pl1 = pl1->next;
		}

		while(pl2)
		{
			if(!pret)
				return pl2;

			int sum = pl2->val;
			if(pret_cur->next)
			{
				sum += pret_cur->next->val;
				pret_cur->next->val = sum%10;
			}else{
				pret_cur->next = new ListNode(sum);
			}
			pret_cur = pret_cur->next;

			if(sum/10 > 0)
			{
				pret_cur->next = new ListNode(sum/10);
			}
			pl2 = pl2->next;
		}

		return pret;
        
    }
};


void solve()
{
	ListNode a[4],b[3];

	a[0].val=2;
	a[0].next=&a[1];
	a[1].val=4;
	a[1].next=&a[2];
	a[2].val=9;
	a[2].next=&a[3];
	a[3].val=9;
	


	b[0].val=5;
	b[0].next=&b[1];
	b[1].val=6;
	b[1].next=&b[2];
	b[2].val=9;
	b[2].next=NULL;

	Solution s;
	ListNode *p=s.addTwoNumbers(a,b);
}

#endif