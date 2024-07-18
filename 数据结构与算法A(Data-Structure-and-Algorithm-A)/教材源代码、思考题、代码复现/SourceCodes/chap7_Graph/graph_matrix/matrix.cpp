// ͼ�����ھ����ʾ����
#include <iostream>
#include <queue>
#include "Graph.h"
#include "Graphm.h"
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
	Graphm aGraphm(N);              // ����ͼ 
	aGraphm.IniGraphm(&aGraphm, A); // ��ʼ��ͼ
	cout << "DFS: ";
	aGraphm.DFS(aGraphm, 0);
	cout << endl;
		
	for (int i = 0; i < aGraphm.VerticesNum(); i ++) //��Mark�Ļ�UNVISITED
		aGraphm.Mark[i] = UNVISITED; 
		
	cout << "BFS: ";
	aGraphm.BFS(aGraphm, 0);
	cout << endl;
}
