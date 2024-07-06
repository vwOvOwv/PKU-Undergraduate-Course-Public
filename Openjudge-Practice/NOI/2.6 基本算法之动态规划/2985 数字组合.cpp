#include<iostream>
#include<cmath>
#include<iomanip>
#include<climits>
#include<cstring>
#include<algorithm>
using namespace std;
int dp[30][1010];//dp[i][j]表示从前i个数中凑j的方式数
int a[30];
int main()
{
	int n, t;
	cin >> n >> t;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= t; j++) {
			for (int k = 1; k <= i; k++) {
				if (j >= a[k])
					dp[i][j] += dp[k - 1][j - a[k]];
			}
		}
	}
	cout << dp[n][t];
	return 0;
}
