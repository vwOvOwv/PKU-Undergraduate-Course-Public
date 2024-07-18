#include <iostream>
#include <stdlib.h>
using namespace std;
#include "../sort.h"


template <class Record>
void InsertSort(Record Array[], int n)  {
	// ֱ�Ӳ�������Array[]Ϊ���������飬nΪ���鳤��
	Record TempRecord;						// ��ʱ����
	for (int i=1; i<n; i++)  {					// ���β����i����¼
		TempRecord=Array[i];
		int j = i-1;
		//��i��ʼ��ǰѰ�Ҽ�¼i����ȷλ��
		while (j >= 0 && TempRecord < Array[j])  {
			Array[j+1] = Array[j];				// ����Щ���ڵ��ڼ�¼i�ļ�¼����
			j = j - 1;
	    }
	    Array[j+1] = TempRecord; 				// ��ʱj������Ǽ�¼i����ȷλ�ã�����
	}
}

int SelectPivot(int left, int right)  {			// ѡ����ֵ������left,right�ֱ��ʾ���е����Ҷ��±�
	return (left+right)/2;					// ѡ���м��¼��Ϊ��ֵ
}

template <class Record>
void ModQuickSort(Record Array[], int left, int right) {  // �Ż��Ŀ�������
	if (right <= left)  return;			// ���������ֻ��0��1����¼���Ͳ�������
	if (right-left+1 > THRESHOLD)  {		// �Գ��ȴ�����ֵ(28���)�ĳ��Ӵ�����
	int pivot = ::SelectPivot(left, right); 		// ѡ����ֵ	
	swap(Array, pivot, right);   		// ����ֵ��������ĩ��
	pivot = Partition(Array, left, right); 		// �ָ����ֵ�ѵ�����ȷλ��
	ModQuickSort(Array, left, pivot-1);  		// ����ֵ��ߵ������н��еݹ��������
	ModQuickSort(Array, pivot+1, right); 		// ����ֵ�ұߵ������н��еݹ��������
	}
}


template <class Record>
int Partition(Record Array[], int left, int right)  {		// �ָ�����ָ����ֵ�ѵ�����ȷλ��
	int l = left;								//  lΪ��ָ�룬rΪ��ָ��
	int r = right;	
	Record TempRecord = Array[r];				// ����ֵ�������ʱ������
	while (l != r)  {							// ��ʼ�ָl,r�������м��ƶ���ֱ������
		// lָ�������ƶ���ֱ���ҵ�һ��������ֵ�ļ�¼
		while (Array[l] <= TempRecord && r > l)	// ����Ҳ���԰ѡ�<=����дΪ��<�����������ȶ�
			l++;
		if (l < r)  {						// ��l,r��δ������������Ԫ�ػ����ұߵĿ�λ
			Array[r] = Array[l];
			r--;							//  rָ�������ƶ�һ��
		}
		// rָ�������ƶ���ֱ���ҵ�һ��С�ڵ�����ֵ�ļ�¼
		while (Array[r] > TempRecord && r > l) 	// ����Ҳ���԰ѡ�>����дΪ��>=�������ټ�¼�ƶ�
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
	ModQuickSort(Array, 0, n-1);			// �����Ż��ĵݹ���ţ�������С�Ӵ�
	InsertSort(Array, n);				// ���������н���ɨβ��������
}


#include "../SortMain.h"
