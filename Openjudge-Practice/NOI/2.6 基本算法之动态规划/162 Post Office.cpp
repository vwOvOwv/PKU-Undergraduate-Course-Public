/*
dp[i][j]��ʾi����ׯj���ʾ�ʱ�ľ���͵���Сֵ
dis[i][j]��ʾ�ӵ�i����ׯ����j����ׯ��"һ��"�ʾ�ʱ�ľ������Сֵ
ע��dis[i][j]�ǿ���ֱ�Ӽ�������ģ��ʾ������м�Ĵ�ׯʱ����ͼ�Ϊ��С
״̬ת�Ʒ��̣�
dp[i][j]=min{dp[k][j-1]+dis[k+1][i]};
i>=j,k=j-1,j,...,i-1
�߽�������
dis[i][i]=0;
dp[i][1]=dis[1][i];
*/
#include<iostream>
#include<climits>
using namespace std;
int dp[310][40];
int dis[310][310];
int pos[310];
int main()
{
	int v, p;
	cin >> v >> p;
	for (int i = 1; i <= v; i++)
		cin >> pos[i];
	for (int i = 1; i <= v - 1; i++) {
		for (int j = i + 1; j <= v; j++) {
			dis[i][j] = dis[i][j - 1] + (pos[j] - pos[(i + j) / 2]);//�ؼ������뵽�������dis
		}
	}
	for (int i = 1; i <= v; i++)
		dp[i][1] = dis[1][i];
	for (int i = 2; i <= p; i++) {
		for (int j = i; j <= v; j++) {
			dp[j][i] = INT_MAX;
			for (int k = i - 1; k < j; k++) {
				dp[j][i] = min(dp[j][i], dp[k][i - 1] + dis[k + 1][j]);
			}
		}
	}
	cout << dp[v][p] << endl;
	return 0;
}
