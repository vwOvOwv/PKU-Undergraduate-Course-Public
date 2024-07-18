#include <iostream>
#include <queue>

#include "TreeNode.h"
#include "Tree.h"

using namespace std;


// �������ܣ���������������ֻ�о�һ�֣��ȸ�����
void Traverse(Tree<char> *tree)
{
	cout << "FirstRoot traverse:  ";
	tree->RootFirstTraverse(tree->getRoot()); // �ȸ������������
	cout << endl;
	
	cout << "LastRoot  traverse:  ";
	tree->RootLastTraverse(tree->getRoot()); // ������
	cout << endl;
	
	cout << "Width traverse    :  ";
	tree->WidthTraverse(tree->getRoot()); // ��ȱ���
	cout << endl << endl;
}


int main()  {
	//����
	Tree<char> aTree;
	aTree.CreateRoot('A');
	TreeNode<char> *f = new TreeNode<char>('F');
	TreeNode<char> *e = new TreeNode<char>('E');
	TreeNode<char> *d = new TreeNode<char>('D');
	TreeNode<char> *c = new TreeNode<char>('C');
	TreeNode<char> *b = new TreeNode<char>('B');
	e->setSibling(f);
	c->setSibling(d);
	c->setChild(e);
	b->setSibling(c);
	aTree.getRoot()->setChild(b);

	TreeNode<char> *x = new TreeNode<char>('X');
	TreeNode<char> *y = new TreeNode<char>('Y');
	TreeNode<char> *z = new TreeNode<char>('Z');
	aTree.getRoot()->setSibling(x);
	x->setChild(y);
	y->setSibling(z);

	
	//��ʾ���Ľṹ
	cout << "      A            X        \n";
    cout << "   /  |  \\      /   \\     \n";
    cout << "  B   C    D    Y     Z     \n";
    cout << "    /   \\                  \n";
    cout << "   E     F                  \n";
    cout << "\n";
	
	//�ж����Ƿ�Ϊ��
	aTree.isEmpty();
	
	//������
	cout << "��������\n";
	Traverse(&aTree);
	
	
	//e�������һ������G
	cout << "e�������һ������G�Ľ����\n";
	TreeNode<char> *g = new TreeNode<char>('G');
	e->InsertFirst(g);
	//������
	Traverse(&aTree);
	
	//e����Ե�һ���ֵܵ���ݲ���H
	cout << "e����Ե�һ���ֵܵ���ݲ���H�Ľ��:\n";
	TreeNode<char> *h = new TreeNode<char>('H');
	e->InsertNext(h);
	//������
	Traverse(&aTree);
	
	//���C�ĸ����
	cout << "���C�ĸ���㣺 ";
	aTree.Visit(aTree.Parent(c)->Value());
	cout << endl;
	//���H����һ���ֵܽ��
	cout << "���H����һ���ֵܽ�㣺 ";
	aTree.Visit(aTree.PrevSibling(h)->Value());
	cout << endl;
//	aTree.Visit(aTree.PrevSibling(e)->Value());
//	cout << endl;
	
	//�󸸽��
	cout<<"E�ĸ���㣺";
	aTree.Visit(aTree.Parent(e)->Value());
	cout<<endl;
	cout<<"D�ĸ���㣺";
	aTree.Visit(aTree.Parent(d)->Value());	
	cout<<endl;
	cout<<"F�ĸ���㣺";
	aTree.Visit(aTree.Parent(f)->Value());
	cout<<endl;

	cout<<"Z�ĸ���㣺";
	aTree.Visit(aTree.Parent(z)->Value());
	cout<<endl;

	cout<<"X�ĸ���㣺";
	if (aTree.Parent(x) == NULL)
		cout<< "Parent is NULL!" << endl;

	//ɾ����ΪE������
	cout << "ɾ��E������" << endl;
	aTree.DeleteSubTree(e);
	Traverse(&aTree);

	//ɾ����ΪC������
	cout << "ɾ��C������" << endl;
	aTree.DeleteSubTree(c);
	Traverse(&aTree);
	return 0;
}