//***********   Graph.h   ************//
//ͼ�Ļ���

#define UNVISITED 0
#define VISITED 1

//Edge��
class Edge  { 
public: 
	int weight;    //weight�Ǳߵ�Ȩ
	int from;      //from�Ǳߵ�ʼ��
	int to;        //to�Ǳߵ��յ�
	Edge()  {		// ���캯��
		from = -1;  to = -1;  weight = 0;
	}							
	Edge(int f,int t,int w)   { // ���캯��
		from=f;   to=t;   weight=w;
	}
	bool operator < (const Edge &arg) {return (this->weight < arg.weight);};
	bool operator == (const Edge &arg) {return (this->weight == arg.weight);};
	bool operator > (const Edge &arg) {return (this->weight > arg.weight);};
	bool operator <= (const Edge &arg) {return (this->weight <= arg.weight);};
	bool operator >= (const Edge &arg) {return (this->weight >= arg.weight);};
};

//ͼ����
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
	}
	
	~Graph() {				//��������
		delete [] Mark;
		delete [] Indegree;
	}
	
	virtual Edge FirstEdge(int oneVertex) {	// �����붥��oneVertex������ĵ�һ����
		Edge myEdge;
		myEdge.from = oneVertex; 
		myEdge.to = -1;
		return myEdge;
	}
	
	virtual Edge NextEdge(Edge preEdge) {      // �������PreEdge����ͬ�����������һ����
		return preEdge;
	}

	int VerticesNum() {		//����ͼ�Ķ������
		return numVertex;
	}
	
	int EdgesNum() {			//����ͼ�ı���
		return numEdge;
	}
	
	int FromVertex(Edge oneEdge) {  // ����oneEdge��ʼ��
		return oneEdge.from;
	}
	
	int ToVertex(Edge oneEdge) {	// ����oneEdge���յ�
		return oneEdge.to;
	}
	
	int Weight(Edge oneEdge) {		// ����oneEdge��Ȩֵ
		return oneEdge.weight;
	}
	
	bool IsEdge(Edge oneEdge)  {	//���oneEdge�Ǳ��򷵻�TRUE�����򷵻�FALSE
		if (oneEdge.weight > 0 && oneEdge.weight <= INFINITE && oneEdge.to >= 0)
			return true;
		else
			return false;
	}
	
	virtual void setEdge(int from, int to, int weight) = 0;
	virtual void delEdge(int from, int to) = 0;
};
