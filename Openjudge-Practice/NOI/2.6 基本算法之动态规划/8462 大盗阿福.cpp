#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int t, n;
int a[100010];
int dp[100010];
int main()
{
	cin >> t;
	while (t--) {
		cin >> n;
		memset(a, 0, sizeof(a));
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		memset(dp, 0, sizeof(dp));
		dp[1] = a[1];
		for (int i = 2; i <= n; i++)
			dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
		cout << dp[n] << endl;
	}
	return 0;
}
