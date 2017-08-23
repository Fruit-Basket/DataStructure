#ifndef StraightInsertionSort_h
#define StraightInsertionSort_h

//ֱ�Ӳ�������
/*
�㷨˼�룺
       ��Ϊ�����Ԫ�ز��뵽�������������
�ص㣺
       ʱ�临�Ӷȣ�O��n^2��
       �ȶ���
	   ���ʺ��ڳ�ʼ��¼�����������򣩵����
*/

#include "Basis.h"
#include "SequenceListForSorting.h"



//ֱ�Ӳ�������
/*��ʹ������ĵ�0�ŵ�Ԫ
*/
void straightInsertionSort(SequenceListForSorting &sequenceList){
	int i,j;
	for(i=2;i<=sequenceList.length;i++){	//��0�ŵ�Ԫ����������ĳ���ֵ
		//�����һ����С��ǰһ����
		if(sequenceList.r[i].key<sequenceList.r[i-1].key){
			sequenceList.r[0]=sequenceList.r[i];
			sequenceList.r[i]=sequenceList.r[i-1];
			for(j=i-2 ; sequenceList.r[0].key<sequenceList.r[j].key ; --j){
				sequenceList.r[j+1]=sequenceList.r[j];
			}
			sequenceList.r[j+1]=sequenceList.r[0];
		}
	}
}



#endif