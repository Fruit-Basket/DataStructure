/**
* Prim最小生成树算法，使用邻接矩阵连通无向网
* Author: FruitBasket
* Time: 2017/8/23
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef Prim_h
#define Prim_h

/*
算法思想：
本算法又称为“加点法”
随机选取一个顶点作为初始最小生成树，逐步增加距离生成树最短的剩余顶点

算法特点：
时间复杂度为O(n^2)，与网中的边数无关
*/

#include "Basis.h"
#include "AMGBaseMethods.h"

/*
辅助数组
1.数组的元素表示生成树与未并入生成树的顶点相连的最短边
2.未并入生成树的顶点和数组元素一一对应
3.数组的下标表示未并入生成树顶点的编号
*/
typedef struct{
	VertexType adjacencyVertex;//该边与生成树的adjacencyVertex顶点相连
	ArcType lowCost;//该边的权值
}CloseEdges[MAX_VERTEX_NUM];

/*
辅助函数: 返回数组中未并入生成树中且lowCost（权值）最小的元素下标

amount : 数组大小
*/
int minLCIndex(CloseEdges closeEdges, int amount){
	int minLowCost = MAX_WEIGHT;
	int minIndex = -1;
	for (int i = 0; i<amount; i++){
		if (minLowCost>closeEdges[i].lowCost
			&&closeEdges[i].lowCost != 0){//lowCost!=0表示未并入生成树
			minLowCost = closeEdges[i].lowCost;
			minIndex = i;
		}
	}
	return minIndex;
}

/*
Prim最小生成树算法
*/
void primMiniSpanTree(AdjacencyMatrixGraph aMGraph, VertexType startVertex){
	int startIndex, minLowCostIndex;
	CloseEdges closeEdges;
	int i, j;

	//1.将初始顶点并入生成树
	startIndex = locateVertex(aMGraph, startVertex);
	closeEdges[startIndex].lowCost = 0;//lowCost==0表示未并入生成树，该结点并入了生成树

	//2.初始化辅助数组
	for (i = 0; i<aMGraph.verticesNum; i++){
		if (i != startIndex){
			closeEdges[i].adjacencyVertex = startIndex;
			closeEdges[i].lowCost = aMGraph.arcs[startIndex][i];    //生成树（只有一个顶点startVertexIndex）到剩余顶点的最短边的权值
		}
	}

	//3.生成最小生成树
	if(DEBUG)printf("the edges are :\n");
	for (i = 0; i<aMGraph.verticesNum - 1; i++){
		minLowCostIndex = minLCIndex(closeEdges, aMGraph.verticesNum);
		if (DEBUG){
			printf("No.%d edge :  %c -> %c , weigth=%d\n",
				i,
				aMGraph.vertices[closeEdges[minLowCostIndex].adjacencyVertex],
				aMGraph.vertices[minLowCostIndex],
				closeEdges[minLowCostIndex].lowCost
				);
		}
		closeEdges[minLowCostIndex].lowCost = 0;	//将minLowCostIndex对应顶点并入生成树

		for (j = 0; j<aMGraph.verticesNum; j++){
			//如果顶点j到顶点minLowCostIndex的权值小于到生成树的权值
			if (aMGraph.arcs[j][minLowCostIndex]<closeEdges[j].lowCost){
				closeEdges[j].adjacencyVertex = minLowCostIndex;
				closeEdges[j].lowCost = aMGraph.arcs[j][minLowCostIndex];
			}
		}
	}
}

#endif