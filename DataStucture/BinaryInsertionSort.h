#ifndef BinaryInsertionSort_h
#define BinaryInsertionSort_h

//折半插入排序
/*
算法思想：
       在直接插入的基础上使用折半查找查找插入位
特点：
       时间复杂度：O（n^2）；相对于直接插入排序，平均情况下，它减少了查找插入位的时间
       稳定的
*/

#include "Basis.h"
#include "StraightInsertionSort.h"



//折半插入排序
/*不使用数组的第0号单元
*/
void binaryInsertionSort(SequenceListForSorting &sequenceList){
	int low,high,middle;
	int i,j;
	for(i=2;i<=sequenceList.length;i++){
		sequenceList.r[0]=sequenceList.r[i];
		//查找
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
		//移动
		for(j=i-1;j>=high+1;--j){
			sequenceList.r[j+1]=sequenceList.r[j];
		}
		sequenceList.r[high+1]=sequenceList.r[0];
	}
}



#endif