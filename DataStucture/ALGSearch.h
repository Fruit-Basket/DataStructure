/**
* 采用邻接表示表示图的搜索遍历算法
* Author: FruitBasket
* Time: 2017/8/23
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef ALGSearch_h
#define ALGSearch_h

#include "Basis.h"
#include "stdio.h"
#include "GraphStructure.h"

/*
连通图深度优先搜索遍历

graph:图
startVertexIndex : 以startVertexIndex编号对应的顶点，开始进行搜索遍历
visited[]:作为顶点是否已被访问的标记。如果已被访问，则顶点对应元素值为true，否则为false
*/
void connectiveDepthFirstSearch(AdjacencyListGraph graph, int startVertexIndex, bool visited[MAX_VERTEX_NUM]){
	printf("%c ", graph.vertices[startVertexIndex]);
	visited[startVertexIndex] = true;
	ArcNode *p;
	p = graph.vertices[startVertexIndex].firstArc;
	while (p){
		if (visited[p->adjacencyVertex] == false){
			connectiveDepthFirstSearch(graph, p->adjacencyVertex, visited);
		}
		p = p->nextArc;
	}
}

/*
非连通图深度优先搜索遍历

graph:图
*/
void depthFirstSearch(AdjacencyListGraph graph){
	int i;
	bool visited[MAX_VERTEX_NUM] = { false };
	//分别以每一个顶点为起始点，进行连通图的深度优先搜索
	for (i = 0; i<graph.verticesNum; i++){
		if (visited[i] == false){
			connectiveDepthFirstSearch(graph, i, visited);
		}
	}
}

/*
连通图广度优先搜索遍历
*/
void connectiveBreadthFirstSearch(AdjacencyListGraph graph, int startVertexIndex, bool visited[MAX_VERTEX_NUM]){
	int currentVertex;
	ArcNode *currentArcNodePointer;

	//1.定义一个循环队列，用来存放即将要访问的层次上的顶点的指针
	int queue[MAX_VERTEX_NUM];
	int front = 0, rear = 0;

	//2.访问第一个顶点
	printf("%c ", graph.vertices[startVertexIndex].data);
	visited[startVertexIndex] = true;

	//3.将刚被访问的顶点入队
	queue[rear] = startVertexIndex;
	rear = (rear + 1) % MAX_VERTEX_NUM;

	//4.进行广度优先遍历
	while (front != rear){//如果队列不空

		currentVertex = queue[front];
		front = (front + 1) % MAX_VERTEX_NUM;

		currentArcNodePointer = graph.vertices[currentVertex].firstArc;
		while (currentArcNodePointer){//如果刚出队顶点存在邻接顶点
			if (visited[currentArcNodePointer->adjacencyVertex] == false){//如果该邻接顶点未被访问过
				printf("%c ", graph.vertices[currentArcNodePointer->adjacencyVertex].data);
				visited[currentArcNodePointer->adjacencyVertex] = true;

				//将刚被访问的顶点入队
				queue[rear] = currentArcNodePointer->adjacencyVertex;
				rear = (rear + 1) % MAX_VERTEX_NUM;
			}
			currentArcNodePointer = currentArcNodePointer->nextArc;
		}
	}
}

/*
非连通图广度优先索搜遍历
*/
void breadthFirstSearch(AdjacencyListGraph graph){
	int i;
	bool visited[MAX_VERTEX_NUM] = { false };
	//分别以每一个顶点为起始点，进行连通图的广度优先搜索
	for (i = 0; i<graph.verticesNum; i++){
		if (visited[i] == false){
			connectiveBreadthFirstSearch(graph, i, visited);
		}
	}
}

#endif