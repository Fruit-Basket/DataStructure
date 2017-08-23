/**
* 采用邻接矩阵表示图的搜索遍历算法
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
连通图深度优先搜索遍历

startVertexIndex : 以startVertexIndex编号对应的顶点，开始进行搜索遍历
visited[]:作为顶点是否已被访问的标记。如果已被访问，则顶点对应元素值为true，否则为false
*/
void connectiveDepthFirstSearch(AdjacencyMatrixGraph graph, int startVertexIndex, bool visited[MAX_VERTEX_NUM]){
	int i;
	printf("%c  ", graph.vertices[startVertexIndex]);
	visited[startVertexIndex] = true;
	//遍历与顶点startVertexIndex直接相连的顶点
	for (i = 0; i<graph.verticesNum; i++){
		if (graph.arcs[startVertexIndex][i] != 0 && visited[i] != true){//如果顶点startVertexIndex和顶点i直接相连，顶点i未被访问过
			//以顶点i作为新的起始顶点
			connectiveDepthFirstSearch(graph, i, visited);
		}
	}
}

/*
非连通图深度优先搜索遍历

graph:图
*/
void depthFirstSearch(AdjacencyMatrixGraph graph){
	int i;
	bool visited[MAX_VERTEX_NUM] = { false };
	//分别以每一个顶点为起始点，进行连通图的深度优先搜索
	for (i = 0; i<graph.verticesNum; i++){
		if (visited[i] == false){
			connectiveDepthFirstSearch(graph, i, visited);
		}
	}
}

#endif