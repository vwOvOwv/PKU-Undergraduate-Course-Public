//还是01背包问题，只是将"价值"抽象为了体积
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 40;
int v, n;
int m[N];
int f[20010];
int main()
{
	cin >> v >> n;
	for (int i = 1; i <= n; i++)
		cin >> m[i];
	for (int i = 1; i <= n; i++) {
		for (int j = v; j >= m[i]; j--) {
				f[j] = max(f[j], f[j - m[i]] + m[i]);//滚动数组优化
		}
	}
	cout << v - f[v];
	return 0;
}
