/**
* 图的存储表示
* Author: FruitBasket
* Time: 2017/8/21
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef GraphStructure_h
#define GraphStructure_h

#define MAX_VERTEX_NUM 100//图中顶点数量的最大值
#define MAX_ARC_NUM 100//图中边数量的最大值
#define MAX_WEIGHT  99999//Huffman树结点的最大权值
//最大权值不能取MAX_INT，因为如果出现一个最大权值和一个普通权值相加时，会发生上溢

typedef char VertexType;//图中顶点的数据类型
typedef int ArcType;//图中边的权值类型（Arc：弧）

/*
图的邻接矩阵存储表示

其中边权的最大值不能大于或等于MAX_COST，即MAX_COST表示“无穷大”的权值
*/
typedef struct{
	VertexType vertices[MAX_VERTEX_NUM];//顶点表

	ArcType arcs[MAX_VERTEX_NUM][MAX_VERTEX_NUM];//邻接矩阵（用边的权值组成的二维表表示）

	int verticesNum, arcsNum;    //图当前的顶点总数数和总边数
}AdjacencyMatrixGraph;

/*
图的邻接表存储表示
*/
//1.边（弧）结点的定义
typedef struct ArcNode{
	int adjacencyVertex;	//该边所指向的顶点的位置
	int weight;	//边的权重
	struct ArcNode *nextArc;	//指向下一条边的指针
}ArcNode;
//2.顶点的定义
typedef struct VertexNode{
	VertexType data;		//顶点信息
	ArcNode *firstArc;	//指向第一条依附该顶点的边的指针
}VertexNode, AdjacencyList[MAX_VERTEX_NUM];
//3.邻接表的定义
typedef struct{
	AdjacencyList vertices;    //邻接表
	int verticesNum, arcsNum;
}AdjacencyListGraph;

#endif