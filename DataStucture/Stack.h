/**
* 定义栈的存储结构以及相关的基本算法
* Author: FruitBasket
* Time: 2017/8/17
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef STACK_H
#define STACK_H

#include "Basis.h"

/*
栈的定义
在此定义下栈，栈满的定义：S.top-S.base==S.stacksize为true；
栈空的定义：S.top==S.base为true
*/
typedef struct{
	SElemType *base;
	SElemType *top;
	int stacksize;
}SequenceStack;

/*
初始化栈
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
压栈
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
出栈
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
获取栈顶元素
*/
Status getTop(SequenceStack sequenceStack){
	if (sequenceStack.top == sequenceStack.base){
		return ERROR;
	}
	return *(sequenceStack.top - 1);///此的返回值略显怪异
}

#endif