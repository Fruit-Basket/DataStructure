/**
* 关键路径算法（使用邻接链表有向网）
* Author: FruitBasket
* Time: 2017/8/23
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef CriticalPath_h
#define CriticalPath_h

/*
算法思想：
1）对图中顶点进行拓扑排序
2）按拓扑序列求出每个事件的最早发生时间
3）按逆拓扑序列求出每个事件的最迟发生时间
4）求出每个活动的最早开始时间。
5）求出每个活动的最迟开始时间。
6）找出最早开始时间和最迟开始时间相同的活动，即得关键路径
*/

#include "Basis.h"
#include "GraphStructure.h"
#include "TopologicalSort.h"

/*
辅助数组
1.vertexEarliest[i]
1）事件vi的最早发生时间为vertexEarliest[i]
2）进入事件vi的每一活动都结束，vi才可发生，所以vertexEarliest[i]是从源
到vi的最长路径长度

2.vertexLatest[i
1）事件vi的最迟发生时间为vertexLatest[i]
2）为了不拖延工程，vi的最迟发生时间不得迟于其后继事件vk的最迟发生时
间-活动<vi,vk>的持续时间。

3.activityEarliest[i]
1）活动ai=<vj,vk>的最早开始时间为activityEarliest[i]
2）只有活动vj发生了，活动ai才能开始。所以，活动ai的最早开始时间等于
事件vj的最早发生时间：activityEarliest[i]=vertexEarliest[j]

4.activityLatest[i]
1）活动ai=<vj,vk>的最晚开始时间为activityEarLatest[i]
2）活动ai的开始时间需保证不延误事件vk的最迟发生时间。所以，活动ai的
最晚开始时间等于时间vk的最迟发生时间-活动ai的持续时间：
activityLatest[i]=vertexLatest[k]-活动ai的持续时间
*/

/*
关键路径算法
*/
Status criticalPath(AdjacencyListGraph aLGraph){
	int topo[MAX_VERTEX_NUM] = { 0 };
	int vertexEarliest[MAX_VERTEX_NUM] = { 0 };
	int vertexLatest[MAX_VERTEX_NUM] = { 0 };
	int activityEarliest[MAX_ARC_NUM] = { 0 };
	int activityLatest[MAX_ARC_NUM] = { 0 };
	int verticesNum = aLGraph.verticesNum;
	int vertexIndex;
	ArcNode *pArcNode;
	int currentArcsIndex;
	int i;

	//1.对图中顶点进行拓扑排序
	if (topologicalSort(aLGraph, topo) == ERROR){	//如果拓扑排序失败
		return ERROR;
	}

	//2.按拓扑序列求出每个事件的最早发生时间
	for (i = 0; i<verticesNum; ++i){
		vertexEarliest[i] = 0;
	}
	for (i = 0; i<verticesNum; ++i){
		vertexIndex = topo[i];
		pArcNode = aLGraph.vertices[vertexIndex].firstArc;
		while (pArcNode != NULL){
			//如果顶点vertexIndex的后继顶点pArcNode->adjacencyVertex的最好开始时间
			//小于vertexIndex的最早发生时间+指向该后继顶点的边的权值
			if (vertexEarliest[pArcNode->adjacencyVertex]<
				vertexEarliest[vertexIndex] + pArcNode->weight){
				vertexEarliest[pArcNode->adjacencyVertex] =
					vertexEarliest[vertexIndex] + pArcNode->weight;
			}
			pArcNode = pArcNode->nextArc;
		}
	}

	//3.按逆拓扑序列求出每个事件的最迟发生时间
	//将所有顶点的最晚发生时间初始化为，拓扑序列中最后一个顶点最晚发生时间
	for (i = verticesNum - 1; i >= 0; --i){
		//拓扑序列中最后一个顶点的最晚发生时间等于最早发生时间
		vertexLatest[i] = vertexEarliest[verticesNum - 1];
	}
	for (i = verticesNum - 1; i >= 0; --i){
		vertexIndex = topo[i];
		pArcNode = aLGraph.vertices[vertexIndex].firstArc;
		while (pArcNode != NULL){
			if (vertexLatest[vertexIndex] >
				vertexLatest[pArcNode->adjacencyVertex] - pArcNode->weight){
				vertexLatest[vertexIndex] =
					vertexLatest[pArcNode->adjacencyVertex] - pArcNode->weight;
			}
			pArcNode = pArcNode->nextArc;
		}
	}

	//4.求出每个活动的最早开始时间。
	currentArcsIndex = 0;    //记录指示活动（边）数组中的当前活动
	//注意：activityEarliest[i]中活动（边）的排列顺序，为这里遍历边的顺序
	for (i = 0; i<verticesNum; i++){
		pArcNode = aLGraph.vertices[i].firstArc;
		while (pArcNode != NULL){
			activityEarliest[currentArcsIndex] = vertexEarliest[i];
			currentArcsIndex++;
			pArcNode = pArcNode->nextArc;
		}
	}

	//5.求出每个活动的最迟开始时间。
	currentArcsIndex = 0;    //记录指示活动（边）数组中的当前活动
	//注意：activityLatest[i]中活动（边）的排列顺序，为这里遍历边的顺序
	for (i = 0; i<verticesNum; i++){
		pArcNode = aLGraph.vertices[i].firstArc;
		while (pArcNode != NULL){
			activityLatest[currentArcsIndex] =
				vertexLatest[pArcNode->adjacencyVertex] - pArcNode->weight;
			currentArcsIndex++;
			pArcNode = pArcNode->nextArc;
		}
	}

	//6.找出最早开始时间和最迟开始时间相同的活动，即得关键路径
	currentArcsIndex = 0;    //记录指示活动（边）数组中的当前活动
	for (i = 0; i<verticesNum; i++){
		pArcNode = aLGraph.vertices[i].firstArc;
		while (pArcNode != NULL){
			if (activityEarliest[currentArcsIndex] ==
				activityLatest[currentArcsIndex]){
				printf("%c --> %c (%d)\n",
					aLGraph.vertices[i].data,
					aLGraph.vertices[pArcNode->adjacencyVertex].data,
					pArcNode->weight);
			}
			currentArcsIndex++;
			pArcNode = pArcNode->nextArc;
		}
	}
}

#endif