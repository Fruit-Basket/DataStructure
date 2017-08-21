/**
* �ۺϲ��Է���
* Author: FruitBasket
* Time: 2017/8/17
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef Test_h
#define Test_h

#include "stdio.h"
#include "BinaryTreeMethods.h"

/*
�������ε�ָ�����
*/
void test1Help(int *pointer);
void test1(){
	int a = 1;
	int *pointer = &a;
	printf("a=%d\n*pointer=%d\n", a, *pointer);
	test1Help(pointer);
	printf("a=%d\n*pointer=%d\n", a, *pointer);
}

void test1Help(int *pointer){
	(*pointer)++;
}

/*
���Խṹ���ָ�����
*/
void test2Help(BinaryTreeNode *);
void test2(){
	BinaryTreeNode node;
	node.data = 'A';
	node.lChild = NULL;
	node.rChild = NULL;

	BinaryTreeNode *pointer = &node;
	printf("data=%c \n",pointer->data);
	test2Help(pointer);
	printf("data=%c \n",pointer->data);
}

void test2Help(BinaryTreeNode *pointer){
	pointer->data = 'B';
}

#endif