/*
����ؼ����ڰѶ�ά����ѹ����һά��ת��Ϊ����Ӷκ��������
*/
#include<iostream>
#include<cmath>
#include<iomanip>
#include<climits>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int a[110][110];
int total[110][110];
int maxi = INT_MIN;
void solve(int j) {
	int dp[110] = { 0 };
	dp[1] = total[j][1];
	for (int i = 2; i <= n; i++) {
		dp[i] = max(total[j][i], dp[i - 1] + total[j][i]);//���е�����Ӷκ�
		maxi = max(dp[i], maxi);//��¼���ֵ
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	//ö�������Ӿ��������
	for (int i = 1; i <= n; i++) {//�Ӿ���ӵ�i�п�ʼ
		memset(total, 0, sizeof(total));//ע��Ҫ����
		for (int j = i; j <= n; j++) {//�Ӿ��󵽵�j�н���
			for (int k = 1; k <= n; k++) {//���Ӿ�����к�
				total[j][k] = total[j - 1][k] + a[j][k];
			}
			solve(j);//ע���ÿһ��j��Ӧ����һ��dp
		}
	}
	cout << maxi << endl;
	return 0;
}
