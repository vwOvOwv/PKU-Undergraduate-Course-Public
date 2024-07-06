// abstract data type for stack
 
template <class T> 					// ջ��Ԫ������Ϊ T
class Stack { 
public: 	            			// ջ�����㼯
	void clear();	   			// ��Ϊ��ջ
   	bool push(const T item); 		// item��ջ���ɹ��򷵻��棬���򷵻ؼ�
 	bool pop(T& item);				// ����ջ�����ݲ��������ɹ������棬���򷵻ؼ�,
 	bool getTop(T& item);	  			// ����ջ�����ݵ��������ɹ������棬���򷵻ؼ�,
   	bool isEmpty(); 	   			// ��ջ�ѿշ�����
   	bool isFull();        			// ��ջ����������
};


