#include <iostream>
#include <stdlib.h>

#include "sort.h"

template <class Record>
void SelectSort(Record Array[], int n)  {	// ֱ��ѡ������Array[]Ϊ���������飬nΪ���鳤��
	for (int i=0; i<n-1; i++)  {			// ����ѡ����iС�ļ�¼����ʣ���¼����С���Ǹ�
        int Smallest = i;				// ���ȼ����¼i������С��
        for (int j=i+1;j<n; j++)			// ��ʼ���ɨ������ʣ���¼
            if (Array[j] < Array[Smallest])
      	       Smallest = j;			// ������ָ�С�ļ�¼����¼����λ��
        swap(Array, i, Smallest);			// ����Array[i]�� Array[Smallest]����iС�ļ�¼��λ
	}
}

template <class Record>
void sort(Record* Array, int n) {
  SelectSort(Array, n);
}

#include "SortMain.h"
