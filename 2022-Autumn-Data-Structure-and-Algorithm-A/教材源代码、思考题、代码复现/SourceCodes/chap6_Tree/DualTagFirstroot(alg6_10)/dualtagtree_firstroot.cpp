#include <iostream>
#include <stack>
//#include "TreeNode.h"

using namespace std;                                     

#define N 10                             //�������

template <class T> class Tree;           //��������


// ����˫��ǡ����ȸ����� �����
template <class T>
class DualTagTreeNode  {
public:
	T info;                   //�������Ϣ
	int ltag;				   //����
	int rtag;                 //�ұ��

	DualTagTreeNode() {};               //���캯��
	virtual ~DualTagTreeNode() {};      //��������
};

// ��������ADT
template <class T>
class TreeNode  {
friend class Tree<T>;
private:
	T m_Value;								//������ֵ
	TreeNode<T>*	pChild;					//���ӽ��
	TreeNode<T>*	pSibling;				//���ֵܽ��
public:
	TreeNode() {};                
	TreeNode(const T &value) {m_Value = value; pChild = NULL; pSibling = NULL;};
	T Value() {return m_Value;};                     // ��ý�����Ϣ
	TreeNode<T> *LeftMostChild() {return pChild;};   // ���ص�һ��������
	TreeNode<T> *RightSibling() {return pSibling;};  // ���ص�һ�����ֵ�
	void setValue(T &value) {m_Value = value;};      //���ý���ֵ
	void setChild(TreeNode<T> *pointer) {pChild = pointer;};   //��������
	void setSibling(TreeNode<T> *pointer) {pSibling = pointer;};  //�����Һ���
};

// ����ADT��ֻд������صı���������
template <class T>
class Tree  {
private:
	TreeNode<T> *root;                                  
	TreeNode<T> *getParent(TreeNode<T> *root, TreeNode<T> *current);
public:
	Tree() {root = NULL;};
	Tree(DualTagTreeNode<T> *nodeArray, int count); //��˫����ȸ��������㷨 
	TreeNode<T> *getRoot() {return root;};          //�������еĸ����
	void Visit(T Value) {cout << Value;};           //����
	void RootFirstTraverse(TreeNode<T> *root);      //�ȸ��������Σ���Ϊ����ʹ��
};

// �������ܣ���˫����ȸ��������㷨 
template <class T>
Tree<T>::Tree(DualTagTreeNode<T>* nodeArray, int count)  {
//���ô�˫���λ���ȸ������ʾ���������������ֵܷ�ʽ��ʾ����
	//ʹ��STL�е�stack
	using std::stack;
	stack<TreeNode<T>* > aStack;
	//׼�����������
	TreeNode<T>* pointer = new TreeNode<T>;
	root=pointer;
	//����һ�����
	for(int i = 0;i < count-1;i++) {
		pointer->setValue(nodeArray[i].info);
		if(nodeArray[i].rtag == 0)
			aStack.push(pointer);						//�����ѹջ
		else
			pointer->setSibling(NULL);					//���ֵ���Ϊ��
		TreeNode<T>* temppointer = new TreeNode<T>;
		if(nodeArray[i].ltag == 0)
			pointer->setChild(temppointer);
		else {
			pointer->setChild(NULL);					//������Ϊ��
			pointer = aStack.top();
  			aStack.pop();		
			pointer->setSibling(temppointer);
		}
		pointer = temppointer;
	}
	//�������һ�����
	pointer->setValue(nodeArray[count-1].info);
	pointer->setChild(NULL);
	pointer->setSibling(NULL);
}

// �������ܣ��ȸ���ȱ���
template <class T>
void Tree<T>::RootFirstTraverse(TreeNode<T> *root)  {
	while (root != NULL)  {
		Visit(root->Value());
		RootFirstTraverse(root->LeftMostChild());
		root = root->RightSibling();
	}
}

// �������ܣ���ʾɭ�ֽṹ.ͼ6.5(a)��ʾ��ɭ��
void DisplayTree()  {
	cout << "      A              G      \n";
	cout << "   /  |  \\         /   \\   \n";
	cout << "  B   C    D      H     I   \n";
	cout << "     / \\          |         \n";
	cout << "    E   F         J         \n";
	cout << endl;
	 
	cout << "rtag =  0 , there is    a right sibling" << endl;
	cout << "rtag =  1 , there isn't a right sibling" << endl;
	cout << "ltag =  0 , there is    a left child" << endl;
	cout << "ltag =  1 , there isn't a left child" << endl << endl;
}

// �������ܣ���ʾɭ�ֽṹ�Ĵ�˫����ȸ������ʾ 
void DisplayNode(char *Info, int *nRtag, int *nLtag)  {
	if (Info != NULL)  {
		cout << "info   ";
		for (int i = 0; i < N; i ++)
			cout << Info[i] << " ";
		cout << endl;
	}
 
	if (nRtag != NULL)  {
		cout << "rtag   ";
		for (int i = 0; i < N; i ++)
			cout << nRtag[i] << " ";
		cout << endl;
	}

	if (nLtag != NULL)  {
		cout << "ltag   ";
		for (int i = 0; i < N; i ++)
			cout << nLtag[i] << " ";
		cout << endl;
	}
}

// �������ܣ���������������ֻ�о�һ�֣��ȸ�����
void Traverse(Tree<char> *tree)  {
	cout << "FirstRoot traverse:  ";
	tree->RootFirstTraverse(tree->getRoot()); // �ȸ������������
	cout << endl;
}

void main()  {
	// ��ʾɭ�ֽṹ
	DisplayTree();
	
	// ��˫����ȸ��������㷨��ͼ6.5(a)��ʾ��ɭ�ֵĴ�˫���λ���ȸ������ʾΪ��
	char strInfo[N] = {'A', 'B', 'C', 'E', 'F', 'D', 'G', 'H', 'J', 'I'};
	int nRtag[N] = {0, 0, 0, 0, 1, 1, 1, 0, 1, 1}; 
	int nLtag[N] = {0, 1, 0, 1, 1, 1, 0, 0, 1, 1}; 
	
	cout << "Dualtag_FirstRoot create tree." << endl;       //��ӡ��˫���λ���ȸ������ʾ 
	DisplayNode(strInfo, nRtag, nLtag);
	 
	DualTagTreeNode<char> *nodeArray = new DualTagTreeNode<char>[N];
	
	for (int i = 0; i < N; i ++)  {                //���ô�˫���λ���ȸ��������� 
		nodeArray[i].info = strInfo[i];
		nodeArray[i].rtag = nRtag[i];
		nodeArray[i].ltag = nLtag[i];
	}

	Tree<char> aTree(nodeArray, N); // ����
	Traverse(&aTree);               // ������
}
