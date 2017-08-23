#ifndef SimpleSelectionSort_h
#define SimpleSelectionSort_h

//简单选择排序
/*
算法思想：
       时间复杂度：O（n^2）
       不稳定，
	   移动记录次数较少，当每一记录占用的空间较多时，此方法比直接插入排序快。
*/

#include "Basis.h"
#include "SequenceListForSorting.h"



//简单选择排序
/*不使用sequenceList.r[i]的第0号单元
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