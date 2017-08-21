/**
* ͼ�Ĵ洢��ʾ
* Author: FruitBasket
* Time: 2017/8/21
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef GraphStructure_h
#define GraphStructure_h

#define MAX_VERTEX_AMOUNT 100//ͼ�ж������������ֵ
#define MAX_ARC_AMOUNT 100//ͼ�б����������ֵ
#define MAX_WEIGHT  99999//Huffman���������Ȩֵ
//���Ȩֵ����ȡMAX_INT����Ϊ�������һ�����Ȩֵ��һ����ͨȨֵ���ʱ���ᷢ������

typedef char VertexType;//ͼ�ж������������
typedef int ArcType;//ͼ�бߵ�Ȩֵ���ͣ�Arc������

//ͼ���ڽӾ���洢��ʾ
//���б�Ȩ�����ֵ���ܴ��ڻ����MAX_COST����MAX_COST��ʾ������󡱵�Ȩֵ
typedef struct{
	VertexType vertices[MAX_VERTEX_AMOUNT];//�����

	ArcType arcs[MAX_VERTEX_AMOUNT][MAX_VERTEX_AMOUNT];//�ڽӾ����ñߵ�Ȩֵ��ɵĶ�ά���ʾ��

	int verticesNum, arcsNum;    //ͼ��ǰ�Ķ������������ܱ���
}AdjacencyMatrixGraph;

#endif