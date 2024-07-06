#include<iostream>
#include<cmath>
#include<iomanip>
#include<climits>
#include<cstring>
#include<algorithm>
using namespace std;
int a[110][110];
int dp[110][110];
int main()
{
	int t;
	cin >> t;
	while (t--) {
		int r, c;
		cin >> r >> c;
		for (int i = 1; i <= r; i++) {
			for (int j = 1; j <= c; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 1; i <= r; i++)
			dp[i][1] = dp[i - 1][1] + a[i][1];
		for (int j = 1; j <= c; j++)
			dp[1][j] = dp[1][j - 1] + a[1][j];
		for (int i = 2; i <= r; i++) {
			for (int j = 2; j <= c; j++) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
			}
		}
		cout << dp[r][c] << endl;
	}
	return 0;
}
