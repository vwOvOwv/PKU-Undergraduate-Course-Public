#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int t, n;
int a[100010];
int dp[100010];//dp[i]表示以第i天作为两次交易分界线时的最大利润
int first[100010], second[100010];//第一次与第二次交易的最大利润，以第i天为分界线
int mmin[100010], mmax[100010];//mmin[i]表示在i前的最小值，mmax[i]表示在i后的最大值（均包含i）
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		memset(a, 0, sizeof(a));
		memset(mmin, 0, sizeof(mmin));
		memset(first, 0, sizeof(first));
		memset(second, 0, sizeof(second));
		memset(dp, 0, sizeof(dp));
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		//本题本质是分治，关键在于如何求出前后两次交易的利润最大值
		mmin[1] = a[1];
		first[1] = 0;
		for (int i = 2; i <= n; i++) {
			mmin[i] = min(a[i], mmin[i - 1]);
			first[i] = max(first[i - 1], a[i] - mmin[i]);//在i之前卖出/在i当天卖出
		}
		mmax[n] = a[n];
		first[n] = 0;
		for (int i = n - 1; i >= 1; i--) {
			mmax[i] = max(a[i], mmax[i + 1]);
			second[i] = max(second[i + 1], mmax[i] - a[i]);
			dp[i] = first[i] + second[i];
		}
		dp[n] = first[n] + second[n];
		cout << *max_element(dp + 1, dp + n + 1) << endl;
	}
	return 0;
}
