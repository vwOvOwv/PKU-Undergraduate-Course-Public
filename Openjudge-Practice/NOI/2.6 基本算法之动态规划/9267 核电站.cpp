#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m;
long long int dp[60][10];//dp[i][j]表示前i个坑已经有j个连续的坑有核物质时的方案数
long long int ans;
int main()
{
    cin >> n >> m;
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m - 1; j++) {
            if (j == 0) {//i中没放入核物质
                for (int k = 0; k <= m - 1; k++) {
                    dp[i][j] += dp[i - 1][k];
                }
            }
            else {//i中放核物质
                dp[i][j] += dp[i - 1][j - 1];
            }
        }
    }
    for (int i = 0; i <= m - 1; i++)
        ans += dp[n][i];
    cout << ans;
    return 0;
}
