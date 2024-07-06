#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int t[20][20];
int mini = 1 << 30;
int ans = 0;
int visited[20];//��¼�Ƿ��Ѿ��߹�
int record[20][1 << 18];//�����ص㣡record[i][j]��ʾ��״̬j�ߵ�i�����·����Ҫ����������м�֦������tle
int state[20];//�涨ÿ�������״̬�������õ��������Ķ����Ʒֽ�
int s;//����״̬
void dfs(int i) {
	bool flag = false;//��ǻ���û��û�ߵ���
	for (int j = 1; j <= n - 1; j++) {//ע����n-1������ߵ�n
		if (j == i)
			continue;
		if (visited[j] == 0) {
			flag = true;//��û�ߵ���
			if (record[j][s+state[j]]==0||(ans + t[i][j] < record[j][s + state[j]])) {
				record[j][s+state[j]] = ans + t[i][j];//����״̬
				s += state[j];
				visited[j] = 1;
				ans += t[i][j];
				dfs(j);
				ans -= t[i][j];
				visited[j] = 0;
				s -= state[j];
			}
		}
	}
	if (!flag) {//�������ˣ�dfs�յ�
		mini = min(mini, ans + t[i][n]);
		return;
	}
}
int main()
{
	cin >> n;
	int tmp = 2;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> t[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {//��2�������������״̬���Ӷ���ÿһ����������״ֵ̬����ͬ
		state[i] = tmp;
		tmp *= 2;
	}
	visited[1] = 1;
	s = state[1];//ע���ʼ��״̬
	dfs(1);
	cout << mini;
}
