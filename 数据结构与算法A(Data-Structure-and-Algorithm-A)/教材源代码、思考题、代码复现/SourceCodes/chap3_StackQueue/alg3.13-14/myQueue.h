template <class T> 
class Queue  { 
public: 			        		// ���е����㼯
void clear();					// ��Ϊ�ն���
bool enQueue(const T& item); 	// item��ӣ������β���ɹ��򷵻�����򷵻ؼ�
bool deQueue(T& item);     	// ���ض�ͷԪ�ز��Ӷ�����ɾ�����ɹ��򷵻���
bool front(T& item);	       	// ���ض�ͷԪ�أ�����ɾ�����ɹ��򷵻���
bool isEmpty(); 				// �����棬�������ѿ�
bool isFull();       			// �����棬����������
};
