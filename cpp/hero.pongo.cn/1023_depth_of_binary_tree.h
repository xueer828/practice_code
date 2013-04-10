#ifndef _TEST_
#define _TEST_

// 1023_depth_of_binary_tree
// Copyright (c) 2013/4/5 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
题目描述：
输入一棵二叉树，求该树的深度。从根结点到叶结点依次经过的结点（含根、叶结点）形成树的一条路径，最长路径的长度为树的深度。

输入：
第一行输入有n，n表示结点数，结点号从1到n。根结点为1。 n <= 10。
接下来有n行，每行有两个个整型a和b，表示第i个节点的左右孩子孩子。a为左孩子，b为右孩子。当a为-1时，没有左孩子。当b为-1时，没有右孩子。
输出：
输出一个整型，表示树的深度。

样例输入：
3
2 3
-1 -1
-1 -1
样例输出：
2
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

typedef struct node{
	struct node* left,*right;
	node():left(NULL),right(NULL){}
}node;

int get_depth(node* root)
{
	if(!root) return 0;

	int left = get_depth(root->left);
	int right=get_depth(root->right);

	return (left>right?left:right)+1;
}

void solve()
{
	int num;
	cin>>num;

	node *arr=new node[num+1];

	int m,n;

	for(int i=1;i<=num;++i)
	{
		cin>>m>>n;
		if(m != -1)
			arr[i].left = &(arr[m]);
		if(n != -1)
			arr[i].right = &(arr[n]);
	}

	cout<<get_depth(&(arr[1]))<<endl;
	delete[] arr;
}

#endif 