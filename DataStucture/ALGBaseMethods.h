/**
* ���ڽӱ��ʾ����ͨͼ�Ļ�������
* Author: FruitBasket
* Time: 2017/8/21
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef ALGBaseMethods_h
#define ALGBaseMethods_h

#include "Basis.h"
#include "stdio.h"
#include "GraphStructure.h"

/*
��������: ���ض�����ͼ�е�λ�ã��±꣩
*/
int locateVertex(AdjacencyListGraph aLGraph, VertexType vertex){
	for (int i = 0; i<aLGraph.verticesNum; ++i){
		if (vertex == aLGraph.vertices[i].data){
			return i;
		}
	}
	return -1;
}

/*
��������ͼ
Ĭ�϶���û�д��Լ������������Լ��ı�
*/
Status createNondirectionalGraph(AdjacencyListGraph &aLGraph){
	int verticesNum, arcsNum;
	VertexType vertex1, vertex2;
	int  vertexLocation1, vertexLocation2;
	ArcNode *pArcNode;
	int i;
	//1.��ʼ������
	printf("input the verticesNum , arcsNum (separate with ',' , end with ENTER): ");
	scanf("%d,%d", &verticesNum, &arcsNum);
	getchar();	//���ڽ��ն���Ļس���
	aLGraph.verticesNum = verticesNum;
	aLGraph.arcsNum = arcsNum;

	printf("input the vertices information (end with ENTER) : ");
	for (i = 0; i<verticesNum; i++){
		aLGraph.vertices[i].data = getchar();
		aLGraph.vertices[i].firstArc = NULL;
	}
	getchar();
	//��ʼ������
	//2.�����ڽӱ�
	printf("input each arc by \" vertex1vertex2\"\n");
	for (i = 0; i<arcsNum; ++i){
		printf("No.%d : ", i);
		scanf("%c%c", &vertex1, &vertex2);
		getchar();		//���ն���Ļس���
		vertexLocation1 = locateVertex(aLGraph, vertex1);
		vertexLocation2 = locateVertex(aLGraph, vertex2);
		//������1���߽��
		pArcNode = new ArcNode;
		pArcNode->adjacencyVertex = vertexLocation2;
		pArcNode->weight = 0;		//���ߵ�Ȩ����Ϊ0
		pArcNode->nextArc = aLGraph.vertices[vertexLocation1].firstArc;
		aLGraph.vertices[vertexLocation1].firstArc = pArcNode;
		//������2���߽��
		pArcNode = new ArcNode;
		pArcNode->adjacencyVertex = vertexLocation1;
		pArcNode->weight = 0;		//���ߵ�Ȩ����Ϊ0
		pArcNode->nextArc = aLGraph.vertices[vertexLocation2].firstArc;
		aLGraph.vertices[vertexLocation2].firstArc = pArcNode;
	}
	return OK;
}

/*
��������ͼ
Ĭ�϶���û�д��Լ������������Լ��ı�
*/
Status createDirectionalGraph(AdjacencyListGraph &aLGraph){
	int verticesNum, arcsNum;
	VertexType vertex1, vertex2;
	int  vertexLocation1, vertexLocation2;
	ArcNode *pArcNode;
	int i;
	//1.��ʼ������
	printf("input the verticesNum , arcsNum (separate with ',' , end with ENTER): ");
	scanf("%d,%d", &verticesNum, &arcsNum);
	getchar();	//���ڽ��ն���Ļس���
	aLGraph.verticesNum = verticesNum;
	aLGraph.arcsNum = arcsNum;

	printf("input the vertices information (end with ENTER) : ");
	for (i = 0; i<verticesNum; i++){
		aLGraph.vertices[i].data = getchar();
		aLGraph.vertices[i].firstArc = NULL;
	}
	getchar();
	//��ʼ������
	//2.�����ڽӱ�
	printf("input each arc by \" vertex1vertex2\"\n");
	for (i = 0; i<arcsNum; ++i){
		printf("No.%d : ", i);
		scanf("%c%c", &vertex1, &vertex2);
		getchar();		//���ն���Ļس���
		vertexLocation1 = locateVertex(aLGraph, vertex1);
		vertexLocation2 = locateVertex(aLGraph, vertex2);
		//�����߽��
		pArcNode = new ArcNode;
		pArcNode->adjacencyVertex = vertexLocation2;
		pArcNode->weight = 0;		//��ͼ��Ȩ����Ϊ0
		pArcNode->nextArc = aLGraph.vertices[vertexLocation1].firstArc;
		aLGraph.vertices[vertexLocation1].firstArc = pArcNode;
	}
	return OK;
}

/*
����������
Ĭ�϶���û�д��Լ������������Լ��ı�
*/
Status createDirectionalNetwork(AdjacencyListGraph &aLGraph){
	int verticesNum, arcsNum;
	VertexType vertex1, vertex2;
	int weight;
	int  vertexLocation1, vertexLocation2;
	ArcNode *pArcNode;
	int i;
	//1.��ʼ������
	printf("input the verticesNum , arcsNum (separate with ',' , end with ENTER): ");
	scanf("%d,%d", &verticesNum, &arcsNum);
	getchar();	//���ڽ��ն���Ļس���
	aLGraph.verticesNum = verticesNum;
	aLGraph.arcsNum = arcsNum;

	printf("input the vertices information (end with ENTER) : ");
	for (i = 0; i<verticesNum; i++){
		aLGraph.vertices[i].data = getchar();
		aLGraph.vertices[i].firstArc = NULL;
	}
	getchar();
	//��ʼ������
	//2.�����ڽӱ�
	printf("input each arc by \" vertex1vertex2weight\"\n");
	for (i = 0; i<arcsNum; ++i){
		printf("No.%d : ", i);
		scanf("%c%c%d", &vertex1, &vertex2, &weight);
		getchar();		//���ն���Ļس���
		vertexLocation1 = locateVertex(aLGraph, vertex1);
		vertexLocation2 = locateVertex(aLGraph, vertex2);
		//�����߽��
		pArcNode = new ArcNode;
		pArcNode->adjacencyVertex = vertexLocation2;
		pArcNode->weight = weight;		//��ͼ��Ȩ����Ϊ0
		pArcNode->nextArc = aLGraph.vertices[vertexLocation1].firstArc;
		aLGraph.vertices[vertexLocation1].firstArc = pArcNode;
	}
	return OK;
}

/*
�������ͼ������ͼ��������
*/
void showGraph(AdjacencyListGraph aLGraph){
	int i;
	ArcNode *pArcNode;

	printf("adjacency List graph:\n");
	printf("verticesNum=%d ,   arcsNum=%d\n", aLGraph.verticesNum, aLGraph.arcsNum);
	printf("the list are :\n");
	for (i = 0; i<aLGraph.verticesNum; i++){
		printf("No.%d : %c   ", i, aLGraph.vertices[i].data);
		pArcNode = aLGraph.vertices[i].firstArc;
		while (pArcNode){
			printf("-->%d(%d) ", pArcNode->adjacencyVertex, pArcNode->weight);
			pArcNode = pArcNode->nextArc;
		}
		putchar('\n');
	}
}

#endif