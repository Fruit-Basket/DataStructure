#ifndef CreateBinarySortTree_h
#define CreateBinarySortTree_h

//��������������

#include "Basis.h"
#include "BinarySortTreeSearch.h"
#include "InsertBinarySortTreeNode.h"



//��������������
void createBinarySortTree(BinarySortTree &bSTree){
	BinarySortTreeElemType e;
	bSTree=NULL;
	scanf("%d",&e.key);
	while(e.key!=END_FLAG){
		insertBinarySortTree(bSTree,e);
		scanf("%d",&e.key);
	}
}


//�������������
//ʹ���������������
void showBinarySortTree(BinarySortTree bSTree){
	if(bSTree==NULL){
		return ;
	}
	showBinarySortTree(bSTree->lChild);
	printf("%d  ",bSTree->data.key);
	showBinarySortTree(bSTree->rChild);
}



#endif