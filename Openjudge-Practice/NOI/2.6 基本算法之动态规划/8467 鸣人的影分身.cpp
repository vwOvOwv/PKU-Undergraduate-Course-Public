//���⼴Ϊ��ƻ���Ķ����
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int t;
int m, n;
int f[20][20];
int main()
{
	cin >> t;
	while (t--) {
		cin >> m >> n;
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= n; i++)
			f[0][i] = 1;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {//j��ȡֵ��Χ�Ǻ�ֱ�ӵģ���Ҫ����
				if (i >= j)
					f[i][j] = f[i - j][j] + f[i][j - 1];//�п����Ӻ�û�������������
				else//����̫�࣬����һ����
					f[i][j] = f[i][i];
			}
		}
		cout << f[m][n] << endl;
	}
	return 0;
}
