#include <iostream>
#include <stdlib.h>
using namespace std;
#include "sort.h"

/*
template<class Record>
void IndexSort(Record Array[], int n)
{	//Array[]Ϊ���������飬nΪ���鳤��
    int *IndexArray = new int[n],  TempIndex;
	int i,j;
    for (i=0; i<n; i++) IndexArray[i] = i;
	for (i=1; i<n; i++)    // ���β����i����¼
		for (j=i;j>0;j--) //���αȽϣ��������þͽ���
			if (Array[IndexArray[j]] < Array[IndexArray[j-1]])  {
				TempIndex=IndexArray[j];
                IndexArray[j]=IndexArray[j-1];
			    IndexArray[j-1]=TempIndex;	
			}
			else break;	//��ʱiǰ���¼������

    // ����IndexArray����Array
    for(i=0; i<n; i++) { 
        j=IndexArray[i];
		while (j<i)  
			j=IndexArray[j]; 	
	    swap(Array, i, j);
		IndexArray[i]=j;
	}
}
*/

// Array[]Ϊ���������飬IndexArray[]Ϊ�������飬nΪ���鳤��
template<class Record>
void IndexSort(Record Array[], int IndexArray[], int n)  {
	int i,j;
    for (i=0; i<n; i++) IndexArray[i] = i;	// ��ʼ�������±�
    // �򵥲�������ĵ�ַ�������
	for (i=1; i<n; i++)				// ���β����i����¼
		for (j=i;j>0;j--)				// ���αȽϣ��������þͽ���
			if (Array[IndexArray[j]] < Array[IndexArray[j-1]])
	            swap(IndexArray, j, j-1);  // ����Array[IndexArray[j]]��Array[IndexArray[j-1]
			else break;				// ��ʱiǰ���¼������
	AdjustRecord(Array, IndexArray, n); 
}


// ����IndexArray����Array��IndexArray[]Ϊ�������飬nΪ���鳤��
template<class Record>
void AdjustRecord(Record Array[],int IndexArray[], int n)  {
	Record TempRec;				// ֻ��Ҫһ����ʱ�洢�ռ�
    for (int i=0; i<n; i++)  {			// ѭ��n-1�Σ�ÿ�δ��������е�i����¼
		int j = i;					// jΪ��ʱ��������ѭ�����еĵ�ǰԪ��
		TempRec = Array[i];			// �ݴ�i�±���Ŀǰ�ļ�¼
		while (IndexArray[j] != i)  {	// ���ѭ�����������±껹����i����˳��ѭ������
			int k = IndexArray[j];		// kΪ����jָ����±�
			Array[j] = Array[k];		// ��k�±��е�ֵ���Ƶ�jλ�ã���j��Ԫ����ȷ��λ
			IndexArray[j] = j;		// ��Ϊ����ȷ��λ������j��������
			j = k;					// j������һ������������
		}
		Array[j]=TempRec;			// ����ҵ���j�����������±�ֵΪi����˵�i��Ԫ����ȷ��λ
		IndexArray[j]=j;				// ��Ϊ����ȷ��λ������j��������
	}
}

template <class Record>
void sort(Record* Array, int n) {
    Record* temp = new Record[n];			// ���븨������
	IndexSort(Array, temp, n);
}

#include "SortMain.h"