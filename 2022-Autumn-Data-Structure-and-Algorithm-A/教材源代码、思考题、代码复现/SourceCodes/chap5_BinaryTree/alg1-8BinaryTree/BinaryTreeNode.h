/*  BinaryTreeNode.h  */


template <class T> class BinaryTree;

template <class T>
class BinaryTreeNode {
friend class BinaryTree<T>;	//����������Ϊ��������Ԫ�࣬���ڷ���˽�����ݳ�Ա
private:
	T  info;				     	    	//���������������
	BinaryTreeNode<T>* left;		   		//���������ָ����������ָ��
	BinaryTreeNode<T>* right;    			//���������ָ����������ָ��

public:
	BinaryTreeNode();							//ȱʡ���캯��
	BinaryTreeNode(const T& inf);	 			//�������ݵĹ��캯��
	BinaryTreeNode(const T& inf,BinaryTreeNode<T>* l, BinaryTreeNode<T>* r);//�����˽��ֵ�����������Ĺ��캯��
	T  value() const;							//���ص�ǰ��������
	BinaryTreeNode<T>*  leftchild() const;		//���ص�ǰ���������
	BinaryTreeNode<T>*  rightchild() const;		//���ص�ǰ���������
	void  setLeftchild(BinaryTreeNode<T>*) ;	//���õ�ǰ����������
	void  setRightchild(BinaryTreeNode<T>*) ;	//���õ�ǰ����������
	void  setValue(const T& val); 				//���õ�ǰ����������
	bool  isLeaf() const;				//�ж���ǰ����Ƿ�ΪҶ���,���Ƿ���true
	BinaryTreeNode<T>& operator = (const BinaryTreeNode<T>& Node){this = Node;};//���ظ�ֵ������
};


//****** BinaryTreeNode Implementation *******//

template<class T>
BinaryTreeNode<T>::BinaryTreeNode()  {
	left = right = NULL;
}

template<class T>
BinaryTreeNode<T>::BinaryTreeNode(const T& inf)  {	//�������ݵĹ��캯��
	info = inf;
	left = right = NULL;
}

template<class T>
BinaryTreeNode<T>::BinaryTreeNode(const T& inf,BinaryTreeNode* l, BinaryTreeNode* r)  {//�������ݵ�����ָ��Ĺ��캯��
	info = inf;
	left = l;
	right = r;
}

template<class T>
T  BinaryTreeNode<T>::value() const  {
	return info; 
}	

template<class T>
BinaryTreeNode<T>*  BinaryTreeNode<T>::leftchild() const  { //���ص�ǰ���ָ����������ָ��
	return left;
}												

template<class T>
BinaryTreeNode<T>*  BinaryTreeNode<T>::rightchild() const  { //���ص�ǰ���ָ����������ָ��
	return right;								
}			

template<class T>
void  BinaryTreeNode<T>::setLeftchild(BinaryTreeNode<T>* subroot)  { //���õ�ǰ����������
	left = subroot;
}

template<class T>
void  BinaryTreeNode<T>::setRightchild(BinaryTreeNode<T>* subroot)  { //���õ�ǰ����������
	right = subroot;
}

template<class T>
void  BinaryTreeNode<T>::setValue(const T& val)  {	//���õ�ǰ����������
	info = val; 
} 									

template<class T>
bool  BinaryTreeNode<T>::isLeaf() const	 {	//�ж���ǰ����Ƿ�ΪҶ���,���Ƿ���true
	return (left == NULL) && (right == NULL); 
}



