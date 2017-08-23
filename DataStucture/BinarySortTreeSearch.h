#ifndef BinarySortTreeSearch_h
#define BinarySortTreeSearch_h

//�����������Ĳ���

#include "Basis.h"
#include "BinarySortTree.h"



//�����������Ĳ���
BinarySortTree binarySortTreeSearch(BinarySortTree tree,KeyType key){
	//���treeΪ�ջ����ҵ��ؼ���
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