/**
* Floyed���·���㷨����ͼ��ÿ�Զ��������·����ʹ���ڽӾ�����������
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
�㷨˼�룺
�ֱ���ÿ��������Ϊÿ�Զ���֮����м�㣬���ÿ�Զ���֮������·����
*/

/*
��������
1.currentShortestPath[i][j]
Ԫ��ֵ��ʾ�Ӷ��� i �� j �����·���϶��� j ��ǰһ����������

2.currentShortestDistance[i][j]
Ԫ��ֵ��ʾ���� i �� j ֮������·������
*/


/*
Floyed���·���㷨
*/
void FloyedShortestPath(AdjacencyMatrixGraph aMGraph){
	int currentShortestPath[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int currentShortestDistance[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
	int i, j, k;

	//1.��ʼ����������
	for (i = 0; i<aMGraph.verticesNum; i++){
		for (j = 0; j<aMGraph.verticesNum; j++){
			if (aMGraph.arcs[i][j]<MAX_WEIGHT){	//������� i ������ j ֮���л�
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

	//2.�ֱ���ÿ��������Ϊÿ�Զ���֮����м�㣬���ÿ�Զ���֮������·����
	for (k = 0; k<aMGraph.verticesNum; ++k){
		for (i = 0; i<aMGraph.verticesNum; ++i){
			for (j = 0; j<aMGraph.verticesNum; ++j){
				//������� i �� j ����̾�����ڶ��� i �� k ����̾����붥�� k �� j ����̾���֮��
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