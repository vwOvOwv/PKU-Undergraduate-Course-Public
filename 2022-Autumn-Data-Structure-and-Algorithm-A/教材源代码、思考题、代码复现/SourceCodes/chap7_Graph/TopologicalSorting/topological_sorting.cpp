// ͼ�����ھ����ʾ�洢ͼ��ʵ��ͼ����������
#include <iostream>
#include <queue>
#include "Graphm.h"
using namespace std;

// �������ܣ���ʾ����������
void Visit(Graph &G, int v) {
	cout << "C" << v << " ";
}
void Visit(int v) {
	cout << "C" << v << " ";
}

//***************************************************************
//[�㷨7.7] ����ʵ�ֵ�ͼ��������
void TopsortbyQueue(Graph& G)  {      //���з�ʽʵ�ֵ���������
	for(int i=0;i<G.VerticesNum();i++)    //��ʼ��Mark����
		G.Mark[i]=UNVISITED;
    using std::queue;
	queue<int> Q; //��ʼ������
	int i;
	for(i=0; i<G.VerticesNum(); i++)
		if(G.Indegree[i]==0)
			Q.push(i);                //ͼ�����Ϊ0�Ķ������
		while(!Q.empty())  {              //��������л���ͼ�Ķ���
			int V=Q.front();
			Q.pop();                     //һ���������
			Visit(G,V);
			G.Mark[V]=VISITED;
			for(Edge e= G.FirstEdge(V);G.IsEdge(e);e=G.NextEdge(e))  {
				G.Indegree[G.ToVertex(e)]--;  //������֮���ڵĶ������-1
				if(G.Indegree[G.ToVertex(e)]==0)
					Q.push(G.ToVertex(e));   //���Ϊ0�Ķ������
			}
		}
		for(i=0; i<G.VerticesNum(); i++)
			if(G.Mark[i]==UNVISITED)  {
				cout<<" ��ͼ�л���";        //ͼ�л�
				break;
			}	
}


int A[N][N] =  {
      //C0  C1  C2  C3  C4  C5  C6  C7  C8	
	    0,  0,  1,  0,  0,  0,  0,  1,  0, 
		0,  0,  1,  1,  1,  0,  0,  0,  0,   
		0,  0,  0,  1,  0,  0,  0,  0,  0,  
		0,  0,  0,  0,  0,  1,  1,  0,  0,  
		0,  0,  0,  0,  0,  1,  0,  0,  0,  
		0,  0,  0,  0,  0,  0,  0,  0,  0,  
		0,  0,  0,  0,  0,  0,  0,  0,  0,  
		0,  0,  0,  0,  0,  0,  0,  0,  1,  
		0,  0,  0,  0,  0,  0,  1,  0,  0};  //��ͼΪͼ7.18��ʾ�γ����ȹ�ϵ�������޻�ͼ

int main()
{
	Graphm aGraphm(N);              // ����ͼ
	aGraphm.IniGraphm(&aGraphm, A); // ��ʼ��ͼ
	cout << "Top sort by Queue is : ";
	TopsortbyQueue(aGraphm);
	cout << "\nOK! " << endl; 
	return 0;
}