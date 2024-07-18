#pragma once
#include "../sort.h"

template <class Record>
void PrintAddr(Record *Array, int n) {
	cout << "��������:" << endl;
	for (int i=0; i<n; i++)  			// ��ӡ��������
		cout << Array[i].key << "  " ;
	cout << endl;
	cout << "��������:" << endl;
	for (i=0; i<n; i++)  				// ��ӡ������������
		cout << Array[i].next << "   " ;
	cout << endl;
}

//�����������������
template <class Record>
void PrintArray(Record* Array, int first) 
{	//firstΪ��̬��Array�е�һ����¼���±�

	int tmp;							//����ɨ����������ָ��
	tmp = first;
	while (tmp != -1) 
	{
		cout << Array[tmp].key <<" ";	//�����¼
		tmp = Array[tmp].next;			//����ָ����һ����¼
	}
	cout << '\n';
}

