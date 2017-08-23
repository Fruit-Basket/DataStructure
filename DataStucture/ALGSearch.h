/**
* �����ڽӱ�ʾ��ʾͼ�����������㷨
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
��ͨͼ���������������

graph:ͼ
startVertexIndex : ��startVertexIndex��Ŷ�Ӧ�Ķ��㣬��ʼ������������
visited[]:��Ϊ�����Ƿ��ѱ����ʵı�ǡ�����ѱ����ʣ��򶥵��ӦԪ��ֵΪtrue������Ϊfalse
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
����ͨͼ���������������

graph:ͼ
*/
void depthFirstSearch(AdjacencyListGraph graph){
	int i;
	bool visited[MAX_VERTEX_NUM] = { false };
	//�ֱ���ÿһ������Ϊ��ʼ�㣬������ͨͼ�������������
	for (i = 0; i<graph.verticesNum; i++){
		if (visited[i] == false){
			connectiveDepthFirstSearch(graph, i, visited);
		}
	}
}

/*
��ͨͼ���������������
*/
void connectiveBreadthFirstSearch(AdjacencyListGraph graph, int startVertexIndex, bool visited[MAX_VERTEX_NUM]){
	int currentVertex;
	ArcNode *currentArcNodePointer;

	//1.����һ��ѭ�����У�������ż���Ҫ���ʵĲ���ϵĶ����ָ��
	int queue[MAX_VERTEX_NUM];
	int front = 0, rear = 0;

	//2.���ʵ�һ������
	printf("%c ", graph.vertices[startVertexIndex].data);
	visited[startVertexIndex] = true;

	//3.���ձ����ʵĶ������
	queue[rear] = startVertexIndex;
	rear = (rear + 1) % MAX_VERTEX_NUM;

	//4.���й�����ȱ���
	while (front != rear){//������в���

		currentVertex = queue[front];
		front = (front + 1) % MAX_VERTEX_NUM;

		currentArcNodePointer = graph.vertices[currentVertex].firstArc;
		while (currentArcNodePointer){//����ճ��Ӷ�������ڽӶ���
			if (visited[currentArcNodePointer->adjacencyVertex] == false){//������ڽӶ���δ�����ʹ�
				printf("%c ", graph.vertices[currentArcNodePointer->adjacencyVertex].data);
				visited[currentArcNodePointer->adjacencyVertex] = true;

				//���ձ����ʵĶ������
				queue[rear] = currentArcNodePointer->adjacencyVertex;
				rear = (rear + 1) % MAX_VERTEX_NUM;
			}
			currentArcNodePointer = currentArcNodePointer->nextArc;
		}
	}
}

/*
����ͨͼ����������ѱ���
*/
void breadthFirstSearch(AdjacencyListGraph graph){
	int i;
	bool visited[MAX_VERTEX_NUM] = { false };
	//�ֱ���ÿһ������Ϊ��ʼ�㣬������ͨͼ�Ĺ����������
	for (i = 0; i<graph.verticesNum; i++){
		if (visited[i] == false){
			connectiveBreadthFirstSearch(graph, i, visited);
		}
	}
}

#endif