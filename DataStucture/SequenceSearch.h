#ifndef SequenceSearch_h
#define SequenceSearch_h

//顺序查找

#include "Basis.h"
#include "SequenceListForSearch.h"



//顺序查找方法一
/*sequenceList中第0号元素不用于存放数据*/
int sequenceSearch1(SequenceListForSearch sequenceList,KeyType key){
	int i;
	for(i=sequenceList.length-1;i>=1;--i){
		if(sequenceList.r[i].key==key){
			return i;
		}
	}
	return 0;
}


//顺序查找方法二
/*sequenceList中第0号元素不用于存放数据*/
int sequenceSearch2(SequenceListForSearch sequenceList,KeyType key){
	int i;
	sequenceList.r[0].key=key;    //设置监视哨
	for(i=sequenceList.length-1 ; sequenceList.r[i].key!=key ; --i);
	return i;    //当查找失败时，返回0
}



#endif