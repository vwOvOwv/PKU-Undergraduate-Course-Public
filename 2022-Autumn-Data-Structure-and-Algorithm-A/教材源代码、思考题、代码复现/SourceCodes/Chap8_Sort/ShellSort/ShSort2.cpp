#include <iostream>
#include <stdlib.h>
using namespace std;
#include "../sort.h"

/*
template <class Record>
void ModInsSort(Record Array[], int n, int delta) {	
	// ��Ա仯���������޸ĵĲ��������㷨������delta��ʾ��ǰ������
	Record TempRecord;						// ��ʱ����
	for (int i=delta; i<n; i+=delta) {		// ���������е�i����¼����
		TempRecord=Array[i];
		int j = i-delta;
		//��i��ʼ��ǰѰ�Ҽ�¼i����ȷλ��
		while (j>=0 && TempRecord < Array[j]) {
			Array[j+delta] = Array[j];		//����Щ���ڵ��ڼ�¼i�ļ�¼����
			j = j - delta;
	    }
	    Array[j+delta] = TempRecord; 			//��ʱj������Ǽ�¼i����ȷλ�ã�����
	}
}
*/

template <class Record>
void ShellSort(Record Array[], int n)  {	 		// Shell����Array[]Ϊ���������飬nΪ���鳤��
	for (int delta=n/2; delta>0; delta/=2)      	// ����deltaÿ�γ���2�ݼ�
		for (int i=0; i<delta; i++)			// �ֱ��delta�������н��в�������
			ModInsSort(&Array[i], n-i, delta);
}

template <class Record>
void ModInsSort(Record Array[], int n, int delta) {	// �޸ĵĲ��������㷨������delta��ʾ��ǰ������
	for (int i=delta; i<n; i+=delta)			// ���������е�i����¼��Ѱ�Һ��ʵĲ���λ��
		for (int j=i; j>=delta; j-=delta)  {		//  j��dealtaΪ������ǰѰ�����öԽ��е���
			if (Array[j] < Array[j-delta])		//  Array[j] < Array[j-delta]�������Ϊ���ö�
				swap(Array, j, j-delta);		// ����Array[j]��Array[j-delta]
			else break;
		}
}

template <class Record>
void sort(Record* Array, int n) {
	ShellSort(Array, n);
}

#include "../SortMain.h"
