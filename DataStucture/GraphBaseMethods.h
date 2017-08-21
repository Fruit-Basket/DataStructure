/**
* ��ͨͼ�Ļ�������
* Author: FruitBasket
* Time: 2017/8/21
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef GraphBaseMethods_h
#define GraphBaseMethods_h

#include "Basis.h"
#include "GraphStructure.h"

/*
��������: ���ض�����ͼ�е�λ�ã��±꣩

graph:���ڽӾ����ʾ��ͼ
vertex:ͼ�Ķ���
*/
int locateVertex(AdjacencyMatrixGraph graph, VertexType vertex){

}

Status createNondirectionalGraph(
	AdjacencyMatrixGraph &graph, 
	int verticesNum, 
	int arcsNum,
	VertexType vertices[],
	int arcs1[],
	int arcs2[],
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
			graph.vertices[i] = vertices[i];
		}

		for (i = 0; i < arcsNum; ++i){
			for (j = 0; j < arcsNum; ++j){
				graph.arcs[i][j] = MAX_WEIGHT;
			}
		}

		///
	}
}


#endif