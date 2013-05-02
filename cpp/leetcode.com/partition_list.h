#ifndef _TEST_
#define _TEST_

// partition_list
// Copyright (c) 2013/4/28 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
 */

/*
Run Status: Accepted!
Program Runtime: 48 milli secs
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
    ListNode *partition(ListNode *head, int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
		if(!head) return head;

		ListNode *pre(NULL),*post(NULL),*hpre(NULL),*hpost(NULL),*cur(head);
		head=NULL; //清空head
		while(cur)
		{
			if(cur->val < x) //linked to pre
			{
				if(!pre){
					pre = cur;
					hpre = pre;
				}else{
					pre->next = cur;
					pre = pre->next;
				}
			}else{ //linked to post
				if(!post){
					post =cur;
					hpost=post;
				}
				else{
					post->next = cur;
					post = post->next;
				}
			}

			cur = cur->next;
		}

		//清理最后节点
		if(pre)
			pre->next = NULL;
		if(post)
			post->next = NULL;

		if(!hpre) //head为空,表示pre链为空
			head = hpost;
		else{
			head = hpre;
			pre->next = hpost;
		}

		return head;
    }
};

void solve()
{
	ListNode n1(1),n2(1);
	n1.next = &n2;
	Solution s;
	s.partition(&n1,1);
}

#endif 