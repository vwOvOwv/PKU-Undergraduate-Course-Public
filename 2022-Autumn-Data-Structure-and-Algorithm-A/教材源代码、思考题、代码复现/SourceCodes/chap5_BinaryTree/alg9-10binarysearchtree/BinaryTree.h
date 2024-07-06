//************BinaryTree.h****************//

#include <stack>
#include <queue>
#include "BinaryTreeNode.h"

enum Tags{Left,Right};    //ö������

template <class T>
class StackElement  {         //StackElement
public:
	BinaryTreeNode<T>* pointer;
	Tags tag;
};	

using namespace std;

template <class T>
class BinaryTree {
protected:
	BinaryTreeNode<T>*  root;      			//�����������
public:
	BinaryTree(){root = NULL;};				//���캯��
	~BinaryTree() {DeleteBinaryTree(root);};	//��������
	bool isEmpty() const;						//�ж��������Ƿ�Ϊ����
	BinaryTreeNode<T>* Root(){return root;};	//���ض����������
	BinaryTreeNode<T>* Parent(BinaryTreeNode<T>* current);//����current�ĸ����
	BinaryTreeNode<T>* LeftSibling(BinaryTreeNode<T>* current);
	//����current�������ֵ�
	BinaryTreeNode<T>* RightSibling(BinaryTreeNode<T>* current);
	//����current�������ֵ�
	void CreateTree(const T& info, BinaryTree<T>& leftTree, BinaryTree<T>& rightTree);
	//����һ����infoΪ����leftTree��rightTreeΪ�����������¶�����
	void PreOrder(BinaryTreeNode<T>* root);  	//ǰ�����ζ�������������
	void InOrder(BinaryTreeNode<T>* root);		//�������ζ�������������
	void PostOrder(BinaryTreeNode<T>* root);	//�������ζ�������������
	void PreOrderWithoutRecursion(BinaryTreeNode<T>* root);//�ǵݹ�ǰ�����ζ�������������
	void InOrderWithoutRecursion(BinaryTreeNode<T>* root);//�ǵݹ��������ζ�������������
	void PostOrderWithoutRecursion(BinaryTreeNode<T>* root);//�ǵݹ�������ζ�������������
	void LevelOrder(BinaryTreeNode<T>* root); 	//��������ζ�������������
	void DeleteBinaryTree(BinaryTreeNode<T>* root);	//ɾ����������������
	void Visit(T Value) {cout << Value<< ", ";};           //����
};


//**********  BianryTree Implementation  ***********//

