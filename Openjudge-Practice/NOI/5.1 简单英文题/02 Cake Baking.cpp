#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
//��ͼ�ϱ����߽��������������
int n, judge;
int a[30][30], visited[30][30];
int c[30];
bool flag;
void dfs(int k) {
	if (flag)
		return;
	for (int i = 1; i <= n; i++) {
		if (a[i][k] && c[k] == c[i])
			return;
	}
	bool t = false;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] && !visited[i][j])
				t = true;
		}
	}
	if (!t) {//���б߶���������
		for (int i = 1; i <= n; i++)
			cout << c[i] << endl;
		flag = true;
		return;
	}
	for (int i = 1; i <= n; i++) {//ö�����е����
		if (a[k][i]&&!visited[k][i]) {
			visited[k][i]  = 1;
			if (c[k] == 1) {
				c[i] = 2;
				dfs(i);
				c[i] = 3;
				dfs(i);
			}
			else if (c[k] == 2) {
				c[i] = 1;
				dfs(i);
				c[i] = 3;
				dfs(i);
			}
			else if (c[k] == 3) {
				c[i] = 1;
				dfs(i);
				c[i] = 2;
				dfs(i);
			}
			visited[k][i] = 0;//ע��Ҫ���ݣ�������֤��������·��
		}
	}
}
int main()
{
	flag = false;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	c[1] = 1;
	dfs(1);
	return 0;
}
