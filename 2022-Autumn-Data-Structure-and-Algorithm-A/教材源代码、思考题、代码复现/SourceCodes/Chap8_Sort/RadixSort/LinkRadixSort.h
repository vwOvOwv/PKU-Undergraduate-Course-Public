#pragma once
//���ھ�̬���Ļ�������

//�����
#define Elem int
class Node {
public:
	Elem key;	//���Ĺؼ���ֵ
	int next;	//��һ������������е��±�
};

//��̬������
class StaticQueue{  
public:
    int head;
    int tail;
};

//��̬��ʵ�ֵĻ�������nΪ���鳤�ȣ�dΪ�����������rΪ����
template <class Record>
void RadixSort(Record* Array, int n, int d, int r) { 
	int first=0;						// firstָ��̬���е�һ����¼
	StaticQueue *queue;
	queue = new StaticQueue[r];			// ���r��Ͱ�ľ�̬����
	for (int i=0; i<n-1; i++)			// ��������ʼΪnext��ָ����һ����¼
		Array[i].next = i+1;
	Array[n-1].next = -1;				// ��βnextΪ��
	int i;
	for (i=0; i<d; i++)  {			// �Ե�i����������з�����ռ���һ��d��
		Distribute(Array, first, i, r, queue);
		Collect(Array, first,  r, queue);
	}
	delete[] queue;
//    PrintArray(Array, first);
    AddrSort(Array, n, first);			// ����ʱ������̬����ʹ�����鰴�±�����
}

// �������,A�д�Ŵ������¼��firstΪ��̬���еĵ�һ����¼,iΪ��i�������룬rΪ����
template <class Record>
void Distribute(Record* Array, int first, int i, int r, StaticQueue* queue)  {
	for (int j=0; j<r; j++)				// ��ʼ��r������
		queue[j].head = -1;     
	while (first != -1)  {				// ��������̬�����з���	   
		int k = Array[first].key;		// ȡ��iλ����������k
		for (int a=0; a<i; a++)
			k = k / r;
		k = k % r;
		// ��Array[first]���䵽��k����������
		if (queue[k].head == -1)		// ���������Ϊ�գ�Array[first]���ǵ�һ����¼
			queue[k].head = first;    
		else							// ����ӵ������е�β��
			Array[queue[k].tail].next = first;  
		queue[k].tail = first;			// firstΪ�����е�β��
		first = Array[first].next;		// ����������һ����¼ 
	}
}

// �ռ����̣�Array�д�Ŵ������¼��firstΪ��̬���еĵ�һ����¼��rΪ����
template <class Record>
void Collect(Record* Array, int& first, int r, StaticQueue* queue)  {
	int last, k=0;						// ���ռ��������һ����¼
	while (queue[k].head == -1) 		// �ҵ���һ���ǿն���
		k++;    
	first = queue[k].head;
	last = queue[k].tail;
	while (k < r-1)  {					// �����ռ���һ���ǿն��У���k==r-1���������һ��	
		// ����һ���ǿն���
		k++; 
		while (k < r-1 && queue[k].head == -1) 	// ��ǰ����kΪ�գ�����k���������Ķ���r-1
			k++;					// ��̽��һ������
		if (queue[k].head != -1)  {		// ������ǿ���������һ���ǿ�������������		
			Array[last].next = queue[k].head;	
			last = queue[k].tail;		// ��ʱ���һ����¼Ϊ������е�β����¼
		}
	}
	Array[last].next = -1; 				// �ռ����
}

template <class Record>
void AddrSort(Record *Array, int n, int first)  {	// ����ʱ������̬����ʹ�����鰴�±�����
	int i, j;
    j = first;					// j�����������±꣬��һ��Ϊfirst
	Record TempRec;
	for (i=0; i<n-1; i++)	{			// ѭ��n-1�Σ�ÿ�δ����i���¼
		TempRec = Array[j];		// �ݴ��i��ļ�¼
		Array[j] = Array[i];			// ��ǰ�±�i�����ݴ�ŵ�jλ��
		Array[i] = TempRec;		// ��i���¼��λ
		Array[i].next = j;			// ��i��ļ�¼��next��Ҫ���������켣j
		j = TempRec.next;			//  j�ƶ�����һλ
		while (j <= i)   			// ��j�ȵ�ǰ�±�iС�����ǹ켣��˳���ҵ�����
			j=Array[j].next;
	}
}
