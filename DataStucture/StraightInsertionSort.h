#ifndef StraightInsertionSort_h
#define StraightInsertionSort_h

//直接插入排序
/*
算法思想：
       将为排序的元素插入到以排序的序列中
特点：
       时间复杂度：O（n^2）
       稳定的
	   更适合于初始记录基本有序（正序）的情况
*/

#include "Basis.h"
#include "SequenceListForSorting.h"



//直接插入排序
/*不使用数组的第0号单元
*/
void straightInsertionSort(SequenceListForSorting &sequenceList){
	int i,j;
	for(i=2;i<=sequenceList.length;i++){	//第0号单元不算入数组的长度值
		//如果后一个数小于前一个数
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