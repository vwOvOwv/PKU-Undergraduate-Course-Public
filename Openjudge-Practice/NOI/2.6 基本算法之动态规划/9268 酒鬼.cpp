#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n;
int a[710];
int dp[710][5];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dp[1][1] = a[1];
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 2; j++) {
			if (j == 0) {
				for (int k = 0; k <= 2; k++) {
					dp[i][j] = max(dp[i][j], dp[i - 1][k]);
				}
			}
			else
				dp[i][j] = dp[i - 1][j - 1] + a[i];
		}
	}
	int ans = 0;
	for (int i = 0; i <= 2; i++) {
		ans = max(ans, dp[n][i]);
	}
	cout << ans;
	return 0;
}
