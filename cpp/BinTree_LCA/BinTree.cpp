// BinTree.cpp : Defines the entry point for the console application.
//求二叉树任意两节点的最近公共父节点
//算法，后续遍历二叉树，如果都在一条线上，那么最近公共父节点就是当前节点
//
//复杂度：o(n)


#include "stdafx.h"
#include <iostream>

using namespace std;

typedef struct _Node{
	int data;
	struct _Node* left;
	struct _Node* right;
}Node;

//1,求二叉树中相距最远的两个节点间的距离
//其实最远的两个节点就是root节点的左右子树上最深的节点，他们的距离之和即为左右子树
//高度之和，所以问题转换为求树的高度
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

//2,判断二叉树是否是平衡二叉树
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

//3，二叉树上任意两节点的最近父节点（Lowest Common Ancestor)
int TraverseTree(Node* root, Node* na,Node* nb, Node* &result, Node* parent)
{
	assert(root&&na&&nb);
	if(result) return 0; //找到结果，直接返回
	//后续遍历
	int left,right,mid;
	//遍历左子树，判断是否分别在左，右子树上
	if(!result && root->left) left=TraverseTree(root->left,na,nb,result,root); 
	if(!left) return 0; //短路剪枝
	if(!result && root->right) right=TraverseTree(root->right, na, nb, result, root);
	if(!right) return 0; //短路剪枝

	//判断当前节点是否为某个节点
	if(na == root && nb == root) //如果两个节点是一个节点
		mid = 2;
	else if(na == root || nb == root)
		mid = 1;
	//如果还未得出结果
	if(!result)
	{
		if(mid == 2)
		{
			result = parent;
		}else if(left == 1 || right == 1) 
			result = parent; //不允许其中任一节点为父节点，如果允许，则直接等于root
	}else if(left == 1 && right == 1)
	{
		result = root; //如果分布在左右子树，则结果为当前后续遍历的root节点
	}else
	{
		//还未找到，继续找 
	}

	return left|right|mid ; //表明这一支有节点	
}

//4, 

int _tmain(int argc, _TCHAR* argv[])
{

	return 0;
}

