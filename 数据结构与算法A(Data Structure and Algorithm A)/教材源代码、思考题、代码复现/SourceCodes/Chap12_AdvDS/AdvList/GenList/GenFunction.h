// ��������ʵ��
#include "GenList.h"



//GenListNode�Ĺ��캯��
/*
template<class T>
GenListNode<T>::GenListNode(GenListNode<T> *list)
{
	//
	type=LIST;
    child=list;
	next=NULL;
	mark=0;
	ref=0;
}


template <class T>
GenListNode<T>::GenListNode(T element)
{
	    type=ATOM;
		child=NULL;
		this->element=element;
		next=NULL;
		mark=0;
		ref=0;
}
*/


template <class T>
GenListNode<T>::GenListNode()
{
	    type=LIST;
		child=NULL;
}
//GenListNode����������
template <class T>
GenListNode<T>::~GenListNode()
{
	//free all the memery 
    Destroy(this);
}

//�ͷ��ڴ�
template <class T>
void GenListNode<T>::Destory(GenListNode<T> *node)
{
	if(node->next!=NULL)
		Destroy(node->next);
	if(node->child!=NULL)
		Destroy(node->child);
	delete node;
}

/*
template <class T>
void GenListNode<T>::Search(GenListNode<T> *node,GenListNode<T> *prenode,int &flag) 
{   //flag Ϊ���ݱ�־
	if (node->type==HEAD)	{//����һ����ͷ��㣬׼�����������ӱ�
		node->mark=VISITED;
		Search(node->next,node,flag);
	}
	else	{//�Ǳ�ͷ��㣬����ÿһ��element���
      if (node->type==ATOM) {
		cout<<node->element;
		node->mark=VISITED;
	    } 
      else if(node->type==LIST) {
			node->mark=VISITED;
			cout<<"(";
			Search(node->child,node,flag);
			cout<<")";
		}
      if((node->next!=NULL)&&(node->next->mark!=VISITED)) {//û�з��ʹ������������
		  cout<<",";
		  node->mark=VISITED;
		  Search(node->next,node,flag);
		}
	  else if((node->next!=NULL)&&(node->type==ATOM))  //������ʹ�������
		      flag=BACKTRACE; //mark==VISITED����Ҫ���л���
	
	  if(flag==BACKTRACE)	{//���ݲ���
		  node->mark=UNVISITED;
		  if(prenode==NULL) 	{//���ݵ���һ����㣬����
			 flag=NOTBACKTRACE;
			 return;
		  }
		  if((prenode->child=node)&&(prenode->next!=NULL)&&(prenode->next->mark==0)) {//���ݵ����Խ������������ĵط�
			 flag=NOTBACKTRACE;
			 return;
		  }
	   }	
	}
	//���ղŽ���������markֵ������ΪUNVISITED
	GenListNode<T>*temp=node;
	while(temp!=NULL)	{
		temp->mark=UNVISITED;
		temp=temp->next;
	}
}
*/

template <class T>
void GenListNode<T>::GenListTraversalHelp(GenListNode<T> *node) 
{   
	GenListNode<T> *p;
	node->headNode.mark=VISITED;
	cout << "(";
	for (p = node->next; p!=NULL; p=p->next) {
		//p->mark=VISITED;
		if ((p->type==LIST)&&(p->child!=NULL)) {	//����һ����ͷ��㣬׼�����������ӱ�
			   cout << p->child->headNode.Name;
			   if (p->child->headNode.mark == UNVISITED)  {
				  if (p->child->headNode.Name[0]!='\0')
				  cout <<":";	
			      GenListTraversalHelp(p->child);
			   }
		}
		else if (p->type==ATOM) 
		    cout<<p->element;
		if ((p->next!=NULL)&&(p->next->type!=HEAD))
		    cout << ", ";
	}
	cout << ")";
}

/*
template <class T>
void GenListNode<T>::GenListTraversalHelp(GenListNode<T> *node) 
{   //flag Ϊ���ݱ�־
	GenListNode<T> *p;
	node->mark=VISITED;
	cout << "(";
	for (p = node->next; (p!=NULL)&&(p->type!=HEAD); p=p->next) {
		p->mark=VISITED;
		if ((p->type==LIST)&&(p->child!=NULL)) {	//����һ����ͷ��㣬׼�����������ӱ�
			   cout << p->child->headNode.Name;
			   if (p->child->mark == UNVISITED)  {
				  if (p->child->headNode.Name[0]!='\0')
				  cout <<":";	
			      GenListTraversalHelp(p->child);
			   }
		}
		else if (p->type==ATOM) 
		    cout<<p->element;
		if ((p->next!=NULL)&&(p->next->type!=HEAD))
		    cout << ", ";
	}
	cout << ")";
}
*/

template <class T>
void GenListNode<T>::ViewAll()
{
	int flag=NOTBACKTRACE;
	cout<<"(";
	GenListTraversal(this,NULL,flag);
	cout<<")";
}
//�����Ĺ��캯��

template <class T>
GenList<T>::GenList(char *Name)
{
	head= new GenListNode<T>();
	head->next=NULL;
	head->type=HEAD;
	head->headNode.ref=0;
	head->headNode.Name = Name;
	current=head;
}


//�����Ĳ��뺯��
template <class T>
void GenList<T>::Insert(T element)
{
	GenListNode<T> *temp=current;
	current=new GenListNode<T>();
	current->type=ATOM;
	current->child=NULL;
	current->element=element;
	temp->next=current;
	current->next=NULL;

}

template <class T>
void GenList<T>::Insert(GenList<T> *genlist)
{
	GenListNode<T> *temp=current;
	GenListNode<T> *n=genlist->GetHead();
	n->headNode.mark=UNVISITED;
	n->headNode.ref++;
   	current=new GenListNode<T>();
	current->child=n;
	current->next=NULL;
	current->type=LIST;
	temp->next=current;
}

//�õ�ͷָ��
template <class T>
GenListNode<T>* GenList<T>::GetHead()
{
	return head;
}

//�õ���һ�����
template <class T>
GenListNode<T>* GenList<T>::GetNext()
{
	if(current->next!=NULL)
	{
		current=current->next;
		return current;
	}
	else return NULL;
}
//�õ���ǰ����ǰһ�����
template <class T>
GenListNode<T>* GenList<T>::GetPrev()
{
	GenListNode<T> *temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		if(temp->next==current)
			return temp;
	}
	return NULL;
}
//ɾ����ǰ���,��ǰ���ָ��ָ����һ�����
template <class T>
int GenList<T>::Remove()
{
	if(current==NULL)
		return -1;
	if(current==head)
		return -2;
	GenListNode<T> *prev=GetPrev();
	GenListNode<T> *next=GetNext();
	prev->next=next;
    GenListNode<T> *temp=current;
	if(next==NULL)
		current=prev;
	else current=next;
	temp->Destory();

}
//move current point to head point
template <class T>
void GenList<T>::MoveToFirst()
{
	current=head;
}


//��������
template <class T>
GenList<T>::~GenList()
{
    current=head->next;
	while(current!=head)
		Remove();
    delete head;
}

template <class T>
void GenList<T>::View()
{
//	cout<<"(";
	MoveToFirst();
//	GenListNode<T> *temp=GetNext();
	int first=1;
    current->ViewAll();
		//temp=GetNext();

//	cout<<")";
}


template <class T>
void GenList<T>::ViewList()
{
	MoveToFirst();
	int first=1;
    current->GenListTraversal();
}


template <class T>
void GenListNode<T>::GenListTraversal()
{
	GenListTraversalHelp(this);
}