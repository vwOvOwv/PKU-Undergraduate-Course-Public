/*
本题关键在于把二维矩阵压缩成一维，转化为最大子段和问题求解
*/
#include<iostream>
#include<cmath>
#include<iomanip>
#include<climits>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
int a[110][110];
int total[110][110];
int maxi = INT_MIN;
void solve(int j) {
	int dp[110] = { 0 };
	dp[1] = total[j][1];
	for (int i = 2; i <= n; i++) {
		dp[i] = max(total[j][i], dp[i - 1] + total[j][i]);//该行的最大子段和
		maxi = max(dp[i], maxi);//记录最大值
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	//枚举所有子矩阵的行数
	for (int i = 1; i <= n; i++) {//子矩阵从第i行开始
		memset(total, 0, sizeof(total));//注意要重置
		for (int j = i; j <= n; j++) {//子矩阵到第j行结束
			for (int k = 1; k <= n; k++) {//求子矩阵的列和
				total[j][k] = total[j - 1][k] + a[j][k];
			}
			solve(j);//注意对每一个j都应进行一次dp
		}
	}
	cout << maxi << endl;
	return 0;
}
