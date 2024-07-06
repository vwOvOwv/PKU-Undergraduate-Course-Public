//本题思路与Post Office一致
#include<iostream>
#include<climits>
using namespace std;
int dis[510][510];
int dp[510][510];
int a[510];
int main()
{
	int m, n;
	cin >> m >> n;
	for (int i = 2; i <= m; i++) {
		cin >> a[i];
		a[i] += a[i - 1];
	}
	for (int i = 1; i < m; i++) {
		for (int j = i + 1; j <= m; j++) {
			dis[i][j] = dis[i][j - 1] + a[j] - a[(i + j) / 2];
		}
	}
	for (int i = 1; i <= m; i++) {
		dp[i][1] = dis[1][i];
	}
	for (int j = 2; j <= n; j++) {
		for (int i = j; i <= m; i++) {
			dp[i][j] = INT_MAX;
			for (int k = j - 1; k < i; k++) {
				dp[i][j] = min(dp[i][j], dp[k][j - 1] + dis[k + 1][i]);
			}
		}
	}
	cout << dp[m][n];
	return 0;
}
