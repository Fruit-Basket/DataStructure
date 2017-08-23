#ifndef BinarySearch_h
#define BinarySearch_h

//二分查找

#include "Basis.h"
#include "SequenceListForSearch.h"


//二分查找
int binarySearch(SequenceListForSearch sequenceList,KeyType key){
	int low,height,middle;

	low=1;
	height=sequenceList.length-1;

	while(low<=height){
		middle=(low+height)/2;
		if(sequenceList.r[middle].key==key){
			return middle;
		}
		else if(sequenceList.r[middle].key<key){
			low=middle+1;
		}
		else{
			height=middle-1;
		}
	}
	return 0;    //查找失败时返回0;
}

#endif