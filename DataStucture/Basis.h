/**
* ��������
* Author: FruitBasket
* Time: 2017/8/17
* Email: FruitBasket@qq.com
* Source code: github.com/Fruit-Basket
*/

#ifndef Basis_h
#define Basis_h

#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define OVERFLOW -2
#define NULL 0
#define MAXSIZE 100
#define MAX_INT 2147483647		//vs2013��ʹ��4���ֽ������int����
#define END_FLAG -1    //��Ϊ���������־���ڶ�������������ʱʹ��
#define ORDER 3   //B-���Ľ�

#define MAX_VERTEX_AMOUNT 100	//ͼ�ж������������ֵ
#define MAX_ARC_AMOUNT 100	//ͼ�б����������ֵ
#define MAX_WEIGHT  99999    //ͼ�б�Ȩ�����ֵ��Huffman���������Ȩֵ
//���Ȩֵ����ȡMAX_INT����Ϊ�������һ�����Ȩֵ��һ����ͨȨֵ���ʱ���ᷢ�����硣

typedef int Status;//��������״̬����������OK��ERROR��OVERFLOWʹ��
typedef char SElemType;//ջ�е���������
typedef char TElemType;//��������������
typedef char VertexType;//ͼ�ж������������
typedef int ArcType;//ͼ�бߵ�Ȩֵ���ͣ�Arc������

typedef int KeyType;//˳�������Ԫ���йؼ��ֵ�����
typedef int InformationType;//˳�������Ԫ���е���Ϣ����

const int DEBUG = TRUE;

#endif