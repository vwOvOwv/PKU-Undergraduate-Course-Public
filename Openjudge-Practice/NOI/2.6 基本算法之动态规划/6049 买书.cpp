#include<iostream>
#include<cstring>
#include<algorithm>
#include<climits>
//��ȫ���������󷽰���
using namespace std;
int n;
int f[1010];
int g[1010];
int v[5] = {0, 10,20,50,100 };
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		f[i] = INT_MIN;//f[i]Ӧ��ʾ���ǡ��Ϊiʱ�ġ�����ֵ��
	}
	f[0] = 0;
	g[0] = 1;//��Ҫ��
	for (int i = 1; i <= 4; i++) {
		for (int j = 10; j <= n; j++) {//��ȫ��������
			if (j >= v[i]) {
				int t = max(f[j], f[j - v[i]]);//����Ҫ�г���ļ�ֵ������˵������Ϊ��ֵ��0
				int s = 0;
				if (t == f[j])//�жϵ�����Դ
					s += g[j];
				if (t == f[j - v[i]])//else if��
					s += g[j - v[i]];
				f[j] = t;
				g[j] = s;
			}
		}
	}
	cout << g[n] << endl;
	return 0;
}
