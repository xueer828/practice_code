// BinTree.cpp : Defines the entry point for the console application.
//��������������ڵ������������ڵ�
//�㷨�������������������������һ�����ϣ���ô����������ڵ���ǵ�ǰ�ڵ�
//
//���Ӷȣ�o(n)


#include "stdafx.h"
#include <iostream>

using namespace std;

typedef struct _Node{
	int data;
	struct _Node* left;
	struct _Node* right;
}Node;

//1,��������������Զ�������ڵ��ľ���
//��ʵ��Զ�������ڵ����root�ڵ����������������Ľڵ㣬���ǵľ���֮�ͼ�Ϊ��������
//�߶�֮�ͣ���������ת��Ϊ�����ĸ߶�
int TreeHeight(Node* node)
{
	assert(node);
	int hleft=node->left?TreeHeight(node->left):0;
	int hright=node->right?TreeHeight(node->right):0;
	return (hleft > hright? hleft : hright) + 1;
}

int LongestDis(Node* root)
{
	assert(root);
	int dis=0;
	dis += root->left? TreeHeight(root->left):0;
	dis += root->right? TreeHeight(root->right):0;
	return dis;
}

//2,�ж϶������Ƿ���ƽ�������
bool BalanceTree(Node* root, int& height)
{
	assert(root);
	int hl,hr;
	if(!root->left || !BalanceTree(root->left,hl))
		return false;


	if(!root->right || !BalanceTree(root->right,hr))
		return false;

	height = hl > hr?hl:hr;

	int diff=hr-hl;
	if(diff > 1 || diff < -1)
	{
		return false;
	}	

	return true;
}


bool IsBalanceTree(Node* root)
{
	int height;
	if(!root) return true;
	return BalanceTree(root,height);

}

//3�����������������ڵ��������ڵ㣨Lowest Common Ancestor)
int TraverseTree(Node* root, Node* na,Node* nb, Node* &result, Node* parent)
{
	assert(root&&na&&nb);
	if(result) return 0; //�ҵ������ֱ�ӷ���
	//��������
	int left,right,mid;
	//�������������ж��Ƿ�ֱ�������������
	if(!result && root->left) left=TraverseTree(root->left,na,nb,result,root); 
	if(!left) return 0; //��·��֦
	if(!result && root->right) right=TraverseTree(root->right, na, nb, result, root);
	if(!right) return 0; //��·��֦

	//�жϵ�ǰ�ڵ��Ƿ�Ϊĳ���ڵ�
	if(na == root && nb == root) //��������ڵ���һ���ڵ�
		mid = 2;
	else if(na == root || nb == root)
		mid = 1;
	//�����δ�ó����
	if(!result)
	{
		if(mid == 2)
		{
			result = parent;
		}else if(left == 1 || right == 1) 
			result = parent; //������������һ�ڵ�Ϊ���ڵ㣬���������ֱ�ӵ���root
	}else if(left == 1 && right == 1)
	{
		result = root; //����ֲ�����������������Ϊ��ǰ����������root�ڵ�
	}else
	{
		//��δ�ҵ��������� 
	}

	return left|right|mid ; //������һ֧�нڵ�	
}

//4, 

int _tmain(int argc, _TCHAR* argv[])
{

	return 0;
}

