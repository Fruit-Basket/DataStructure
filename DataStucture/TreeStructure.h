/**
* �������Ĵ洢��ʾ
* Author: FruitBasket
* Time: 2017/8/17
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef TreeStructure_h
#define TreeStructure_h

#include "Basis.h"

//��������˳�򴢴��ʾ
//���ֱ�ʾ��ʽ����������ȫ������
typedef TElemType SquenceBinaryTree[MAXSIZE];

//�������Ķ�������洢��ʾ
typedef struct BinaryTreeNode{
	TElemType data;
	struct BinaryTreeNode *lChild, *rChild;
}BinaryTreeNode, *BinaryTree;

//�����������Ķ���
//˵����
//        { 0  lChild���ʾ��������
// lTag{
//		   { 1  lChild���ʾ����ǰ��
//
//		   { 0  rChild���ʾ�����Һ���
// rTag{
//		   { 1  rChild���ʾ���ĺ��
typedef struct ThreadedBinaryTreeNode{
	TElemType data;
	struct ThreadedBinaryTreeNode *lChild, *rChild;
	int lTag, rTag;
}ThreadedBinaryTreeNode, *ThreadedBinaryTree;

//���Ķ�����������-�ֵܣ��洢��ʾ
typedef struct ChildSiblingNode{
	TElemType data;
	struct ChildSiblingNode *firstChild, *nextSibling;
}ChildSiblingNode,*ChildSiblingTree;

//Huffman���Ĵ洢��ʾ
typedef struct{
	int weight;//����Ȩֵ
	int parent, lChild, rChild;//����˫�ס����ӡ��Һ���
}HuffmanTreeNode,*HuffmanTree;

//Huffman�����Ĵ洢��ʾ
//ʹ��˵����
//	1. HuffmanCode HC�൱��char** HC��
//	2. �����HC��һ��ָ���������ָ��һ��char�����ݵ�ָ�����
typedef char **HuffmanCode;    //��̬��������洢Huffman�����

#endif