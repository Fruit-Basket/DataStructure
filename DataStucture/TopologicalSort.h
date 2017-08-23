/**
* 拓扑排序（使用邻接链表有向无权图）
* Author: FruitBasket
* Time: 2017/8/21
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef Topological_h
#define Topological_h

/*
算法思想：
不断选择无前驱的顶点输出。
*/

#include "Basis.h"
#include "GraphStructure.h"
#include "stdio.h"

/*
本算法的辅助数据结构：
1.一维数组inDegree[i]
存放顶点入度，没有前驱的顶点就是入度为0的顶点。

2.栈stack
暂存所有入度为0顶点的编号，这样可以避免重复扫描数组inDegree
检测入度为0的顶点，提高算法的效率。

3.一维数组topo[i]
记录拓扑序列的顶点编号
*/

/*
辅助方法
1）方法结束后，topo[]存放图中顶点的入度
2）topo[]元素编号和图中顶点编号一一对应
*/
void findInDegree(AdjacencyListGraph aLGraph, int inDegree[]){
	int i;
	ArcNode *p;

	for (i = 0; i<aLGraph.verticesNum; i++){
		inDegree[i] = 0;
	}

	for (i = 0; i<aLGraph.verticesNum; i++){
		p = aLGraph.vertices[i].firstArc;
		while (p != NULL){
			inDegree[p->adjacencyVertex]++;
			p = p->nextArc;
		}
	}
}


/*
拓扑排序
*/
Status topologicalSort(AdjacencyListGraph aLGraph, int topo[]){
	int inDegree[MAX_VERTEX_NUM];
	int stack[MAX_VERTEX_NUM], top = -1;
	int amount;	//记录拓扑序列中顶点数量
	int popVertexIndex;
	ArcNode *pArcNode;
	int i;

	//初始化
	findInDegree(aLGraph, inDegree);
	amount = 0;
	for (i = 0; i<aLGraph.verticesNum; ++i){	//将入度为0的顶点的编号入栈
		if (inDegree[i] == 0){
			++top;
			stack[top] = i;
		}
	}

	//2.主算法
	while (top>-1){    //如果栈不空
		popVertexIndex = stack[top];	//顶点编号出栈
		--top;
		topo[amount] = popVertexIndex;		//出栈的顶点编号进入拓扑队列
		++amount;   //拓扑序列中顶点数量加1
		pArcNode = aLGraph.vertices[popVertexIndex].firstArc;
		while (pArcNode != NULL){		//如果还有从顶点popVertexIndex发出的边
			inDegree[pArcNode->adjacencyVertex]--;    //被边pArcNode指向的顶点的入度减1
			if (inDegree[pArcNode->adjacencyVertex] == 0){		//如果结点入读变为0，则入栈
				top++;
				stack[top] = pArcNode->adjacencyVertex;
			}
			pArcNode = pArcNode->nextArc;
		}
	}

	//3.判断图中是否存在环
	if (amount<aLGraph.verticesNum){
		return ERROR;
	}
	else{
		return OK;
	}
}

#endif