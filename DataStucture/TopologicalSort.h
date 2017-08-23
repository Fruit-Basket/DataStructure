/**
* ��������ʹ���ڽ�����������Ȩͼ��
* Author: FruitBasket
* Time: 2017/8/21
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef Topological_h
#define Topological_h

/*
�㷨˼�룺
����ѡ����ǰ���Ķ��������
*/

#include "Basis.h"
#include "GraphStructure.h"
#include "stdio.h"

/*
���㷨�ĸ������ݽṹ��
1.һά����inDegree[i]
��Ŷ�����ȣ�û��ǰ���Ķ���������Ϊ0�Ķ��㡣

2.ջstack
�ݴ��������Ϊ0����ı�ţ��������Ա����ظ�ɨ������inDegree
������Ϊ0�Ķ��㣬����㷨��Ч�ʡ�

3.һά����topo[i]
��¼�������еĶ�����
*/

/*
��������
1������������topo[]���ͼ�ж�������
2��topo[]Ԫ�ر�ź�ͼ�ж�����һһ��Ӧ
*/
void findInDegree(AdjacencyListGraph aLGraph, int inDegree[]){
	int i;
	ArcNode *p;

	for (i = 0; i<aLGraph.verticesNum; i++){
		inDegree[i] = 0;
	}

	for (i = 0; i<aLGraph.verticesNum; i++){
		p = aLGraph.vertices[i].firstArc;
		while (p != NULL){
			inDegree[p->adjacencyVertex]++;
			p = p->nextArc;
		}
	}
}


/*
��������
*/
Status topologicalSort(AdjacencyListGraph aLGraph, int topo[]){
	int inDegree[MAX_VERTEX_NUM];
	int stack[MAX_VERTEX_NUM], top = -1;
	int amount;	//��¼���������ж�������
	int popVertexIndex;
	ArcNode *pArcNode;
	int i;

	//��ʼ��
	findInDegree(aLGraph, inDegree);
	amount = 0;
	for (i = 0; i<aLGraph.verticesNum; ++i){	//�����Ϊ0�Ķ���ı����ջ
		if (inDegree[i] == 0){
			++top;
			stack[top] = i;
		}
	}

	//2.���㷨
	while (top>-1){    //���ջ����
		popVertexIndex = stack[top];	//�����ų�ջ
		--top;
		topo[amount] = popVertexIndex;		//��ջ�Ķ����Ž������˶���
		++amount;   //���������ж���������1
		pArcNode = aLGraph.vertices[popVertexIndex].firstArc;
		while (pArcNode != NULL){		//������дӶ���popVertexIndex�����ı�
			inDegree[pArcNode->adjacencyVertex]--;    //����pArcNodeָ��Ķ������ȼ�1
			if (inDegree[pArcNode->adjacencyVertex] == 0){		//�����������Ϊ0������ջ
				top++;
				stack[top] = pArcNode->adjacencyVertex;
			}
			pArcNode = pArcNode->nextArc;
		}
	}

	//3.�ж�ͼ���Ƿ���ڻ�
	if (amount<aLGraph.verticesNum){
		return ERROR;
	}
	else{
		return OK;
	}
}

#endif