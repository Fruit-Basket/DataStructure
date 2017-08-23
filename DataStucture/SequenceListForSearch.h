#ifndef SequenceList_h
#define SequenceList_h

//顺序表的定义

#include "Basis.h"



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