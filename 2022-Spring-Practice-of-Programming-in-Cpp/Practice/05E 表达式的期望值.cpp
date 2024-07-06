#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>
#include<iomanip>
#include<stack>

using namespace std;

//E[X]=E[sum{2^i*Xi,0<=i<=20}=sum{2^i*E[Xi],0<=i<=20}
/*
λ����ÿһλ�����໥������
���Կ�������λ�������ÿһλ������ֵ
�����õ��ܵ�����ֵ
��ÿһλ����0-1�ֲ�����������ֵ��Ϊ����Ϊ1�ĸ���
*/

double calculate(double left, char op, double right) {
	switch (op)
	{
	case '^':
		return right ? 1 - left : left;//�Ҳ�����1�������Ϊ1��������1-E(�����Ϊ0������)
	case '|':
		return right ? 1 : left;
	case '&':
		return right ? left : 0;
	default:
		return 0;
	}
}
int num[210];
char ops[210];
double prob[210];

int main() {
	int t = 0, n;
	while (cin >> n) {
		n++;
		t++;
		double result = 0;
		int digit = 0;
		for (int i = 0; i < n; i++)
			cin >> num[i];
		for (int i = 1; i < n; i++)
			cin >> ops[i];
		for (int i = 1; i < n; i++)
			cin >> prob[i];
		for (int i = 0; i < 21; i++) {//num[i]<2^20
			double E = (double)((num[0] >> i) & 1);//��ʼ�����׸����ĵ�iλ��Ϊ������,��Ϊ�׸�����������ʧ
			for (int j = 1; j < n; j++)
				E = prob[j] * E + (1 - prob[j]) * calculate(E, ops[j], (num[j] >> i) & 1);
			//����j���������ʧ�����iλ��������ǰһλ��������ͬ(E)��������ʧ���������
			result += E * (double)(1 << digit);//ת����ʮ������
			digit++;
		}
		cout << "Case " << t << ':' << endl;
		cout << fixed << setprecision(6) << result << endl;
	}
	return 0;
}
