/**
* Huffman树的相关方法
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
辅助函数：从第0到index个结点中找到parent=0且权值最小的两个结点的下标

huffmanTree:
index:
min1:第1个下标
min2:第2个下标
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
创建Huffman树

huffmanTree:
nodesAmount:Huffman树的叶子结点数量
weights[]:权值表
*/
void createHuffmanTree(HuffmanTree &huffmanTree, int nodesAmount, int weights[]){
	if (nodesAmount <= 1){
		return;
	}
	/*
	Huffman树中总结点的数量计算方法：
	因为
	1.Huffman树是二叉树，而且没有度为1的结点
	2.总结点数量amount=叶子结点数量+2度结点数量
	3.amount=总度数+1
	4.总度数=2*2度结点数量
	故amount=2*叶子结点数量-1
	*/
	int amount = 2 * nodesAmount - 1;//Huffman树中总结点的数量
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
			//筛选min1和min2时出错
			printf("Error: min1=%d;min2=%d\n", min1, min2);
			return;
		}
	}
	
}

/*
输出Huffman树

huffmanTree:
amount:Huffman树的叶子结点个数
*/
void showHuffmanTree(HuffmanTree huffmanTree, int amount){
	int total = 2 * amount - 1;//Huffman树结点的总数
	for (int i = 0; i < total; i++){
		printf("   %-3d    |   %-3d   |   %-3d   |  %-3d   |  %-3d\n ", i, huffmanTree[i].weight, huffmanTree[i].parent, huffmanTree[i].lChild, huffmanTree[i].rChild);
	}
	putchar('\n');
}

/*
根据Huffman树求Huffman编码

huffmanTree:
huffmanCode:用于存放Huffman编码
amount:要进行编码的字符数量，也是Huffman树的叶子结点数量
*/
void createHuffmanCode(HuffmanTree huffmanTree, HuffmanCode &huffmanCode, int amount){
	huffmanCode = new char*[amount];

	char *codes = new char[amount];//创建字符数组，用于临时存放字符的Huffman编码
	codes[amount - 1] = '\0';//因为字符的Huffman编码长度值一定小于字符的数量，故编码长度=字符数量-1就足够

	int start;
	int child, parent;

	for (int i = 0; i < amount; ++i){
		start = amount - 1;
		child = i;
		parent = huffmanTree[i].parent;

		//这个循环生成了一个字符的Huffman编码
		while (parent != 0){//如果parent!=0,则child存在双亲
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

		//结束循环时，start指向了Huffman编码的第1个编码
		huffmanCode[i] = new char[amount - start + 1];
		strcpy(huffmanCode[i], &codes[start]);
	}
	
	delete codes;
}

/*
huffmanCode:Huffman编码
amount:编码的字符数量，也是Huffman树的叶子结点数量
*/
void showHuffmanCode(HuffmanCode huffmanCode, int amount){
	for (int i = 0; i < amount; i++){
		printf("the No.%d  huffman code is  %s\n", i, huffmanCode[i]);
	}
}

#endif