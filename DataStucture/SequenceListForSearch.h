#ifndef SequenceList_h
#define SequenceList_h

//顺序表的定义

#include "Basis.h"

typedef int KeyType;//顺序表数据元素中关键字的类型
typedef int InformationType;//顺序表数据元素中的信息类型

//1.表中元素的定义
typedef struct{
	KeyType key;
	InformationType otherInformation;
}LinearListElemType;


//2.顺序表的定义
typedef struct{
	LinearListElemType    *r;    //存储空间基地址
	int length;
}SequenceListForSearch;



#endif