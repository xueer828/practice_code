#ifndef _TEST_
#define _TEST_

// populating_next_right_pointers_in_each_node2
// Copyright (c) 2013/4/28 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,

1
/  \
2    3
/ \    \
4   5    7
After calling your function, the tree should look like:

1 -> NULL
/  \
2 -> 3 -> NULL
/ \    \
4-> 5 -> 7 -> NULL
 */


/*
Run Status: Accepted!
Program Runtime: 168 milli secs
Progress: 61/61 test cases passed.

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
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */

struct TreeLinkNode{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x):val(x),left(NULL),right(NULL),next(NULL){}
};
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return;

		TreeLinkNode *TNULL=NULL;

		queue<TreeLinkNode*> tq;
		tq.push(root);
		tq.push(TNULL);

		TreeLinkNode *last=NULL;
		while(!tq.empty())
		{
			TreeLinkNode* n=tq.front();
			tq.pop();

			if(!n)
			{
				if(tq.size()>0) //这里很容易犯错误:只有在队列中还存在元素时才能压入分界符号
					tq.push(TNULL);
				if(last)
					last->next = NULL;
				last = NULL;
				continue;
			}

			if(last)
			{
				last->next = n;
			}
			last = n; //更新last


			if(n->left)
				tq.push(n->left);
			if(n->right)
				tq.push(n->right);
		}
    }
};

void solve()
{
}

#endif 