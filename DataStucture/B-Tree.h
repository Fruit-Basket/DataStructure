#ifndef BMinusTree_h
#define BMinusTree_h

//B-s树的存储表示

#include "Basis.h"



typedef struct BMinusTreeNode{
	int keynum;
	struct BMinusTreeNode *parent;
	KeyType key[ORDER+1];    //不使用数组的第0号单元
	struct BMinusTreeNode *pChildNode[ORDER+1];
}BMinusTreeNode,*BMinusTree;

#endif