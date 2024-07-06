#include <iostream>
#include "BinarySearchTree.h"

#define N 11

void main()  {
	int K[N] = {50,19,35,55,20,5,100,52,88,53,92};        //��һ��ͼ5.11��ʾ����
	BinarySearchTree<int> aBST;
	BinaryTreeNode<int > *newpointer, *node1, *node2;     // ѭ��������
	
	for (int i = 0; i < N; i ++)  {                       
		newpointer = new BinaryTreeNode<int>();
		newpointer->setValue(K[i]);
		aBST.InsertNode(aBST.Root(), newpointer);      //���β�����
		
		if (K[i] == 52){                                //��¼��ɾ������ָ��node1
			node1 = newpointer;
			//	 cout<<node1->value()<<endl;
		}
		if (K[i] == 55)                                 //��¼��ɾ������ָ��node2
			node2 = newpointer; 
	}
	
	// �������
	cout << "�������ζ�����������" << endl;
	aBST.InOrder(aBST.Root());
	cout << endl; 
	
	// ɾ���������                          //�̲���û������㷨             
	//  cout << "ɾ�����52, 55." << endl;
	//	BST.DeleteNode(node1);
	//	aBST.DeleteNode(node2); 
	
	// ɾ���������ĸĽ��㷨
	cout << "ɾ�����52, 55." << endl;
	aBST.DeleteNodeEx(node1);
	aBST.DeleteNodeEx(node2);
	
	// �����ڵ�
	cout << "ɾ�����֮���������ζ�����������" << endl;	
	aBST.InOrder(aBST.Root());
	cout << endl;

}