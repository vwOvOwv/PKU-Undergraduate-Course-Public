

template <class T>
class MaxHeap  
{
private:
	T* heapArray;							//��Ŷ����ݵ�����
	int CurrentSize;						//��ǰ����Ԫ����Ŀ
	int MaxSize;							//���������ɵ����Ԫ����Ŀ
public:
	MaxHeap(T* array,int num,int max);
	virtual ~MaxHeap(){};					//��������
	void BuildHeap();
	bool isLeaf(int pos) const;				//�����Ҷ��㣬����TRUE
	int leftchild(int pos) const;			//��������λ��
	int rightchild(int pos) const;			//�����Һ���λ��
	int parent(int pos) const;				//���ظ����λ��
	bool Remove(int pos, T& node);			//ɾ�������±��Ԫ��
	void SiftDown(int left);				//ɸѡ������������left��ʾ��ʼ����������±�
	void SiftUp(int position);			 	//��position���Ͽ�ʼ������ʹ���г�Ϊ��
	bool Insert(const T& newNode);			//����в�����Ԫ��newNode
	void MoveMax();							//�ӶѶ��ƶ����ֵ��β��
	T& RemoveMax();							//�ӶѶ�ɾ�����ֵ
};

template<class T>
MaxHeap<T>::MaxHeap(T* array,int num,int max)
{
	heapArray=array;
	CurrentSize=num;
	MaxSize=max;
	BuildHeap();
}

template<class T>
void MaxHeap<T>::BuildHeap()
{
	for (int i=CurrentSize/2-1; i>=0; i--) 
		SiftDown(i); 
}

template<class T>
bool MaxHeap<T>::isLeaf(int pos) const
{
		return (pos>=CurrentSize/2)&&(pos<CurrentSize);
}

template<class T>
int MaxHeap<T>::leftchild(int pos) const
{
	return 2*pos+1;						//��������λ��
}

template<class T>
int MaxHeap<T>::rightchild(int pos) const
{
	return 2*pos+2;						//�����Һ���λ��
}

template<class T>
int MaxHeap<T>::parent(int pos) const	//���ظ��ڵ�λ��
{
	return (pos-1)/2;
}

template<class T>
void MaxHeap<T>::SiftDown(int left)
{
	//׼��
	int i=left;							//��ʶ�����
	int j=2*i+1;						//��ʶ�ؼ�ֵ��С���ӽ��		
	T	temp=heapArray[i];				//���游���
	//��ɸ
	while(j<CurrentSize)
	{
		if((j<CurrentSize)&&(heapArray[j]<heapArray[j+1]))
			j++;						//jָ�����ӽ��
		if(temp<heapArray[j])
		{
			heapArray[i]=heapArray[j];
			i=j;
			j=2*j+1;					//���¼���
		}
		else break;
	}
	heapArray[i]=temp;
}

template<class T>
void MaxHeap<T>::SiftUp(int position) 
{//��position���Ͽ�ʼ������ʹ���г�Ϊ��
	int temppos=position;
	T temp=heapArray[temppos];
	int parentpos=0;
	if(temppos>0)
		parentpos=parent(temppos);
	while((temppos>0)&&(heapArray[parentpos]<temp))
	{
		heapArray[temppos]=heapArray[parentpos];
		temppos=parentpos;
		parentpos=parent(temppos);
	}
	heapArray[temppos]=temp;
}

template<class T>
bool MaxHeap<T>::Insert(const T& newNode)
{//����в���һ�����
	if(CurrentSize==MaxSize)				//�ѿռ��Ѿ���
		return false;
	heapArray[CurrentSize]=newNode;
	SiftUp(CurrentSize);					//���ϵ���
	CurrentSize++;
}

template<class T>
T& MaxHeap<T>::RemoveMax()
{
	if(CurrentSize==0)
	{
		//AfxMessageBox("Can't Delete");

	}
	else
	{
		T temp=heapArray[0];					//ȡ�Ѷ�Ԫ��
		heapArray[0]=heapArray[CurrentSize-1];	//��ĩԪ���������Ѷ�
		CurrentSize--;
		SiftDown(0);							//�ӶѶ���ʼɸѡ
		return temp;
	}
}

template<class T>
void MaxHeap<T>::MoveMax()
{
	if(CurrentSize==0)
	{
		//��Ϊ��
		return;
	}
	else
	{
		T temp=heapArray[0];					//ȡ�Ѷ�Ԫ��
		heapArray[0]=heapArray[CurrentSize-1];	//��ĩԪ���������Ѷ�
		CurrentSize--;
		SiftDown(0);							//�ӶѶ���ʼɸѡ
		heapArray[CurrentSize]=temp;
	}
	return;
}

template<class T>
bool MaxHeap<T>::Remove(int pos, T& node)
{// ɾ�������±��Ԫ��
	if((pos<0)||(pos>CurrentSize))
		return false;
	heapArray[pos]=heapArray[--CurrentSize];	//ָ��Ԫ���������
	SiftUp(pos);								//����ɸ
	SiftDown(pos);								//����ɸ	
	node=heapArray[CurrentSize];
	return true;
}

