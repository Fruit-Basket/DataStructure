/**
* Kruskal（克鲁斯卡尔）最小生成树算法，使用邻接矩阵连通无向网
* Author: FruitBasket
* Time: 2017/8/23
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef KruskalMiniSpanTree_h
#define KruskalMiniSpanTree_h

/*
算法思想：
本算法又称为“加边法”
将图中所有边按权值从小到大顺序排列，从权值较小的边起依次选择不形成回路的边来生成最小生成树
*/

#include "Basis.h"
#include "stdio.h"
#include "GraphStructure.h"

//辅助数组
/*
1.数组edges的元素定义
存放边的信息，包括边的两个顶点信息和权值
*/
typedef struct{
	VertexType head;    //边的起点编号
	VertexType tail;	    //边的终点编号
	ArcType lowCost;	//边上的权值
}Edge;

/*
2.数组vertexSet
1）元素值标识各个顶点所属的连通分量
2）数组元素和顶点一一对应
3）元素的下标和顶点编号对应
4）元素之表示该顶点所在的连通分量，值相同则表示两个顶点在同一个连通分量中。
*/

/*
辅助方法：将数组Edge中的元素按权值从小到大排序，使用直接插入排序，数组的第0号同样使用
*/
void sort(Edge edges[MAX_ARC_NUM], int arcsNum){
	Edge temp;
	int i, j;
	for (i = 1; i<arcsNum; i++){
		if (edges[i - 1].lowCost>edges[i].lowCost){
			temp.head = edges[i].head;
			temp.lowCost = edges[i].lowCost;
			temp.tail = edges[i].tail;

			for (j = i; edges[j - 1].lowCost>temp.lowCost; --j){
				edges[j].head = edges[j - 1].head;
				edges[j].lowCost = edges[j - 1].lowCost;
				edges[j].tail = edges[j - 1].tail;
			}

			edges[j].head = temp.head;
			edges[j].lowCost = temp.lowCost;
			edges[j].tail = temp.tail;
		}
	}
}

/*
Kruskal（克鲁斯卡尔）最小生成树算法
*/
void KruskalMiniSpanTree(AdjacencyMatrixGraph aMGraph){
	int i, j, k;
	int head, tail;
	int headVertexSet, tailVertexSet;
	int vertexSet[MAX_VERTEX_NUM];
	Edge edges[MAX_ARC_NUM];

	//1.初始化edges和vertexSet数组，第0号单元同样使用
	k = 0;
	for (i = 0; i<aMGraph.verticesNum; i++){
		for (j = i; j<aMGraph.verticesNum; j++){
			if (aMGraph.arcs[i][j]<MAX_WEIGHT){		//如果顶点i和顶点j之间有边相连
				edges[k].head = i;
				edges[k].tail = j;
				edges[k].lowCost = aMGraph.arcs[i][j];
				k++;
			}
		}
	}
	sort(edges, aMGraph.arcsNum);	//将数组Edge中的元素按权值从小到大排序

	for (i = 0; i<aMGraph.verticesNum; ++i){
		vertexSet[i] = i;		//初始时将每个顶点分别标识为在不同的连通分量中
	}

	//2.从权值较小的边起依次选择不形成回路的边来生成最小生成树
	for (i = 0; i<aMGraph.arcsNum; i++){
		//取得边的起点和终点的编号
		head = edges[i].head;
		tail = edges[i].tail;

		headVertexSet = vertexSet[head];
		tailVertexSet = vertexSet[tail];

		if (headVertexSet != tailVertexSet){	//如果顶点head和顶点tail不在同一个连通分量中
			printf("%c <-> %c\n", aMGraph.vertices[head], aMGraph.vertices[tail]);
			//将顶点head所属的连通分量headVertexSet合并到连通分量tailVertexSet中
			for (j = 0; j<aMGraph.verticesNum; j++){
				if (vertexSet[j] == headVertexSet){
					vertexSet[j] = tailVertexSet;
				}
			}
		}
	}
}

#endif