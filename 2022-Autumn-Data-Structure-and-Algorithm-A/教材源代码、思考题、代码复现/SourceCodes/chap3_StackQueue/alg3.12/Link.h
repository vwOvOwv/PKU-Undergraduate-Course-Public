
template <class T> class Link {
public: 
    	T  		data;							// ���ڱ�����Ԫ�ص�����
	Link 	* next;						// ָ���̽���ָ��
	
	Link(const T info, Link* nextValue = NULL)  {	// ��������������Link���캯��
		data = info;
		next = nextValue;
	}
	Link(Link* nextValue = NULL)  { 			// ����һ��������Link���캯��
		next = nextValue;
	}
};

