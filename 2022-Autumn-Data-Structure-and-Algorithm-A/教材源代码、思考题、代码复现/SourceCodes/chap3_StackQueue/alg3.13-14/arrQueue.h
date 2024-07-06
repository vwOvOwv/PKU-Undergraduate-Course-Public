#include <cstdlib>
#include <iostream>

#include "myQueue.h"

using namespace std;

template <class T> 
class arrQueue: public Queue<T> { 
private: 	
	int 	mSize; 						// ��Ŷ��е�����Ĵ�С
	int 	front;							// ��ʾ��ͷ����λ�õ��±�
	int 	rear;							// ��ʾ��β����λ�õ��±�
	T 	    *qu;							// �������ΪT�Ķ���Ԫ�ص�����
public: 								// ���е����㼯
   	arrQueue(int size)  {    				// �������е�ʵ��
		mSize = size +1;					// �˷�һ���洢�ռ䣬��������пպͶ�����
		qu = new T[mSize];
		front = rear = 0;
}
   	~arrQueue()  {  					// ������ʵ�������ͷ���ռ�
		delete [] qu;
}
void clear() {						// ��ն���
	front = rear; 
}
   	bool enQueue(const T item)  { 			//  item��ӣ������β
		if (((rear + 1 ) % mSize) == front) {
			cout << "�������������" << endl;
			return false;
		}
		qu[rear] = item;
		rear = (rear +1) % mSize;  			// ѭ�����
		return true;
	}
 	bool deQueue(T*item)  {     			// ���ض�ͷԪ�ز��Ӷ�����ɾ��
		if ( front == rear)  {
			cout << "����Ϊ��" << endl;
			return false;
		}
		*item = qu[front];
		front = (front +1) % mSize;
		return true;
 	}
    bool getFront(T* item) {	     			// ���ض�ͷԪ�أ�����ɾ��
		if (front == rear)  {
			cout << "����Ϊ��" << endl;
			return false;
		}
		*item = qu[front];
		return true;
	}
	void print() {	     			// ���ض�ͷԪ�أ�����ɾ��
		if (front == rear)  {
			cout << "����Ϊ��" << endl;
		}
		int p = front;
		while(p != rear ) {
              cout << qu[p] << " ";
              p =( p + 1)  % mSize;  
        } 
        cout << endl;
	}
};



