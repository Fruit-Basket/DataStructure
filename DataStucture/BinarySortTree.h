#ifndef BinarySortTree_h
#define BinarySortTree_h

//�����������Ķ���

#include "Basis.h"



//1.����Ԫ�صĶ���
typedef struct{
	KeyType key;
	InformationType otherInformation;
}BinarySortTreeElemType;


//2.�����������Ķ���
typedef struct BinarySortNode{
	BinarySortTreeElemType data;
	struct BinarySortNode *lChild,*rChild;
}BinarySortNode,*BinarySortTree;



#endif