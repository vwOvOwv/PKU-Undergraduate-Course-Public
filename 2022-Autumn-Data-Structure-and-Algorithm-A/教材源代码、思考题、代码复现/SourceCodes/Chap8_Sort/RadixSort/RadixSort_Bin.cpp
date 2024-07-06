#include <iostream>
#include <stdlib.h>
using namespace std;
#include "../sort.h"

// ���16λ�����ݣ�< 32003 ������
/*
// �����ƣ�16��
#define radix 2
#define DStep 16
*/

/*
// �Ľ��ƣ�8��
#define radix 4
#define DStep 8
*/

/*
// �˽��ƣ�6��
#define radix 8
#define DStep 6
*/

// ʮ�����ƣ�4��
#define radix 16
#define DStep 4

/*
// ��ʮ�����ƣ�4��
#define radix 32
#define DStep 4
*/


template <class Record>
void RadixSort(Record Array[], int n, int d, int r)  {
	//����ʵ�ֵĻ�������nΪ���鳤�ȣ�dΪ�����������rΪ����
	Record *TempArray =new Record[n];		// �����������ʱ����
	int* count = new int[r];				// Ͱ������������count[i] �洢�˵�i��Ͱ�еļ�¼��
	int i,j,k;
	int Radix = 1;							// ģ���ֽ�λ������ȡArray[j]�ĵ�iλ������
	for (i=0; i<d; i++)  {					// �ֱ�Ե�i����������з���
		for (j=0; j<r; j++)					// ��ʼ��������Ϊ0
			count[j] = 0;    
		for (j=0; j<n; j++)	 {				// ͳ��ÿ��Ͱ�еļ�¼��
			k = (Array[j] / Radix) % r;		// ȡArray[j]�ĵ�iλ������
			count[k]++;						// ��Ӧ��������1
		}
		for (j=1; j<r; j++)					// ��TempArray�е�λ�����η����r��Ͱ
			count[j] = count[j-1] + count[j];
		for (j=n-1; j>=0; j--) {			// ������β�����Ѽ�¼�ռ�����ӦͰ 
			k = (Array[j] / Radix ) % r;	// ȡArray[j]�ĵ�iλ������
			count[k]--;						// ʹ���˵�k��Ͱ��һ��λ�ã�Ͱʣ�����ļ�������1
			TempArray[count[k]] = Array[j];
		}
		for (j=0; j<n; j++)					// ����ʱ�����е����ݸ��Ƶ�Array��
			Array[j] = TempArray[j];         
		Radix *= r;							// �����һλ���޸�ģRadix
	}
}

template <class Record>
void sort(Record* Array, int n) {
    RadixSort(Array, n, DStep, radix);    // 16����
  // RadixSort(Array, n, 6, 8);		// 8����
}

#include "../SortMain.h"
