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
#define MAXSIZE 100
#define MAX_INT 2147483647		//vs2013中使用4个字节来存放int变量
#define END_FLAG -1    //作为结束输入标志，在二叉排序树创建时使用
#define ORDER 3   //B-树的阶

typedef int Status;//用于描述状态，结合上面的OK、ERROR、OVERFLOW使用

typedef int KeyType;//顺序表数据元素中关键字的类型
typedef int InformationType;//顺序表数据元素中的信息类型

const int DEBUG = TRUE;

#endif