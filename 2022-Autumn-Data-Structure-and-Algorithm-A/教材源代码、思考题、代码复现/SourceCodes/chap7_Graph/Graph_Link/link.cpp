// ͼ���ڽӱ��ʾ����
#include <iostream>
#include <queue>

#include "Graph.h"
#include "Graphl.h"
using namespace std;
#define N 5 // ����ͼ�Ķ�����

int A[N][N] = {
	//        V0 V1 V2 V3 V4 
	/*V0*/    0, 0, 1, 1, 0,
	/*V1*/    0, 0, 0, 1, 1,
	/*V2*/    1, 0, 0, 1, 1,
	/*V3*/    1, 1, 1, 0, 0,
	/*V4*/    0, 1, 1, 0, 0,};      //ͼ7.2��G1��ʾ������ͼ
	
	
void main()  {
	Graphl aGraphl(N);              // ����ͼ 
	aGraphl.IniGraphl(&aGraphl, A); // ��ʼ��ͼ

	cout << "DFS: ";
	aGraphl.DFS(aGraphl, 0);
	cout << endl;

	for (int i = 0; i < aGraphl.VerticesNum(); i ++) //��Mark�Ļ�UNVISITED
		aGraphl.Mark[i] = UNVISITED; 
	
	cout << "BFS: ";
	aGraphl.BFS(aGraphl, 0);
	cout << endl;

}