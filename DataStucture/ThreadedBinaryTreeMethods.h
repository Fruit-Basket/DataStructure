/**
* 线索二叉树的基本方法
* Author: FruitBasket
* Time: 2017/8/17
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef ThreadedBinaryTreeMethods_h
#define ThreadedBinaryTreeMethods_h

#include "TreeStructure.h"
#include "stdio.h"

/*
先根序顺序建立二叉树
根据先根遍历的结果建立二叉树，如"ABD##E##CF##G##"、"ABCF##G##E##C##"
结点中的Tag部分并未初始化
*/
void createBiThrTree(ThreadedBinaryTree  &tbTree){
	char ch = getchar();
	if (ch == '#'){
		tbTree = NULL;
	}
	else{
		tbTree = new ThreadedBinaryTreeNode;
		tbTree->data = ch;
		createBiThrTree(tbTree->lChild);
		createBiThrTree(tbTree->rChild);
	}
}

//建立中序线索二叉树
void createInThread(ThreadedBinaryTree tbTree){
	ThreadedBinaryTreeNode *pre = NULL;
	if (tbTree){    //如果二叉树不空
		InThread(tbTree, pre);    //对二叉树进行中序线索化
		pre->rChild = NULL;    //执行完该函数后，pre指向最后一个结点
		pre->rTag = 1;

	}
}
//对二叉树进行中序线索化
void InThread(ThreadedBinaryTreeNode *node, ThreadedBinaryTreeNode *preNode){
	if (node){//如果当前结点不空
		InThread(node->lChild, preNode);

		if (node->lChild){
			node->lChild = preNode;
			node->lTag = 1;//指明lchild为线索
		}
		if (preNode&& preNode->rChild){
			preNode->rChild = node;//让前驱结点的右孩子指向当前结点
			preNode->rTag = 1;
		}
		preNode = node;//preNode指向当前结点
		InThread(node->rChild, preNode);
	}
}

//在中序二叉树上执行中序遍历
void Inorder(ThreadedBinaryTree tbTree){
	for (ThreadedBinaryTreeNode *node = First(tbTree); node; node = Next(node))
	{
		;//这里可以进行对结点p的各种访问操作
	}
}
//求中序线索二叉树中序序列下的第一个结点
ThreadedBinaryTreeNode * First(ThreadedBinaryTree tbTree){
	while (tbTree->lTag == 0){
		tbTree = tbTree->lChild;
	}
	return tbTree;
}
//求中序线索二叉树当前中序序列下的后继结点
ThreadedBinaryTreeNode * Next(ThreadedBinaryTreeNode *node){
	if (node->rTag){
		return First(node->rChild);
	}
	else{
		return node->rChild;
	}
}

#endif