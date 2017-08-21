/**
* Huffman������ط���
* Author: FruitBasket
* Time: 2017/8/20
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef HuffmanTreeMethods_h
#define HuffmanTreeMethods_h

#include "TreeStructure.h"
#include "stdio.h"
#include "string.h"

/*
�����������ӵ�0��index��������ҵ�parent=0��Ȩֵ��С�����������±�

huffmanTree:
index:
min1:��1���±�
min2:��2���±�
*/
void select(HuffmanTree huffmanTree, int index, int &min1, int &min2){
	if (DEBUG){
		printf("select(HuffmanTree,int,int,int)\n");
		printf("search range: 0~%d\n", index);
	}

	if (huffmanTree&&index>=1){
		int minWeight;
		int i;

		for (i = 0, minWeight = MAX_HTN_WEIGHT; i <= index; ++i){
			if (minWeight > huffmanTree[i].weight
				&&huffmanTree[i].parent == 0){
				minWeight = huffmanTree[i].weight;
				min1 = i;
			}
		}

		for (i = 0, minWeight = MAX_HTN_WEIGHT; i <= index; ++i){
			if (minWeight > huffmanTree[i].weight
				&&huffmanTree[i].parent == 0
				&& i != min1){
				minWeight = huffmanTree[i].weight;
				min2 = i;
			}
		}
	}
	else{
		printf("select error!");
		return;
	}

	if (DEBUG){
		printf("min1=%d;min2=%d\n", min1, min2);
	}
}

/*
����Huffman��

huffmanTree:
nodesAmount:Huffman����Ҷ�ӽ������
weights[]:Ȩֵ��
*/
void createHuffmanTree(HuffmanTree &huffmanTree, int nodesAmount, int weights[]){
	if (nodesAmount <= 1){
		return;
	}
	/*
	Huffman�����ܽ����������㷽����
	��Ϊ
	1.Huffman���Ƕ�����������û�ж�Ϊ1�Ľ��
	2.�ܽ������amount=Ҷ�ӽ������+2�Ƚ������
	3.amount=�ܶ���+1
	4.�ܶ���=2*2�Ƚ������
	��amount=2*Ҷ�ӽ������-1
	*/
	int amount = 2 * nodesAmount - 1;//Huffman�����ܽ�������
	huffmanTree = new HuffmanTreeNode[amount];
	for (int i = 0; i < amount; i++){
		huffmanTree[i].weight = weights[i];
		huffmanTree[i].parent = 0;
		huffmanTree[i].lChild = 0;
		huffmanTree[i].rChild = 0;
	}

	int min1=-1, min2=-1;
	for (int i = nodesAmount; i < amount; ++i){
		select(huffmanTree, i - 1, min1, min2);
		if (min1 != -1 && min2!=- 1){
			huffmanTree[min1].parent = i;
			huffmanTree[min2].parent = i;

			huffmanTree[i].weight = huffmanTree[min1].weight + huffmanTree[min2].weight;
			huffmanTree[i].lChild = min1;
			huffmanTree[i].rChild = min2;
		}
		else{
			//ɸѡmin1��min2ʱ����
			printf("Error: min1=%d;min2=%d\n", min1, min2);
			return;
		}
	}
	
}

/*
���Huffman��

huffmanTree:
amount:Huffman����Ҷ�ӽ�����
*/
void showHuffmanTree(HuffmanTree huffmanTree, int amount){
	int total = 2 * amount - 1;//Huffman����������
	for (int i = 0; i < total; i++){
		printf("   %-3d    |   %-3d   |   %-3d   |  %-3d   |  %-3d\n ", i, huffmanTree[i].weight, huffmanTree[i].parent, huffmanTree[i].lChild, huffmanTree[i].rChild);
	}
	putchar('\n');
}

/*
����Huffman����Huffman����

huffmanTree:
huffmanCode:���ڴ��Huffman����
amount:Ҫ���б�����ַ�������Ҳ��Huffman����Ҷ�ӽ������
*/
void createHuffmanCode(HuffmanTree huffmanTree, HuffmanCode &huffmanCode, int amount){
	huffmanCode = new char*[amount];

	char *codes = new char[amount];//�����ַ����飬������ʱ����ַ���Huffman����
	codes[amount - 1] = '\0';//��Ϊ�ַ���Huffman���볤��ֵһ��С���ַ����������ʱ��볤��=�ַ�����-1���㹻

	int start;
	int child, parent;

	for (int i = 0; i < amount; ++i){
		start = amount - 1;
		child = i;
		parent = huffmanTree[i].parent;

		//���ѭ��������һ���ַ���Huffman����
		while (parent != 0){//���parent!=0,��child����˫��
			--start;
			if (child == huffmanTree[parent].lChild){
				codes[start] = '0';
			}
			else{
				codes[start] = '1';
			}
			child = parent;
			parent = huffmanTree[child].parent;
		}
		
		if (DEBUG){
			printf("codes[%d]=%s\n", start, &codes[start]);
		}

		//����ѭ��ʱ��startָ����Huffman����ĵ�1������
		huffmanCode[i] = new char[amount - start + 1];
		strcpy(huffmanCode[i], &codes[start]);
	}
	
	delete codes;
}

/*
huffmanCode:Huffman����
amount:������ַ�������Ҳ��Huffman����Ҷ�ӽ������
*/
void showHuffmanCode(HuffmanCode huffmanCode, int amount){
	for (int i = 0; i < amount; i++){
		printf("the No.%d  huffman code is  %s\n", i, huffmanCode[i]);
	}
}

#endif