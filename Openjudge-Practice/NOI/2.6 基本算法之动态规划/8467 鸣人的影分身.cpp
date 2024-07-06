//本题即为放苹果的动规版
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int t;
int m, n;
int f[20][20];
int main()
{
	cin >> t;
	while (t--) {
		cin >> m >> n;
		memset(f, 0, sizeof(f));
		for (int i = 1; i <= n; i++)
			f[0][i] = 1;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {//j的取值范围是很直接的，不要多想
				if (i >= j)
					f[i][j] = f[i - j][j] + f[i][j - 1];//有空盘子和没空盘子两种情况
				else//盘子太多，丢掉一部分
					f[i][j] = f[i][i];
			}
		}
		cout << f[m][n] << endl;
	}
	return 0;
}
