#include <iostream>
#include "LoserTree.h"
using namespace std;
#define MAX 8 // ѡ����

void main()
{
	int A[MAX + 1] =  {0, 10, 9, 6, 20, 12, 8, 15, 16}; //���±�1��ʼ
	LoserTree<int> aLosTree(MAX);
	
	// ���ѡ����Ϣ
	cout << "Players numbers: " << MAX << endl;
	cout << "Players valus  : ";
	for (int i = 1; i <= MAX; i ++)
		cout << A[i] << " ";
	cout << endl << endl;
	
	// ��ʼ��
	aLosTree.Initialize(A, MAX, winner, loser);
	cout << "The loser tree is" << endl;
	aLosTree.Output();
	
	// ѡ��3��ʤ����Ϊ11����
	A[3] = 11;
	aLosTree.RePlay(3, winner, loser);
	cout << "Changed player 3 to 11, new tree is" << endl;
	aLosTree.Output();
}
