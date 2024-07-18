//��ParTree���������Ķ���
template<class T>
class ParTree  {								//������
public:
	ParTreeNode<T>* array;						//�洢����������
	int	Size;									//�����С
	ParTree(const int size);					//���캯��
	virtual ~ParTree();							//��������
	ParTreeNode<T> *Find(ParTreeNode<T>* node)const;//����node���ĸ����
	ParTreeNode<T> *FindPC(ParTreeNode<T> *node) const; // ��ѹ��

	void Union(int i,int j);					//���±�Ϊi��j�Ľ��ϲ���һ������
	void UnionPC(int i, int j);                 //��ѹ��
	bool Different(int i,int j);				//�ж��±�Ϊi��j�Ľ���Ƿ���һ������
};

//���ĳ�Ա������ʵ��
template <class T>
ParTree<T>::ParTree(const int size)  {			//���캯��
	Size = size;
	array = new ParTreeNode<T>[size];
}

template <class T>											
ParTree<T>::~ParTree()  {						//���캯��
	delete []array;
}

// �������ܣ��ҵ�Ŀ����ĸ����
template <class T>
ParTreeNode<T>*	ParTree<T>::Find(ParTreeNode<T>* node) const  {
	ParTreeNode<T>* pointer = node;
	while(pointer->getParent() != NULL)
		pointer = pointer->getParent();
	return pointer;
}

//�������ܣ���·��ѹ����Find�㷨
template <class T>
ParTreeNode<T> *ParTree<T>::FindPC(ParTreeNode<T> *node) const  {
	if (node->getParent() == NULL)
	return node;

	node->setParent(FindPC(node->getParent()));
	return node->getParent();
}

//�������ܣ��ж��±�Ϊi��j�Ľ���Ƿ���һ������
template<class T>
bool ParTree<T>::Different(int i,int j)  {
	ParTreeNode<T>* pointeri = Find(&array[i]);		//�ҵ����i�ĸ�
	ParTreeNode<T>* pointerj = Find(&array[j]);		//�ҵ����j�ĸ�
	return pointeri != pointerj;
}

//���±�Ϊi��j�Ľ��ϲ���һ������
template<class T>
void ParTree<T>::Union(int i,int j)  {
	ParTreeNode<T>* pointeri = Find(&array[i]);		//�ҵ����i�ĸ�
	ParTreeNode<T>* pointerj = Find(&array[j]);		//�ҵ����j�ĸ�
	if(pointeri != pointerj) {
		if(pointeri->getCount()>=pointerj->getCount()) {
			pointerj->setParent(pointeri);
			pointeri->setCount(pointeri->getCount()+pointerj->getCount());
		}
		else {
			pointeri->setParent(pointerj);
			pointerj->setCount(pointeri->getCount()+pointerj->getCount());
		}
	}
}

// �������ܣ��鲢�������ϣ� ��ѹ��
template <class T>
void ParTree<T>::UnionPC(int i, int j)  {
	ParTreeNode<T> *pointeri = FindPC(&array[i]);
	ParTreeNode<T> *pointerj = FindPC(&array[j]);
 
	if (pointeri != pointerj)  {
		if (pointeri->getCount() >= pointerj->getCount())  {
			pointerj->setParent(pointeri);
			pointeri->setCount(pointeri->getCount() + pointerj->getCount());
		}
		else  {
			pointeri->setParent(pointerj);
			pointerj->setCount(pointeri->getCount() + pointerj->getCount());
		}
	}
}