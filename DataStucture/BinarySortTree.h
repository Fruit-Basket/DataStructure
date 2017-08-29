#ifndef BinarySortTree_h
#define BinarySortTree_h

//二叉排序树的定义

#include "Basis.h"

typedef int KeyType;//数据元素中关键字的类型
typedef int InformationType;//数据元素中的信息类型

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