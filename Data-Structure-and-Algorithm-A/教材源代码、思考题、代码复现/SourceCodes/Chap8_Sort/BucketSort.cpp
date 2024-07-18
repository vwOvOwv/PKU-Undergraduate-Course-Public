#include <iostream>
#include <stdlib.h>
using namespace std;
#include "sort.h"

template <class Record>
void BucketSort(Record Array[], int n, int max) {	
    // Ͱʽ����Array[]Ϊ���������飬���鳤��Ϊn�����м�¼��λ������[0,max)��
    int* TempArray = new Record[n];		// ��ʱ����
    int* count = new int[max];			// С�ڻ����i��Ԫ�ظ���
    int i;

    for (i=0; i<n; i++)					// �����и��Ƶ���ʱ����
  	    TempArray[i] = Array[i];
    for (i=0; i<max; i++)				// ���м�������ʼ��Ϊ0
  	    count[i] = 0;
    for (i=0; i<n; i++)					// ͳ��ÿ��ȡֵ���ֵĴ���
	    count[Array[i]]++;
    for (i=1; i<max; i++)				// ͳ��С�ڵ���i��Ԫ�ظ���
  	    count[i] = count[i-1]+count [i];
    for (i=n-1;i>=0;i--)				// ��β����ʼ��˳������������У���֤������ȶ���
        Array[--count[TempArray[i]]] = TempArray[i];
}


template <class Record>
void sort(Record* Array, int n) {
  BucketSort(Array, n, 80); 
}

#include "SortMain.h"
