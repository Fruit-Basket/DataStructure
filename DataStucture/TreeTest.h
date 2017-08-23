/**
*  ˜µƒ≤‚ ‘∑Ω∑®
* Author: FruitBasket
* Time: 2017/8/17
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef TreeTest_h
#define TreeTest_h

#include "BinaryTreeBaseMethods.h"
#include "HuffmanTreeMethods.h"

/*
≤‚ ‘
*/
void treeTest1(){
	printf("treeTest1()\n");
	BinaryTree binaryTree;
	BinaryTree newBinarysTree;

	createBinaryTree(binaryTree);
	copy(binaryTree, newBinarysTree);

	inorderTraverse(newBinarysTree);
	printf("\n");
}

/*
≤‚ ‘
*/
void treeTest2(){
	printf("treeTest2()\n");
	BinaryTree binaryTree;
	createBinaryTree(binaryTree);
	printf("depth=%d\n", getDepth(binaryTree));
	printf("noteCount=%d\n", nodeCount(binaryTree));
}

/*
Huffman ˜≤‚ ‘
*/
void huffmanTreeTest(){
	if (DEBUG){
		printf("huffmanTreeTest()\n");
	}

	HuffmanTree huffmanTree;
	HuffmanCode huffmanCode;

	//≤‚ ‘ ˝æ›
	int weights[] = { 1, 2, 3, 4 };
	int amount = 4;

	//int weights[] = {1,2,3,4,5,6,7,8,9,10};
	//int amount = 10;

	//int weights[] = { 5,29, 7, 8, 14, 23, 3, 11 };
	//int amount = 8;

	createHuffmanTree(huffmanTree,amount, weights);
	showHuffmanTree(huffmanTree, amount);

	createHuffmanCode(huffmanTree, huffmanCode, amount);
	showHuffmanCode(huffmanCode, amount);
}


#endif