#include <iostream>
#include <string> 
#include "myList.h"
 
using namespace std;

template  <class T>  			// �ٶ�˳����Ԫ������ΪT
class arrList : public List<T>  {		// ˳�������
private:    					// ���Ա��ȡֵ���ͺ�ȡֵ�ռ�
	int  maxSize;            	// ˽�б�����˳���ʵ������󳤶�
    int  curLen; 		    		// ˽�б�����˳���ʵ���ĵ�ǰ����
    int  position;				// ˽�б�������ǰ����λ��
   	T  *aList ;            		// ˽�б������洢˳����ʵ��
public: 						// ˳�������㼯
	arrList(const int size) {  		// ����һ���µ�˳�������Ϊ��ʵ������󳤶�
		maxSize = size;
		aList = new T[maxSize];
		curLen = position = 0;
	}
	~arrList() {					// �������������������ñ�ʵ��
		delete [] aList;
	} 
	void clear() {      			// ��˳���洢�������������Ϊ�ձ�
		delete [] aList;
		curLen = position = 0;
		aList = new T[maxSize];
	}
	int length();            		// ���ش�˳���ĵ�ǰʵ�ʳ���
    bool append(T value);			// �ڱ�β���һ��Ԫ��value����ĳ�����1
	bool insert(int p, T value);	 	// ��λ��p�ϲ���һ��Ԫ��value����ĳ�����1
	bool del(int p); 			// ɾ��λ��p�ϵ�Ԫ�أ���ĳ��ȼ� 1
	int getPos(const T value);		// �����Ա��в���ֵΪvalue��Ԫ�أ������ص�1�γ��ֵ�λ��
	void print();                     // ��ӡ���Ա� 
}; 

template <class T>  					// �ٶ�˳����Ԫ������ΪT 
int arrList<T> :: getPos (const T value) {
		int i;     						// Ԫ���±�
		for (i = 0; i < curLen; i++)  {				// ���αȽ�
	        if (value == aList[i])			// �±�Ϊi��Ԫ����value���
               return i;				// �����±�i
		}
		return -1;						// ˳���û��Ԫ��ֵΪvalue��Ԫ��
}

// ��Ԫ�ص�����ΪT�� aList�Ǵ洢˳�������飬 maxSize������󳤶ȣ�
// pΪ��Ԫ��value�Ĳ���λ��,
// ����ɹ��򷵻�true, ���򷵻�false
template <class T>  			      		// �ٶ�˳����Ԫ������ΪT
bool arrList<T> :: insert(int p, const T value)  {
		int i;
		if (curLen >= maxSize)  { 		  		// ���˳����Ƿ����
  	       cout << "The list is overflow"<<endl;
	       return false;
		}
		if (p < 0 || p > curLen)  {		  		// ������λ���Ƿ�Ϸ�
            cout << "Insertion is illegal" <<endl;
	        return false;
		}
		for (i = curLen; i > p; i--)
	         aList[i] = aList[i-1];   	 	 	// �ӱ�βcurLen -1�������ƶ�ֱ��p
		aList[p] = value;          		 	// λ��p��������Ԫ��
        curLen++;               		 	// ���ʵ�ʳ�����1 
        return true; 
}


template <class T>  			    // �ٶ�˳����Ԫ������ΪT
bool arrList<T> :: del(int p)  {
	int i;
    if (curLen <= 0 )  { 				// ���˳����Ƿ�Ϊ��
       cout << " No element to delete \n"<<endl;
       return false ;
	}
    if (p < 0 || p > curLen-1)  {			// ���ɾ��λ���Ƿ�Ϸ�
       cout << "deletion is illegal\n"<<endl;
       return false ;
    }
    for (i = p; i < curLen-1; i++)
        aList[i] = aList[i+1];   	 		// ��λ��p��ʼÿ��Ԫ������ֱ��curLen,
    curLen--;               			// ���ʵ�ʳ��ȼ�1
	return true;
}

template <class T>  			    // �ٶ�˳����Ԫ������ΪT
void arrList<T> :: print()  {
	 for (int i = 0; i < curLen; i++)
        cout << aList[i]; 
     cout << endl;  	 		// ��λ��p��ʼÿ��Ԫ������ֱ��curLen,
}

