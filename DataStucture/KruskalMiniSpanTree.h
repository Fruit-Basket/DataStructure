/**
* Kruskal����³˹��������С�������㷨��ʹ���ڽӾ�����ͨ������
* Author: FruitBasket
* Time: 2017/8/23
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef KruskalMiniSpanTree_h
#define KruskalMiniSpanTree_h

/*
�㷨˼�룺
���㷨�ֳ�Ϊ���ӱ߷���
��ͼ�����б߰�Ȩֵ��С����˳�����У���Ȩֵ��С�ı�������ѡ���γɻ�·�ı���������С������
*/

#include "Basis.h"
#include "stdio.h"
#include "GraphStructure.h"

//��������
/*
1.����edges��Ԫ�ض���
��űߵ���Ϣ�������ߵ�����������Ϣ��Ȩֵ
*/
typedef struct{
	VertexType head;    //�ߵ������
	VertexType tail;	    //�ߵ��յ���
	ArcType lowCost;	//���ϵ�Ȩֵ
}Edge;

/*
2.����vertexSet
1��Ԫ��ֵ��ʶ����������������ͨ����
2������Ԫ�غͶ���һһ��Ӧ
3��Ԫ�ص��±�Ͷ����Ŷ�Ӧ
4��Ԫ��֮��ʾ�ö������ڵ���ͨ������ֵ��ͬ���ʾ����������ͬһ����ͨ�����С�
*/

/*
����������������Edge�е�Ԫ�ذ�Ȩֵ��С��������ʹ��ֱ�Ӳ�����������ĵ�0��ͬ��ʹ��
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
Kruskal����³˹��������С�������㷨
*/
void KruskalMiniSpanTree(AdjacencyMatrixGraph aMGraph){
	int i, j, k;
	int head, tail;
	int headVertexSet, tailVertexSet;
	int vertexSet[MAX_VERTEX_NUM];
	Edge edges[MAX_ARC_NUM];

	//1.��ʼ��edges��vertexSet���飬��0�ŵ�Ԫͬ��ʹ��
	k = 0;
	for (i = 0; i<aMGraph.verticesNum; i++){
		for (j = i; j<aMGraph.verticesNum; j++){
			if (aMGraph.arcs[i][j]<MAX_WEIGHT){		//�������i�Ͷ���j֮���б�����
				edges[k].head = i;
				edges[k].tail = j;
				edges[k].lowCost = aMGraph.arcs[i][j];
				k++;
			}
		}
	}
	sort(edges, aMGraph.arcsNum);	//������Edge�е�Ԫ�ذ�Ȩֵ��С��������

	for (i = 0; i<aMGraph.verticesNum; ++i){
		vertexSet[i] = i;		//��ʼʱ��ÿ������ֱ��ʶΪ�ڲ�ͬ����ͨ������
	}

	//2.��Ȩֵ��С�ı�������ѡ���γɻ�·�ı���������С������
	for (i = 0; i<aMGraph.arcsNum; i++){
		//ȡ�ñߵ������յ�ı��
		head = edges[i].head;
		tail = edges[i].tail;

		headVertexSet = vertexSet[head];
		tailVertexSet = vertexSet[tail];

		if (headVertexSet != tailVertexSet){	//�������head�Ͷ���tail����ͬһ����ͨ������
			printf("%c <-> %c\n", aMGraph.vertices[head], aMGraph.vertices[tail]);
			//������head��������ͨ����headVertexSet�ϲ�����ͨ����tailVertexSet��
			for (j = 0; j<aMGraph.verticesNum; j++){
				if (vertexSet[j] == headVertexSet){
					vertexSet[j] = tailVertexSet;
				}
			}
		}
	}
}

#endif