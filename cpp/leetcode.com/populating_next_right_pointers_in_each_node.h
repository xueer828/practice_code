#ifndef _TEST_
#define _TEST_

// populating_next_right_pointers_in_each_node
// Copyright (c) 2013/4/28 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
Given a binary tree

struct TreeLinkNode {
TreeLinkNode *left;
TreeLinkNode *right;
TreeLinkNode *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,

1
/  \
2    3
/ \  / \
4  5  6  7
After calling your function, the tree should look like:

1 -> NULL
/  \
2 -> 3 -> NULL
/ \  / \
4->5->6->7 -> NULL
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
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
    }
};

void solve()
{
}

#endif 