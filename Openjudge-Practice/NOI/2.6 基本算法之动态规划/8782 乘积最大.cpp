//最佳加法表达式的同类题
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 50;
int f[N][N];
int n, k;
string s;
int num(int ss, int e) {
	int l = e - ss + 1;
	return atoi((s.substr(ss - 1, l)).c_str());
}
int main()
{
	cin >> n >> k >> s;
	for (int i = 1; i <= n; i++)
		f[i][0] = atoi((s.substr(0, i)).c_str());
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			for (int k = j; k <= i - 1; k++) {
				f[i][j] = max(f[i][j], f[k][j - 1] * num(k + 1, i));
			}
		}
	}
	cout << f[n][k];
	return 0;
}
