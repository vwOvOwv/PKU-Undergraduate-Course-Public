//*******  BinarySearchTree.h  ******//

//#include "BinaryTreeNode.h"
#include "BinaryTree.h"


template <class T>
class BinarySearchTree:public BinaryTree<T>  {
public:
	BinarySearchTree(){this->root=NULL;};
	virtual ~BinarySearchTree(){};
	void Initialize(BinaryTreeNode<T> *newpointer);
	BinaryTreeNode<T>* Root() {return this->root;};
	
	void InsertNode(BinaryTreeNode<T>* root,BinaryTreeNode<T>* newpointer);
	void DeleteNode(BinaryTreeNode<T>* pointer);
	void DeleteNodeEx(BinaryTreeNode<T>* pointer);
};


//*********  implemention ***********//

template <class T>
void BinarySearchTree<T>::Initialize(BinaryTreeNode<T> *newpointer)
{
	this->root = newpointer;
}

template<class T>
void BinarySearchTree<T>::InsertNode(BinaryTreeNode<T>* root , BinaryTreeNode<T>* newpointer)  {                          //����������������½��
	BinaryTreeNode<T>* pointer = NULL;
	if(root == NULL)  {                 //����ǿ�������ʼ��
		Initialize(newpointer);	        //��ָ��newpointer��ʼ��������������������ֵʵ��
		return;
	}
	else 
		pointer = root;
	while(1)  {
		if (newpointer->value() == pointer->value())
			return ;					  //������ò���
		else if (newpointer->value() < pointer->value())  {
			if(pointer->leftchild() == NULL)  {
				pointer->left = newpointer;		//��Ϊ������
				return;
			}
			else	pointer = pointer->leftchild();
		}
		else  {
			if(pointer->rightchild() == NULL)  {
				pointer->right = newpointer;      //��Ϊ������
				return;
			}
			else	pointer = pointer->rightchild();
		}
	}//endwhile
}

/*
template<class T>
void BinarySearchTree<T>::DeleteNode(BinaryTreeNode<T>* pointer)  {      //�̲���д������㷨
	//�����������н���ɾ��
	BinaryTreeNode<T>* temppointer = NULL;
	if(!pointer)                            //���ɾ�����ǿս�㣬�򷵻�
		return;
	BinaryTreeNode<T>* parent = Parent(pointer);
	if (pointer->leftchild() == NULL)  {
		//��ɾ������������������������ĸ������ɾ�����
		if (parent == NULL)                 //��ɾ������Ǹ����
			root = pointer->rightchild();
		else if (parent->leftchild() == pointer)
			parent->left = pointer->rightchild();
		else
			parent->right = pointer->rightchild();
		delete pointer;                     //ɾ���ý��
		pointer = NULL;
		return;
	}
	else                                 //��������Ϊ��ʱ
		temppointer = pointer->leftchild();
	while (temppointer->rightchild() != NULL)  //�����������ҶԳ�������һ�����
		temppointer = temppointer->rightchild();
	//��ɾ��������������Ϊtemppointer��������
	temppointer->right = pointer->rightchild();
	//��ɾ�����������������汻ɾ�����
	if(NULL == parent)
		root = pointer->leftchild();
	else if (parent->leftchild() == pointer)
		parent->left = pointer->leftchild();
	else 
		parent->right = pointer->leftchild();
	delete pointer;                          //ɾ���ý��
	pointer = NULL;
	return;
}
*/

template <class T>
void BinarySearchTree<T>::DeleteNodeEx(BinaryTreeNode<T>* pointer)  {
	if ( pointer == NULL )                    // ����ɾ����㲻���ڣ�����
		return;
	BinaryTreeNode<T> * temppointer;         // ���ڱ����滻���
	BinaryTreeNode<T> * tempparent = NULL;  // ���ڱ����滻���ĸ����
	BinaryTreeNode<T> * parent = Parent(pointer ); // ����ɾ�����ĸ����
	// �����ɾ������������Ϊ�գ��ͽ�����������������
	if ( pointer->leftchild() == NULL )  
       temppointer = pointer->rightchild();
    else {
		// ����ɾ�������������Ϊ�գ�������������Ѱ��������滻��ɾ�����
		temppointer = pointer->leftchild();
		while (temppointer->rightchild() != NULL )  {
			tempparent = temppointer;
			temppointer = temppointer->rightchild();
		}
		// ɾ���滻���
		if (tempparent == NULL)
			pointer->left = temppointer->leftchild();
		else tempparent->right = temppointer->leftchild();
		temppointer->left = pointer->leftchild();    // �̳�pointer��������
		temppointer->right = pointer->rightchild();  // �̳�pointer��������
	}
	// ���滻���ȥ���������ɾ�����
	if (parent == NULL)
		this->root = temppointer;
	else if ( parent->leftchild() == pointer )
	    parent->left = temppointer;
	else parent->right = temppointer;
	delete pointer;                         	// ɾ���ý��
	pointer = NULL;
	return;
}



