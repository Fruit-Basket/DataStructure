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
#define MAX_INT 2147483647//vs2013中使用4个字节来存放int变量

typedef int Status;//用于描述状态，结合上面的OK、ERROR、OVERFLOW使用

#define END_FLAG -1//作为结束输入标志，在二叉排序树创建时使用
#define ORDER 3//B-树的阶

const int DEBUG = TRUE;//设置程序是否为调试状态（在调试状态下会输出调试信息）

#endif