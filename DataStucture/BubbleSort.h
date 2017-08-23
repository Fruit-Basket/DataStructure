#ifndef BubbleSort_h
#define BubbleSort_h

//冒泡排序
/*
特点：
       时间复杂度：O（n^2）
	   稳定的
	   更适合于初始记录基本有序（正序）的情况
	   移动记录次数较多，算法平局时间性能比直接插入排序差。
*/
#include "Basis.h"
#include "SequenceListForSorting.h"



//冒泡排序
void bubbleSort(SequenceListForSorting &sequenceList){
	int length=sequenceList.length;
	int flag=1;
	RedType temp;
	int i;
	while((length>1) && (flag==1)){
		flag=0;
		for(i=1;i<length;i++){    //注意，sequenceList.r[i]不使用第0号单元
			if(sequenceList.r[i].key>sequenceList.r[i+1].key){
				flag=1;    //flag==1，则表示发生了交换

				temp=sequenceList.r[i];
				sequenceList.r[i]=sequenceList.r[i+1];
				sequenceList.r[i+1]=temp;
			}
		}
		length--;
	}
}



#endif