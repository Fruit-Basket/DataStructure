/**
* ����ջ�Ĵ洢�ṹ�Լ���صĻ����㷨
* Author: FruitBasket
* Time: 2017/8/17
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef STACK_H
#define STACK_H

#include "Basis.h"

/*
ջ�Ķ���
�ڴ˶�����ջ��ջ���Ķ��壺S.top-S.base==S.stacksizeΪtrue��
ջ�յĶ��壺S.top==S.baseΪtrue
*/
typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SequenceStack;

/*
��ʼ��ջ
*/
Status initStack(SequenceStack &sequenceStack){
	sequenceStack.base = new SElemType[MAXSIZE];
	if (!sequenceStack.base){
		return OVERFLOW;
	}
	sequenceStack.top = sequenceStack.base;
	sequenceStack.stacksize = MAXSIZE;
	return OK;
}

/*
ѹջ
*/
Status push(SequenceStack &sequenceStack, SElemType e){
	if (sequenceStack.top - sequenceStack.base == sequenceStack.stacksize){
		return ERROR;
	}
	*sequenceStack.top = e;
	sequenceStack.top++;
	return OK;
}

/*
��ջ
*/
Status pop(SequenceStack &sequenceStack, SElemType &e){
	if (sequenceStack.top == sequenceStack.base){
		return ERROR;
	}
	sequenceStack.top--;
	e = *sequenceStack.top;
	return OK;
}

/*
��ȡջ��Ԫ��
*/
Status getTop(SequenceStack sequenceStack){
	if (sequenceStack.top == sequenceStack.base){
		return ERROR;
	}
	return *(sequenceStack.top - 1);///�˵ķ���ֵ���Թ���
}

#endif