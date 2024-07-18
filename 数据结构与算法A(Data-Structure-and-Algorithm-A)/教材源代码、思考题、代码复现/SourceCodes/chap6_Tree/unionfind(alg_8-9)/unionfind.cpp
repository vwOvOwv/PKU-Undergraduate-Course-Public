#include <iostream>
#include "ParTreeNode.h"
#include "ParTree.h"
using namespace std;
#define  N 10                              // ��������

char strInfo[N] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};  //�����Ϣ����

// �������ܣ������ַ���Ϣ��������������е�λ���±�
int GetNum(char ch)  {
	for (int i = 0; i < N; i ++)
		if (ch == strInfo[i])
			return i;
	return -1;
}

// �������ܣ���ʾ�����ڸ�ָ���ʾ���еĸ�����±�
void Display(ParTree<char> &aParTree)  {
	for (int i = 0; i < N; i ++)  {
		if (aParTree.array[i].getParent() == NULL)            //�����û�и�������*��ʾ
		cout << "*" << " ";
		else  {
			char ch = aParTree.array[i].getParent()->getValue(); //����и����ʹ�ӡ�����еĸ������±�
			cout << GetNum(ch) << " ";
		}
	}
	cout << endl;
}


#define PATHCOMPRESSION   1  // 0-����ѹ��
                             // 1-��ѹ��

void main()  {
	ParTree<char> aParTree(N);
	cout << "* means that the node has no parents!\n" ;

	for (int i = 0; i < N; i++)
		cout << i << " ";
	cout << endl;
	int i;
	for (i = 0; i < N; i++)  {
		aParTree.array[i].setValue(strInfo[i]);
		cout << strInfo[i] << " ";
	}
	cout << endl;

	cout << "Union: (A,B),(C,D),(E,F),(G,H),(I,J)\n" ;
	aParTree.Union(GetNum('A'), GetNum('B')); 
	aParTree.Union(GetNum('C'), GetNum('D'));
	aParTree.Union(GetNum('E'), GetNum('F'));
	aParTree.Union(GetNum('G'), GetNum('H'));
	aParTree.Union(GetNum('I'), GetNum('J'));
	Display(aParTree);                             //��ʾ�����ڸ�ָ���ʾ���еĸ�����±�

	cout << "\nUnion: (A,D),(I,H)\n";
	aParTree.Union(GetNum('A'), GetNum('D'));
	aParTree.Union(GetNum('I'), GetNum('H'));
	Display(aParTree);								//��ʾ�����ڸ�ָ���ʾ���еĸ�����±�
 
	#if !PATHCOMPRESSION 
	// 0.����ѹ��
		cout << "\nUnion: (F,J)\n" ;
		aParTree.Union(GetNum('F'), GetNum('J'));
		Display(aParTree);								//��ʾ�����ڸ�ָ���ʾ���еĸ�����±�
		cout << "Union: (D,J)\n";
		aParTree.Union(GetNum('D'), GetNum('J'));
		Display(aParTree);								//��ʾ�����ڸ�ָ���ʾ���еĸ�����±�

	#else
	// 1.��ѹ�� 
		cout << "\nUnion: (F,J)\n";
		aParTree.UnionPC(GetNum('F'), GetNum('J'));
		Display(aParTree);								//��ʾ�����ڸ�ָ���ʾ���еĸ�����±�
		cout << "\nUnion: (D,J)\n";
		aParTree.UnionPC(GetNum('D'), GetNum('J'));
		Display(aParTree);								//��ʾ�����ڸ�ָ���ʾ���еĸ�����±�
	#endif

	if (aParTree.Different(GetNum('D'), GetNum('E')))
		cout << "D and E are in different sets!!!" << endl;
	else
		cout << "D and E are in a common set!!!" << endl;
	cout << endl;
} 

