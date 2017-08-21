/**
* ��ͨ�������Ļ�������
* Author: FruitBasket
* Time: 2017/8/17
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef BinaryTreeBaseMethods_h
#define BinaryTreeBaseMethods_h

#include "Basis.h"
#include "TreeStructure.h"
#include "stdio.h"

//�ȸ���˳����������
//�����ȸ������Ľ����������������"ABD##E##CF##G##"��"ABCF##G##E##C##"
void createBinaryTree(BinaryTree  &binaryTree){
	char ch = getchar();
	if (ch == '#'){
		binaryTree = NULL;
	}
	else{
		binaryTree = new BinaryTreeNode;
		binaryTree->data = ch;
		createBinaryTree(binaryTree->lChild);
		createBinaryTree(binaryTree->rChild);
	}
}

//��������������ĵݹ��㷨
void inorderTraverse(BinaryTree binaryTree){
	if (binaryTree){
		inorderTraverse(binaryTree->lChild);
		printf("%c ", binaryTree->data);
		inorderTraverse(binaryTree->rChild);
	}
}

//��α���
void levelTraverse(BinaryTree binaryTree){
	int front, rear;
	BinaryTreeNode *queue[MAXSIZE];    //ʹ��ѭ�����д�ż���Ҫ���ʵĽ���ָ��
	front = rear = 0;
	if (binaryTree){
		queue[rear] = binaryTree;    //����������
		rear = (rear + 1) % MAXSIZE;    //�Ƚ�Ԫ����Ӻ��ٽ���βָ��ѭ����1
		while (front != rear){    //�����в���ʱִ��ѭ���������п��ˣ��������н��������
			binaryTree = queue[front];
			front = (front + 1) % MAXSIZE;
			;   //������Խ��жԽ��p�ĸ��ַ��ʲ���
			if (binaryTree->lChild != NULL){     //����ǰ�����������
				queue[rear] = binaryTree->lChild;
				rear = (rear + 1) % MAXSIZE;
			}
			if (binaryTree->rChild != NULL){    //����ǰ�����ֺ������
				queue[rear] = binaryTree->rChild;
				rear = (rear + 1) % MAXSIZE;
			}
		}
	}
}

//�������ĸ���
//ʹ���ȸ�����������ƶ�����
void copy(BinaryTree T, BinaryTree &newT){
	//printf("\ncopy(BinaryTree,BinaryTree)\n");
	if (T){
		newT = new BinaryTreeNode;
		newT->data = T->data;

		copy(T->lChild, newT->lChild);
		copy(T->rChild, newT->rChild);
	}
	else{
		newT = NULL;
	}
}

//ȡ�ö����������
int getDepth(BinaryTree binaryTree){
	if (binaryTree){
		int leftDepth = getDepth(binaryTree->lChild);//���������
		int rightDepth = getDepth(binaryTree->rChild);//���������
		return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
	}
	else{
		return 0;
	}
}

//ȡ�ö�����������
int nodeCount(BinaryTree binaryTree){
	if (binaryTree){
		int leftCount = nodeCount(binaryTree->lChild);//������������
		int rightCount = nodeCount(binaryTree->rChild);//������������
		return leftCount + rightCount + 1;
	}
	else{
		return 0;
	}
}


#endif
