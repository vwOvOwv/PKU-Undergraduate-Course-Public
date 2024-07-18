
#include <iostream>
#include <stdlib.h>
using namespace std;
#include "../sort.h"
#include "MaxHeap.h"


//������Array[]Ϊ���������飬nΪ���鳤��
template <class Record>
void sort(Record Array[], int n) 
{ 
	MaxHeap<Record> max_heap = MaxHeap<Record>(Array,n,n);	//����
	for (int i=0; i<n; i++)		 // �����ҳ�ʣ���¼�е�����¼�����Ѷ�
		max_heap.MoveMax();	
}


#include "../SortMain.h"
