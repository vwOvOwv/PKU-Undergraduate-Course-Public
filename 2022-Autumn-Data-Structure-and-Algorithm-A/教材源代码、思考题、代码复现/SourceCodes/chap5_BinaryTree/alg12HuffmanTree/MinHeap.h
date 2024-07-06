/****************  �㷨5.12 �ѵ��ඨ���ɸѡ��  **********************/
/****************           MinHeap.h           **********************/
#include <iostream>
using namespace std;
#define FALSE 0
#define TRUE 1

template <class T>
class MinHeap  { 							//��С���ඨ��
private:
	T* heapArray;							//��Ŷ����ݵ�����
	int CurrentSize;						//��ǰ����Ԫ����Ŀ
	int MaxSize;							//���������ɵ����Ԫ����Ŀ
	void swap(int pos_x, int pos_y);		//����λ��x��y��Ԫ��
	void BuildHeap();						//����
public:
	MinHeap(const int n);				 //���캯��,n��ʾ��ʼ���ѵ����Ԫ����Ŀ
	virtual ~MinHeap(){delete []heapArray;}; 	//��������
    bool isLeaf(int pos) const;		 	    //�����Ҷ��㣬����TRUE
	int leftchild(int pos) const;		   	//��������λ��
	int rightchild(int pos) const;			//�����Һ���λ��
	int parent(int pos) const;				//���ظ����λ��
	bool Remove(int pos, T& node);			//ɾ�������±��Ԫ��
	bool Insert(const T& newNode);			//����в�����Ԫ��newNode
	T& RemoveMin();				        	//�ӶѶ�ɾ����Сֵ
	void SiftUp(int position);			 //��position���Ͽ�ʼ������ʹ���г�Ϊ��
	void SiftDown(int left);             //ɸѡ������������left��ʾ��ʼ����������±�
};
template<class T>
MinHeap<T>::MinHeap(const int n)  {
	if(n <= 0)
		return;
	CurrentSize = 0;													
	MaxSize = n;							//��ʼ��������Ϊn
	heapArray = new T[MaxSize];		    //�����ѿռ�
	//�˴����ж�Ԫ�صĸ�ֵ����
	BuildHeap();
}
template<class T>
bool MinHeap<T>::isLeaf(int pos) const  {
	return (pos >= CurrentSize/2) && (pos < CurrentSize);
}

template<class T>
void MinHeap<T>::BuildHeap()  {
	for (int i = CurrentSize/2-1; i >= 0; i--) 	//��������ɸѡ����
		SiftDown(i);
}

template<class T>
int MinHeap<T>::leftchild(int pos) const  {
	return 2*pos + 1;						//��������λ��
}

template<class T>
int MinHeap<T>::rightchild(int pos) const  {
	return 2*pos + 2;						  //�����Һ���λ��
}

template<class T>
int MinHeap<T>::parent(int pos) const  {
	return (pos-1)/2;						   //���ظ����λ��
}

template <class T>
bool MinHeap<T>::Insert(const T& newNode)  {  //����в�����Ԫ��newNode
	if(CurrentSize == MaxSize)				   //�ѿռ��Ѿ���
		return FALSE;
	heapArray[CurrentSize] = newNode;
	SiftUp(CurrentSize);					   //���ϵ���
	CurrentSize++;
	return TRUE;
}

template<class T>
void MinHeap<T>::SiftUp(int position)  {    //��position���Ͽ�ʼ������ʹ���г�Ϊ��
	int temppos = position;
	T temp = heapArray[temppos];
	while ((temppos>0) && (heapArray[parent(temppos)]>temp))  {
		heapArray[temppos] = heapArray[parent(temppos)];
		temppos = parent(temppos);
	}
	heapArray[temppos] = temp;
}

template<class T>
void MinHeap<T>::swap(int pos_x, int pos_y)     //����λ��x��y��Ԫ��
{
 T temp = heapArray[pos_x];
 heapArray[pos_x] = heapArray[pos_y];
 heapArray[pos_y] = temp;
}

template<class T>
T& MinHeap<T>::RemoveMin()	 {				//�ӶѶ�ɾ����Сֵ
	if (CurrentSize == 0)  {
		cout<< "Can't Delete" <<endl;
//		exit(0);
	}
	else  {
		swap(0,--CurrentSize);					//�����Ѷ������һ��Ԫ��
		if(CurrentSize>1)
			SiftDown(0);						//�ӶѶ���ʼɸѡ
		return heapArray[CurrentSize];
	}
}

template<class T>
bool MinHeap<T>::Remove(int pos, T& node)  {    // ɾ�������±��Ԫ��
	if((pos < 0) || (pos >= CurrentSize))
		return false;
	T temp = heapArray[pos];
	heapArray[pos] = heapArray[--CurrentSize];		//ָ��Ԫ���������
	SiftUp(pos);								//��������
	SiftDown(pos);							//���µ���
	node = temp;
	return true;
}

template <class T>
void MinHeap<T>::SiftDown(int left)  {
	int i = left;						//��ʶ�����
	int j = leftchild (i);					//��ʶ�ؼ�ֵ��С���ӽ��
	T	temp = heapArray[i];			//���游���
	while (j < CurrentSize)  		{   	//��ɸ
		if((j < CurrentSize-1) && (heapArray[j]>heapArray[j + 1]))
			j++;						//jָ�����ӽ��
		if (temp>heapArray[j])  {
			heapArray[i] = heapArray[j];
			i = j;
			j = leftchild(j);				//���¼���
		}
		else break;
	}
	heapArray[i] = temp;
}
