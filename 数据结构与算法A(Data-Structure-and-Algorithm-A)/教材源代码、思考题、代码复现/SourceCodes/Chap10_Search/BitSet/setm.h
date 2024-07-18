#include <string>
#include <iostream>
//using namespace std;


template<size_t N> 
class mySet {
	typedef unsigned long ulong;
private:
	enum {
		NB = 8 * sizeof (ulong),			//unsigned long�������͵�λ����Ŀ
		LI = N == 0 ? 0 : (N - 1) / NB		//�������һ��Ԫ�ص��±�
	};

	ulong A[LI + 1];						//���λ����������
	void Tidy(ulong X = 0);					//�������е�ÿ��Ԫ�����X
	void Trim();							//����ʹ�õ�λ���0

public:	
	mySet() ;								//���캯��
	mySet(ulong X);
	
	mySet<N>& set();						//����Ԫ������
	mySet<N>& set(size_t P, bool X = true);
	mySet<N>& reset();						//�Ѽ�����Ϊ��
	mySet<N>& reset(size_t P);				//ɾ��Ԫ��P
	
	bool at(size_t P) const;				//��������
	bool operator[](size_t P) const ;

	mySet<N>& flip();						//��
	mySet<N>& flip(size_t P);				
	ulong to_ulong() const;
	std::string to_string() const;				
	size_t count() const;					//���㼯����Ԫ����Ŀ
	size_t size() const;

	bool test(size_t P) const;				
	bool any() const;						//�жϼ����Ƿ����Ԫ��
	bool none() const;						//�жϼ����Ƿ�Ϊ��

	mySet<N> operator~() const;					//������
	mySet<N>& operator&=(const mySet<N>& R);	//������
	mySet<N>& operator|=(const mySet<N>& R);	//������
	mySet<N>& operator^=(const mySet<N>& R);	//������

	bool operator==(const mySet<N>& R) const;	//����
	bool operator!=(const mySet<N>& R) const;	//����
	bool operator<=(const mySet<N>& R) const;	//������
	bool operator< (const mySet<N>& R) const;	//�������
	bool operator>=(const mySet<N>& R) const;	//����
	bool operator>(const mySet<N>& R) const;	//�����

	friend mySet<N> operator&(const mySet<N>& L, const mySet<N>& R){  //������
		return (mySet<N>(L) &= R); 
	};
	friend mySet<N> operator|(const mySet<N>& L, const mySet<N>& R){  //������
		return (mySet<N>(L) |= R); 
	};
	friend mySet<N> operator-(const mySet<N>& L, const mySet<N>& R){  //������
		return (mySet<N>(L) & ~R); 
	};
	friend mySet<N> operator^(const mySet<N>& L, const mySet<N>& R){  //�������
		return (mySet<N>(L) ^= R); 
	};
	friend std::ostream& operator<<(std::ostream& O, const mySet<N>& R){        //����<<�����
		for (size_t P = 0; P < N; P++ )
			O << (R.test(P) ? '1' : '0');
		return (O); 
	};

	};

template<size_t N>  void mySet<N>::Tidy(ulong X){   //�������е�ÿ��Ԫ�����X
	for (int I = LI; I >= 0; I--)
			A[I] = X;
	if (X != 0)
			Trim(); 
}

template<size_t N>  void mySet<N>::Trim(){			//����ʹ�õ�λ���0
	if (N % NB != 0)
			A[LI] &= ((ulong)1 << N % NB) - 1;
}

template<size_t N> 	mySet<N>::mySet(){				//���캯��
	Tidy();
}

template<size_t N> 	mySet<N>::mySet(ulong X){
	Tidy();
	for (size_t P = 0; X != 0 && P < N; X >>= 1, ++P)
		if (X & 1)
			set(P); 
}

template<size_t N> mySet<N>& mySet<N>::set(){		//����Ԫ������
	Tidy(~(ulong)0);
	return (*this); 
}

/*
template<size_t N>	mySet<N>& mySet<N>::set(size_t P){
	A[P / NB] |= (ulong)1 << P % NB;
	return (*this); 
}
*/


template<size_t N>	mySet<N>& mySet<N>::set(size_t P, bool X){
	if (X)   									// XΪ�棬λ��������Ӧֵ��Ϊ1
		A[P / NB] |= (ulong)1 << (P % NB); 		// P��Ӧ��Ԫ�ؽ��а�λ������
	else									
		A[P / NB] &= ~((ulong)1 << (P % NB));	// XΪ�٣�λ��������Ӧֵ��Ϊ0
	return (*this); 
}