template<class T>
bool BinaryTree<T>:: isEmpty() const  {      //�ж��������Ƿ�Ϊ����
	return ( root? false : true);
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::Parent(BinaryTreeNode<T>* current)  {
	using std::stack;						//ʹ��STL�е�stack
	stack<BinaryTreeNode<T>* > aStack;
	BinaryTreeNode<T>* pointer = root;      	//�����������	
	if(NULL != root && NULL != current)  {		
		while(!aStack.empty() || pointer)	{
			if (pointer)  {
				if(current == pointer->leftchild() ||current == pointer->rightchild()) //�����ǰpointer�ĺ��Ӿ���current������parent
					return pointer;
				aStack.push(pointer);				//��ǰ����ַ��ջ
				pointer = pointer->leftchild();		//��ǰ���ӽṹָ������
			}
			else  {                         //������������ϣ�ת�����������
				pointer = aStack.top();			//ջ��Ԫ����ջ                 
				aStack.pop();
				pointer = pointer->rightchild();  	//��ǰ���ӽṹָ���Һ���
			}//endif
		} //endwhile
	}//endif
}


template<class T>
BinaryTreeNode<T>* BinaryTree<T>::LeftSibling(BinaryTreeNode<T>* current)  {
	//����current�������ֵ�
	if(current)  {
		BinaryTreeNode<T>* temp = Parent(current);    //����current���ĸ����
		if ((temp == NULL) || current == temp->leftchild())
			return  NULL;	  //��������Ϊ�գ�����currentû�����ֵܣ����ؿ�
		else return temp->leftchild();
	}
	return NULL;
}

template<class T>
BinaryTreeNode<T>* BinaryTree<T>::RightSibling(BinaryTreeNode<T>* current)  {
	//����current�������ֵ�
	if(current)  {
		BinaryTreeNode<T>* temp = Parent(current);//����current���ĸ����
		if(temp == NULL||current == temp->rightchild())
			return  NULL;		    //��������Ϊ�գ�����currentû�����ֵ�
		else return temp->rightchild();
	}
	return NULL;
}

template<class T>
void BinaryTree<T>:: CreateTree (const T& info, BinaryTree<T>& leftTree, BinaryTree<T>& rightTree)  {
	//��������leftTree��������rightTree������Ԫ��info����һ���������������info
	//����this��leftTree��rightTree�����ǲ�ͬ��������
	root = new BinaryTreeNode<T>(info, leftTree.root, rightTree.root);	//��������
	leftTree.root = rightTree.root = NULL;  //ԭ�����������ĸ����ָ�գ��������
}

template<class T>
void BinaryTree<T>:: DeleteBinaryTree(BinaryTreeNode<T>* root)  { //�Ժ������εķ�ʽɾ��������
	if(root)  {
		DeleteBinaryTree(root->left);				//�ݹ�ɾ��������
		DeleteBinaryTree(root->right);		    //�ݹ�ɾ��������
		delete root;							//ɾ�������
	}
}

template<class T>
void BinaryTree<T>::PreOrder (BinaryTreeNode<T>* root)  {  //ǰ�����ζ�����
	if(root != NULL)  {
		Visit(root->value());						//���ʵ�ǰ���
		PreOrder(root->leftchild());			//����������
		PreOrder(root->rightchild());			//����������
	}
}
template<class T>
void BinaryTree<T>:: InOrder (BinaryTreeNode<T>* root)  {  //�������ζ�����
	if(root != NULL)  {
		InOrder (root->leftchild());			//����������
		Visit(root->value());						//���ʵ�ǰ���
		InOrder (root->rightchild());			//����������
	}
}
template<class T>
void BinaryTree<T>:: PostOrder (BinaryTreeNode<T>* root)  { //�������ζ�����
	if(root != NULL)  {
		PostOrder(root->leftchild());			//����������
		PostOrder (root->rightchild());		//����������
		Visit(root->value());						//���ʵ�ǰ���
	}
}

template<class T>
void BinaryTree<T>::PreOrderWithoutRecursion(BinaryTreeNode<T>* root)  {//�ǵݹ�ǰ�����ζ�������������
	using std::stack;						//ʹ��STL�е�stack
	stack<BinaryTreeNode<T>* > aStack;
	BinaryTreeNode<T>* pointer = root;      	//�����������	
	while(!aStack.empty() || pointer)	{
		if (pointer)  {
			Visit(pointer->value());			//���ʵ�ǰ���
			aStack.push(pointer);				//��ǰ����ַ��ջ
			pointer = pointer->leftchild();		//��ǰ���ӽṹָ������
		}
		else  {                         //������������ϣ�ת�����������
			pointer = aStack.top();			//ջ��Ԫ����ջ                 
			aStack.pop();
			pointer = pointer->rightchild();  	//��ǰ���ӽṹָ���Һ���
		}//endif
    } //endwhile
}

template<class T>
void BinaryTree<T>::InOrderWithoutRecursion(BinaryTreeNode<T>* root)  {
	//�ǵݹ��������ζ�������������
	using std::stack;							//ʹ��STL�е�stack
	stack<BinaryTreeNode<T>* > aStack;
	BinaryTreeNode<T>* pointer = root;      	//�����������	
	while(!aStack.empty() || pointer)  {
		if (pointer)  {
			aStack.push(pointer);				//��ǰ����ַ��ջ
			pointer = pointer->leftchild();		//��ǰ���ӽṹָ������
		}
		else  {                            //������������ϣ�ת�����������
			pointer = aStack.top();
			aStack.pop();					//ջ��Ԫ����ջ 
			Visit(pointer->value());		//���ʵ�ǰ���
			pointer = pointer->rightchild(); 	//��ǰ���ӽṹָ���Һ���
                
		}
	} //endwhile
}

template<class T>
void BinaryTree<T>::PostOrderWithoutRecursion(BinaryTreeNode<T>* root)  {
	//�ǵݹ�������ζ�������������
	using std::stack;							//ʹ��STLջ����
	StackElement<T> element;
	stack<StackElement<T > > aStack;			//ջ����
	BinaryTreeNode<T>* pointer;
	if(root == NULL)
		return;							//����������
	else pointer = root;						//�����������
	while (true)  {                        //����������			
		while(pointer != NULL) 	{
			element.pointer = pointer;
			element.tag = Left;
			aStack.push(element);
			pointer = pointer->leftchild();		//��������������������
		}	
		element = aStack.top();
		aStack.pop();                         //�г�ջ��Ԫ��
		pointer = element.pointer;
		while(element.tag == Right)  {           //������������
			Visit(pointer->value());		    //���ʵ�ǰ���
			if (aStack.empty())
				return;
			else  {
				element = aStack.top();
				aStack.pop();				//����ջ��Ԫ��
				pointer = element.pointer;
			}
		}
		//������������
		element.tag = Right;
		aStack.push(element);
		pointer = pointer->rightchild();				//ת�����������
	}
}

template<class T>
void BinaryTree<T>::LevelOrder(BinaryTreeNode<T>* root)	{
	//��������ζ�������������
	using std::queue;							//ʹ��STL�Ķ���
	queue<BinaryTreeNode<T>*> aQueue;
	BinaryTreeNode<T>* pointer = root;			//�����������
	if (pointer)
		aQueue.push(pointer);                  //����������
	while (!aQueue.empty())  {                 //���зǿ�
		pointer = aQueue.front();			 	//ȡ�����׽��
		aQueue.pop();                        //��ǰ��������
        Visit(pointer->value());					//���ʵ�ǰ���
		if(pointer->leftchild())
			aQueue.push(pointer->leftchild());		//������������
		if(pointer->rightchild())
			aQueue.push(pointer->rightchild());	//������������
	}
}