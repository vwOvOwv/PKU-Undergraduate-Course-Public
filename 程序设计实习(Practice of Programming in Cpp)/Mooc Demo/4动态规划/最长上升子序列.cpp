//�����Ͷ�̬�滮
//�����⣺����akΪ�յ㣨����ak��������������еĳ���
//ps.�������޺�Ч�Ե��������޷�д�����Ʒ���
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 1010;
int a[maxn];
int maxlen[maxn];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		maxlen[i] = 1;
	}
	for (int i = 2; i <= n; i++)//ÿ�����Ե�i����Ϊ�յ������������г���
		for (int j = 1; j < i; j++)//�鿴�Ե�j����Ϊ�յ������������г���
			if (a[i] > a[j])
				maxlen[i] = max(maxlen[i], maxlen[j] + 1);//ע��+1
	cout << *max_element(maxlen + 1, maxlen + n + 1);
	return 0;
}
