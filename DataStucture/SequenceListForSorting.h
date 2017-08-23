#ifndef SequenceListForSorting_h
#define SequenceListForSorting_h

//待排序的数据类型定义

#include "Basis.h"
#include ""


typedef struct{
	KeyType key;
	InformationType otherInformation;
}RedType;


typedef struct{
	RedType r[MAXSIZE+1];    //不使用数组的第0号单元，即第0号单元不算入数组的长度值
	int length;
}SequenceListForSorting;



#endif