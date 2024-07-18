#include <iostream>

#include "arrStack.h"

// Class Declaration ���˵��
class Calculator  { 
private:
      arrStack<double> s;		// ���ջ����ѹ�뱣�������
      bool GetTwoOperands(double& opd1, double& opd2); 	// ��ջ����������������opd1��opd2
      void Compute(char op);  	// ����GetTwoOperands������op������������������м���
  public:
//       Calculator(){} ;		// ����������ʵ��������һ����ջ
      void Run();		    // ��׺���ʽ�Ķ��룬����������"="ʱ ��������ֵ���� 
      void Clear();   		// �������������Ϊ������һ�μ�����׼��  
};

// ��������class Calculator�в��ֳ�Ա�����ĳ���ʵ��
bool Calculator::GetTwoOperands(double& opd1, double& opd2)  { 
   	if (s.isEmpty()) {
    		cerr << "Missing operand!" <<endl;
    		return false;
   	}
     s.pop(&opd1); 							// �Ҳ�����
   	if (s.isEmpty())  {
    		cerr << "Missing operand!" <<endl;
    		return false;
   	}
   	s.pop(&opd2)	;						// �������
   	return true;
}

void Calculator::Compute(char op)  { 
  	bool result;
  	double operand1, operand2;
  	result = GetTwoOperands(operand1, operand2);
  	if (result == true)
    		switch(op)  {
        		case '+' : 	s.push(operand2 + operand1);
                   	break;
        		case '-' : 	s.push(operand2 - operand1);
                   	break;
        		case '*' : 	s.push(operand2 * operand1);
                   	break;
        		case '/' :	if (operand1 == 0.0)  {
                   		cerr << "Divide by 0!" << endl;
                   		s.clear();
                   	}
                   	else
                   		s.push(operand2 / operand1);
                   	break;
    		}
  	else
      	s.clear();
}

void Calculator::Run(void)  { 
 	char c;
 	double newOperand, res;
 	while (cin >> c, c != '=')  {     
    		switch(c)  {
        		case '+' :                         
        		case '-' :
        		case '*' :
        		case '/' :
                    Compute(c);           
                    break;
        		default :                         
                    cin.putback(c);         
                    cin >> newOperand;     
                    s.push(newOperand);     
                    break;
    		}
  	}
 	if (!s.isEmpty()) {
		s.pop(&res);
        cout << res << endl; 					// ӡ����ֵ�������
   }		
}

