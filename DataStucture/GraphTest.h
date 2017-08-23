/**
* Í¼µÄ²âÊÔ·½·¨
* Author: FruitBasket
* Time: 2017/8/22
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef GraphTest_h
#define GraphTest_h

#include "GraphStructure.h"
#include "AMGBaseMethods.h"

void GraphBaseTest(){
	AdjacencyMatrixGraph graph;

	int verticesNum = 4;
	int arcsNum = 3;
	VertexType vertices[] = { 'A', 'B', 'C', 'D' };
	VertexType arcs1[] = {'A','B','A'};
	VertexType arcs2[] = {'B','C','D'};
	int weights[] = { 2, 3, 4 };


	createNondirectionalGraph(
		graph,
		verticesNum,
		arcsNum,
		vertices,
		arcs1,
		arcs2,
		weights);

	showGraph(graph);
}

#endif