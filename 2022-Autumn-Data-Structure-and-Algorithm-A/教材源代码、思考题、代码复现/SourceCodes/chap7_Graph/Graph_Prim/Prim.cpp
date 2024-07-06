#include <iostream>
#include <queue>
#define UNVISITED 0
#define VISITED 1
#define INFINITY 9999
#define N 7         // ����ͼ�Ķ�����
using namespace std;
#include "Graphm.h"


class Dist  {      //����Dist�࣬�����Prim�㷨Ҫ�õ�
 public:
	 int index;      //���������ֵ����Dijkstra�㷨���õ�
	 int length;     //����֮��ľ���
	 int pre;       //·����󾭹��Ķ���
	 Dist() {};
	 ~Dist() {};
	 void Dijkstra(Graphm & G,int s, Dist* &D);
	 bool operator < (const Dist &arg)  {
		 return (length < arg.length);
	 }
	 bool operator == (const Dist &arg)  {
		 return (length==arg.length);
	 }
	 bool operator == (const int c)  {
		 return (length==c);
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



int minVertex(Graph& G, Dist* & D) { 			// ��Dist����������Сֵ
	int i, v;  
	for (i=0; i<G.VerticesNum(); i++)
		if (G.Mark[i] == UNVISITED) {
			v = i; 						// ��vΪ����һ��δ���ʵĶ���
			break; 
		}
	for (i=0; i<G.VerticesNum(); i++)  		
		if ((G.Mark[i] == UNVISITED) && (D[i] < D[v])) 
			v = i;						// ����Ŀǰ���ֵľ�����С����Ķ���
	return v;
}


//��С֧������Prim�㷨��
//����G��ͼ������s�ǿ�ʼ���㣬����MST�Ǳ�����С֧���������бߵ�����
void AddEdgetoMST(Edge e, Edge *&MST, int n)
{
	MST[n] = e;
}

void Prim(Graph& G, int s, Edge* &MST)  {
	int MSTtag = 0;                       // ��С�������ߵı��
	MST = new Edge[G.VerticesNum()-1];
	Dist *D;
	D = new Dist[G. VerticesNum()];          	// D����
	for (int i = 0; i < G.VerticesNum(); i++)  {  	// ��ʼ��Mark���顢D����
		G.Mark[i] = UNVISITED;
        D[i].index = i;
        D[i].length = INFINITE;
        D[i].pre = s;
    }

    D[s].length = 0; 
	G.Mark[s]= VISITED;	

    int v = s;
	int i;
	for (i = 0; i < G.VerticesNum()-1; i++)  {
 
    	if (D[v] == INFINITY) return;    	// ����ͨ���в��ɴﶥ�㣬
 
		// ��Ϊv�ļ��룬��Ҫˢ��v�ڽӵ��Dֵ
		for (Edge e = G.FirstEdge(v); G.IsEdge(e);e = G.NextEdge(e))
			if (G.Mark[G.ToVertex(e)]!=VISITED && (D[G.ToVertex(e)].length > e.weight)) {
				D[G.ToVertex(e)].length = e.weight;
				D[G.ToVertex(e)].pre = v;
		 	}

		v = minVertex(G, D);

		G.Mark[v] = VISITED;
		Edge edge(D[v].pre, D[v].index, D[v].length);

     	AddEdgetoMST(edge,MST,MSTtag++);  // ����e�ӵ�MST��
	} 
}





int A[N][N] =  {
	//   v0  v1  v2  v3  v4  v5  v6     
		0, 20,  0,  0,  1,  0,  0,
		20,  0,  6,  4,  0,  0,  0,
		0,  6,  0,  0,  0,  0,  2,
		0,  4,  0,  0,  0, 12,  8,
		1,  0,  0,  0,  0, 15,  0,
		0,  0,  0, 12, 15,  0, 10,
		0,  0,  2,  8,  0, 10,  0,
};			                    	//ͼ7.24 ��Ȩͼ

void main()
{
	Graphm aGraphm(N); // ����ͼ
	aGraphm.IniGraphm(&aGraphm, A); // ��ʼ��ͼ
	
	Edge *D;
	Prim(aGraphm, 0, D);
	for (int i = 0; i < N - 1; i ++)
		cout << "V" << D[i].from << "->V" << D[i].to << "   Weight is : " << D[i].weight << endl;
}