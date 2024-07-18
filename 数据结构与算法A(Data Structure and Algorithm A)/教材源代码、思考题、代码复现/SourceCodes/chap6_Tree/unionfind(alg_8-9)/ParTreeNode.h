//��ParTreeNode���������Ľ�㶨��
template<class T>
class ParTreeNode  { 					    //����㶨��
private:
	T				value;					//����ֵ
	ParTreeNode<T>* parent;					//�����ָ��
	int		nCount;							//�Դ˽��Ϊ�����������ܽ�����
public:
	ParTreeNode();							//���캯��
	virtual ~ParTreeNode(){};				//��������
	T	getValue();							//���ؽ���ֵ
	void  setValue(const T& val);			//���ý���ֵ
	ParTreeNode<T>*  getParent();			//���ظ����ָ��
	void  setParent(ParTreeNode<T>* par);	//���ø����ָ��
	int   getCount();						//���ؽ����Ŀ
	void  setCount(const int count);		//���ý����Ŀ
};

//ParTreeNode�����������ͳ�Ա������ʵ��
template<class T>
ParTreeNode<T>::ParTreeNode()  {            //���캯��
	parent = NULL;
	nCount = 1;
}
template<class T>
T ParTreeNode<T>::getValue()  {				//���ؽ���ֵ
	return value;
}
template<class T>
void ParTreeNode<T>::setValue(const T& val)  {			//���ý���ֵ
	value = val;
}
template<class T>
ParTreeNode<T>* ParTreeNode<T>::getParent()  {			//���ظ����ָ��
	return parent;
}
template<class T>
void ParTreeNode<T>::setParent(ParTreeNode<T>* par)  {   //���ø����ָ��
	parent = par;
}
template<class T>
int ParTreeNode<T>::getCount()  {						//���ؽ����Ŀ
	return nCount;
}
template<class T>
void ParTreeNode<T>::setCount(const int count)  {		//���ý����Ŀ
	nCount = count;
}