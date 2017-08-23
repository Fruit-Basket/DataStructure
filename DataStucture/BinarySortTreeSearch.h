#ifndef BinarySortTreeSearch_h
#define BinarySortTreeSearch_h

//二叉排序树的查找

#include "Basis.h"
#include "BinarySortTree.h"



//二叉排序树的查找
BinarySortTree binarySortTreeSearch(BinarySortTree tree,KeyType key){
	//如果tree为空或者找到关键字
	if(tree==NULL || key==tree->data.key){
		return tree;
	}
	else if(key>tree->data.key){
		return binarySortTreeSearch(tree->rChild,key);
	}
	else if(key<tree->data.key){
		return binarySortTreeSearch(tree->lChild,key);
	}
}



#endif