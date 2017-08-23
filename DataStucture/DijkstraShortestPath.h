/**
* Dijdstra最短路径算法，使用邻接矩阵有向网（可连通或不连通）
* Author: FruitBasket
* Time: 2017/8/21
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef DijkstraShortestPath_h
#define DijkstraShortestPath_h

/*
算法思想：
1.找出源点v0到其余各顶点的最短距离点vi
2.已找到从源点v0到vi的最短路径
3.将源点v0到剩余各顶点的当前最短路径与源点v0通过vi到剩余个顶点的
当前最短路径作比较，将较短的作为v0到剩余各顶点的当前最短路径
4.......
*/

#include "Basis.h"
#include "stdio.h"
#include "GraphStructure.h"

//辅助数组
//1.数组S[i]
/*
记录从源点v0到终点vi是否已被确定最短路径长度，ture表示确定，false
表示尚未确定
*/

//2.数组currentShortestPath[i]
/*
1）记录从原点v0到终点vi的当前最短路径上vi的直接前驱顶点编号
2）其初值为：如果从v0到vi有弧，则currentShortestPath[i]为v0；否则
为-1
*/

//3.数组currentShortestDistance[i]
/*
1）记录从源点v0到终点vi的当前最短路径长度
2）其初值为：如果从v0到vi有弧，则currentShortestDistance[i]为弧上的
权值；否则为-1
*/

/*
Dijdstra最短路径算法

startVertexIndex：源点的编号
*/
void dijkstraShortestPath(AdjacencyMatrixGraph aMGraph, int startVertexIndex){
	bool s[MAX_VERTEX_NUM] = { false };
	int currentShortestPath[MAX_VERTEX_NUM];
	int currentShortestDistance[MAX_VERTEX_NUM];
	int i, j, k;
	int endVertexIndex, minDistance;

	//1.初始化
	for (i = 0; i<aMGraph.verticesNum; ++i){
		s[i] = false;
		if (aMGraph.arcs[startVertexIndex][i]<MAX_WEIGHT){
			currentShortestPath[i] = startVertexIndex;
		}
		else{
			currentShortestPath[i] = -1;
		}
		currentShortestDistance[i] = aMGraph.arcs[startVertexIndex][i];
	}
	s[startVertexIndex] = true;   //已找到源点到顶点startVertex的最短路径
	currentShortestDistance[startVertexIndex] = 0;	//源点到顶点startVertex的最短路径为0

	//2.主算法
	for (i = 1; i<aMGraph.verticesNum; ++i){	//循环aMGraph.verticesNum-1次
		printf("No.%d 回循环\n", i);
		//2.1找出从源点到剩余顶点的当前最短路径的长度和对应终点
		endVertexIndex = -1;	//记录终点
		minDistance = MAX_WEIGHT;    //记录从源点到终点endVertexIndex当前最短路径长度
		for (j = 0; j<aMGraph.verticesNum; ++j){
			if (s[j] == false && currentShortestDistance[j]<minDistance){
				endVertexIndex = j;
				minDistance = currentShortestDistance[j];
			}
		}
		s[endVertexIndex] = true;		//已找到源点到顶点endVertexIndex的最短路径

		//2.2以顶点endVertexIndex为中转，更新从源点出发到剩余所有顶点的最短路径长度
		for (j = 0; j<aMGraph.verticesNum; ++j){
			//如果未确定找到从源点到顶点j的最短路径，
			//且源点到顶点j的当前最短路径长度大于源点到顶点endVertexIndex路径长度+顶点endVertexIndex到顶点j的路径长度
			if (s[j] == false &&
				currentShortestDistance[j]>currentShortestDistance[endVertexIndex] + aMGraph.arcs[endVertexIndex][j])
			{
				currentShortestDistance[j] = minDistance + aMGraph.arcs[endVertexIndex][j];
				currentShortestPath[j] = endVertexIndex;    //endVertexIndex作为从源点到顶点j路径中，顶点j的前驱
			}
		}
	}

	printf("算法结果：\n");
	printf("the s:\n");
	for (i = 0; i<aMGraph.verticesNum; ++i){
		if (s[i] == true){
			printf("s[%d]=true\n", i);
		}
		else{
			printf("s[%d]=false\n", i);
		}
	}
	putchar('\n');
	printf("the currentShortestPath:\n");
	for (i = 0; i<aMGraph.verticesNum; ++i){
		printf("currentShortestPath[%d]=%d\n", i, currentShortestPath[i]);
	}
	putchar('\n');
	printf("the currentShortestDistance :\n");
	for (i = 0; i<aMGraph.verticesNum; ++i){
		printf("currentShortestDistance[%d]=%d\n", i, currentShortestDistance[i]);
	}
}

#endif