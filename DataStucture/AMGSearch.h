/**
* �����ڽӾ����ʾͼ�����������㷨
* Author: FruitBasket
* Time: 2017/8/23
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef AMGSearch_h
#define AMGSearch_h

#include "stdio.h"
#include "Basis.h"
#include "GraphStructure.h"

/*
��ͨͼ���������������

startVertexIndex : ��startVertexIndex��Ŷ�Ӧ�Ķ��㣬��ʼ������������
visited[]:��Ϊ�����Ƿ��ѱ����ʵı�ǡ�����ѱ����ʣ��򶥵��ӦԪ��ֵΪtrue������Ϊfalse
*/
void connectiveDepthFirstSearch(AdjacencyMatrixGraph graph, int startVertexIndex, bool visited[MAX_VERTEX_NUM]){
	int i;
	printf("%c  ", graph.vertices[startVertexIndex]);
	visited[startVertexIndex] = true;
	//�����붥��startVertexIndexֱ�������Ķ���
	for (i = 0; i<graph.verticesNum; i++){
		if (graph.arcs[startVertexIndex][i] != 0 && visited[i] != true){//�������startVertexIndex�Ͷ���iֱ������������iδ�����ʹ�
			//�Զ���i��Ϊ�µ���ʼ����
			connectiveDepthFirstSearch(graph, i, visited);
		}
	}
}

/*
����ͨͼ���������������

graph:ͼ
*/
void depthFirstSearch(AdjacencyMatrixGraph graph){
	int i;
	bool visited[MAX_VERTEX_NUM] = { false };
	//�ֱ���ÿһ������Ϊ��ʼ�㣬������ͨͼ�������������
	for (i = 0; i<graph.verticesNum; i++){
		if (visited[i] == false){
			connectiveDepthFirstSearch(graph, i, visited);
		}
	}
}

#endif