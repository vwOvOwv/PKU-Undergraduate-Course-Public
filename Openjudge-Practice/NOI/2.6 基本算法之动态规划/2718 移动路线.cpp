#include<iostream>
#include<cmath>
#include<iomanip>
#include<climits>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[30][30];
int main()
{
	int m, n;
	cin >> m >> n;
	for (int j = 1; j <= n; j++)
		dp[1][j] = 1;
	for (int i = 1; i <= m; i++)
		dp[i][1] = 1;
	for (int i = 2; i <= m; i++) {
		for (int j = 2; j <= n; j++) {
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
		}
	}
	cout << dp[m][n];
	return 0;
}
