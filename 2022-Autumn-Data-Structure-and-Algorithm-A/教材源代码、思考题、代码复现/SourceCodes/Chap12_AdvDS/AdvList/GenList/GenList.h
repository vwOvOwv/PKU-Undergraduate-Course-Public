//����������ʵ��
#include <iostream>
using namespace std;
#define ATOM 0  //���д洢����ԭ��Ԫ��
#define LIST 1  //���д洢�����ӱ�
#define HEAD -1  //�Ƿ��Ǳ�ͷ���
#define VISITED 1  //�Ѿ����ʹ�
#define UNVISITED 0  //δ���ʹ�
#define BACKTRACE 1  //��Ҫ����
#define NOTBACKTRACE 0  //����Ҫ����
#define MaxName 20; 

//�����Ľ������
template <class T>
class GenListNode
{
	public:
		int type;   //��ʾ�ý����ATOM or LIST	
		union {
			struct {
		         int ref;   //����Ǳ�ͷ����򣬴洢�ý�㱻���������ָ��
				 char* Name;  // ��ͷ����	
				 int mark;   // ���ӱ��Ƿ񱻷��ʹ�
			} headNode;
	        GenListNode<T> *child;//�����LIST ,��ָ������Ԫ�ص��׽��	
	        T element; //�����ATOM����洢����ֵ
		};

	    GenListNode<T> *next;//ָ����һ�����
		GenListNode(T element);//���캯��
		GenListNode();
		GenListNode(GenListNode<T> *list);//
	   ~GenListNode();//��������
	    void Destory(GenListNode<T>* node);//�ͷ������ڴ� 
	    void ViewAll();//�����ý���������ֵ�
	    void GenListTraversal();//�����ý���������ֵܣ�����
		void Search(GenListNode<T>* node,GenListNode<T>*prenode,int &flag);
		void GenListTraversalHelp(GenListNode<T> *node);  // ����
};
//GenList��һ��ԭ��Ԫ������ΪT�Ĺ����
//���Ҫʵ���ܹ��洢�����������͵Ĺ���
//��ֻ��ҪǶ�׵�ʹ����

template <class T>
class GenList
{
	private:
		GenListNode<T> *head;//����������ͷ���,���洢�κ���Ϣ
		GenListNode<T> *current;//��ǰָ���λ��
	
	public:
		GenList(char *Name);
		~GenList();
		void Insert(T element);//��β������һ��Ԫ�ؽ��
		void Insert(GenList<T> *gl);//��β������һ���ӱ�
        GenListNode<T> *GetHead();//�õ�ͷ����ָ��
		GenListNode<T> *GetNext();//�õ���ǰ������һ�����
		GenListNode<T> *GetPrev();//�õ���ǰ����ǰһ�����
		void MoveToFirst();//��ǰָ��ָ��head
		int Remove();//ɾ����ǰ���
		void View();//�������������
		void ViewList();//���������, ����
};

