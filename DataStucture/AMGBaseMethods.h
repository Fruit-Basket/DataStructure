/**
* ���ڽӾ����ʾ����ͨͼ�Ļ�������
* Author: FruitBasket
* Time: 2017/8/21
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef AMGBaseMethods_h
#define AMGBaseMethods_h

#include "Basis.h"
#include "GraphStructure.h"
#include "stdio.h"

/*
������ڽӾ����ʾ��ͼ

graph:���ڽӾ����ʾ��ͼ
*/
void showGraph(AdjacencyMatrixGraph graph){
	int i, j;
	printf("adjacency matrix graph:\n");
	printf("verticesNum=%d ,   arcsNum=%d\n", graph.verticesNum, graph.arcsNum);
	printf("the vertices are :  ");
	for (int i = 0; i<graph.verticesNum; i++){
		putchar(graph.vertices[i]);
	}
	putchar('\n');
	printf("the Matrix is :\n");
	for (i = 0; i<graph.verticesNum; i++){
		for (j = 0; j<graph.verticesNum; j++){
			printf("%10d    ", graph.arcs[i][j]);
		}
		putchar('\n');
	}
}

/*
��������: ���ض�����ͼ�е�λ�ã��±꣩

graph:���ڽӾ����ʾ��ͼ
vertex:ͼ�Ķ���
*/
int locateVertex(AdjacencyMatrixGraph graph, VertexType vertex){
	for (int i = 0; i < graph.verticesNum; ++i){
		if (vertex == graph.vertices[i]){
			return i;
		}
	}
	return -1;
}

/*
������������Ĭ�϶���û�д��Լ������������Լ��ı�

graph:���ڽӾ����ʾ��ͼ
verticesNum:������
arcsNum:����
vertices[]:�����
arcs1[]:���бߵ�һ�ඥ��
arcs2[]:���бߵ���һ�ඥ��
weights[]:���бߵ�Ȩֵ
*/
Status createNondirectionalGraph(
	AdjacencyMatrixGraph &graph, 
	int verticesNum, 
	int arcsNum,
	VertexType vertices[],
	VertexType arcs1[],
	VertexType arcs2[],
	int weights[]){

	if (verticesNum <= 0
		|| arcsNum < 0){
		return ERROR;
	}
	else{
		graph.verticesNum = verticesNum;
		graph.arcsNum = arcsNum;

		int i,j;
		for (i = 0; i < verticesNum; ++i){
			graph.vertices[i] = vertices[i];//����û�п��Ƕ�������������ͬ����Ĵ������
		}

		for (i = 0; i < verticesNum; ++i){
			for (j = 0; j < verticesNum; ++j){
				graph.arcs[i][j] = MAX_WEIGHT;
			}
		}

		int vertexIndex1, vertexIndex2;
		for (i = 0; i < arcsNum; ++i){
			vertexIndex1 = locateVertex(graph, arcs1[i]);
			vertexIndex2 = locateVertex(graph, arcs2[i]);

			if (vertexIndex1 != -1
				&& vertexIndex2 != -1){
				graph.arcs[vertexIndex1][vertexIndex2] = weights[i];
				graph.arcs[vertexIndex2][vertexIndex1] = weights[i];
			}
			else{
				printf("Error: locate vertex error!");
				return ERROR;
			}
		}
	}
}

/*
������������Ĭ�϶���û�д��Լ������������Լ��ı�
*/
Status createNondirectionalNetwork(AdjacencyMatrixGraph &aMGraph){
	int verticesNum, arcsNum;
	VertexType vertex1, vertex2;
	ArcType arcWeight;
	int  vertexLocation1, vertexLocation2;
	int i, j;
	//1.��ʼ������
	printf("input the verticesNum , arcsNum (separate with ',' , end with ENTER): ");
	scanf("%d,%d", &verticesNum, &arcsNum);
	getchar();	//���ڽ��ն���Ļس���
	aMGraph.verticesNum = verticesNum;
	aMGraph.arcsNum = arcsNum;

	printf("input the vertices information (end with ENTER) : ");
	for (i = 0; i<verticesNum; i++){
		aMGraph.vertices[i] = getchar();
	}
	getchar();

	for (i = 0; i<verticesNum; i++){
		for (j = 0; j<verticesNum; j++){
			aMGraph.arcs[i][j] = MAX_WEIGHT;
		}
	}
	//��ʼ������
	//2.��������
	printf("input each arc by \" vertex1vertex2arcWeight\"\n");
	for (i = 0; i<arcsNum; i++){
		printf("No.%d : ", i);
		scanf("%c%c%d", &vertex1, &vertex2, &arcWeight);
		getchar();		//���ն���Ļس���
		vertexLocation1 = locateVertex(aMGraph, vertex1);
		vertexLocation2 = locateVertex(aMGraph, vertex2);
		aMGraph.arcs[vertexLocation1][vertexLocation2] = arcWeight;
		aMGraph.arcs[vertexLocation2][vertexLocation1] = arcWeight;
	}
	return OK;
}

/*
������������Ĭ�϶���û�д��Լ������������Լ��ı�
*/
Status createDirectionalNetwork(AdjacencyMatrixGraph &aMGraph){
	int verticesNum, arcsNum;
	VertexType vertex1, vertex2;
	ArcType arcWeight;
	int  vertexLocation1, vertexLocation2;
	int i, j;
	//1.��ʼ������
	printf("input the verticesNum , arcsNum (separate with ',' , end with ENTER): ");
	scanf("%d,%d", &verticesNum, &arcsNum);
	getchar();	//���ڽ��ն���Ļس���
	aMGraph.verticesNum = verticesNum;
	aMGraph.arcsNum = arcsNum;

	printf("input the vertices information (end with ENTER) : ");
	for (i = 0; i<verticesNum; i++){
		aMGraph.vertices[i] = getchar();
	}
	getchar();

	for (i = 0; i<verticesNum; i++){
		for (j = 0; j<verticesNum; j++){
			aMGraph.arcs[i][j] = MAX_WEIGHT;
		}
	}
	//��ʼ������
	//2.��������
	printf("input each arc by \" vertex1vertex2arcWeight\"\n");
	for (i = 0; i<arcsNum; i++){
		printf("No.%d : ", i);
		scanf("%c%c%d", &vertex1, &vertex2, &arcWeight);
		getchar();		//���ն���Ļس���
		vertexLocation1 = locateVertex(aMGraph, vertex1);
		vertexLocation2 = locateVertex(aMGraph, vertex2);
		aMGraph.arcs[vertexLocation1][vertexLocation2] = arcWeight;
		//aMGraph.arcs[vertexLocation2][vertexLocation1]=arcWeight;
	}
	return OK;
}

#endif