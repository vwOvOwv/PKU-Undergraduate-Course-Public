//���ھ�̬���Ļ�������

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "LinkSort.h"
#include "LinkRadixSort.h"
using namespace std;
// ���16λ�����ݣ�< 32003 ������
/*
// �����ƣ�16��
#define radix 2
#define DStep 16
*/

/*
// �Ľ��ƣ�8��
#define radix 4
#define DStep 8
*/

/*
// �˽��ƣ�6��
#define radix 8
#define DStep 6
*/

// ʮ�����ƣ�4��
#define radix 16
#define DStep 4

/*
// ��ʮ�����ƣ�4��
#define radix 32
#define DStep 4
*/

/*
// ��ʮ�Ľ��ƣ�3��
#define radix 64
#define DStep 3
*/

/*
// 128���ƣ�3��
#define radix 128
#define DStep 3

// 256���ƣ�2��
#define radix 256
#define DStep 2
*/

template <class Record>
void sort(Record* Array, int n) {
/*	
	int listsize = 9;    
	Node *Array = new Node[9];
	
	Array[0].key = 97;
	Array[1].key = 53;
	Array[2].key = 88;
	Array[3].key = 59;
	Array[4].key = 26;
	Array[5].key = 41;
	Array[6].key = 88;
	Array[7].key = 31;
	Array[8].key = 22;

	cout << "����ǰ:" << endl;
	Print<Node>(Array, listsize);
	RadixSort<Node>(Array, listsize, DStep, radix);
	cout << "�����:" << endl;
	Print<Node>(Array, listsize);
*/	
	RadixSort(Array, n, DStep, radix);
}

#include "LinkSortMain.cpp"