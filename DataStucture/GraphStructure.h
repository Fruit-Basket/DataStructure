/**
* ͼ�Ĵ洢��ʾ
* Author: FruitBasket
* Time: 2017/8/21
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef GraphStructure_h
#define GraphStructure_h

#define MAX_VERTEX_NUM 100//ͼ�ж������������ֵ
#define MAX_ARC_NUM 100//ͼ�б����������ֵ
#define MAX_WEIGHT  99999//Huffman���������Ȩֵ
//���Ȩֵ����ȡMAX_INT����Ϊ�������һ�����Ȩֵ��һ����ͨȨֵ���ʱ���ᷢ������

typedef char VertexType;//ͼ�ж������������
typedef int ArcType;//ͼ�бߵ�Ȩֵ���ͣ�Arc������

/*
ͼ���ڽӾ���洢��ʾ

���б�Ȩ�����ֵ���ܴ��ڻ����MAX_COST����MAX_COST��ʾ������󡱵�Ȩֵ
*/
typedef struct{
	VertexType vertices[MAX_VERTEX_NUM];//�����

	ArcType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//�ڽӾ����ñߵ�Ȩֵ��ɵĶ�ά���ʾ��

	int verticesNum, arcsNum;    //ͼ��ǰ�Ķ������������ܱ���
}AdjacencyMatrixGraph;

/*
ͼ���ڽӱ�洢��ʾ
*/
//1.�ߣ��������Ķ���
typedef struct ArcNode{
	int adjacencyVertex;	//�ñ���ָ��Ķ����λ��
	int weight;	//�ߵ�Ȩ��
	struct ArcNode *nextArc;	//ָ����һ���ߵ�ָ��
}ArcNode;
//2.����Ķ���
typedef struct VertexNode{
	VertexType data;		//������Ϣ
	ArcNode *firstArc;	//ָ���һ�������ö���ıߵ�ָ��
}VertexNode, AdjacencyList[MAX_VERTEX_NUM];
//3.�ڽӱ�Ķ���
typedef struct{
	AdjacencyList vertices;    //�ڽӱ�
	int verticesNum, arcsNum;
}AdjacencyListGraph;

#endif