#ifndef SequenceListForSorting_h
#define SequenceListForSorting_h

//��������������Ͷ���

#include "Basis.h"
#include ""


typedef struct{
	KeyType key;
	InformationType otherInformation;
}RedType;


typedef struct{
	RedType r[MAXSIZE+1];    //��ʹ������ĵ�0�ŵ�Ԫ������0�ŵ�Ԫ����������ĳ���ֵ
	int length;
}SequenceListForSorting;



#endif