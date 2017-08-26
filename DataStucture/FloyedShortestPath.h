/**
* Floyed最短路径算法，求图中每对顶点间的最短路径（使用邻接矩阵有向网）
* Author: FruitBasket
* Time: 2017/8/23
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef FloyedShortestPath_h
#define FloyedShortestPath_h

#include "Basis.h"
#include "stdio.h"
#include "GraphStructure.h"

/*
算法思想：
分别以每个顶点作为每对顶点之间的中间点，检测每对顶点之间的最短路径。
*/

/*
辅助数组
1.currentShortestPath[i][j]
元素值表示从顶点 i 到 j 的最短路径上顶点 j 的前一个顶点的序号

2.currentShortestDistance[i][j]
元素值表示顶点 i 和 j 之间的最短路径长度
*/


/*
Floyed最短路径算法
*/
void FloyedShortestPath(AdjacencyMatrixGraph aMGraph){
	int currentShortestPath[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int currentShortestDistance[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int i, j, k;

	//1.初始化辅助数组
	for (i = 0; i<aMGraph.verticesNum; i++){
		for (j = 0; j<aMGraph.verticesNum; j++){
			if (aMGraph.arcs[i][j]<MAX_WEIGHT){	//如果顶点 i 到顶点 j 之间有弧
				currentShortestPath[i][j] = i;
			}
			else{
				currentShortestPath[i][j] = -1;
			}
			currentShortestDistance[i][j] = aMGraph.arcs[i][j];
		}
	}

	if (DEBUG){
		for (i = 0; i<aMGraph.verticesNum; i++){
			for (j = 0; j<aMGraph.verticesNum; j++){
				printf("%4d", currentShortestPath[i][j]);
			}
			putchar('\n');
		}

		for (i = 0; i<aMGraph.verticesNum; i++){
			for (j = 0; j<aMGraph.verticesNum; j++){
				printf("%d    ", currentShortestDistance[i][j]);
			}
			putchar('\n');
		}
		printf("aMGraph.verticesNum=%d\n", aMGraph.verticesNum);
	}

	//2.分别以每个顶点作为每对顶点之间的中间点，检测每对顶点之间的最短路径。
	for (k = 0; k<aMGraph.verticesNum; ++k){
		for (i = 0; i<aMGraph.verticesNum; ++i){
			for (j = 0; j<aMGraph.verticesNum; ++j){
				//如果顶点 i 到 j 的最短距离大于顶点 i 到 k 的最短距离与顶点 k 到 j 的最短距离之和
				if (currentShortestDistance[i][j]>currentShortestDistance[i][k] + currentShortestDistance[k][j]){
					currentShortestDistance[i][j] = currentShortestDistance[i][k] + currentShortestDistance[k][j];
					currentShortestPath[i][j] = currentShortestPath[k][j];
				}
			}
		}
	}

	for (i = 0; i<aMGraph.verticesNum; i++){
		for (j = 0; j<aMGraph.verticesNum; j++){
			printf("%4d", currentShortestPath[i][j]);
		}
		putchar('\n');
	}
	for (i = 0; i<aMGraph.verticesNum; i++){
		for (j = 0; j<aMGraph.verticesNum; j++){
			printf("%d    ", currentShortestDistance[i][j]);
		}
		putchar('\n');
	}
}

#endif