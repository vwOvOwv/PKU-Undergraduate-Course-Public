//#include <queue>
#include <iostream>
using namespace std;

template  <class T>
class Tree  {
private:
	TreeNode<T>* root;                         //�������
	void DestroyNodes(TreeNode<T>*root);       //ɾ����rootΪ��������
public:
	Tree();										//���캯��
	virtual ~Tree();							//��������
	TreeNode<T>* getRoot();						//�������еĸ����
	void CreateRoot(const T& rootValue);     //�������еĸ���㣬ʹ�����Ԫ�ص�ֵΪrootValue
	bool isEmpty();							 //�ж��Ƿ�Ϊ������������򷵻�true
	TreeNode<T>* Parent(TreeNode<T>* current);	    //����current���ĸ����
	TreeNode<T>* PrevSibling(TreeNode<T>* current); //����current����ǰһ���ھӽ��
	void DeleteSubTree(TreeNode<T>* subroot);	    //ɾ����subrootΪ�������������н��
    void RootFirstTraverse(TreeNode<T>* root);		//�ȸ��������������
	void RootLastTraverse(TreeNode<T>* root);		//����������������
	void WidthTraverse(TreeNode<T>* root);			//�������������
	void Visit(T Value) {							//����
		cout << Value;
	};           
};

template <class T>
Tree<T>::Tree()	 {							//���캯��
	root=NULL;
}
template <class T>
Tree<T>::~Tree()  {							//��������
	while(root)
		DeleteSubTree(root);
}

template <class T>
TreeNode<T>* Tree<T>::getRoot()  {			//�������еĸ����
	return root;
}
template <class T>
void Tree<T>::CreateRoot(const T& rootValue)  {//�������еĸ���㣬ʹ�����Ԫ�ص�ֵΪrootValue
	if(!root)
		root=new TreeNode<T>(rootValue);
}
template <class T>
bool Tree<T>::isEmpty()  {		 //�ж��Ƿ�Ϊ������������򷵻�true
	if(root)
		return false;
	return true;
}
template <class T>
TreeNode<T>* Tree<T>::PrevSibling(TreeNode<T>* current)  {//����current����ǰһ���ھӽ��
	using std::queue;								//ʹ��STL����
	queue<TreeNode<T>*> aQueue;
	TreeNode<T>* pointer=root;						//��ʶ��ǰ���
	TreeNode<T>* prev=NULL;						//��ʶ��ǰ����ǰһ���ֵܽ��
	//��ǰ���Ϊ�գ���Ϊ�ջ�������Ϊ�����ʱ������NULL	
	if((current==NULL)||(pointer==NULL)||(current==root))
		return NULL;								
	while(pointer)  {
		if(pointer==current)
			return prev;							//�ҵ���ǰ���
		aQueue.push(pointer);
		prev=pointer;
		pointer=pointer->pSibling;					//�ص�ǰ������ֵܽ����Ѱ��
	}
	while(!aQueue.empty())  {
		prev=NULL;
		pointer=aQueue.front();				 		
		aQueue.pop();								//������
		pointer=pointer->LeftMostChild();			//�½������ӽ��
		while(pointer)  {
			if(pointer==current)
				return prev;
			aQueue.push(pointer);
			prev=pointer;
			pointer=pointer->pSibling;				//�ص�ǰ������ֵܽ����Ѱ��
		}//end while
	}//end while
	return NULL;
}

template  <class T>
TreeNode<T>* Tree<T>::Parent(TreeNode<T>* current)  {
	using std::queue;                          		// ʹ��STL����
	queue<TreeNode<T>*> aQueue;
	TreeNode<T>* pointer = root;
	TreeNode<T>* upperlevelpointer = NULL;     		// ���ڼ�¼parent���
	if (current != NULL && pointer != current) {
		while (pointer) {                       		// ɭ�������и���������
			if (current == pointer)
				return NULL;    				// ���ĸ����ָ��Ϊ�գ�����
			aQueue.push(pointer);
			pointer=pointer-> RightSibling();
		}
		while (!aQueue.empty()) {
			pointer = aQueue.front();            		// ȡ�����׽��ָ��
			aQueue.pop();                    		// ������	
			upperlevelpointer = pointer;		    		// ָ����һ��Ľ��
			pointer = pointer-> LeftMostChild();  		// ָ��ǰ����������
			while (pointer) {                  		// ��ǰ�����ӽ�������
				if (current == pointer)
					return upperlevelpointer;    	// ���ظ����ָ��
				else {
					aQueue.push(pointer);
					pointer = pointer->RightSibling();
				}
			}//end while
		}//end while
	}//end if
	return NULL;
}



template  <class T>
void Tree<T>::DestroyNodes(TreeNode<T>* root)  {
	//ɾ����rootΪ�������������н��
	if (root) {
		DestroyNodes(root->LeftMostChild());	//�ݹ�ɾ����һ����
		DestroyNodes(root->RightSibling());		//�ݹ�ɾ����������
		delete root;							//ɾ�������
	}
}


template  <class T>
void Tree<T>::DeleteSubTree(TreeNode<T>* subroot)  {
	// ɾ����subrootΪ�������������н��
	if (subroot == NULL) return;
	TreeNode<T>* pointer = Parent (subroot); 	// ��subroot�ĸ����
	if (pointer == NULL) 							// subroot����ɭ�ֵ�һ������
		root = subroot->RightSibling();
	else if (pointer-> LeftMostChild() == subroot) 		// subrootΪ�����ӽ������
		pointer->setChild(subroot->RightSibling());
	else {									// subroot�����ֵ�
		pointer = pointer-> LeftMostChild();		// �½��������ֵ�
		while (pointer-> RightSibling() != subroot) 	// ˳�����ҵ�ֱ�����ֵ�
			pointer = pointer ->RightSibling();
		pointer->setSibling(subroot->RightSibling());
	}
	subroot->setSibling(NULL);
	DestroyNodes(subroot);
}



//������ȡ���������㷨
template  <class T>
void Tree<T>::RootFirstTraverse(TreeNode<T>* root)  { 	//�ȸ��������������
	while (NULL != root) {
		Visit(root->Value());					  //���ʵ�ǰ���
		RootFirstTraverse(root->LeftMostChild());   //����ͷһ��������������
		root = root->RightSibling();			      //������������
	}
}

template  <class T>
void Tree<T>::RootLastTraverse(TreeNode<T>* root)  { 	//����������������
	while (NULL != root) {
		RootLastTraverse(root->LeftMostChild());  //����ͷһ��������������
		Visit(root->Value());					//���ʵ�ǰ���
		root = root->RightSibling();			    //������������
	}
}

template  <class T>
void Tree<T>::WidthTraverse(TreeNode<T>* root)  {  // �������������
    using std::queue;                             // ʹ��STL����
    queue<TreeNode<T>*> aQueue;
	TreeNode<T>* pointer = root;				// ����Ϊ��ǰ���
    while (pointer)  {
        aQueue.push(pointer);                  // ��ǰ���������
        pointer = pointer->RightSibling();         // ָ��ǰ�������ֵ�
	}//end while
	while (!aQueue.empty()) {
        pointer = aQueue.front();                // ȡ�����׽��ָ��
        aQueue.pop();                         // ������
        Visit(pointer->Value());                 // ���ʵ�ǰ���
        pointer = pointer-> LeftMostChild();       // ָ��ǰ����������
        while (pointer) {                       // ��ǰ�����ӽ�������
            aQueue.push(pointer);
            pointer = pointer->RightSibling();
        }
	}//end while
}
