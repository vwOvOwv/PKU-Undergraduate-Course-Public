#include <iostream>
#include "Link.h"
#include "myQueue.h"

template <class T> 
class lnkQueue: public Queue <T> { 
private: 	
	int 		size; 							// �����е�ǰԪ�صĸ���
	Link<T>* front;							// ��ʾ��ͷ��ָ��
	Link<T>* rear;							// ��ʾ��β��ָ��
public: 									// ���е����㼯
 	lnkQueue(int size)  {    					// �������е�ʵ��
		size = 0;
		front = rear = NULL;
}
   	~lnkQueue()  {  						// ������ʵ�������ͷ���ռ�
		clear();
}
void clear() {							// ��ն���
	while (front != NULL) {
rear = front;
front = front->next;
delete rear;
			}
			rear = NULL; 
			size = 0;
}
bool enQueue(const T item) { 				//  item��ӣ������β
		if (rear == NULL) 	{				// �ն���
			front = rear = new Link<T> (item, NULL);
		}
		else  {							// ����µ�Ԫ��
			rear-> next = new Link<T> (item, NULL);  
			rear = rear ->next;
		}
		size++;
		return true;
	}
 	bool deQueue(T* item)  {          			// ���ض�ͷԪ�ز��Ӷ�����ɾ��
		Link<T> tmp;
		if (size == 0)  {						// ����Ϊ�գ�û��Ԫ�ؿɳ���
			cout << "����Ϊ��" << endl;
			return false;
		}
		item = front -> element; 
		tmp = front;
		front = front -> next;
		delete tmp;
		if (front == NULL)
rear = NULL;
size--;
		return true;
 	}
bool front(T* item)  {	       				// ���ض�ͷԪ�أ�����ɾ��
		if (size == 0)  {						// ����Ϊ�գ�û��Ԫ�ؿɳ���
			cout << "����Ϊ��" << endl;
			return false;
		}
		item = front -> element; 
		return true;
	}
}
