//GraphMatrix.h

//Edge
class Edge
{ 
public: 
	int weight;  // Edge weight
	int from; 
	int to; // form To to 
	Edge(){};								// ���캯��
	Edge(int f,int t,int w)   { 			// ���캯��
		from=f;   to=t;   weight=w;
	}
	bool operator < (const Edge &arg) {return (this->weight < arg.weight);};
	bool operator == (const Edge &arg) {return (this->weight == arg.weight);};
	bool operator > (const Edge &arg) {return (this->weight > arg.weight);};
	bool operator <= (const Edge &arg) {return (this->weight <= arg.weight);};
	bool operator >= (const Edge &arg) {return (this->weight >= arg.weight);};
};

// ͼ����
class Graph  {
public:
	int numVertex;             //ͼ�Ķ���ĸ���
	int numEdge;				//ͼ�ıߵ���Ŀ
	int *Mark;					/*Markָ��ָ�򱣴���ͼ�Ķ���ı�־λ������,��־λ�������ĳ�����Ƿ񱻷��ʹ�*/
	int *Indegree;				//Indegreeָ��ָ�򱣴���ͼ�Ķ������ȵ�����
	Graph(int numVert)  {		//���캯��
		numVertex = numVert;      //ȷ��ͼ�Ķ���ĸ���
		numEdge = 0;				//ȷ��ͼ�ıߵ���Ŀ
		Indegree = new int[numVertex]; /*Ϊ����ͼ�Ķ���������������,IndegreeΪ����ָ��*/
		Mark = new int[numVertex];	 /*Ϊͼ�Ķ���ı�־λ��������,MarkΪ����ָ��*/
		
		for (int i = 0; i < numVertex; i ++)  {	/*ȷ��ͼ�Ķ���ı�־λ�����,�����ж���ı�־λ��ʼ��Ϊδ�����ʹ�,��ȳ�ʼ��Ϊ0*/
			Mark[i] = UNVISITED;
			Indegree[i] = 0;
		}
	};
	~Graph() {				//��������
		delete [] Mark;
		delete [] Indegree;
	}; 
	virtual Edge FirstEdge(int oneVertex) {	// �����붥��oneVertex������ĵ�һ����
		Edge myEdge;
		myEdge.from = oneVertex; 
		myEdge.to = -1;
		return myEdge;
	}; 
	virtual Edge NextEdge(Edge preEdge) {      // �������PreEdge����ͬ�����������һ����
		return preEdge;
	};
	int VerticesNum() {		//����ͼ�Ķ������
		return numVertex;
	};       
	int EdgesNum() {			//����ͼ�ı���
		return numEdge;
	};
	int FromVertex(Edge oneEdge) {  // ����oneEdge��ʼ��
		return oneEdge.from;
	}; 
	int ToVertex(Edge oneEdge) {	// ����oneEdge���յ�
		return oneEdge.to;
	};    
	int Weight(Edge oneEdge) {		// ����oneEdge��Ȩֵ
		return oneEdge.weight;
	}; 
	bool IsEdge(Edge oneEdge)  {	//���oneEdge�Ǳ��򷵻�TRUE�����򷵻�FALSE
		if (oneEdge.weight > 0 && oneEdge.weight < INFINITE && oneEdge.to >= 0)
			return true;
		else
			return false;
	}; 
	virtual void setEdge(int from, int to, int weight) = 0;
	virtual void delEdge(int from, int to) = 0;
};


