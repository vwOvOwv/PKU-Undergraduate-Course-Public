#include <iostream>
#include <stdlib.h>
using namespace std;
#include "sort.h"

template <class Record>
void BubbleSort(Record Array[], int n)  {	// �Ż���ð������Array[]Ϊ���������飬nΪ���鳤��
	bool NoSwap;			// �Ƿ����˽����ı�־
	for (int i=0; i<n-1; i++)  {
	NoSwap = true;		// ��־��ʼΪ��
	for (int j=n-1; j>=i; j--)
	  if (Array[j] < Array[j-1])  {	// �жϣ�Array[j-1]��Array[j]���Ƿ�����
		swap(Array, j, j-1);	// �������ö�Array[j]��Array[j-1]
		NoSwap = false;		// �����˽�������־��Ϊ��
	  }
	if (NoSwap)  			// ���û��������������ʾ���ź��򣬽����㷨
		return;
	}
}

template <class Record>
void sort(Record* Array, int n) {
  BubbleSort(Array, n);
}

#include "SortMain.h"