template<size_t N> mySet<N>& mySet<N>::reset(){				//�Ѽ�������Ϊ��
	Tidy();
	return (*this); 
}

template<size_t N> mySet<N>& mySet<N>::reset(size_t P){		//�Ѿ���Ԫ������Ϊ��
	return set(P, 0);
}

template<size_t N> bool mySet<N>::at(size_t P) const{		//��������
	return (test(P)); 
}
	
template<size_t N> bool mySet<N>::operator[](size_t P) const {
	return (test(P)); 
}

template<size_t N> mySet<N>& mySet<N>::flip(){				//�������
	for (int I = LI; I >= 0; I--)
		A[I] = ~A[I];
	Trim();
	return (*this); 
}

template<size_t N> mySet<N>& mySet<N>::flip(size_t P){      // ȡ��
	A[P / NB] ^= (ulong)1 << P % NB;
	return (*this); 
}

template<size_t N> unsigned long mySet<N>::to_ulong() const{ // ת��Ϊulong����
	return A[0]; 
}

template<size_t N> std::string mySet<N>::to_string() const{   // ��0��1��ʽ�Ѽ�������������ַ���
	std::string S;
	S.reserve(N);
	for (size_t P = N; 0 < P; )
		S += test(--P) ? '1' : '0';
	return (S); 
}

template<size_t N> size_t mySet<N>::count() const{      //���㼯��Ԫ����Ŀ
	size_t V = 0;
	for (int I = LI; I >= 0; I--)
		for (ulong X = A[I]; X != 0; X >>= 4)
			V += "\0\1\1\2\1\2\2\3"						//"\0\1\1\2\1\2\2\3\1\2\2\3\2\3\3\4"����ʮ��������0-F������1����Ŀ������
				"\1\2\2\3\2\3\3\4"[X & 0xF];			
	return (V); 
}

template<size_t N> size_t mySet<N>::size() const{        
	return (N); 
}
	
template<size_t N> bool mySet<N>::test(size_t P) const{   
	return ((A[P / NB] & ((ulong)1 << P % NB)) != 0); 
}

template<size_t N> bool mySet<N>::any() const{           //�жϼ����Ƿ����Ԫ��
	for (int I = LI; I >= 0; I--)
		if (A[I] != 0)
			return (true);
	return (false); }

template<size_t N> bool mySet<N>::none() const{          //�жϼ����Ƿ�Ϊ��
	return (!any()); 
}

template<size_t N> mySet<N> mySet<N>::operator~() const{	//������
	return (mySet<N>(*this).flip()); 
}

template<size_t N>	mySet<N>& mySet<N>::operator&=(const mySet<N>& R) { //��ֵ��
	for (int I = LI; I >= 0; I--)			// �ӵ�λ����λ
		A[I] &= R.A[I];						// ��ulongԪ��Ϊ��λ��λ��
	return (*this); 
}

template<size_t N>	mySet<N>& mySet<N>::operator|=(const mySet<N>& R) { //����������
	for (int I = LI; I >= 0; I--)
		A[I] |= R.A[I];
	return (*this); 
}

template<size_t N>	mySet<N>& mySet<N>::operator^=(const mySet<N>& R) {  //����������
	for (int I = LI; I >= 0; I--)
		A[I] ^= R.A[I];
	return (*this); 
}
	
template<size_t N>	bool mySet<N>::operator==(const mySet<N>& R) const{  //��������
	for (int I = LI; I >= 0; I--)
		if (A[I] != R.A[I])
			return (false);
	return (true); }

template<size_t N>	bool mySet<N>::operator!=(const mySet<N>& R) const{  //��������
	return (!(*this == R)); 
}
	
template<size_t N>	bool mySet<N>::operator<=(const mySet<N>& R) const{  //����������
	return ((mySet(*this) |= R) == R);
}

template<size_t N>	bool mySet<N>::operator<(const mySet<N>& R) const{   //���������
	 return ((*this <= R) && (*this != R));
}

template<size_t N>	bool mySet<N>::operator>=(const mySet<N>& R) const{  //��������
	return ((mySet(*this) &= R) == R);
}

template<size_t N>	bool mySet<N>::operator>(const mySet<N>& R) const{   //���������
	return ((*this >= R) && (*this != R));	
}

/*  &����ֻ��friend, LI����δ����
template<size_t N>	 mySet<N> operator&( const mySet<N>& L,  const mySet<N>& R) {//������
	mySet<N> s = L;
	for (int I = LI; I >= 0; I--)
		s.A[I] &= R.A[I];
	return s; 	
}
*/