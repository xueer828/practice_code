#ifndef _TEST_
#define _TEST_

// merge_k_sorted_lists
// Copyright (c) 2013/4/25 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
 */

//思路:将构造一个K小顶堆,将每个链表的首元素填入堆中,每次取出堆顶元素,加入到新链表中,并将原链表中的后继结点加入堆中
//这样,对于每个元素都经过堆处理,O(NlgK)

/*
//堆排序不好写啊,调整起来还是蛮麻烦的,尤其是用vector
Run Status: Accepted!
Program Runtime: 88 milli secs
Progress: 129/129 test cases passed.
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
	ListNode():val(0),next(NULL){};
};
class Solution {
	void AdjHeap(vector<ListNode*>& hp, int beg, int end)
	{
		while(beg*2+1 <= end) //存在左孩子或右孩子
		{
			int replace=beg*2+1; //先令替换结点为左孩子

			if(2*beg+2 <= end && hp[2*beg+2]->val < hp[2*beg+1]->val) //小心堆顶是大还是小
				replace = 2*beg+2;

			if(hp[replace]->val > hp[beg]->val) //满足小顶堆定义
				return;
			else
			{
				ListNode* tmp=hp[replace]; //交换
				hp[replace]=hp[beg];
				hp[beg]=tmp;
				beg = replace; //down父节点
			}
		}
	}

	void InitHeap(vector<ListNode*>& lists, vector<ListNode*>& hp)
	{
		int sz=lists.size();
		for(int i=0;i<sz;++i)
		{
			if(lists[i])
				hp.push_back(lists[i]); 
		}
		sz=hp.size();
		for(int i=(sz-2)/2;i>=0;--i)
		{
			AdjHeap(hp,i,sz-1);
		}
	}

	ListNode* GetNext(vector<ListNode*>& hp)
	{
		if(hp.size()<=0)
			return NULL;
		ListNode* rs=hp[0];
		if(hp[0]->next)
			hp[0]=hp[0]->next;
		else{
			//交换第一个和最后一个元素,删除最后一个元素
			hp[0]=hp[hp.size()-1];
			hp.erase(hp.end()-1);
		}

		//进行调整
		AdjHeap(hp,0,hp.size()-1);

		return rs;
	}
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
		if(lists.size() <= 0)
			return NULL;

        if(lists.size()==1)
			return lists[0];

		vector<ListNode*> hp;
		InitHeap(lists,hp);

		ListNode *head=GetNext(hp);
		ListNode *cur=head; //得到头结点
		while(cur && (cur->next=GetNext(hp))) cur = cur->next; //串联


		return head;

    }
};

void solve()
{
	ListNode n[9];
	n[0].val = 1;
	n[1].val = 2;
	n[2].val = 2;
	n[3].val = 1;
	n[4].val = 1;
	n[5].val = 2;

	n[0].next = &n[1];
	n[1].next = &n[2];

	n[3].next = &n[4];
	n[4].next = &n[5];

	vector<ListNode*> t;
	t.push_back(&n[0]);
	t.push_back(&n[3]);

	Solution s;
	s.mergeKLists(t);
}

#endif 