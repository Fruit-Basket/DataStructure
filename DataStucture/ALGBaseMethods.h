/**
* 以邻接表表示的普通图的基本方法
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
辅助函数: 返回顶点在图中的位置（下标）
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
创建无向图
默认顶点没有从自己出发到到达自己的边
*/
Status createNondirectionalGraph(AdjacencyListGraph &aLGraph){
	int verticesNum, arcsNum;
	VertexType vertex1, vertex2;
	int  vertexLocation1, vertexLocation2;
	ArcNode *pArcNode;
	int i;
	//1.初始化矩阵
	printf("input the verticesNum , arcsNum (separate with ',' , end with ENTER): ");
	scanf("%d,%d", &verticesNum, &arcsNum);
	getchar();	//用于接收多余的回车健
	aLGraph.verticesNum = verticesNum;
	aLGraph.arcsNum = arcsNum;

	printf("input the vertices information (end with ENTER) : ");
	for (i = 0; i<verticesNum; i++){
		aLGraph.vertices[i].data = getchar();
		aLGraph.vertices[i].firstArc = NULL;
	}
	getchar();
	//初始化结束
	//2.创建邻接表
	printf("input each arc by \" vertex1vertex2\"\n");
	for (i = 0; i<arcsNum; ++i){
		printf("No.%d : ", i);
		scanf("%c%c", &vertex1, &vertex2);
		getchar();		//接收多余的回车键
		vertexLocation1 = locateVertex(aLGraph, vertex1);
		vertexLocation2 = locateVertex(aLGraph, vertex2);
		//创建第1个边结点
		pArcNode = new ArcNode;
		pArcNode->adjacencyVertex = vertexLocation2;
		pArcNode->weight = 0;		//将边的权重置为0
		pArcNode->nextArc = aLGraph.vertices[vertexLocation1].firstArc;
		aLGraph.vertices[vertexLocation1].firstArc = pArcNode;
		//创建第2个边结点
		pArcNode = new ArcNode;
		pArcNode->adjacencyVertex = vertexLocation1;
		pArcNode->weight = 0;		//将边的权重置为0
		pArcNode->nextArc = aLGraph.vertices[vertexLocation2].firstArc;
		aLGraph.vertices[vertexLocation2].firstArc = pArcNode;
	}
	return OK;
}

/*
创建有向图
默认顶点没有从自己出发到到达自己的边
*/
Status createDirectionalGraph(AdjacencyListGraph &aLGraph){
	int verticesNum, arcsNum;
	VertexType vertex1, vertex2;
	int  vertexLocation1, vertexLocation2;
	ArcNode *pArcNode;
	int i;
	//1.初始化矩阵
	printf("input the verticesNum , arcsNum (separate with ',' , end with ENTER): ");
	scanf("%d,%d", &verticesNum, &arcsNum);
	getchar();	//用于接收多余的回车健
	aLGraph.verticesNum = verticesNum;
	aLGraph.arcsNum = arcsNum;

	printf("input the vertices information (end with ENTER) : ");
	for (i = 0; i<verticesNum; i++){
		aLGraph.vertices[i].data = getchar();
		aLGraph.vertices[i].firstArc = NULL;
	}
	getchar();
	//初始化结束
	//2.创建邻接表
	printf("input each arc by \" vertex1vertex2\"\n");
	for (i = 0; i<arcsNum; ++i){
		printf("No.%d : ", i);
		scanf("%c%c", &vertex1, &vertex2);
		getchar();		//接收多余的回车键
		vertexLocation1 = locateVertex(aLGraph, vertex1);
		vertexLocation2 = locateVertex(aLGraph, vertex2);
		//创建边结点
		pArcNode = new ArcNode;
		pArcNode->adjacencyVertex = vertexLocation2;
		pArcNode->weight = 0;		//将图的权重置为0
		pArcNode->nextArc = aLGraph.vertices[vertexLocation1].firstArc;
		aLGraph.vertices[vertexLocation1].firstArc = pArcNode;
	}
	return OK;
}

/*
创建有向网
默认顶点没有从自己出发到到达自己的边
*/
Status createDirectionalNetwork(AdjacencyListGraph &aLGraph){
	int verticesNum, arcsNum;
	VertexType vertex1, vertex2;
	int weight;
	int  vertexLocation1, vertexLocation2;
	ArcNode *pArcNode;
	int i;
	//1.初始化矩阵
	printf("input the verticesNum , arcsNum (separate with ',' , end with ENTER): ");
	scanf("%d,%d", &verticesNum, &arcsNum);
	getchar();	//用于接收多余的回车健
	aLGraph.verticesNum = verticesNum;
	aLGraph.arcsNum = arcsNum;

	printf("input the vertices information (end with ENTER) : ");
	for (i = 0; i<verticesNum; i++){
		aLGraph.vertices[i].data = getchar();
		aLGraph.vertices[i].firstArc = NULL;
	}
	getchar();
	//初始化结束
	//2.创建邻接表
	printf("input each arc by \" vertex1vertex2weight\"\n");
	for (i = 0; i<arcsNum; ++i){
		printf("No.%d : ", i);
		scanf("%c%c%d", &vertex1, &vertex2, &weight);
		getchar();		//接收多余的回车键
		vertexLocation1 = locateVertex(aLGraph, vertex1);
		vertexLocation2 = locateVertex(aLGraph, vertex2);
		//创建边结点
		pArcNode = new ArcNode;
		pArcNode->adjacencyVertex = vertexLocation2;
		pArcNode->weight = weight;		//将图的权重置为0
		pArcNode->nextArc = aLGraph.vertices[vertexLocation1].firstArc;
		aLGraph.vertices[vertexLocation1].firstArc = pArcNode;
	}
	return OK;
}

/*
输出无向图、有向图和有向网
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