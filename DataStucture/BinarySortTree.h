#ifndef BinarySortTree_h
#define BinarySortTree_h

//二叉排序树的定义

#include "Basis.h"



//1.表中元素的定义
typedef struct{
	KeyType key;
	InformationType otherInformation;
}BinarySortTreeElemType;


//2.二叉排序树的定义
typedef struct BinarySortNode{
	BinarySortTreeElemType data;
	struct BinarySortNode *lChild,*rChild;
}BinarySortNode,*BinarySortTree;



#endif