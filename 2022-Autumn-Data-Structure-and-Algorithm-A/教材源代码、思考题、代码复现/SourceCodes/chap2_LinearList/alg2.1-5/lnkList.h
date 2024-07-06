#include <cstdlib>
#include <iostream>

#include "myList.h" 

using namespace std;

template <class T> class Link {
public: 
   	T  		data;							// ���ڱ�����Ԫ�ص�����
	Link 	* next;						// ָ���̽���ָ��
	Link(const T info, Link* nextValue = NULL)  {	// ��������������Link���캯��
		data = info;
		next = nextValue;
	}
	Link(Link* nextValue = NULL)  { 			// ����һ��������Link���캯��
		next = nextValue;
	}
} 


// ������2.7�� ����������Ͷ���
template <class T>
class lnkList : public List<T>  {
protected: 
	Link<T>*  head, tail;    				// �������ͷ��βָ��
public: 
	lnkList();						// ���캯��
	~lnkList();						// ��������
    bool isEmpty(); 					// �ж������Ƿ�Ϊ��
    void clear(); 					// ������洢�������������Ϊ�ձ�
	int length();                   	// ���ش�˳���ĵ�ǰʵ�ʳ���
    bool append(T value);				// �ڱ�β���һ��Ԫ��value����ĳ�����1
	bool insert(int p, T value);			// ��λ��p�ϲ���һ��Ԫ��value����ĳ�����1
	bool delete(int p); 				// ɾ��λ��p�ϵ�Ԫ�أ���ĳ��ȼ� 1
	int getPos(const T value);			// ����ֵΪvalue��Ԫ�أ������ص�1�γ��ֵ�λ��
	Link<T> setPos(int p);				// �������Ա�ָ���p��Ԫ�ص�ָ��ֵ
} 

template <class T>
class lnkList:: lnkList() {
		head = tail = new Link<T>;
}

template <class T>
class lnkList:: ~lnkList() {
		Link tmp;
        while (head != NULL) { 
 		      tmp = head;
			  head = head->next;
			  delete tmp;
		}
}

template <class T>  			// �ٶ����Ա��Ԫ������ΪT
Link lnkList :: setPos(int i) {
	int count = 0;
    Link *p;
	if (i == -1) 				// iΪ-1��λ��"��"ͷ���
		return head;
    p = head->next;			// ��iΪ0��λ����һ����� 
	while (p != NULL && count < i) {
 	p = p-> next;
  	count++;
    };
    return p;         		// ָ��� i ��㣬i��0,1,�����������н����С��iʱ����NULL
}
template  <class T>  			 	// �ٶ����Ա��Ԫ������ΪT
bool lnkList :: insert (int i, T value)  {
     Link *p, *q;
     q = new Link<T>;
     p = setPos(i-1);					// p�ǵ�i������ǰ��
     if (p == NULL )	{ 
		cout << " the inserted point is illegal"<<endl;
		return false;
     }
	 q->next = p->next;
	 q->data = value;
	 p->next = q;
     if (q->next == NULL )				// ���������β���������Ϊ�µ���β
        tail = q;
	return true;
}
// delete a node from singly linked list
template  <class T>  			// �ٶ����Ա��Ԫ������ΪT
bool lnkList :: delete(int i)  {
     Link *p, *q;
     p = setPos(i-1);				// p�ǵ�i������ǰ��
    if (p == NULL )	{ 
		cout << " the deletion point is illegal"<<endl;
		return false;
     }
     q = p->next;					// q��������ɾ���
	 if (q == tail)					// ��ɾ���Ϊβ��㣬���޸�βָ��
			tail = p;
	if (q != NULL)  {			//  ɾ�����q ���޸���ָ�� 
		p->next = q->next;
		delete q;
    }
    return true;
}
 
template <class T>  			    // �ٶ�˳����Ԫ������ΪT
void lnkList<T> :: print()  {
        while (head != NULL) { 
 	    	cout << head->data; 
            cout << endl;  	 		// ��λ��p��ʼÿ��Ԫ������ֱ��curLen,      tmp = head;
			head = head->next;
		}
}
