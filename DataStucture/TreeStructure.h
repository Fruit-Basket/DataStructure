/**
* 二叉树的存储表示
* Author: FruitBasket
* Time: 2017/8/17
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef TreeStructure_h
#define TreeStructure_h

#include "Basis.h"

//二叉树的顺序储存表示
//这种表示方式最适用于完全二叉树
typedef TElemType SquenceBinaryTree[MAXSIZE];

//二叉树的二叉链表存储表示
typedef struct BinaryTreeNode{
	TElemType data;
	struct BinaryTreeNode *lChild, *rChild;
}BinaryTreeNode, *BinaryTree;

//线索二叉树的定义
//说明：
//        { 0  lChild域表示结点的左孩子
// lTag{
//		   { 1  lChild域表示结点的前驱
//
//		   { 0  rChild域表示结点的右孩子
// rTag{
//		   { 1  rChild域表示结点的后继
typedef struct ThreadedBinaryTreeNode{
	TElemType data;
	struct ThreadedBinaryTreeNode *lChild, *rChild;
	int lTag, rTag;
}ThreadedBinaryTreeNode, *ThreadedBinaryTree;

//树的二叉链表（孩子-兄弟）存储表示
typedef struct ChildSiblingNode{
	TElemType data;
	struct ChildSiblingNode *firstChild, *nextSibling;
}ChildSiblingNode,*ChildSiblingTree;

//Huffman树的存储表示
typedef struct{
	int weight;//结点的权值
	int parent, lChild, rChild;//结点的双亲、左孩子、右孩子
}HuffmanTreeNode,*HuffmanTree;

//Huffman编码表的存储表示
//使用说明：
//	1. HuffmanCode HC相当于char** HC；
//	2. 上面的HC是一个指针变量，它指向一个char型数据的指针变量
typedef char **HuffmanCode;    //动态分配数组存储Huffman编码表

#endif