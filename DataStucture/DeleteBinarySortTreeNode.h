#ifndef DeleteBinarySortTreeNode_h
#define DeleteBinarySortTreeNode_h

//ɾ��������������

#include "Basis.h"
#include "BinarySortTree.h"
#include "stdio.h"



//ɾ��������������
/*
1���ҵ�Ҫ��ɾ�Ľ��
2���Ա�ɾ����3���������ɾ���������������������ֻ������������������������
3��������3�����
*/
void deleteBinarySortTreeNode(BinarySortTree &bSTree,KeyType key){
	BinarySortNode *pNodeToDelete;
	BinarySortNode *pParentNode,*pChildTree;    //ָʾҪ��ɾ����˫�׺�����
	BinarySortNode *pVanNode,*pVanParentNode;		//ָʾ��ɾ����ǰ����ǰ����˫�׽��
	
	//1.�ҵ�Ҫ��ɾ�Ľ��
	pNodeToDelete=bSTree;
	pParentNode;    //��˫�׽���ʼ��ΪNULL
	while(pNodeToDelete){
		if(key==pNodeToDelete->data.key){
			break;    //���ҵ���ɾ��㣬������ѭ��
		}
		//�������if��������������ǰ��pNodeToDelete����ָ��Ҫ��ɾ�Ľ��
		pParentNode=pNodeToDelete;    
	    if(key>pNodeToDelete->data.key){
			pNodeToDelete=pNodeToDelete->rChild;
		}
		else{
			pNodeToDelete=pNodeToDelete->lChild;
		}
	}
	if(pNodeToDelete){    //���ѭ��������pNodeToDelete==NULL������������ڱ�ɾ���
		return ;
	}

	//2.�Ա�ɾ����3���������ɾ���������������������ֻ������������������������
	if(pNodeToDelete->lChild &&
		pNodeToDelete->rChild){
			pVanParentNode=pNodeToDelete;    //����pVanParentNode�Ĵ���������������������

			//Ѱ�ұ�ɾ����ǰ����ǰ����˫�ף��Ա�ɾ��������Ϊ���
			pVanNode=pNodeToDelete->lChild;
			while(pVanNode->rChild){
				pVanParentNode=pVanNode;
				pVanNode=pVanNode->rChild;
			}
			//Ѱ�ҽ���

			pNodeToDelete->data=pVanNode->data;    //����ǰ������Ϣ�滻��ɾ������Ϣ���ʺ���ֱ��ɾ����ǰ�����

			//��pVanNode�����ӽӵ���ȷ�ĵط�
			if(pVanParentNode==pNodeToDelete){
				pNodeToDelete->lChild=pVanNode->lChild;
			}
			else{
				pVanParentNode->rChild=pVanNode->lChild;
			}
			delete pVanNode;    //ɾ��ǰ�����ռ�
	}
	else{
		if(pNodeToDelete->lChild){
			pChildTree=pNodeToDelete->lChild;
	    }
	    else if(pNodeToDelete->rChild){
			pChildTree=pNodeToDelete->rChild;
		}

		//��pChildTree��ָ�������ҽӵ���˫�׽��pParentNode��Ӧ��λ��
		if(pParentNode==NULL){    //���Ҫ��ɾ���Ϊ�����
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