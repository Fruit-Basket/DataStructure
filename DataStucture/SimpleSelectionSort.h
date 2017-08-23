#ifndef SimpleSelectionSort_h
#define SimpleSelectionSort_h

//��ѡ������
/*
�㷨˼�룺
       ʱ�临�Ӷȣ�O��n^2��
       ���ȶ���
	   �ƶ���¼�������٣���ÿһ��¼ռ�õĿռ�϶�ʱ���˷�����ֱ�Ӳ�������졣
*/

#include "Basis.h"
#include "SequenceListForSorting.h"



//��ѡ������
/*��ʹ��sequenceList.r[i]�ĵ�0�ŵ�Ԫ
*/
void simpleSelectionSort(SequenceListForSorting &sequenceList){
	int minElementIndex;
	RedType tempElement;
	int i,j;
	for(i=1;i<=sequenceList.length;i++){
		minElementIndex=i;
		for(j=i+1;j<=sequenceList.length;j++){
			if(sequenceList.r[minElementIndex].key>sequenceList.r[j].key){
				minElementIndex=j;
			}
		}
		if(minElementIndex!=i){
			tempElement=sequenceList.r[minElementIndex];
			sequenceList.r[minElementIndex]=sequenceList.r[i];
			sequenceList.r[i]=tempElement;
		}
	}
}



#endif