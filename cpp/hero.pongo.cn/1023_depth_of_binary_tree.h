#ifndef _TEST_
#define _TEST_

// 1023_depth_of_binary_tree
// Copyright (c) 2013/4/5 
// Author: xdutaotao (xdutaotao@gmail.com)
// 

/*
��Ŀ������
����һ�ö����������������ȡ��Ӹ���㵽Ҷ������ξ����Ľ�㣨������Ҷ��㣩�γ�����һ��·�����·���ĳ���Ϊ������ȡ�

���룺
��һ��������n��n��ʾ����������Ŵ�1��n�������Ϊ1�� n <= 10��
��������n�У�ÿ��������������a��b����ʾ��i���ڵ�����Һ��Ӻ��ӡ�aΪ���ӣ�bΪ�Һ��ӡ���aΪ-1ʱ��û�����ӡ���bΪ-1ʱ��û���Һ��ӡ�
�����
���һ�����ͣ���ʾ������ȡ�

�������룺
3
2 3
-1 -1
-1 -1
���������
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