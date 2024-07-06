#include <iostream>
#include <queue>
using namespace std;                                     

#define N 10                             // �������

template <class T> class Tree;           //��������


// ����˫��ǡ��Ĵ�������
template <class T>
class DualTagWidthTreeNode  {
public:
	T info;                   //�������Ϣ
	int ltag;				  //����
	int rtag;                 //�ұ��
	
	DualTagWidthTreeNode() {};               //���캯��
	virtual ~DualTagWidthTreeNode() {};      //��������
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
	Tree(DualTagWidthTreeNode<T> *nodeArray, int count); //��˫����ȸ��������㷨 
	TreeNode<T> *getRoot() {return root;};          //�������еĸ����
	void Visit(T Value) {cout << Value;};           //����
	void RootFirstTraverse(TreeNode<T> *root);      //�ȸ��������Σ���Ϊ����ʹ��
};

// �������ܣ���˫��ǲ�δ������㷨 
template <class T>
Tree<T>::Tree(DualTagWidthTreeNode<T>* nodeArray, int count)  {
	//�ɴ�˫���λ�Ĳ�δ����ʾ�����������ֵܷ�ʽ��ʾ����
	using std::queue;                                 //ʹ��STL����
	queue<TreeNode<T>*> aQueue;
	//׼�����������
	TreeNode<T>* pointer=new TreeNode<T>;
	root=pointer;
	//����һ�����
	for(int i=0;i<count-1;i++) {
		pointer->setValue(nodeArray[i].info);
		if(nodeArray[i].ltag==0)
			aQueue.push(pointer);					   //��������
		else
			pointer->setChild(NULL);				   //������Ϊ��
		TreeNode<T>* temppointer=new TreeNode<T>;
		if(nodeArray[i].rtag == 0)
			pointer->setSibling(temppointer);
		else {
			pointer->setSibling(NULL);					//���ֵ���Ϊ��
			pointer=aQueue.front();                     //ȡ�����׽��ָ��
			aQueue.pop();                            //����Ԫ�س�����
			pointer->setChild(temppointer);
		}
		pointer=temppointer;
	}
	//�������һ�����
	pointer->setValue(nodeArray[count-1].info);
	pointer->setChild(NULL);
	pointer->setSibling(NULL);
}

// �������ܣ��ȸ���ȱ���
template <class T>
void Tree<T>::RootFirstTraverse(TreeNode<T> *root)  {
	while (root != NULL)   {
		Visit(root->Value());
		RootFirstTraverse(root->LeftMostChild());
		root = root->RightSibling();
	}
}

// �������ܣ���������������ֻ�о�һ�֣��ȸ�����
void Traverse(Tree<char> *tree)  {
	cout << "FirstRoot traverse:  ";
	tree->RootFirstTraverse(tree->getRoot()); // �ȸ������������
	cout << endl;
}


// �������ܣ���ʾɭ�ֽṹ.ͼ6.5(a)��ʾ��ɭ��
void DisplayTree()  {
	cout << "      A              G      \n";
	cout << "   /  |  \\         /   \\   \n";
	cout << "  B   C    D      H     I   \n";
	cout << "     / \\          |         \n";
	cout << "    E   F         J         \n";
	cout << "\n";
	cout << "rtag =  0  have right sibling" << endl;
	cout << "rtag =  1  havn't right sibling" << endl;
	cout << "ltag =  0  have left child" << endl;
	cout << "ltag =  1  havn't left child" << endl << endl;
}

// �������ܣ���ʾɭ�ֽṹ�Ĵ�˫��ǲ�δ����ʾ 
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


void main()  {
	// ��ʾɭ�ֽṹ
	DisplayTree();
	
	// ��˫��ǲ�δ������㷨��ͼ6.5(a)��ʾ��ɭ�ֵĴ�˫���λ�Ĳ�δ����ʾΪ��
	char strInfo[N] = {'A', 'G', 'B', 'C', 'D', 'H', 'I', 'E', 'F', 'J'};
	int nRtag[N] = {0, 1, 0, 0, 1, 0, 1, 0, 1, 1}; 
	int nLtag[N] = {0, 0, 1, 0, 1, 0, 1, 1, 1, 1}; 
	
	cout << "Dualtag_Width create tree." << endl;       //��ӡ��˫���λ�Ĳ�δ����ʾ 
	DisplayNode(strInfo, nRtag, nLtag);
	
	DualTagWidthTreeNode<char> *nodeArray = new DualTagWidthTreeNode<char>[N];
	
	for (int i = 0; i < N; i ++)  {                //���ô�˫���λ�Ĳ�δ������� 
		nodeArray[i].info = strInfo[i];
		nodeArray[i].rtag = nRtag[i];
		nodeArray[i].ltag = nLtag[i];
	}
	
	Tree<char> aTree(nodeArray, N); // ����
	Traverse(&aTree);               // ������
}
