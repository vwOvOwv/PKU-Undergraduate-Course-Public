// abstract data type for List 

template <class T> 
class List  {
      void clear(); 				 	// �ÿ����Ա�
      bool isEmpty();				 	// ���Ա�Ϊ��ʱ������True
      bool append(T value);		 		// �ڱ�β���һ��Ԫ��value����ĳ�����1
      bool insert(int p, T value);	 		// ��λ��p�ϲ���һ��Ԫ��value����ĳ�����1
      bool del(int p); 			 	// ɾ��λ��p�ϵ�Ԫ�أ���ĳ��ȼ� 1
      T getValue(int p);			 	// ����λ��p��Ԫ��ֵ 
      T setValue(int p, T value);	 		// ��value�޸�λ��p��Ԫ��ֵ
}; 
