/**
* �ؼ�·���㷨��ʹ���ڽ�������������
* Author: FruitBasket
* Time: 2017/8/23
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef CriticalPath_h
#define CriticalPath_h

/*
�㷨˼�룺
1����ͼ�ж��������������
2���������������ÿ���¼������緢��ʱ��
3�����������������ÿ���¼�����ٷ���ʱ��
4�����ÿ��������翪ʼʱ�䡣
5�����ÿ�������ٿ�ʼʱ�䡣
6���ҳ����翪ʼʱ�����ٿ�ʼʱ����ͬ�Ļ�����ùؼ�·��
*/

#include "Basis.h"
#include "GraphStructure.h"
#include "TopologicalSort.h"

/*
��������
1.vertexEarliest[i]
1���¼�vi�����緢��ʱ��ΪvertexEarliest[i]
2�������¼�vi��ÿһ���������vi�ſɷ���������vertexEarliest[i]�Ǵ�Դ
��vi���·������

2.vertexLatest[i
1���¼�vi����ٷ���ʱ��ΪvertexLatest[i]
2��Ϊ�˲����ӹ��̣�vi����ٷ���ʱ�䲻�ó��������¼�vk����ٷ���ʱ
��-�<vi,vk>�ĳ���ʱ�䡣

3.activityEarliest[i]
1���ai=<vj,vk>�����翪ʼʱ��ΪactivityEarliest[i]
2��ֻ�лvj�����ˣ��ai���ܿ�ʼ�����ԣ��ai�����翪ʼʱ�����
�¼�vj�����緢��ʱ�䣺activityEarliest[i]=vertexEarliest[j]

4.activityLatest[i]
1���ai=<vj,vk>������ʼʱ��ΪactivityEarLatest[i]
2���ai�Ŀ�ʼʱ���豣֤�������¼�vk����ٷ���ʱ�䡣���ԣ��ai��
����ʼʱ�����ʱ��vk����ٷ���ʱ��-�ai�ĳ���ʱ�䣺
activityLatest[i]=vertexLatest[k]-�ai�ĳ���ʱ��
*/

/*
�ؼ�·���㷨
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

	//1.��ͼ�ж��������������
	if (topologicalSort(aLGraph, topo) == ERROR){	//�����������ʧ��
		return ERROR;
	}

	//2.�������������ÿ���¼������緢��ʱ��
	for (i = 0; i<verticesNum; ++i){
		vertexEarliest[i] = 0;
	}
	for (i = 0; i<verticesNum; ++i){
		vertexIndex = topo[i];
		pArcNode = aLGraph.vertices[vertexIndex].firstArc;
		while (pArcNode != NULL){
			//�������vertexIndex�ĺ�̶���pArcNode->adjacencyVertex����ÿ�ʼʱ��
			//С��vertexIndex�����緢��ʱ��+ָ��ú�̶���ıߵ�Ȩֵ
			if (vertexEarliest[pArcNode->adjacencyVertex]<
				vertexEarliest[vertexIndex] + pArcNode->weight){
				vertexEarliest[pArcNode->adjacencyVertex] =
					vertexEarliest[vertexIndex] + pArcNode->weight;
			}
			pArcNode = pArcNode->nextArc;
		}
	}

	//3.���������������ÿ���¼�����ٷ���ʱ��
	//�����ж����������ʱ���ʼ��Ϊ���������������һ������������ʱ��
	for (i = verticesNum - 1; i >= 0; --i){
		//�������������һ�������������ʱ��������緢��ʱ��
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

	//4.���ÿ��������翪ʼʱ�䡣
	currentArcsIndex = 0;    //��¼ָʾ����ߣ������еĵ�ǰ�
	//ע�⣺activityEarliest[i]�л���ߣ�������˳��Ϊ��������ߵ�˳��
	for (i = 0; i<verticesNum; i++){
		pArcNode = aLGraph.vertices[i].firstArc;
		while (pArcNode != NULL){
			activityEarliest[currentArcsIndex] = vertexEarliest[i];
			currentArcsIndex++;
			pArcNode = pArcNode->nextArc;
		}
	}

	//5.���ÿ�������ٿ�ʼʱ�䡣
	currentArcsIndex = 0;    //��¼ָʾ����ߣ������еĵ�ǰ�
	//ע�⣺activityLatest[i]�л���ߣ�������˳��Ϊ��������ߵ�˳��
	for (i = 0; i<verticesNum; i++){
		pArcNode = aLGraph.vertices[i].firstArc;
		while (pArcNode != NULL){
			activityLatest[currentArcsIndex] =
				vertexLatest[pArcNode->adjacencyVertex] - pArcNode->weight;
			currentArcsIndex++;
			pArcNode = pArcNode->nextArc;
		}
	}

	//6.�ҳ����翪ʼʱ�����ٿ�ʼʱ����ͬ�Ļ�����ùؼ�·��
	currentArcsIndex = 0;    //��¼ָʾ����ߣ������еĵ�ǰ�
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