/*
dp[i][j]表示i个村庄j个邮局时的距离和的最小值
dis[i][j]表示从第i个村庄到第j个村庄有"一个"邮局时的距离和最小值
注：dis[i][j]是可以直接计算出来的，邮局设在中间的村庄时距离和即为最小
状态转移方程：
dp[i][j]=min{dp[k][j-1]+dis[k+1][i]};
i>=j,k=j-1,j,...,i-1
边界条件：
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
			dis[i][j] = dis[i][j - 1] + (pos[j] - pos[(i + j) / 2]);//关键在于想到并计算出dis
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
