#ifndef SequenceSearch_h
#define SequenceSearch_h

//˳�����

#include "Basis.h"
#include "SequenceListForSearch.h"



//˳����ҷ���һ
/*sequenceList�е�0��Ԫ�ز����ڴ������*/
int sequenceSearch1(SequenceListForSearch sequenceList,KeyType key){
	int i;
	for(i=sequenceList.length-1;i>=1;--i){
		if(sequenceList.r[i].key==key){
			return i;
		}
	}
	return 0;
}


//˳����ҷ�����
/*sequenceList�е�0��Ԫ�ز����ڴ������*/
int sequenceSearch2(SequenceListForSearch sequenceList,KeyType key){
	int i;
	sequenceList.r[0].key=key;    //���ü�����
	for(i=sequenceList.length-1 ; sequenceList.r[i].key!=key ; --i);
	return i;    //������ʧ��ʱ������0
}



#endif