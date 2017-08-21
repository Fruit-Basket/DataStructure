/**
* 普通二叉树的基本方法
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

//先根序顺序建立二叉树
//根据先根遍历的结果建立二叉树，如"ABD##E##CF##G##"、"ABCF##G##E##C##"
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

//中序遍历二叉树的递归算法
void inorderTraverse(BinaryTree binaryTree){
	if (binaryTree){
		inorderTraverse(binaryTree->lChild);
		printf("%c ", binaryTree->data);
		inorderTraverse(binaryTree->rChild);
	}
}

//层次遍历
void levelTraverse(BinaryTree binaryTree){
	int front, rear;
	BinaryTreeNode *queue[MAXSIZE];    //使用循环队列存放即将要访问的结点的指针
	front = rear = 0;
	if (binaryTree){
		queue[rear] = binaryTree;    //将根结点入队
		rear = (rear + 1) % MAXSIZE;    //先将元素入队后，再将队尾指针循环加1
		while (front != rear){    //当队列不空时执行循环。当队列空了，表明所有结点访问完毕
			binaryTree = queue[front];
			front = (front + 1) % MAXSIZE;
			;   //这里可以进行对结点p的各种访问操作
			if (binaryTree->lChild != NULL){     //将当前结点的左孩子入队
				queue[rear] = binaryTree->lChild;
				rear = (rear + 1) % MAXSIZE;
			}
			if (binaryTree->rChild != NULL){    //将当前结点的又孩子入队
				queue[rear] = binaryTree->rChild;
				rear = (rear + 1) % MAXSIZE;
			}
		}
	}
}

//二叉树的复制
//使用先根序遍历来复制二叉树
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

//取得二叉树的深度
int getDepth(BinaryTree binaryTree){
	if (binaryTree){
		int leftDepth = getDepth(binaryTree->lChild);//左子树深度
		int rightDepth = getDepth(binaryTree->rChild);//右子树深度
		return leftDepth > rightDepth ? leftDepth + 1 : rightDepth + 1;
	}
	else{
		return 0;
	}
}

//取得二叉树结点个数
int nodeCount(BinaryTree binaryTree){
	if (binaryTree){
		int leftCount = nodeCount(binaryTree->lChild);//左子树结点个数
		int rightCount = nodeCount(binaryTree->rChild);//右子树结点个数
		return leftCount + rightCount + 1;
	}
	else{
		return 0;
	}
}


#endif
