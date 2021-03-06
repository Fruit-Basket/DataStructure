/**
* 以邻接矩阵表示的普通图的基本方法
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
输出以邻接矩阵表示的图

graph:以邻接矩阵表示的图
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
辅助函数: 返回顶点在图中的位置（下标）

graph:以邻接矩阵表示的图
vertex:图的顶点
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
创建无向网，默认顶点没有从自己出发到到达自己的边

graph:以邻接矩阵表示的图
verticesNum:顶点数
arcsNum:边数
vertices[]:顶点表
arcs1[]:所有边的一侧顶点
arcs2[]:所有边的另一侧顶点
weights[]:所有边的权值
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
			graph.vertices[i] = vertices[i];//这里没有考虑顶点表如果存在相同顶点的错误情况
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

#endif