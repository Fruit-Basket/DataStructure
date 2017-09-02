#ifndef DeleteBinarySortTreeNode_h
#define DeleteBinarySortTreeNode_h

//删除二叉查找树结点

#include "Basis.h"
#include "BinarySortTree.h"
#include "stdio.h"



//删除二叉查找树结点
/*
1）找到要被删的结点
2）对被删结点分3种情况：被删结点有左子树和右子树、只有左子树或右子树、无子树
3）处理这3种情况
*/
void deleteBinarySortTreeNode(BinarySortTree &bSTree,KeyType key){
	BinarySortNode *pNodeToDelete;
	BinarySortNode *pParentNode,*pChildTree;    //指示要被删结点的双亲和子树
	BinarySortNode *pVanNode,*pVanParentNode;		//指示被删结点的前驱和前驱的双亲结点
	
	//1.找到要被删的结点
	pNodeToDelete=bSTree;
	pParentNode;    //将双亲结点初始化为NULL
	while(pNodeToDelete){
		if(key==pNodeToDelete->data.key){
			break;    //若找到被删结点，则跳出循环
		}
		//若上面的if条件不成立，则当前的pNodeToDelete不是指向要被删的结点
		pParentNode=pNodeToDelete;    
	    if(key>pNodeToDelete->data.key){
			pNodeToDelete=pNodeToDelete->rChild;
		}
		else{
			pNodeToDelete=pNodeToDelete->lChild;
		}
	}
	if(pNodeToDelete){    //如果循环结束后，pNodeToDelete==NULL，则表明不存在被删结点
		return ;
	}

	//2.对被删结点分3种情况：被删结点有左子树和右子树、只有左子树或右子树、无子树
	if(pNodeToDelete->lChild &&
		pNodeToDelete->rChild){
			pVanParentNode=pNodeToDelete;    //设置pVanParentNode的处置以区分下面的两种情况

			//寻找被删结点的前驱及前驱的双亲，以被删结点的左孩子为起点
			pVanNode=pNodeToDelete->lChild;
			while(pVanNode->rChild){
				pVanParentNode=pVanNode;
				pVanNode=pVanNode->rChild;
			}
			//寻找结束

			pNodeToDelete->data=pVanNode->data;    //用其前驱的信息替换被删结点的信息，故后面直接删除其前驱结点

			//将pVanNode的左孩子接到正确的地方
			if(pVanParentNode==pNodeToDelete){
				pNodeToDelete->lChild=pVanNode->lChild;
			}
			else{
				pVanParentNode->rChild=pVanNode->lChild;
			}
			delete pVanNode;    //删除前驱结点空间
	}
	else{
		if(pNodeToDelete->lChild){
			pChildTree=pNodeToDelete->lChild;
	    }
	    else if(pNodeToDelete->rChild){
			pChildTree=pNodeToDelete->rChild;
		}

		//将pChildTree所指的子树挂接到其双亲结点pParentNode相应的位置
		if(pParentNode==NULL){    //如果要被删结点为根结点
			bSTree=pChildTree;
		}
		else if(pParentNode->lChild==pNodeToDelete){
			pParentNode->lChild=pChildTree;
		}
		else if(pParentNode->rChild==pNodeToDelete){
			pParentNode->rChild=pChildTree;
		}
		delete pNodeToDelete;
	}
}



#endif