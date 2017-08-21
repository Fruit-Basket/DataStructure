/**
* �����������Ļ�������
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
�ȸ���˳����������
�����ȸ������Ľ����������������"ABD##E##CF##G##"��"ABCF##G##E##C##"
����е�Tag���ֲ�δ��ʼ��
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

//������������������
void createInThread(ThreadedBinaryTree tbTree){
	ThreadedBinaryTreeNode *pre = NULL;
	if (tbTree){    //�������������
		InThread(tbTree, pre);    //�Զ�������������������
		pre->rChild = NULL;    //ִ����ú�����preָ�����һ�����
		pre->rTag = 1;

	}
}
//�Զ�������������������
void InThread(ThreadedBinaryTreeNode *node, ThreadedBinaryTreeNode *preNode){
	if (node){//�����ǰ��㲻��
		InThread(node->lChild, preNode);

		if (node->lChild){
			node->lChild = preNode;
			node->lTag = 1;//ָ��lchildΪ����
		}
		if (preNode&& preNode->rChild){
			preNode->rChild = node;//��ǰ�������Һ���ָ��ǰ���
			preNode->rTag = 1;
		}
		preNode = node;//preNodeָ��ǰ���
		InThread(node->rChild, preNode);
	}
}

//�������������ִ���������
void Inorder(ThreadedBinaryTree tbTree){
	for (ThreadedBinaryTreeNode *node = First(tbTree); node; node = Next(node))
	{
		;//������Խ��жԽ��p�ĸ��ַ��ʲ���
	}
}
//�������������������������µĵ�һ�����
ThreadedBinaryTreeNode * First(ThreadedBinaryTree tbTree){
	while (tbTree->lTag == 0){
		tbTree = tbTree->lChild;
	}
	return tbTree;
}
//������������������ǰ���������µĺ�̽��
ThreadedBinaryTreeNode * Next(ThreadedBinaryTreeNode *node){
	if (node->rTag){
		return First(node->rChild);
	}
	else{
		return node->rChild;
	}
}

#endif