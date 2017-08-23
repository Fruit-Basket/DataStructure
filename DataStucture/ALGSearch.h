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

startVertexIndex : ��startVertexIndex��Ŷ�Ӧ�Ķ��㣬��ʼ������������
*/
void connectiveDepthFirstSearch(AdjacencyListGraph aLGraph, int startVertexIndex, bool visited[MAX_VERTEX_NUM]){
	printf("%c ", aLGraph.vertices[startVertexIndex]);
	visited[startVertexIndex] = true;
	ArcNode *p;
	p = aLGraph.vertices[startVertexIndex].firstArc;
	while (p){
		if (visited[p->adjacencyVertex] == false){
			connectiveDepthFirstSearch(aLGraph, p->adjacencyVertex, visited);
		}
		p = p->nextArc;
	}
}

/*
����ͨͼ���������������
*/
void depthFirstSearch(AdjacencyListGraph aLGraph){
	int i;
	bool visited[MAX_VERTEX_NUM] = { false };
	//�ֱ���ÿһ������Ϊ��ʼ�㣬������ͨͼ�������������
	for (i = 0; i<aLGraph.verticesNum; i++){
		if (visited[i] == false){
			connectiveDepthFirstSearch(aLGraph, i, visited);
		}
	}
}

/*
��ͨͼ���������������
*/
void connectiveBreadthFirstSearch(AdjacencyListGraph aLGraph, int startVertexIndex, bool visited[MAX_VERTEX_AMOUNT]){
	int currentVertex;
	ArcNode *currentArcNodePointer;

	//1.����һ��ѭ�����У�������ż���Ҫ���ʵĲ���ϵĶ����ָ��
	int queue[MAX_VERTEX_AMOUNT];
	int front = 0, rear = 0;

	//2.���ʵ�һ������
	printf("%c ", aLGraph.vertices[startVertexIndex].data);
	visited[startVertexIndex] = true;

	//3.���ձ����ʵĶ������
	queue[rear] = startVertexIndex;
	rear = (rear + 1) % MAX_VERTEX_AMOUNT;

	//4.���й�����ȱ���
	while (front != rear){    //������в���
		currentVertex = queue[front];
		front = (front + 1) % MAX_VERTEX_AMOUNT;
		currentArcNodePointer = aLGraph.vertices[currentVertex].firstArc;
		while (currentArcNodePointer){	//����ճ��Ӷ�������ڽӶ���
			if (visited[currentArcNodePointer->adjacencyVertex] == false){	//������ڽӶ���δ�����ʹ�
				printf("%c ", aLGraph.vertices[currentArcNodePointer->adjacencyVertex].data);
				visited[currentArcNodePointer->adjacencyVertex] = true;
				queue[rear] = currentArcNodePointer->adjacencyVertex;
				rear = (rear + 1) % MAX_VERTEX_AMOUNT;
			}
			currentArcNodePointer = currentArcNodePointer->nextArc;
		}
	}
}

/*
����ͨͼ����������ѱ���
*/
void breadthFirstSearch(AdjacencyListGraph aLGraph){
	int i;
	bool visited[MAX_VERTEX_NUM] = { false };
	//�ֱ���ÿһ������Ϊ��ʼ�㣬������ͨͼ�Ĺ����������
	for (i = 0; i<aLGraph.verticesNum; i++){
		if (visited[i] == false){
			connectiveBreadthFirstSearch(aLGraph, i, visited);
		}
	}
}

#endif