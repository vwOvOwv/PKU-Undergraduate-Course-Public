#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>

using namespace std;

int n;
int k[20], x[15];
long long int f[20][3];//f[i][j]表示第i位模3余j的数的个数
long long int result[3];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		for (int j = 1; j <= k[i]; j++) {
			cin >> x[j];
			f[i][x[j] % 3]++;
		}
	}
	for (int i = 0; i < 3; i++)
		result[i] = f[1][i];
	for (int i = 2; i <= n; i++) {//乘法原理+简单数论
		long long int tmp0 = result[0], tmp1 = result[1], tmp2 = result[2];
		result[0] = tmp0 * f[i][0] + tmp1 * f[i][2] + tmp2 * f[i][1];
		result[1] = tmp0 * f[i][1] + tmp1 * f[i][0] + tmp2 * f[i][2];
		result[2] = tmp0 * f[i][2] + tmp1 * f[i][1] + tmp2 * f[i][0];
	}
	cout << result[0] << endl;
	return 0;
}
