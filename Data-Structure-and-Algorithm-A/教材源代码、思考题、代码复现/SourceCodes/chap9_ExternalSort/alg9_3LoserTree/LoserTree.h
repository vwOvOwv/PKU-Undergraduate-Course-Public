//**************   LooserTree.h   ***************//

// �������ܣ�����Ӯ��
int winner(int A[], int b, int c)  {
	return A[b]<=A[c] ? b:c;
}

// �������ܣ����ذ���
int loser(int A[], int b, int c)  {
	return A[b]>A[c] ? b:c;
}

// class
// -----------------------------------------------------------------------------------------------
template <class T>
class LoserTree  {
public:
	LoserTree(int Treesize);
	~LoserTree() {delete [] B;}; 
	void Initialize(T A[], int size, int(*winner)(T A[], int b, int c), int(*loser)(T A[], int b, int c));
	int Winner();
	void RePlay(int i,  int(*winner)(T A[], int b, int c), int(*loser)(T A[], int b, int c));
	void Output() const;
	
private:
	void Play(int p, int lc, int rc,  int(*winner)(T A[], int b, int c), int(*loser)(T A[], int b, int c));
					// ���ڲ������ҷ�֧���ϱ���
	int MaxSize; // ���ѡ����
	int n;   // ��ǰѡ����
	int LowExt;  // ��ײ��ⲿ����� lowest-level external nodes
	int offset;  // ��ײ��ⲿ���֮�ϵĽ���� 2^k - 1
	int *B;   // Ӯ�������� array for winner tree
	T *L;   // ѡ������ element array
};

//���캯��
template<class T>
LoserTree<T>::LoserTree(int TreeSize)  {
	MaxSize = TreeSize;
	B = new int[MaxSize];
	n = 0;
}

//��Ա����Winner����������ʤ�ߵ��������ڰ�������������������B[0]��
template<class T>
int LoserTree<T>::Winner()  {  // ��������ʤ�ߵ�����B[0]
	return (n)?B[0]:0;
}

//��Ա����Initilalize�����ʼ��������
template<class T>
void LoserTree<T>::Initialize(T A[], int size, int(*winner)(T A[], int b, int c),
							  int(*loser)(T A[], int b, int c))   {// ��ʼ��������
	if(size > MaxSize || size < 2)  {        //�ܷ���size��ѡ�ֵ�����a[]
		cout<<"Bad Input!"<<endl<<endl;
		return;
	}	
	n = size;                    //��ʼ����Ա����
	L = A;	
	int i,s;
	for(s = 1; 2*s <= n-1; s += s);    //����s = 2^log(n-1)
	LowExt = 2*(n-s);
	offset = 2*s-1;
	//��ײ��ⲿ���ı���
	for(i = 2; i <= LowExt; i += 2)     // ��ײ��ⲿ���ı���
		Play((offset+i)/2, i-1, i, winner, loser);
	//���������ⲿ���
	if(n%2)  {           // nΪ�������ڲ������ⲿ����һ��
		Play(n/2, B[(n-1)/2], LowExt+1, winner, loser);//�ݴ��ڸ�������ʤ�����ⲿ���ӽ���
		i = LowExt+3;
	}
	else
		i = LowExt+2;	
	for(; i <= n; i += 2)   // ʣ���ⲿ���ı���
		Play((i-LowExt+n-1)/2, i-1, i, winner, loser);  
}

//��Ա����Play�������ڲ����B[p]����ʼ����
template<class T>
void LoserTree<T>::Play(int p, int lc, int rc, int(* winner)(T A[],
						int b, int c), int(* loser)(T A[], int b, int c))  {  // ���ڲ������ҷ�֧���ϱ���
	B[p] = loser(L, lc, rc);       //������������B[p]��			
	int temp1, temp2;
	temp1 = winner(L, lc, rc);    //p����ʤ������
	while(p>1 && p%2)  {       // pΪ�����Һ��ӣ���·���������ϱ���
		temp2 = winner(L, temp1, B[p/2]);
		//p��ʤ�ߺ�p�ĸ����Ƚϣ�Ӯ���ݴ���temp2��
		B[p/2] = loser(L, temp1, B[p/2]);                //������������B[p/2]
		temp1 = temp2;         // ʤ�߷���temp1
		p/=2;
	}//while
	B[p/2] = temp1;             // B[p]�����ӻ���p=1������
	
}

//��Ա����RePlay����ѡ��i��ֵ�ı�����¿�ʼ����
template<class T>
void LoserTree<T>::RePlay(int i, int (*winner)(T A[], int b, int c), 
						  int (*loser)(T A[], int b, int c))  {  // ѡ��i��ֵ�ı�����¿�ʼ����
	int p;               // ���ڼ��㸸�����������ʱ����
	if(i <= 0 || i > n)  {
		cout<<"Out of Bounds!"<<endl<<endl;
		return;
	}
	//ȷ��������λ��
	if (i <= LowExt)
		p = (i+offset)/2;
	else
		p = (i-LowExt+n-1)/2;
	B[0] = winner(L, i, B[p]);         //B[0]��ʼ�ձ���ʤ�ߵ�����
	B[p] = loser(L, i, B[p]); 	      //B[p]�б�����ߵ�����
	for(; (p/2) >= 1; p/=2)  { 	      //��·�����ϱ���
		int temp;//��ʱ���Ӯ�ߵ�����
		temp = winner(L,B[p/2], B[0]);
		B[p/2] = loser(L,B[p/2], B[0]);
		B[0] = temp;
	}
}


// �������ܣ����
template<class T>
void LoserTree<T>::Output() const  {
	cout << "��ǰѡ����(size) = "<< n << " ��ײ��ⲿ�����(LowExt) = " << LowExt
         << " ��ײ��ⲿ���֮�ϵĽ������(Offset) = " << offset << endl;
	cout << "������B��B0���ʤ���±꣩: " << endl;
	for (int i = 0; i < n; i++)
		cout << B[i] << ' ';
	cout << endl << endl;
}