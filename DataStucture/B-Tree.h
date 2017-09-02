#ifndef BMinusTree_h
#define BMinusTree_h

//B-树的存储表示

#include "Basis.h"

typedef int KeyType;//数据元素中关键字的类型

typedef struct BMinusTreeNode{
	int keynum;
	struct BMinusTreeNode *parent;
	KeyType key[ORDER+1];    //不使用数组的第0号单元
	struct BMinusTreeNode *pChildNode[ORDER+1];
}BMinusTreeNode,*BMinusTree;

#endif