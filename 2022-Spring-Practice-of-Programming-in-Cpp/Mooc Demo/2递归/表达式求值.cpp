/*���ʽ��һ�����������Ӽ����
����һ�����ӻ���������˳����
������һ������һ�����ʽ���
*/
//�����ѵ�������λ�������������С�����ģ
#include<iostream>
#include<cstdlib>
#include<cstring>
using namespace std;
int factor_value();//������ֵ
int term_value();//����ֵ
int expression_value();//���ʽ��ֵ
int main()
{
	cout<<expression_value()<<endl;
	return 0;
}
int expression_value(){//��һ�����ʽ��ֵ
	int result=term_value();//�����һ��
	bool more=true;
	while(more){
		char op=cin.peek();//�����滹��û����
		if(op=='+'||op=='-'){//�Ƕ�����Ӽ�
			cin.get();
			int value=term_value();
			if(op=='+')
				result+=value;
			else
				result-=value;
		}
		else
			more=false;//����
	}
	return result;
}
int term_value(){//��һ�����ֵ
	int result=factor_value();//�����һ������
	while(true){
		char op=cin.peek();
		if(op=='*'||op=='/'){//�Ƕ��������˳�
			cin.get();
			int value=factor_value();
			if(op=='*')
				result*=value;
			else
				result/=value;
		}
		else
			break;
	}
	return result;
}
int factor_value(){
	int result=0;
	char c=cin.peek();
	if(c=='('){//�������Ǳ��ʽ
		cin.get();
		result=expression_value();
		cin.get();//��')'����
	}
	else{
		while(c>='0'&&c<='9'){//��һ���������������
			result=10*result+c-'0';//������ֵ
			cin.get();
			c=cin.peek();
		}
	}
	return result;
}
