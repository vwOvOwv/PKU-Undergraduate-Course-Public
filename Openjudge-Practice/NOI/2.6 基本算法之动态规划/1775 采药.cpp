//01±³°üÄ£°å
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int v[110], w[110];
int dp[1100];
int main()
{
	int t, m;
	cin >> t >> m;
	for (int i = 1; i <= m; i++)
		cin >> v[i] >> w[i];
	for (int i = 1; i <= m; i++) {
		for (int j = t; j >= v[i]; j--) {
			dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
		}
	}
	cout << dp[t];
	return 0;
}
