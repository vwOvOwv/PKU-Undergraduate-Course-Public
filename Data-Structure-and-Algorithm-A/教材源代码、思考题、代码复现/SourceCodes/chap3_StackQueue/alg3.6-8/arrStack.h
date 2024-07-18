//  array-based stack: definition and implementation for some methods

#include <iostream>
#include "myStack.h"

using namespace std;

template <class T> 	
class arrStack : public Stack<T> {      
private: 	                    	// ջ��˳��洢
		int		mSize;			// ջ�����ɴ�ŵ�Ԫ�ظ���
		T 		*st;	  		// ���ջԪ�ص�����
public:  
         int		top;					// ջ��λ�ã�ӦС��mSize 
public:  						// ջ�������˳��ʵ��
	arrStack(int size){ 				// ����һ��˳��ջ��ʵ��
		mSize = size;
		top = -1;
		st = new T[mSize];
	}
	arrStack(){
        top = -1;
    }
	~arrStack() {					// ��������
		delete [] st;
	}
	void clear() {					// ���ջ����
		top = -1;
    }
	bool push(const T item) { 	   		// ��ջ������˳��ʵ��	
		if (top == mSize-1) {  			// ջ���� 
			cout << "ջ�����" << endl;
			return false;
		}
		else {					// ��Ԫ����ջ���޸�ջ��ָ��
			st[++top] = item;
			return true;
		}
	}
	bool pop(T* item) { 	        	                  	// ��ջ��˳��ʵ��
		if (top == -1) {			                       // ջΪ��
			cout << "ջΪ�գ����ܳ�ջ����"<< endl; 
			return false;
		}
		else {
			*item = st[top--];	         // ����ջ��Ԫ�ز��޸�ջ��ָ��
			return true;
		}
	}
	bool getTop(T* item) {				     // ����ջ�����ݣ���������
		if (top == -1) {			         // ջ��
			cout << " ջΪ�գ����ܳ�ջ����"<< endl; 
			return false;
		}
		else { 						
			*item = st[top];
			return true;
		}
    }
    bool isEmpty() { 
         return (top == -1);
    }
    bool isFull() { 
         return (top == mSize-1);
    }
};

