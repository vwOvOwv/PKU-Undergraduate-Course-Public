#include "MinHeap.h"
#include <iostream>

using namespace std;
int main()  {

	int temp,elem;

	MinHeap<int> minheap(8);
	int i;
/*
	int Key[] = {19,8,35,65,40,3,7,45} ;    //ͼ��5.17��ʾ������
	
	cout << "���ѣ�" << endl;    //�˴�Ϊ���β��룬��ͬ��ͼʾ��ͼʾ��������ֱ���ڹ��캯����д
	for(i = 0;i < 8; i++)  {            //���ѹ���
		minheap.Insert(Key[i]);
		cout<< Key[i] << " added." <<endl;
	}
*/

	cout<< "ɾ�������±�(3)��Ԫ��:" <<endl;
	minheap.Remove(3,elem);
	cout<<  elem << " deleted." <<endl;

	//����45
	minheap.Insert(45);


	cout << "�ӶѶ�ɾ����Сֵ:" << endl;
	for (i = 0; i <8; i ++)  {           //���δӶѶ�ɾ����Сֵ
		temp = minheap.RemoveMin();
		cout << temp << " ";             //��ӡ��ǰ��Сֵ
	} 
	cout << "\n\n";
	
	return 0;	
} 