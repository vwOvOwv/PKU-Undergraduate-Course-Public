// ͼ�����ھ����ʾ����

//*****************************************************
//����Ҫע�� ͼ���еı�Ϊ������ʱ��ҲӦ�ÿ�����һ����
//����Ҫ�޸�һ��IsEdge�����Ķ���
//******************************************************


#include <iostream>
#include <queue>
using namespace std;
#define N 3 // ����ͼ�Ķ�����
#define INFINITE 0xffff

#include "Graphm.h"


class Dist  {      //����Dist�࣬�����Dijkstra�㷨��Floyd�㷨Ҫ�õ�
public:
	int index;      //���������ֵ����Dijkstra�㷨���õ�
	int length;     //����֮��ľ���
	int pre;       //·����󾭹��Ķ���
	Dist() {};
	~Dist() {};

	bool operator < (const Dist & arg)  {
		return (length < arg.length);
	}
	bool operator == (const Dist &arg)  {
		return (length==arg.length);
	}
	bool operator > (const Dist &arg)  {
		return (length>arg.length);
	}
	bool operator <=(const Dist &arg)  {
		return (length<=arg.length);
	}
	bool operator >= (const Dist &arg)  {
		return (length>=arg.length);
	}
};


//[�㷨7.9] Floyd�㷨
void Floyd(Graph& G, Dist** &D)  {
	int i,j,v;                               // i,j,v�Ǽ�����
	D = new Dist*[G.VerticesNum()];          // Ϊ����D����ռ�
    for (i = 0; i < G.VerticesNum();i++) 
		D[i] = new Dist[G.VerticesNum()];
	for (i = 0;i < G.VerticesNum();i++)          // ��ʼ������D
		for (j = 0;j < G.VerticesNum();j++) {
			if (i == j) {
				D[i][j].length = 0;
				D[i][j].pre = i;
			}
			else {
				D[i][j].length = INFINITE;
				D[i][j].pre = -1;
			}
		}
		for (v = 0;v < G.VerticesNum();v++)
			for (Edge e = G.FirstEdge(v); G.IsEdge(e);e = G.NextEdge(e)) {
				D[v][G.ToVertex(e)].length = G.Weight(e);		
				D[v][G.ToVertex(e)].pre = v;	
			}
			// ����������������·����������v���������̾���
			for (v = 0;v < G.VerticesNum();v++)
				for (i = 0;i < G.VerticesNum();i++)
					for (j = 0;j < G.VerticesNum();j++)
						if (D[i][j].length > (D[i][v].length+D[v][j].length)) {
							D[i][j].length = D[i][v].length+D[v][j].length;
							D[i][j].pre = D[v][j].pre;
						}
}



int A[N][N] =  {
//	V0    V1    V2
	0,    4,    11,
	6,    0,     2,
    3, INFINITE, 0
};



void main()  {
	Graphm aGraphm(N); // ����ͼ
	aGraphm.IniGraphm(&aGraphm, A); // ��ʼ��ͼ

	Dist **D;
	Floyd(aGraphm, D);
	
	for (int i = 0; i < N; i ++)  {
		for (int j = 0; j < N; j ++)
			cout << D[i][j].length << " ";
		cout << endl;
	}
}
