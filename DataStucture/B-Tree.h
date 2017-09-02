#ifndef BMinusTree_h
#define BMinusTree_h

//B-���Ĵ洢��ʾ

#include "Basis.h"

typedef int KeyType;//����Ԫ���йؼ��ֵ�����

typedef struct BMinusTreeNode{
	int keynum;
	struct BMinusTreeNode *parent;
	KeyType key[ORDER+1];    //��ʹ������ĵ�0�ŵ�Ԫ
	struct BMinusTreeNode *pChildNode[ORDER+1];
}BMinusTreeNode,*BMinusTree;

#endif