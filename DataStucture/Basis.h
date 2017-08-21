/**
* 基本定义
* Author: FruitBasket
* Time: 2017/8/17
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef Basis_h
#define Basis_h

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define NULL 0
#define MAXSIZE 100
#define MAX_INT 2147483647		//vs2013中使用4个字节来存放int变量
#define END_FLAG -1    //作为结束输入标志，在二叉排序树创建时使用
#define ORDER 3   //B-树的阶

#define MAX_VERTEX_AMOUNT 100	//图中顶点数量的最大值
#define MAX_ARC_AMOUNT 100	//图中边数量的最大值
#define MAX_WEIGHT  99999    //图中边权的最大值或Huffman树结点的最大权值
//最大权值不能取MAX_INT，因为如果出现一个最大权值和一个普通权值相加时，会发生上溢。

typedef int Status;//用于描述状态，结合上面的OK、ERROR、OVERFLOW使用
typedef char SElemType;//栈中的数据类型
typedef char TElemType;//数结点的数据类型
typedef char VertexType;//图中顶点的数据类型
typedef int ArcType;//图中边的权值类型（Arc：弧）

typedef int KeyType;//顺序表数据元素中关键字的类型
typedef int InformationType;//顺序表数据元素中的信息类型

const int DEBUG = TRUE;

#endif