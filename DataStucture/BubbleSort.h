#ifndef BubbleSort_h
#define BubbleSort_h

//ð������
/*
�ص㣺
       ʱ�临�Ӷȣ�O��n^2��
	   �ȶ���
	   ���ʺ��ڳ�ʼ��¼�����������򣩵����
	   �ƶ���¼�����϶࣬�㷨ƽ��ʱ�����ܱ�ֱ�Ӳ�������
*/
#include "Basis.h"
#include "SequenceListForSorting.h"



//ð������
void bubbleSort(SequenceListForSorting &sequenceList){
	int length=sequenceList.length;
	int flag=1;
	RedType temp;
	int i;
	while((length>1) && (flag==1)){
		flag=0;
		for(i=1;i<length;i++){    //ע�⣬sequenceList.r[i]��ʹ�õ�0�ŵ�Ԫ
			if(sequenceList.r[i].key>sequenceList.r[i+1].key){
				flag=1;    //flag==1�����ʾ�����˽���

				temp=sequenceList.r[i];
				sequenceList.r[i]=sequenceList.r[i+1];
				sequenceList.r[i+1]=temp;
			}
		}
		length--;
	}
}



#endif