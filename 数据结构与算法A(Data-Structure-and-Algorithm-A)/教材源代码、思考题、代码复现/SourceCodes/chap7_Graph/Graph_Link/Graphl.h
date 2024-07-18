//*************** Link.h **************//

#define UNVISITED 0
#define VISITED 1
#define INFINITE 0xffffffff
#define N 5 // ����ͼ�Ķ�����
using namespace std;
struct listUnit  {    //�ڽӱ��Ŀ�����ݲ��ֵĽṹ����
	int vertex;      //�ߵ��յ�
	int weight;      //�ߵ�Ȩ
};

template<class Elem>   //����Ԫ��
class Link  {
public:
	Elem element;      //��Ŀ������
	Link *next;        //��Ŀָ�룬ָ����һ����Ŀ
	Link(const Elem& elemval,Link *nextval = NULL)  { //���캯��
		element = elemval; 
		next = nextval; 
	}
	Link(Link *nextval = NULL)  { 					//���캯��
		next = nextval; 
	} 
};

template<class Elem>   //����
class LList  {
public:
	Link<Elem>* head;  //headָ�벢�������κ�ʵ��Ԫ�أ������ֻ��Ϊ�˲�������
	LList()  {          //���캯��
		head = new Link<Elem>();
	}
	void removeall()  {  //�ͷű߱����б�Ŀռ�ݵĿռ�
		Link<Elem> *fence;
		while(head != NULL)  { //���ͷ�ÿ����Ŀռ�ݵĿռ�
			fence = head;
			head = head->next;
			delete fence;
		}
	}
	~LList() {				//��������
		removeall();
	}
};


class Graphl: public Graph  {
private:
	LList<listUnit> *graList;  //graList�Ǳ������б߱������	
public:
	Graphl(int numVert):Graph(numVert)  { //���캯��
		graList = new LList<listUnit>[numVertex]; /*ΪgraList��������ռ䣬ͼ��
										  numVertex�����㣬����numVertex���߱�*/
	}

	~Graphl()  {                        //��������
		delete [] graList;				   //�ͷſռ�
	}
	
	Edge FirstEdge(int oneVertex)  {   //���ض���oneVertex�ĵ�һ����
		Edge myEdge;                   //��myEdge����Ϊ�����ķ���ֵ
		myEdge.from = oneVertex;       //������oneVertex��Ϊ��myEdge��ʼ��
									  /*graList[oneVertex].head������Ƕ���oneVertex�ı߱�
									  temp->nextָ�򶥵�oneVertex�ĵ�һ����(���temp->next
									  ��Ϊnull)*/
		Link<listUnit> *temp = graList[oneVertex].head;
		if(temp->next != NULL)  {        //�������oneVertex�ĵ�һ����ȷʵ����
			myEdge.to = temp->next->element.vertex;
			myEdge.weight = temp->next->element.weight;
		}
		/*����ҵ��˶���oneVertex�ĵ�һ����,�򷵻ص�myEdgeȷʵ��һ����;���û��
		�ҵ�����oneVertex�ĵ�һ����,��myEdge�ĳ�Ա����toΪ-1,����IsEdge������
		�Ͽ�֪myEdge����һ����*/
		return myEdge;
	}	

	Edge NextEdge(Edge preEdge)  {  // �������PreEdge����ͬ�����������һ����
		Edge myEdge;			 		// myEdge�ĳ�ʼ��Ա����toΪ-1
		myEdge.from = preEdge.from;  		// ���ߵ�ʼ����Ϊ����һ���ߵ���ͬ
		Link<listUnit> *temp = graList[preEdge.from].head;		// tempָ��߱�ͷһ��
		while (temp->next != NULL && temp->next->element.vertex <= preEdge.to)
			temp = temp->next; 			// ȷ����preEdge��λ��
		if (temp->next != NULL) {		// ��preEdge����һ���ߴ���
			myEdge.to = temp->next->element.vertex;
			myEdge.weight = temp->next->element.weight;
		}
		return myEdge;					// ���û���ҵ���һ���ߣ�myEdge.to=-1
	}

