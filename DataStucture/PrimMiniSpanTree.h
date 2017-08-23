/**
* Prim��С�������㷨��ʹ���ڽӾ�����ͨ������
* Author: FruitBasket
* Time: 2017/8/23
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef Prim_h
#define Prim_h

/*
�㷨˼�룺
���㷨�ֳ�Ϊ���ӵ㷨��
���ѡȡһ��������Ϊ��ʼ��С�������������Ӿ�����������̵�ʣ�ඥ��

�㷨�ص㣺
ʱ�临�Ӷ�ΪO(n^2)�������еı����޹�
*/

#include "Basis.h"
#include "AMGBaseMethods.h"

/*
��������
1.�����Ԫ�ر�ʾ��������δ�����������Ķ�����������̱�
2.δ�����������Ķ��������Ԫ��һһ��Ӧ
3.������±��ʾδ��������������ı��
*/
typedef struct{
	VertexType adjacencyVertex;//�ñ�����������adjacencyVertex��������
	ArcType lowCost;//�ñߵ�Ȩֵ
}CloseEdges[MAX_VERTEX_NUM];

/*
��������: ����������δ��������������lowCost��Ȩֵ����С��Ԫ���±�

amount : �����С
*/
int minLCIndex(CloseEdges closeEdges, int amount){
	int minLowCost = MAX_WEIGHT;
	int minIndex = -1;
	for (int i = 0; i<amount; i++){
		if (minLowCost>closeEdges[i].lowCost
			&&closeEdges[i].lowCost != 0){//lowCost!=0��ʾδ����������
			minLowCost = closeEdges[i].lowCost;
			minIndex = i;
		}
	}
	return minIndex;
}

/*
Prim��С�������㷨
*/
void primMiniSpanTree(AdjacencyMatrixGraph aMGraph, VertexType startVertex){
	int startIndex, minLowCostIndex;
	CloseEdges closeEdges;
	int i, j;

	//1.����ʼ���㲢��������
	startIndex = locateVertex(aMGraph, startVertex);
	closeEdges[startIndex].lowCost = 0;//lowCost==0��ʾδ�������������ý�㲢����������

	//2.��ʼ����������
	for (i = 0; i<aMGraph.verticesNum; i++){
		if (i != startIndex){
			closeEdges[i].adjacencyVertex = startIndex;
			closeEdges[i].lowCost = aMGraph.arcs[startIndex][i];    //��������ֻ��һ������startVertexIndex����ʣ�ඥ�����̱ߵ�Ȩֵ
		}
	}

	//3.������С������
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
		closeEdges[minLowCostIndex].lowCost = 0;	//��minLowCostIndex��Ӧ���㲢��������

		for (j = 0; j<aMGraph.verticesNum; j++){
			//�������j������minLowCostIndex��ȨֵС�ڵ���������Ȩֵ
			if (aMGraph.arcs[j][minLowCostIndex]<closeEdges[j].lowCost){
				closeEdges[j].adjacencyVertex = minLowCostIndex;
				closeEdges[j].lowCost = aMGraph.arcs[j][minLowCostIndex];
			}
		}
	}
}

#endif