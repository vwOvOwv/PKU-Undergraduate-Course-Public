#include<iostream>
#include<cstring>
#include<algorithm>
#include<climits>
//完全背包问题求方案数
using namespace std;
int n;
int f[1010];
int g[1010];
int v[5] = {0, 10,20,50,100 };
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		f[i] = INT_MIN;//f[i]应表示体积恰好为i时的“最大价值”
	}
	f[0] = 0;
	g[0] = 1;//重要！
	for (int i = 1; i <= 4; i++) {
		for (int j = 10; j <= n; j++) {//完全背包问题
			if (j >= v[i]) {
				int t = max(f[j], f[j - v[i]]);//不需要有抽象的价值，或者说可以认为价值是0
				int s = 0;
				if (t == f[j])//判断递推来源
					s += g[j];
				if (t == f[j - v[i]])//else if错
					s += g[j - v[i]];
				f[j] = t;
				g[j] = s;
			}
		}
	}
	cout << g[n] << endl;
	return 0;
}
