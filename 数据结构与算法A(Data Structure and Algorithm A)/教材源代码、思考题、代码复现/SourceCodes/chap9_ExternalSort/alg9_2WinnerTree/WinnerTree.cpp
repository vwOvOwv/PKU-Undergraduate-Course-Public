#include <iostream>
#include "WinnerTree.h"
using namespace std;
//��9.3.3.1С����ʾ��
void main(void)  {
	int A[MAX + 1] =  {0, 10, 9, 6, 20, 12, 8, 15,16};  //�����±��1��ʼ
	WinnerTree<int> aWinTree; // ���ѡ����Ϣ
	cout << "Players numbers: " << MAX << endl;
	cout << "Players valus  : ";
	for (int i = 1; i <= MAX; i ++)
		cout << A[i] << " ";
	cout << endl << endl;
	
	// ��ʼ��
	aWinTree.Initialize(A, MAX, winner);
	cout << "winner tree is" << endl;
	aWinTree.Output();
	
	// ѡ��3��ʤ����Ϊ11����
	A[3] = 11;
	aWinTree.RePlay(3, winner);
	cout << "Changed player 3 to 11, new tree is" << endl;
	aWinTree.Output();
}