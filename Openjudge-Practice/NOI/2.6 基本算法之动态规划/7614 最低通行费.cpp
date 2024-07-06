#include<iostream>
#include<vector>
using namespace std;
const int N = 110;
int n;
int a[N][N];
int dp[N][N];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    for (int i = 1; i <= n; i++)
        dp[1][i] = dp[1][i - 1] + a[1][i];
    for (int j = 1; j <= n; j++)
        dp[j][1] = dp[j - 1][1] + a[j][1];
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++)
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
    }
    cout << dp[n][n];
    return 0;
}