	void setEdge(int from,int to,int weight)  {  //Ϊͼ�趨һ����
		Link<listUnit> *temp = graList[from].head;  /*graList[from].head������Ƕ���from��
													�߱�temp->nextָ�򶥵�from�ĵ�һ����
													(���temp->next��Ϊnull)*/
		while(temp->next != NULL && temp->next->element.vertex < to)
			temp = temp->next;   /*ȷ����(from,to)��<from,to>�ڱ߱��е�λ��,���������,
									���(from,to)��<from,to>Ϊ�¼ӵ�һ����*/
		if(temp->next == NULL) {  /*��(from,to)��<from,to>�ڱ߱��в��������ڱ߱������
									����������,���ڱ߱��м���������*/
			temp->next = new Link<listUnit>;
			temp->next->element.vertex = to;
			temp->next->element.weight = weight;
			numEdge++;
			Indegree[to]++;
			return;
		}
		if(temp->next->element.vertex == to)  { /*��(from,to)��<from,to>�ڱ߱����Ѵ���,
												��ֻ��Ҫ�ı�ߵ�Ȩֵ*/
			temp->next->element.weight = weight;
			return;
		}
		if(temp->next->element.vertex>to) { /*��(from,to)��<from,to>�ڱ߱��в�����,���ڱ߱���
												������������,���ڱ߱��в���������*/
			Link<listUnit> *other = temp->next;
			temp->next = new Link<listUnit>;
			temp->next->element.vertex = to;
			temp->next->element.weight = weight;
			temp->next->next = other;
			numEdge++;
			Indegree[to]++;
			return;
		}
	}

	void delEdge(int from,int to)  {          //ɾ��ͼ��һ����
		Link<listUnit> *temp = graList[from].head;  /*graList[from].head������Ƕ���from�ı߱�temp->nextָ�򶥵�from�ĵ�һ����(���temp->next��Ϊnull)*/
		while(temp->next != NULL && temp->next->element.vertex<to)  
			temp = temp->next;	/*ȷ����(from,to)��<from,to>�ڱ߱��е�λ��(����ñߴ���)*/
		if(temp->next == NULL)
			return;        //��(from,to)��<from,to>�ڱ߱��в�����,����Ҫ���κβ���
		if(temp->next->element.vertex>to)
			return;        //��(from,to)��<from,to>�ڱ߱��в�����,����Ҫ���κβ���
		if(temp->next->element.vertex == to) { /*��(from,to)��<from,to>�ڱ߱��д�����ȷ
											   ���˸ñ��ڱ߱��е�λ��,��ӱ߱��н���ɾ��*/
			Link<listUnit> *other = temp->next->next;
		    delete temp->next;
		    temp->next = other;
		    numEdge--;
		    Indegree[to]--;
		    return;
		}
	}

	void IniGraphl(Graphl *Graphl, int A[N][N]);
	void DFS(Graph& G, int v);
	void BFS(Graph& G, int v);
	void Visit(Graph &G, int v);
};

// �������ܣ���ʼ��ͼ
void Graphl::IniGraphl(Graphl *Graphl, int A[N][N])  {
	for (int i = 0; i < N; i ++)  	{
		for (int j = 0; j < N; j ++)  {
			if (A[i][j] > 0)
				Graphl->setEdge(i, j, A[i][j]);
		}
	}
}


//�������ܣ�������������㷨ʵ��
void Graphl::DFS(Graph& G, int v)  {    //������������㷨ʵ��
    G.Mark[v] = VISITED;       //���ʶ���v����������־λ
    Visit(G,v);	
    //����V�ڽӵ���δ�����ʹ��Ķ��㣬���ݹ�ذ���������ȵķ�ʽ��������
    for(Edge e=G.FirstEdge(v);G.IsEdge(e);e=G.NextEdge(e))
        if(G.Mark[G.ToVertex(e)]== UNVISITED)
			DFS(G, G.ToVertex(e));
}


// �������ܣ������������
void Graphl::BFS(Graph& G, int v)  {           // ������������㷨��ʵ��
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
void Graphl::Visit(Graph &G, int v) {
	cout << 'V' << v <<" ";
}
