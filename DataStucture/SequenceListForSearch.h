#ifndef SequenceList_h
#define SequenceList_h

//˳���Ķ���

#include "Basis.h"



//1.����Ԫ�صĶ���
typedef struct{
	KeyType key;
	InformationType otherInformation;
}LinearListElemType;


//2.˳���Ķ���
typedef struct{
	LinearListElemType    *r;    //�洢�ռ����ַ
	int length;
}SequenceListForSearch;



#endif