#include <cstdlib>
#include <iostream>

#include "myStack.h"

using namespace std;

template <class T> class Link {
public: 
        T  		data;							// ���ڱ�����Ԫ�ص�����
	    Link 	* next;						// ָ���̽���ָ��
	
	    Link(const T info, Link* nextValue)  {	// ��������������Link���캯��
		           data = info;
		           next = nextValue;
       }
       Link(Link* nextValue = NULL)  {	// ��������������Link���캯��
		           next = nextValue;
       }
};

template <class T> 
class lnkStack : public Stack <T>  { 
private: 	                    		// ջ����ʽ�洢
   Link<T>*	top;					// ָ��ջ����ָ��
   int 		size;					// ���Ԫ�صĸ���
public:                      			// ջ�������ʽʵ��
    lnkStack(int defSize) {				// ���캯��
    	top = NULL;
    	size = 0;
    }
    ~lnkStack() {					// ��������
    	clear();
    }
    void clear() {					// ���ջ����
    	while (top != NULL) {
    		Link<T> *tmp = top; 
    		top = top->next;
    		delete tmp;
        }
    	size = 0; 
    }
    bool push(const T item) { 	    		// ��ջ��������ʽʵ��	
         Link<T>* tmp = new Link<T>(item, top);
         top = tmp;
         size++;
         return true;
    }
    bool pop(T* item) { 				// ��ջ����ʽʵ��
         Link<T> *tmp;
         if (size == 0) {
            cout << "ջΪ�գ����ܳ�ջ����" << endl; 
            return false;
         } 
         *item = top->data; 
         tmp = top->next;
         delete top;
         top = tmp;
         size--;
         return true;
    }
    bool getTop(T* item) {				// ����ջ�����ݣ���������
         if (size == 0) {
            cout << "ջΪ�գ����ܳ�ջ����"<< endl; 
            return false;
         } 
         *item = top->data;
         return true;
    }	       
};

