//****************   WinnerTree.h   *****************//
#define MAX 8		//ѡ����

template<class T>
class WinnerTree  {
public:
	WinnerTree(int TreeSize = MAX);
	~WinnerTree() {delete [] B;} 
	void Initialize(T A[], int size, int(*winner)(T A[], int b, int c));  //��ʼ��Ӯ����
	int Winner()  const {return (n) ? B[1] : 0;}     ////��������ʤ�ߵ���������Ӯ�����������������B[1]��
	int Winner(int i) const {return (i < n) ? B[i] : 0;}
	void RePlay(int i, int(*winner) (T A[], int b, int c)); //λ��i���ⲿѡ�ָı���ع�Ӯ����
	void Output() const;
private:
	void Play(int p, int lc, int rc, int(*winner)(T A[], int b, int c));

	int MaxSize;	 //��������ѡ����
	int n;			 //��ǰѡ����
	int LowExt;		 //��ײ��ⲿ�����
	int offset;	     //��ײ��ⲿ���֮�ϵĽ������
	int *B;          //Ӯ�������飬ʵ�ʴ�ŵ����±�
	T *L;            //Ԫ������
};

//���캯��
template<class T>
WinnerTree<T>::WinnerTree(int TreeSize)  {
	MaxSize = TreeSize;
	B = new int[MaxSize];
	n = 0;
}

//��ʼ��Ӯ����
template<class T>
void WinnerTree<T>::Initialize(T A[], int size, int(*winner)(T A[], int b, int c))  {
	if (size > MaxSize || size < 2)   //�ܷ���size��ѡ�ֵ�����A[]
		return; 
	n = size;                   //��ʼ����Ա����
	L = A; 
	int i, s;
	for (s = 1; 2*s <= n-1; s += s);  //���� s = 2^log(n-1)
	LowExt = 2*(n - s);
	offset = 2*s - 1; 
	for (i = 2; i <= LowExt; i += 2)     //��ײ��ⲿ���ı���
		Play((offset+i)/2, i-1, i, winner); 
//���������ⲿ���
//��nΪ�������ڲ������ⲿ��������������L[LowExt+1]�����ĸ�������
	if (n % 2)  {
		Play(n/2, B[n-1], LowExt+1, winner);
		i = LowExt + 3;
	}
	else 
		i = LowExt + 2;
	for (; i <= n; i += 2)        //ʣ���ⲿ���ı���
		Play((i-LowExt+n-1)/2, i-1, i, winner);
}


//���ڲ����B[p]����ʼ����
template<class T>
void WinnerTree<T>::Play(int p, int lc, int rc, int(*winner)(T A[], int b, int c))  {
	B[p] = winner(L, lc, rc); 		//ʤ����������B[p]��
	while (p > 1 && p % 2)   {     //�Һ��ӣ���Ҫ��·���������ϱ���
		B[p/2] = winner(L, B[p-1], B[p]);
		p /= 2;  //�����
	}
}


//��Ա����RePlay����ѡ��i��ֵ�ı�����¿�ʼ����
template<class T>
void WinnerTree<T>::RePlay(int i, int(*winner)(T A[], int b, int c))  {
	if (i <= 0 || i > n) 
		return; 
int p, lc, 	rc;     	//������㼫�����Һ��ӵ��±�
if (i <= LowExt)  {	    //����ײ㿪ʼ
		p = (offset  +  i)/2;
		lc = 2*p - offset; // left child of p
		rc = lc+1;
	}
	else  {
		p = (i-LowExt+n-1)/2;
		if (2*p == n-1)  {
			lc = B[2*p];
			rc = i;
		}
		else  {
			lc = 2*p - n  +  1  +  LowExt;
			rc = lc+1;
		}
	} 
	B[p] = winner(L, lc, rc); 	 //B[p]�б���Ӯ�ߵ�����
	//���ʣ�µı���
	p /= 2;
	for (; p >= 1; p /= 2)       //��·�����ϱ���
		B[p] = winner(L, B[2*p], B[2*p+1]);
}


//�������
template<class T>
void WinnerTree<T>::Output() const  {
	cout << "��ǰѡ����(size) = "<< n << " ��ײ��ⲿ�����(LowExt) = " << LowExt
         << " ��ײ��ⲿ���֮�ϵĽ������(Offset) = " << offset << endl;
	cout << "Ӯ����B:" << endl;
	for (int i = 1; i < n; i++)
		cout << B[i] << ' ';
	cout << endl << endl;
}

//����Ӯ��
int winner(int A[], int b, int c)  {
	if (A[b] <= A[c])
		return b;
	return c;
}