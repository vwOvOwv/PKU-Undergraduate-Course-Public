#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    long long int dp[51] = { 0 };//dp[i]表示从1到i的所有取法
    dp[1] = 2;//也可以一个都不取
    dp[2] = 3;
    for (int i = 3; i <= 50; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    //若取i，则第i-1个数不能取，有dp[i-2]种取法
    //若不取i，则第i-1个数能取，有dp[i-1]种取法
    int n;
    cin >> n;
    cout << dp[n];
    return 0;
}
