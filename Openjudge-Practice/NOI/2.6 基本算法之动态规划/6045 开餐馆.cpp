#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        int m[110] = { 0 };
        int p[110] = { 0 };
        for (int i = 1; i <= n; i++)
            cin >> m[i];
        for (int j = 1; j <= n; j++)
            cin >> p[j];
        int dp[110] = { 0 };//dp[i]表示以第i个位置为终点的餐厅所能得到的最大利润
        for (int i = 1; i <= n; i++)
            dp[i] = p[i];
        for (int i = 2; i <= n; i++) {
            for (int k = 1; k <= i - 1; k++) {
                if (m[i] - m[k] > d)
                    dp[i] = max(dp[i], dp[k] + p[i]);
            }
        }
        cout << *max_element(dp + 1, dp + n + 1) << endl;
    }
    return 0;
}
