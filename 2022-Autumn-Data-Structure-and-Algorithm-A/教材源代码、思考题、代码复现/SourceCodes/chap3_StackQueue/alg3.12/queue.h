

// array-base queue
template <class T> 
class arrQueue: class Queue<T> { 
private: 	
	int 	mSize; 						// ��Ŷ��е�����Ĵ�С
	int 	front;							// ��ʾ��ͷ����λ�õ��±�
	int 	rear;							// ��ʾ��β����λ�õ��±�
	T 	*qu��						// �������ΪT�Ķ���Ԫ�ص�����
public: 								// ���е����㼯
   	arrQueue(int size)  {    				// �������е�ʵ��
		mSize = size +1;					// �˷�һ���洢�ռ䣬��������пպͶ�����
		qu = new T [mSize];
		front = rear = 0;
	}
   	~arrQueue()  {  					// ������ʵ�������ͷ���ռ�
		delete [] qu;
	}
	void clear {						// ��ն���
		front = rear; 
	}
   	bool enQueue(T item)  { 				//  item��ӣ������β
		if (((rear + 1 ) % mSize) == front) {
			cout << "�������������" << endl;
			return false;
		}
		qu[rear] = item;
		rear = (rear +1) % mSize;  			// ѭ�����
		return true;
	}
 	bool deQueue(T& item)  {     			// ���ض�ͷԪ�ز��Ӷ�����ɾ��
		if ( front == rear)  {
			cout << "����Ϊ��" << endl;
			return false;
		}
		item = qu[front];
		front = (front +1) % mSize;
		return true;
 	}
	bool front(T & item) {	     			// ���ض�ͷԪ�أ�����ɾ��
		if (front == rear)  {
			cout << "����Ϊ��" << endl;
			return false;
		}
		item = qu[front];
		return true;
	}
}

template <class T> 
class lnkQueue: class Queue <T> { 
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
	void clear {							// ��ն���
		while (front != NULL) {
			rear = front;
			front = front->next;
			delete rear;
		}
		rear = NULL; 
		size = 0;
	}
	bool enQueue(const T& item) { 				//  item��ӣ������β
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
 	bool deQueue(T & item)  {          		// ���ض�ͷԪ�ز��Ӷ�����ɾ��
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
	bool front(T & item)  {	       			// ���ض�ͷԪ�أ�����ɾ��
		if (size == 0)  {						// ����Ϊ�գ�û��Ԫ�ؿɳ���
			cout << "����Ϊ��" << endl;
			return false;
		}
		item = front -> element; 
		return true;
	}
}
