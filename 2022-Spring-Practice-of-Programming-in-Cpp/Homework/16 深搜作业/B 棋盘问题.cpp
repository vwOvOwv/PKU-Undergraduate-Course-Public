#include<iostream>
#include<cstring>
using namespace std;
int n, k, cnt;
char a[15][15];
void dfs(int i) {
	if (k == 0) {
		cnt++;
		return;
	}
	if (i == n + 1)//ע������Ӧ����i����һ��
		return;
	for (int j = 1; j <= n; j++) {//����ÿ��λ��
		if (a[i][j] == '#') {
			int r;
			for (r = 1; r <= i; r++)
				if (a[r][j] == 'x')
					break;
			if (r == i + 1) {//���Է���
				a[i][j] = 'x';
				k--;
				dfs(i + 1);
				k++;
				a[i][j] = '#';//����
			}
		}
	}
	dfs(i + 1);//ע�⻹���Բ�����һ�з��ӣ���
}
int main()
{
	while (cin >> n >> k) {
		if (k == -1 && n == -1)
			break;
		memset(a, 0, sizeof(a));
		cnt = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
			}
		}
		dfs(1);
		cout << cnt << endl;
	}
	return 0;
}
