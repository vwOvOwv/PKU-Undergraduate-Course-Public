
#include <iostream>

#include "arrStack.h"

using namespace std;

bool knap(int s, int n);
bool nonRecKnap(int s, int n);
bool nonRecKnapOpt(int s, int n);

enum rdType {a, b, c}; 

class knapNode {
      friend  bool nonRecKnap(int s, int n);
      friend  bool nonRecKnapOpt(int s, int n);
       int 		s, n;  	      // �����ĳ���������Ʒ����Ŀ
       rdType	rd; 		  // ���ص�ַ
       bool		k;		      // �����Ԫ	
}; 
// ����������ջ�н��������ͬ�ı���tmp��x��Ϊ����ջ�Ļ��壺
class knapNode 	tmp, x;

// ����һ��ջ������
//Stack<knapNode> st(20); 


int w[5] = {2,4,4,5,7};

int main() {
    int s;
    
    cin >> s; 
    
    cout << "recursion" << endl; 
    if (knap(s, 5))  
        cout << "Have solution" << endl;
    else  cout << "No solution" << endl;
       
       
    cout << "non recursion" << endl;  
    if (nonRecKnap(s, 5))  
        cout << "Have solution" << endl;
    else  cout << "No solution" << endl;
   
    cout << "non recursion optimization" << endl;     
    if (nonRecKnapOpt(s, 5))  
        cout << "Have solution" << endl;
    else  cout << "No solution" << endl;

cin >> s; 
   
    return 0;
} 


//�ݹ��ı������� 
bool knap(int s, int n) {
		if (s == 0)  
			return true;
		if ((s < 0)||(s>0 && n <1))
			return false;
 		if (knap(s-w[n-1], n-1)) {
			cout << w[n-1];
			return true;
		} 
		else knap(s, n-1); 
}
// �ǵݹ�Ļ�е�� 
bool nonRecKnap(int s, int n) {
     arrStack<knapNode> st(20);  
		tmp.s = s,  tmp.n = n,  tmp.rd = a; 	// �ǵݹ�������
		st.push(tmp);
  label0:								 // �ݹ�������
		st.pop(&tmp); 
		if (tmp.s == 0 ) { 	
			tmp.k = true;				// �޸�ջ���Ľ����Ԫk
			st.push(tmp);
            goto label3;
		}
        if ((tmp.s < 0) || (tmp.s > 0 && tmp.n < 1)) {
			tmp.k = false;				// �޸�ջ���Ľ����Ԫk
			st.push(tmp);
            goto label3;
		}
		st.push(tmp);
        x.s = tmp.s-w[tmp.n-1]; 			// ���չ���1����ѹջ����
		x.n = tmp.n -1;
		x.rd = b;
		st.push(x);
		goto label0;
	label1: 							// ����1��Ӧ�ķ��ش���
		st.pop(&x);					// �鿴ջ�������������ݷ��������
        if (tmp.k == true) {			// ��ĳ��Ľ����ԪΪtrue
			x.k = true;					// ��true����ϴ������÷�
			st.push(x);
			cout << w[x.n-1]<<endl;		// �������Ӧ����Ʒ
			goto label3;
		}
		st.push(x);					// ��ĳ��Ľ����ԪΪfalse
        tmp.s = x.s;					// ��ǰ��Ʒ��ѡ�񲻺��ʣ����ݣ����ù���2
		tmp.n = x.n - 1;					// ���չ���2����ѹջ����
		tmp.rd = c;
		st.push(tmp);
		goto label0;
  	 label2: 							// ����2��Ӧ�ķ��ش���
		st.pop(&x);
		x.k = tmp.k;					// �����Ԫk�������ϴ������÷�
		st.push(x);
     label3:							// �ݹ���ڴ���
		st.pop(&tmp);
		switch (tmp.rd) {
			case a:  	return tmp.k; 		// �㷨���������ؽ��
			case b:	goto label1;		// ת�����1�ķ��ش���
		 	case c:	goto label2;		// ת�����2�ķ��ش���
		}
}	 

// �ǵݹ���Ż��� 
bool nonRecKnapOpt(int s, int n) {
	int 	t, n0 = n;
    bool 	k = false;
    arrStack<knapNode> st(20);  
    
	tmp.s = s, tmp.rd = a; 
	st.push(tmp);

	while (!st.isEmpty()) {
		t = st.top;
		st.getTop(&tmp);
		while ((tmp.s >= 0) && (tmp.s <= 0 || n0 > t)){  //����ջ��Ԫ�أ����ж��Ƿ�����ݹ��������
              if (tmp.s == 0 ) { 
				k = true;
				break;
			  } else {						// ��δ�ݴ�����ǰ��������1����ѹջ����
				x.s = tmp.s - w[n0 - 1 - t];
				x.rd = b;
				st.push(x);
			  }
			  t = st.top;
			  st.getTop(&tmp);
		}
		while (!st.isEmpty()) {				// ���ش���			
              st.pop(&tmp);
              t = st.top;
              if (tmp.rd == 0) 					// �㷨����
                 return k; 
              if (tmp.rd == 1) 					// �ӹ���1����
		         if (k == true) 				// ���Ϊ�����ӡ��Ӧ����Ʒ
                       cout << w[n0 - 1 - t]<<endl;	
                 else {						// ������ݣ����ù���2��ջ
                      st.getTop(&x);
                      tmp.s = x.s;
                      tmp.rd = c;
                      st.push(tmp);
                      break;
				}
		}
	}
}	 


