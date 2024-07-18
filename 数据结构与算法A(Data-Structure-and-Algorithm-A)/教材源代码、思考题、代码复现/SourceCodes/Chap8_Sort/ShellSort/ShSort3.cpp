#include <iostream>
#include <stdlib.h>
using namespace std;
#include "../sort.h"

/*
template <class Record>
void ModInsSort(Record Array[], int n, int delta) {	// �޸ĵĲ��������㷨������delta��ʾ��ǰ������
	for (int i=delta; i<n; i+=delta)			// ���������е�i����¼��Ѱ�Һ��ʵĲ���λ��
		for (int j=i; j>=delta; j-=delta)  {		//  j��dealtaΪ������ǰѰ������Խ��е���
			if (Array[j] < Array[j-delta])
				swap(Array, j, j-delta);
			else break;
		}
}
*/

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

template <class Record>
void ShellSort(Record Array[], int n)  {	 		// Shell����Array[]Ϊ���������飬nΪ���鳤�� 
	for (int delta=n/3; delta>=3; delta/=3)			//����deltaÿ�γ���3�ݼ�
		for (int j=0; j<delta; j++)					//�ֱ��delta�������н��в�������
			ModInsSort(&Array[j],n-j, delta);
	ModInsSort(Array, n, 1);
}

template <class Record>
void sort(Record* Array, int n) {
	ShellSort(Array, n);
}

#include "../SortMain.h"
