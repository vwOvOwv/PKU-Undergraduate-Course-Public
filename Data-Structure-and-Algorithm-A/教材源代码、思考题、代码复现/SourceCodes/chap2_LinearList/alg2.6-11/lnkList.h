#include <cstdlib>
#include <iostream>

#include "myList.h" 

using namespace std;

template <class T> 
class Link {
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
};

// ������2.7�� ����������Ͷ���
template <class T> 
class lnkList: public List<T>  {
private: 
	Link<T>*  head;                    // �������ͷָ��
    Link<T>*  tail;    				// �������βָ��
	Link<T>* setPos(int p);				// �������Ա�ָ���p��Ԫ�ص�ָ��ֵ     
public: 
	lnkList(int);						// ���캯��
	~lnkList();						// ��������
    bool isEmpty(); 					// �ж������Ƿ�Ϊ��
    void clear(); 					 // ������洢�������������Ϊ�ձ�
	int length();                   	          // ���ش�˳���ĵ�ǰʵ�ʳ���
    bool append(T value);				   // �ڱ�β���һ��Ԫ��value����ĳ�����1
	bool insert(int p, T value);			// ��λ��p�ϲ���һ��Ԫ��value����ĳ�����1
	bool del(int p); 				     // ɾ��λ��p�ϵ�Ԫ�أ���ĳ��ȼ� 1
    bool getValue(int p, T value);	       // ����λ��p��Ԫ��ֵ 
	bool getPos(int p, const T value);	// ����ֵΪvalue��Ԫ�أ������ص�1�γ��ֵ�λ��
	void print();
};

template <class T> 
lnkList<T>::lnkList(int defSize){
		head = tail = new Link<T>(9999,NULL);
}

template <class T>
lnkList<T>::~lnkList(){
		Link<T> *tmp;
		head = head->next;
        while (head != NULL) { 
 		      tmp = head;
			  head = head->next;
			  delete tmp;
		}
}

template <class T>  			// �ٶ����Ա��Ԫ������ΪT
Link<T>* lnkList<T> :: setPos(int i) {
        Link<T> *p;
        int count = 0;
        if (i == -1) 			       // iΪ-1��λ��"��"ͷ���
		   return head;
        
        p = new Link<T>(head->next);      // ��iΪ0��λ����һ�����     
        
	    while (p != NULL && count < i) {
 	           p = p-> next;
  	           count++;
        };
        return p;         		// ָ��� i ��㣬i��0,1,�����������н����С��iʱ����NULL
}
     

template  <class T>  			 		// ���Ա��Ԫ������ΪT
bool lnkList<T> :: insert(int i, T value)  {
     Link<T> *p, *q;
					
     if ((p = setPos(i-1)) == NULL){ 		// p�ǵ�i������ǰ��
		cout << " the insertion point is illegal"<<endl;
		return false;
    }
    q = new Link<T>(value, p->next);
    p->next = q;
    if (p == tail)						// ���������β���������Ϊ�µ���β
		tail = q;

    return true;
}

// delete a node from singly linked list
template  <class T>  					// ���Ա��Ԫ������ΪT
bool lnkList<T>:: del(int i)  {
     Link<T> *p, *q; 
	 if  ((p = setPos(i-1)) == NULL )	{ 		// ��ɾ��㲻���ڣ���������i���ڵ�ǰ����Ԫ�ظ���
		cout << " the deletion point is illegal"<<endl;
		return false;
	}
    q = p->next;							// q��������ɾ���
    if (q == tail) {						// ��ɾ���Ϊβ��㣬���޸�βָ��
		  tail = p;
		  delete q;
    }
    if (q != NULL)  {						// ɾ�����q ���޸���ָ��
    	p->next = q->next;
	    delete q;
     }
     return true;
}
 
template <class T>  			    // �ٶ�˳����Ԫ������ΪT
void lnkList<T> :: print() {
       	Link<T> *tmp = head;
       	cout << "begin\n" ;
        while (tmp != NULL) { 
 	    	cout << tmp->data <<" ";
      	    tmp = tmp->next;
		}
		cout << "\n";
		cout << "end\n";
}
