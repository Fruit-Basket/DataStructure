#ifndef BinaryInsertionSort_h
#define BinaryInsertionSort_h

//�۰��������
/*
�㷨˼�룺
       ��ֱ�Ӳ���Ļ�����ʹ���۰���Ҳ��Ҳ���λ
�ص㣺
       ʱ�临�Ӷȣ�O��n^2���������ֱ�Ӳ�������ƽ������£��������˲��Ҳ���λ��ʱ��
       �ȶ���
*/

#include "Basis.h"
#include "StraightInsertionSort.h"



//�۰��������
/*��ʹ������ĵ�0�ŵ�Ԫ
*/
void binaryInsertionSort(SequenceListForSorting &sequenceList){
	int low,high,middle;
	int i,j;
	for(i=2;i<=sequenceList.length;i++){
		sequenceList.r[0]=sequenceList.r[i];
		//����
		low=0;
		high=i-1;
		while(low<=high){
			middle=(low+high)/2;
			if(sequenceList.r[0].key>sequenceList.r[middle].key){
				low=middle+1;
			}
			else{
				high=middle-1;
			}
		}
		//�ƶ�
		for(j=i-1;j>=high+1;--j){
			sequenceList.r[j+1]=sequenceList.r[j];
		}
		sequenceList.r[high+1]=sequenceList.r[0];
	}
}



#endif