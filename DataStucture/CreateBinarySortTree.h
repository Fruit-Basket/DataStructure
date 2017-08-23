#ifndef CreateBinarySortTree_h
#define CreateBinarySortTree_h

//创建二叉排序树

#include "Basis.h"
#include "BinarySortTreeSearch.h"
#include "InsertBinarySortTreeNode.h"



//创建二叉排序树
void createBinarySortTree(BinarySortTree &bSTree){
	BinarySortTreeElemType e;
	bSTree=NULL;
	scanf("%d",&e.key);
	while(e.key!=END_FLAG){
		insertBinarySortTree(bSTree,e);
		scanf("%d",&e.key);
	}
}


//输出二叉排序树
//使用中序遍历二叉树
void showBinarySortTree(BinarySortTree bSTree){
	if(bSTree==NULL){
		return ;
	}
	showBinarySortTree(bSTree->lChild);
	printf("%d  ",bSTree->data.key);
	showBinarySortTree(bSTree->rChild);
}



#endif