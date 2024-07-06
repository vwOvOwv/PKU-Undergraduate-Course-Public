#include "Graph.h" 
#define N 9 // ����ͼ�Ķ�����
using namespace std;

// ͼ�����ھ����ʾ��
class Graphm:public Graph  {
private:
	int **matrix;				//ָ�����ھ����ָ��
public:
	void IniGraphm(Graphm *Graphm, int A[N][N]); // ��ʼ��
	void DFS(Graph &G, int v);			// �����������  
	void BFS(Graph &G, int v);			// �����������
	void Visit(Graph &G, int v);		// ����
	
public:
	Graphm(int numVert):Graph(numVert)  {//���캯��
		int i, j;			//i, j��Ϊforѭ���еļ�����
		matrix = (int **)new int*[numVertex]; /*����matrix����,��������numVertex��Ԫ��,ÿ��Ԫ��������ָ������*/
		
		for (i = 0; i < numVertex; i ++)		/*matrix�����ÿ��Ԫ��,��ָ��һ������numVertex��Ԫ�ص�����*/
			matrix[i] = new int[numVertex];  

		for (i = 0; i < numVertex; i++)       /*���ھ��������Ԫ�ض���ʼ��Ϊ0,�������Ԫ��matrix[i][j]��Ϊ0,���������i�붥��j֮����һ����,�ߵ�Ȩ��Ϊmatrix[i][j]��ֵ*/
			for (j = 0; j < numVertex; j ++)
				matrix[i][j] = 0;
	}

	~Graphm() {							//��������
		for (int i = 0; i < numVertex; i ++)
			delete [] matrix[i];			//�ͷ�ÿ��matrix[i]����Ŀռ�
		delete [] matrix;				//�ͷ�matrixָ��ָ��Ŀռ�
	}

	Edge FirstEdge(int oneVertex)  {	//���ض���oneVertex�ĵ�һ����
		Edge myEdge;						//��myEdge����Ϊ�����ķ���ֵ
		myEdge.from = oneVertex;			//������oneVertex��Ϊ��myEdge��ʼ��
		//  myEdge.to = -1; 
		for (int i = 0; i < numVertex; i ++)   {/* ����Ѱ�ҵ�һ��ʹ��matrix[oneVertex][i]
												��Ϊ0��iֵ����ô��(oneVertex,i)����
												��<oneVertex,i>��Ϊ����oneVertex
												�ĵ�һ���ߣ�������i��Ϊ��myEdge���յ��myEdge
			                                    ��ȨΪ����Ԫ��matrix[oneVertex][i]��ֵ*/
			if (matrix[oneVertex][i] != 0)  {									
				myEdge.to = i;
				myEdge.weight = matrix[oneVertex][i];
				break;
			}
		}
		return myEdge;/*����ҵ��˶���oneVertex�ĵ�һ����,�򷵻ص�myEdgeȷʵ��һ���ߣ�
		              ���û���ҵ�����oneVertex�ĵ�һ����,��myEdge�ĳ�Ա����toΪ-1��
		              ����IsEdge�����жϿ�֪myEdge����һ����*/
	}

	Edge NextEdge(Edge preEdge)  { //�������PreEdge����ͬ�����������һ����
		Edge myEdge;
		myEdge.from=preEdge.from; /*����myEdge��ʼ����Ϊ����һ����preEdge��ʼ����ͬ*/
		if(preEdge.to<numVertex)  {
			//���preEdge.to+1>=numVertex,��ô�Ͳ�������һ������
			for(int i=preEdge.to+1;i<numVertex;i++)  {
				/*Ѱ����һ��ʹ��//matrix[preEdge.from][i]��Ϊ0��iֵ,��ô
				(preEdge.from,i)����<preEdge.from,i>��Ϊ����preEdge.from����һ����*/
				if(matrix[preEdge.from][i]!=0)  {
					myEdge.to=i;
					myEdge.weight=matrix[preEdge.from][i];
					break;
				}
			}
		}
		return myEdge; /*����ҵ��˶���preEdge.from����һ���ߣ��򷵻ص�myEdgeȷʵ��һ���ߣ�
					   ���û���ҵ�����preEdge.from����һ���ߣ���myEdge�ĳ�Ա����toΪ-1��
						����IsEdge�����жϿ�֪myEdge����һ����*/
	}
	
	void setEdge(int from, int to, int weight)  {	//Ϊͼ�趨һ����
		if (matrix[from][to] <= 0) {  /*���matrix[from][to]<=0�����(from,to) ����<from,to>
			                       ����������һ���ߣ�����ñ��Ѿ����ڣ�����ֻ�ǶԸñ߽����޸ģ�*/
			numEdge ++;
			Indegree[to] ++;
		}
		matrix[from][to] = weight;
	}
	
	void delEdge(int from,int to)  {     //ɾ��ͼ��һ����
		if(matrix[from][to]>0)  { /*���matrix[from][to]>0�����(from,to)����<from,to>ȷʵ���ڣ�
			                      ����ñ�ʵ���ϲ������ڣ��Ӷ����ض�ͼ�ı����Ͷ���to����Ƚ����޸ģ�*/
			numEdge--;
			Indegree[to]--;
		}
		matrix[from][to]=0;		     
	}
};

// �������ܣ���ʼ��ͼ
void Graphm::IniGraphm(Graphm *Graphm, int A[N][N])  {
	for (int i = 0; i < N; i ++)  	{
		for (int j = 0; j < N; j ++)  {
			if (A[i][j] > 0)
				Graphm->setEdge(i, j, A[i][j]);
		}
	}
}

//�������ܣ�������������㷨ʵ��
void Graphm::DFS(Graph& G, int v)  {    //������������㷨ʵ��
    G.Mark[v] = VISITED;       //���ʶ���V����������־λ
    Visit(G,v);	
    //����V�ڽӵ���δ�����ʹ��Ķ��㣬���ݹ�ذ���������ȵķ�ʽ��������
    for(Edge e=G.FirstEdge(v);G.IsEdge(e);e=G.NextEdge(e))
        if(G.Mark[G.ToVertex(e)]== UNVISITED)
			DFS(G, G.ToVertex(e));
}


// �������ܣ������������
void Graphm::BFS(Graph& G, int v)  {           // ������������㷨��ʵ��
    using std::queue;
	queue<int> Q;                    // ��ʼ�������������Ҫ�õ��Ķ���
	Visit(G,v);                       // �ʶ���v����������־λ
    G.Mark[v] = VISITED;
    Q.push(v);                       // v���
	while (!Q.empty())  {              // ���������Ȼ��Ԫ��
		int u = Q.front ();              // ���ж���Ԫ��
		Q.pop();                     // ���ж���Ԫ�س���
       		// �ö����ڽӵ���ÿһ��δ���ʶ��㶼���
		for (Edge e = G.FirstEdge(u);G.IsEdge(e);e = G.NextEdge(e))
		if (G.Mark[G.ToVertex(e)] == UNVISITED)  {
		        Visit(G, G.ToVertex(e));	
			G.Mark[G.ToVertex(e)] = VISITED;
		    	Q.push(G.ToVertex(e));  // ���
		    }
	}
}

// �������ܣ���ʾ����
void Graphm::Visit(Graph &G, int v) {
	cout << 'V' << v <<" ";
}
