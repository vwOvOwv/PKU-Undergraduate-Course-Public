/****************  ??5.12 ????????????  **********************/
/****************           MinHeap.h           **********************/

#include <iostream>
using namespace std;

#define FALSE 0
#define TRUE 1

template <class T>
class MinHeap  { 							//??��??????
private:
	T* heapArray;							//?????????????
	int CurrentSize;						//?????????????
	int MaxSize;							//????????????????????
	void swap(int pos_x, int pos_y);		//????��??x??y?????
	void BuildHeap();						//????
public:
	MinHeap(const int n);				 //??????,n????????????????????
	virtual ~MinHeap(){delete []heapArray;}; 	//????????
	bool isEmpty( );							// ????????????
    bool isLeaf(int pos) const;		 	    //?????????????TRUE
	int leftchild(int pos) const;		   	//????????��??
	int rightchild(int pos) const;			//?????????��??
	int parent(int pos) const;				//????????��??
	bool Remove(int pos, T& node);			//????????��?????
	bool Insert(const T& newNode);			//????��????????newNode
	T& RemoveMin();				        	//?????????��?
	void SiftUp(int position);			 //??position????????????????��????
	void SiftDown(int left);             //??????????????left?????????????????��?
};
template<class T>
MinHeap<T>::MinHeap(const int n)  {
	if(n <= 0)
		return;
	CurrentSize = 0;													
	MaxSize = n;						//????????????n
	heapArray = new T[MaxSize];		    //????????

	//??????��???????????
	heapArray[0] = 19;                 //??????��?????????
	heapArray[1] = 8;
	heapArray[2] = 35;
	heapArray[3] = 65;
	heapArray[4] = 40;
	heapArray[5] = 3;
	heapArray[6] = 7;
	heapArray[7] = 45;
	CurrentSize = 8;

	BuildHeap();
}

template<class T>
bool MinHeap<T>::isEmpty()  {			// ????????????{
	return ((CurrentSize)?false:true);
}

template<class T>
bool MinHeap<T>::isLeaf(int pos) const  {
	return (pos >= CurrentSize/2) && (pos < CurrentSize);
}

template<class T>
void MinHeap<T>::BuildHeap()  {
	for (int i = CurrentSize/2-1; i >= 0; i--) 	//??????????????
		SiftDown(i);
}

template<class T>
int MinHeap<T>::leftchild(int pos) const  {
	return 2*pos + 1;						//????????��??
}

template<class T>
int MinHeap<T>::rightchild(int pos) const  {
	return 2*pos + 2;						  //?????????��??
}

template<class T>
int MinHeap<T>::parent(int pos) const  {
	return (pos-1)/2;						   //????????��??
}

template <class T>
bool MinHeap<T>::Insert(const T& newNode)  {  //????��????????newNode
	if(CurrentSize == MaxSize)				   //?????????
		return FALSE;
	heapArray[CurrentSize] = newNode;
	SiftUp(CurrentSize);					   //???????
	CurrentSize++;
	return TRUE;
}

template<class T>
void MinHeap<T>::SiftUp(int position)  {    //??position????????????????��????
	int temppos = position;
	T temp = heapArray[temppos];
	while ((temppos>0) && (heapArray[parent(temppos)]>temp))  {
		heapArray[temppos] = heapArray[parent(temppos)];
		temppos = parent(temppos);
	}
	heapArray[temppos] = temp;
}

template<class T>
void MinHeap<T>::swap(int pos_x, int pos_y)     //????��??x??y?????
{
 T temp = heapArray[pos_x];
 heapArray[pos_x] = heapArray[pos_y];
 heapArray[pos_y] = temp;
}

template<class T>
T& MinHeap<T>::RemoveMin()	 {				//?????????��?
	if (CurrentSize == 0)  {
		cout<< "Can't Delete" <<endl;
	}
	else  {
		swap(0,--CurrentSize);					//??????????????????
		if(CurrentSize>1)
			SiftDown(0);						//?????????
		return heapArray[CurrentSize];
	}
}

template<class T>
bool MinHeap<T>::Remove(int pos, T& node)  {   	// ????????��?????
	if ((pos < 0) || (pos >= CurrentSize))
		return false;
	node = heapArray[pos];
	heapArray[pos] = heapArray[--CurrentSize];		// ????????????????��??????
    	if (heapArray[parent(pos)] > heapArray[pos]) 	
		SiftUp(pos);						// ??????��?????????????????
	else SiftDown(pos);						// ??????????????????
	return true;
}


template <class T>
void MinHeap<T>::SiftDown(int left)  {
	int i = left;								// ????????
	int j = leftchild (i);							// ?????????��??????
	T	temp = heapArray[i];					// ???��???
	while (j < CurrentSize) {       			    // ???
		if ((j < CurrentSize-1) && (heapArray[j]>heapArray[j + 1]))
			j++;								// j?????????
		if (temp>heapArray[j]) {
			heapArray[i] = heapArray[j];
			i = j;
			j = leftchild(j);						// ???????
		}
		else break;
	}
	heapArray[i] = temp;
}
