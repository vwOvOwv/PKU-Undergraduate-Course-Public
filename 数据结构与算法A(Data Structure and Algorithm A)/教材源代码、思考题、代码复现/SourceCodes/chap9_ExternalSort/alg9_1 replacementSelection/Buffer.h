/***************  Buffer.h  *****************/
#include <iostream>
#include <stdio.h>
using namespace std;
#define BUFFER_SIZE  100  // ��������С

template <class T>
class Buffer  {
public:
	T *L;        // ������
	int nLen;    // �����С
	int nCurr;   // ��ǰָ�룬��ʼ��Ϊ0
public:
	Buffer() {L = NULL; nLen = 0; nCurr = 0;};  //���캯��
	bool isEmpty();                             //�շ�
	bool isFull();                              //����
	
	void insert(T e);						    //��������
	void read(T &e);                            
	void flush(FILE *fp);                       //��������д�ص��ļ�
};

template <class T>
bool Buffer<T>::isEmpty()  {  //�շ�
	if (nCurr == nLen)
		return true; 
	return false;
}

template <class T>
bool Buffer<T>::isFull()  {   //����
	if (nLen == BUFFER_SIZE) 
		return true; 
	return false;
}

template <class T>
void Buffer<T>::insert(T e)  {  //��������
	if (nLen < BUFFER_SIZE)
		L[nLen++] = e;
// 	cout<<"buffer insert!"<<endl;
}

template <class T>
void Buffer<T>::read(T &e)  {     //��������
	e = L[nCurr++];
//	cout<< "Buffer read out."<<endl;
}

template <class T>
void Buffer<T>::flush(FILE *fp)  {  //��������д�ص��ļ�
	fwrite(L, sizeof(T), nLen, fp); 
	nLen = 0;
	nCurr = 0;
}

template <class T>
void fillBuffer(FILE *fp, Buffer<T> b)  {    //�������
	b.nLen = fread(b.L, sizeof(T), BUFFER_SIZE, fp);
	b.nCurr = 0;
}

