#include <iostream>
#include <stdlib.h>
using namespace std;
#include "../sort.h"

template <class Record>
void InsertSort (Record Array[], int n)  {
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

/*
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
*/

template <class Record>
void ModMergeSort(Record Array[], Record TempArray[], int left, int right) { 
//	if (right <= left)	return;						// ���ֻ����һ��Ԫ�أ�ֱ�ӷ���		  
	if (right-left+1 > THRESHOLD)  {				//������г��ȴ�����ֵ(16���)�������ݹ�
		int middle=(left+right)/2;					// ���м仮��Ϊ����������
		ModMergeSort(Array, TempArray ,left,middle);	// �����һ����еݹ�
		ModMergeSort(Array, TempArray ,middle+1,right);	// ���ұ�һ����еݹ�
		ModMerge(Array, TempArray ,left,right,middle);	// ���й鲢
	}
    else  InsertSort(&Array[left],right-left+1);        	// ������С�ڵ�����ֵ������ֱ�Ӳ�������
}

template <class Record>
void ModMerge(Record Array[],Record TempArray[],int left,int right,int middle)  {	//�鲢����
	int index1,index2;							// ���������е���ʼλ��
	int i,j,k ;
	for (i=left; i<=middle; i++)						// ������ߵ�������
		TempArray[i] = Array[i];
	for (j=1; j<=right-middle; j++)					// �����ұߵ������У���˳��ߵ�����
		TempArray[right-j+1] = Array[j+middle];
	// ��ʼ�鲢��ȡ��С�߲���ϲ�������
	for (index1=left, index2=right, k=left;  k<=right;  k++)
		if (TempArray[index1] <= TempArray[index2])	// Ϊ��֤�ȶ��ԣ����ʱ�������
			Array[k] = TempArray[index1++];
		else  Array[k] = TempArray[index2--];
}

template <class Record>
void sort(Record* array, int n) {
	static Record* temp = NULL;
	if (temp == NULL) temp = new Record[n];				// ���븨������
	ModMergeSort(array, temp, 0, n-1);
}

#include "../SortMain.h"
