/**
* Dijdstra���·���㷨��ʹ���ڽӾ���������������ͨ����ͨ��
* Author: FruitBasket
* Time: 2017/8/21
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef DijkstraShortestPath_h
#define DijkstraShortestPath_h

/*
�㷨˼�룺
1.�ҳ�Դ��v0��������������̾����vi
2.���ҵ���Դ��v0��vi�����·��
3.��Դ��v0��ʣ�������ĵ�ǰ���·����Դ��v0ͨ��vi��ʣ��������
��ǰ���·�����Ƚϣ����϶̵���Ϊv0��ʣ�������ĵ�ǰ���·��
4.......
*/

#include "Basis.h"
#include "stdio.h"
#include "GraphStructure.h"

//��������
//1.����S[i]
/*
��¼��Դ��v0���յ�vi�Ƿ��ѱ�ȷ�����·�����ȣ�ture��ʾȷ����false
��ʾ��δȷ��
*/

//2.����currentShortestPath[i]
/*
1����¼��ԭ��v0���յ�vi�ĵ�ǰ���·����vi��ֱ��ǰ��������
2�����ֵΪ�������v0��vi�л�����currentShortestPath[i]Ϊv0������
Ϊ-1
*/

//3.����currentShortestDistance[i]
/*
1����¼��Դ��v0���յ�vi�ĵ�ǰ���·������
2�����ֵΪ�������v0��vi�л�����currentShortestDistance[i]Ϊ���ϵ�
Ȩֵ������Ϊ-1
*/

/*
Dijdstra���·���㷨

startVertexIndex��Դ��ı��
*/
void dijkstraShortestPath(AdjacencyMatrixGraph aMGraph, int startVertexIndex){
	bool s[MAX_VERTEX_NUM] = { false };
	int currentShortestPath[MAX_VERTEX_NUM];
	int currentShortestDistance[MAX_VERTEX_NUM];
	int i, j, k;
	int endVertexIndex, minDistance;

	//1.��ʼ��
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
	s[startVertexIndex] = true;   //���ҵ�Դ�㵽����startVertex�����·��
	currentShortestDistance[startVertexIndex] = 0;	//Դ�㵽����startVertex�����·��Ϊ0

	//2.���㷨
	for (i = 1; i<aMGraph.verticesNum; ++i){	//ѭ��aMGraph.verticesNum-1��
		printf("No.%d ��ѭ��\n", i);
		//2.1�ҳ���Դ�㵽ʣ�ඥ��ĵ�ǰ���·���ĳ��ȺͶ�Ӧ�յ�
		endVertexIndex = -1;	//��¼�յ�
		minDistance = MAX_WEIGHT;    //��¼��Դ�㵽�յ�endVertexIndex��ǰ���·������
		for (j = 0; j<aMGraph.verticesNum; ++j){
			if (s[j] == false && currentShortestDistance[j]<minDistance){
				endVertexIndex = j;
				minDistance = currentShortestDistance[j];
			}
		}
		s[endVertexIndex] = true;		//���ҵ�Դ�㵽����endVertexIndex�����·��

		//2.2�Զ���endVertexIndexΪ��ת�����´�Դ�������ʣ�����ж�������·������
		for (j = 0; j<aMGraph.verticesNum; ++j){
			//���δȷ���ҵ���Դ�㵽����j�����·����
			//��Դ�㵽����j�ĵ�ǰ���·�����ȴ���Դ�㵽����endVertexIndex·������+����endVertexIndex������j��·������
			if (s[j] == false &&
				currentShortestDistance[j]>currentShortestDistance[endVertexIndex] + aMGraph.arcs[endVertexIndex][j])
			{
				currentShortestDistance[j] = minDistance + aMGraph.arcs[endVertexIndex][j];
				currentShortestPath[j] = endVertexIndex;    //endVertexIndex��Ϊ��Դ�㵽����j·���У�����j��ǰ��
			}
		}
	}

	printf("�㷨�����\n");
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