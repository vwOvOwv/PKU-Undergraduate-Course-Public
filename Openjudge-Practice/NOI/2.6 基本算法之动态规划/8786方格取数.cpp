//多线程dp
#include<iostream>
#include<cstring>
#include<algorithm>
#include<climits>
#include<vector>

using namespace std;

int n;
int x, y, num;
int f[20][20][20][20];//格局打开.jpg
int a[40][40];
/*
由于本题的数据规模很小，所以（n^4)的方法也能解决。但是的规模增大的时候我们就必须对算法进行优化了。
很明显dp[i1][j1][i2][j2]的四维状态描述了所有可能的走法，当然我们也可以改变状态的表示法，减少状态的维数。
f[k][i][j] = max { f[k-1][i][j], f[k-1][i-1][j-1], f[k-1][i-1][j],f[k-1][i][j-1] } + (i==j ? a[k-i][i] : a[k-i+1][i]+a[k-j+1][j])
f[k][i][j]表示走了k步，第一条路向右走i步，第二条路向右走j步。
*/
int mymax(int a, int b, int c, int d) {
	int ans = a;
	ans = max(ans, b);
	ans = max(ans, c);
	ans = max(ans, d);
	return ans;
}
int main()
{
	cin >> n;
	while (cin >> x >> y >> num) {
		if (x == 0 && y == 0 && num == 0)
			break;
		a[x][y] = num;
	}
	for (int i1 = 1; i1 <= n; i1++) {
		for (int j1 = 1; j1 <= n; j1++) {
			for (int i2 = 1; i2 <= n; i2++) {
				for (int j2 = 1; j2 <= n; j2++) {
					f[i1][j1][i2][j2] = mymax(f[i1 - 1][j1][i2 - 1][j2], f[i1 - 1][j1][i2][j2 - 1], f[i1][j1 - 1][i2 - 1][j2], f[i1][j1 - 1][i2][j2 - 1]);
					if (i1 == i2 && j1 == j2)
						f[i1][j1][i2][j2] += a[i1][j1];//注意只能加一次
					else
						f[i1][j1][i2][j2] = f[i1][j1][i2][j2] + a[i1][j1] + a[i2][j2];
					//不用担心一个数被加了两次的情况（状态的转移方法保证正确性）
				}
			}
		}
	}
	cout << f[n][n][n][n];
	return 0;
}
