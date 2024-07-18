#include <iostream>
#include <stdlib.h>
using namespace std;
#include "../sort.h"

template <class Record>
void MergeSort(Record Array[], Record TempArray[], int left, int right)  {
	//��·�鲢����Array[]Ϊ���������飬left��right�ֱ�Ϊ��������
	if (left < right)  {							// ���������ֻ��0��1����¼���Ͳ�������
		int middle=(left+right)/2;					//���м仮��Ϊ����������
		MergeSort(Array,TempArray,left,middle);		//�����һ����еݹ�
		MergeSort(Array, TempArray,middle+1,right);	//���ұ�һ����еݹ�
		Merge(Array, TempArray,left,right,middle);		// ���й鲢
	}
}

template <class Record>
void Merge(Record Array[], Record TempArray[], int left, int right, int middle)  {  //�鲢����
	for (int j=left; j<=right; j++)   					// �������ݴ�����ʱ����
		TempArray[j] = Array[j];
	int index1=left;								// ��������е���ʼλ��
	int index2=middle+1;							// �ұ������е���ʼλ��
	int i=left;									// ����ʼ�鲢
	while (index1 <= middle && index2 <= right)  {
		//ȡ��С�߲���ϲ�������
		if (TempArray[index1] <= TempArray[index2])	// Ϊ��֤�ȶ��ԣ����ʱ�������
			Array[i++] = TempArray[index1++];
		else  Array[i++] = TempArray[index2++];
	}
	while (index1 <= middle)						// ֻʣ�����У�����ֱ�Ӹ���
		Array[i++] = TempArray[index1++];
	while (index2 <= right) 						// ���ϸ�ѭ�����⣬ֱ�Ӹ���ʣ���������
		Array[i++] = TempArray[index2++];			
}

template <class Record>
void sort(Record* array, int n) {
    static Record* temp = NULL;
    if (temp == NULL) temp = new Record[n];			// ���븨������
    MergeSort(array, temp, 0, n-1);
}

#include "../SortMain.h"
