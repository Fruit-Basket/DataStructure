#ifndef InsertBinarySortTree_h
#define InsertBinarySortTree_h

//二叉排序树插入结点

#include "Basis.h"
#include "BinarySortTree.h"
#include "BinarySortTreeSearch.h"



void insertBinarySortTree(BinarySortTree &bSTree,BinarySortTreeElemType e){
	if(bSTree==NULL){
		bSTree=new BinarySortNode;
		bSTree->data=e;
		bSTree->lChild=NULL;
		bSTree->rChild=NULL;
	}
	else if(e.key>bSTree->data.key){
		insertBinarySortTree(bSTree->rChild,e);
	}
	else if(e.key<bSTree->data.key){
		insertBinarySortTree(bSTree->lChild,e);
	}
	else{
		return;
	}
}

#endif