// ͼ�����ھ����ʾ��
class Graphm:public Graph  {
private:
	int **matrix;				//ָ�����ھ����ָ��
public:
	void IniGraphm(Graphm *Graphm, int A[N][N]); // ��ʼ��
	void DFS(Graph &G, int V);			// �����������  
	void BFS(Graph &G, int V);			// �����������
	void Visit(Graph &G, int V);		// ����
	
public:
	Graphm(int numVert):Graph(numVert)  {//���캯��
		int i, j;			//i, j��Ϊforѭ���еļ�����
		matrix = (int **)new int*[numVertex]; /*����matrix����,��������numVertex��Ԫ��,ÿ��Ԫ��������ָ������*/
		
		for (i = 0; i < numVertex; i ++)		/*matrix�����ÿ��Ԫ��,��ָ��һ������numVertex��Ԫ�ص�����*/
			matrix[i] = new int[numVertex];  
		for (i = 0; i < numVertex; i++)       /*���ھ��������Ԫ�ض���ʼ��Ϊ0,�������Ԫ��matrix[i][j]��Ϊ0,���������i�붥��j֮����һ����,�ߵ�Ȩ��Ϊmatrix[i][j]��ֵ*/
			for (j = 0; j < numVertex; j ++)
				matrix[i][j] = 0;
	};
	~Graphm() {							//��������
		for (int i = 0; i < numVertex; i ++)
			delete [] matrix[i];			//�ͷ�ÿ��matrix[i]����Ŀռ�
		delete [] matrix;				//�ͷ�matrixָ��ָ��Ŀռ�
	}; 
	Edge FirstEdge(int oneVertex)  {	//���ض���oneVertex�ĵ�һ����
		Edge myEdge;						//��myEdge����Ϊ�����ķ���ֵ
		myEdge.from = oneVertex;			//������oneVertex��Ϊ��myEdge��ʼ��
		//  myEdge.to = -1; 
		for (int i = 0; i < numVertex; i ++)   {/* ����Ѱ�ҵ�һ��ʹ��matrix[oneVertex][i]��Ϊ0��iֵ��
												��ô��(oneVertex,i)���߻�<oneVertex,i>��Ϊ����oneVertex
												�ĵ�һ���ߣ�������i��Ϊ��myEdge���յ��myEdge��ȨΪ
			����Ԫ��matrix[oneVertex][i]��ֵ*/
			if (matrix[oneVertex][i] != 0)
			{									
				myEdge.to = i;
				myEdge.weight = matrix[oneVertex][i];
				break;
			}
		}
		return myEdge;/*����ҵ��˶���oneVertex�ĵ�һ����,�򷵻ص�myEdgeȷʵ��һ���ߣ����û���ҵ�����oneVertex�ĵ�һ����,��myEdge�ĳ�Ա����toΪ-1������IsEdge�����жϿ�֪myEdge����һ����*/
	}; 
	Edge NextEdge(Edge preEdge)  { //�������PreEdge����ͬ�����������һ����
		Edge myEdge;
		myEdge.from=preEdge.from; /*����myEdge��ʼ����Ϊ����һ����preEdge��ʼ����ͬ*/
		if(preEdge.to<numVertex)  {
			//���preEdge.to+1>=numVertex,��ô�Ͳ�������һ������
			for(int i=preEdge.to+1;i<numVertex;i++)  {
				/*Ѱ����һ��ʹ��//matrix[preEdge.from][i]��Ϊ0��iֵ,��ô(preEdge.from,i)����<preEdge.from,i>��Ϊ����preEdge.from����һ����*/
				if(matrix[preEdge.from][i]!=0)  {
					myEdge.to=i;
					myEdge.weight=matrix[preEdge.from][i];
					break;
				}
			}
		}
		return myEdge; /*����ҵ��˶���preEdge.from����һ���ߣ��򷵻ص�myEdgeȷʵ��һ���ߣ����û���ҵ�����preEdge.from����һ���ߣ���myEdge�ĳ�Ա����toΪ-1��
		����IsEdge�����жϿ�֪myEdge����һ����*/
	}
	
	void setEdge(int from, int to, int weight)  {	//Ϊͼ�趨һ����
		if (matrix[from][to] <= 0) {    //���matrix[from][to]<=0�����(from,to)����<from,to>����������һ���ߣ�����ñ��Ѿ����ڣ�����ֻ�ǶԸñ߽����޸ģ�
			numEdge ++;
			Indegree[to] ++;
		}
		matrix[from][to] = weight;
	}; 
	
	void delEdge(int from,int to)  {     //ɾ��ͼ��һ����
		if(matrix[from][to]>0)  {
			/*���matrix[from][to]>0�����(from,to)����<from,to>ȷʵ���ڣ�����ñ�ʵ���ϲ������ڣ��Ӷ����ض�ͼ�ı����Ͷ���to����Ƚ����޸ģ�*/
			numEdge--;
			Indegree[to]--;
		}
		matrix[from][to]=0;		     
	}
};

// �������ܣ���ʾ����
void Graphm::Visit(Graph &G, int v) {
	cout << 'V' << v <<" ";
}


// �������ܣ���ʼ��ͼ
void Graphm::IniGraphm(Graphm *Graphm, int A[N][N])  {
	for (int i = 0; i < N; i ++)  {
		for (int j = 0; j < N; j ++)  {
			if (A[i][j] > 0)
				Graphm->setEdge(i, j, A[i][j]);
		}
	}
}
