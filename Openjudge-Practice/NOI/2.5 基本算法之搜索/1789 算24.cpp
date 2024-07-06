#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;

double num[5];
bool flag;
bool isZero(double a) {
	return fabs(a) < 1e-6;
}
void dfs(double a[], int n) {//用a中的前n个数算24
	if (flag)
		return;
	if (n == 1) {
		if (isZero(a[0] - 24))
			flag = true;
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int cnt = 0;
			double b[5] = { 0 };
			for (int k = 0; k < n; k++) {
				if (k == i || k == j)
					continue;
				b[cnt] = a[k];
				cnt++;
			}
			b[cnt] = a[i] + a[j];
			dfs(b, n - 1);
			b[cnt] = a[i] - a[j];
			dfs(b, n - 1);
			b[cnt] = a[j] - a[i];
			dfs(b, n - 1);
			b[cnt] = a[i] * a[j];
			dfs(b, n - 1);
			if (!isZero(a[i])) {
				b[cnt] = a[j] / a[i];
				dfs(b, n - 1);
			}
			if (!isZero(a[j])) {
				b[cnt] = a[i] / a[j];
				dfs(b, n - 1);
			}
		}
	}
}
int main()
{
	int a, b, c, d;
	while (cin >> a >> b >> c >> d) {
		if (a == 0 && b == 0 && c == 0 && d == 0)
			break;
		memset(num, 0, sizeof(num));
		num[0] = a, num[1] = b, num[2] = c, num[3] = d;
		flag = false;
		dfs(num, 4);
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return;
}
