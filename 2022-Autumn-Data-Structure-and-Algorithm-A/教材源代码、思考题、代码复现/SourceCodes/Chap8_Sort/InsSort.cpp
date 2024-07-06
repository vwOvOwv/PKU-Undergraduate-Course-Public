#include <iostream>
#include <stdlib.h>
using namespace std;
#include "sort.h"

template <class Record>
void InsertSort (Record Array[], int n)  {
	// ֱ�Ӳ�������Array[]Ϊ���������飬nΪ���鳤��
	Record TempRecord;						// ��ʱ����
	for (int i=1; i<n; i++)  {					// ���β����i����¼
		TempRecord=Array[i];					// �ȰѼ�¼Array[i]��������ʱ��¼������
		int j = i-1;							// �ڴ�ѭ��������j��i-1��ʼ
		// ��ǰѰ�Ҽ�¼i����ȷλ��
		while (j >= 0 && TempRecord < Array[j])  {
			Array[j+1] = Array[j];				// ����Щ���ڵ��ڼ�¼i�ļ�¼����
			j = j - 1;						// �±�jǰ��
	    }
	    Array[j+1] = TempRecord; 				// ��ʱj+1���Ǽ�¼i����ȷλ�ã�����
	}
}

template <class Record>
void sort(Record* Array, int n) {
	InsertSort(Array, n);
}

#include "SortMain.h"
