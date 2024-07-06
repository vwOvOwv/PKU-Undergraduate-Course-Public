#include <iostream>
#include <stdlib.h>
using namespace std;
#include "../sort.h"

int SelectPivot(int left, int right)  {				// ѡ����ֵ������left,right�ֱ��ʾ���е����Ҷ��±�
	return (left+right)/2;						// ѡ���м��¼��Ϊ��ֵ
}

template <class Record>
void QuickSort(Record Array[], int left, int right) { 		// Array[]Ϊ���������飬left,right�ֱ�Ϊ��������
	if (right <= left) 	return;					// �����������ֻ��0��1����¼���Ͳ�������
	int pivot = ::SelectPivot(left, right); 			// ѡ����ֵ
	swap(Array, pivot, right);   				// �ָ�ǰ�Ƚ���ֵ�ŵ�����ĩ��
	pivot = Partition(Array, left, right); 			// �ָ����ֵ�ѵ�����ȷλ��
    	QuickSort(Array, left, pivot-1);  				// ����ֵ��ߵ������н��еݹ��������
    	QuickSort(Array, pivot +1, right); 			// ����ֵ�ұߵ������н��еݹ��������
}

template <class Record>
int Partition(Record Array[], int left, int right)  {		// �ָ�����ָ����ֵ�ѵ�����ȷλ��
	int l = left;								//  lΪ��ָ�룬rΪ��ָ��
	int r = right;	
	Record TempRecord = Array[r];				// ����ֵ�������ʱ������
	while (l != r)  {							// ��ʼ�ָl,r�������м��ƶ���ֱ������
		// lָ�������ƶ���ֱ���ҵ�һ��������ֵ�ļ�¼
		while (Array[l] <= TempRecord && r > l)	// ����Ҳ���԰�"<="��дΪ"<"���������ȶ�
			l++;
		if (l < r)  {						// ��l,r��δ������������Ԫ�ػ����ұߵĿ�λ
			Array[r] = Array[l];
			r--;							//  rָ�������ƶ�һ��
		}
		// rָ�������ƶ���ֱ���ҵ�һ��С�ڵ�����ֵ�ļ�¼
		while (Array[r] > TempRecord && r > l) 	// ����Ҳ���԰�">"��дΪ">="�����ټ�¼�ƶ�
			r--;
		if (l < r)  {						// ��l,r��δ������������Ԫ�ػ�����ߵĿ�λ
			Array[l] = Array[r];
			l++;							// lָ�������ƶ�һ��
		}
	}	//end while
	Array[l] = TempRecord;					// ����ֵ����ֽ�λ��l��
	return l;								// ���طֽ�λ��l
}


template <class Record>
void sort(Record* Array, int n) {
	QuickSort(Array, 0, n-1);
}

#include "../SortMain.h"
