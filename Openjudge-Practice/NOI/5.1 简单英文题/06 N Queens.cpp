#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
bool flag;
int n;
int a[210][210];
void dfs(int k) {
	if (flag)
		return;
	if (k == n + 1) {
		flag = true;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cout << a[i][j];
				if (j != n)
					cout << ' ';
			}
			cout << endl;
		}
		return;
	}
	for (int i = 1; i <= n; i++) {
		bool t = true;
		for (int j = 1; j < k; j++) {
			for (int l = 1; l <= n; l++) {
				if (a[j][i] == 1 || (a[j][l] == 1 && abs(j - k) == abs(l - i))) {
					t = false;
					j = k, l = n + 1;
				}
			}
		}
		if (t) {
			a[k][i] = 1;
			dfs(k + 1);
			a[k][i] = 0;
		}
	}
}
int main()
{
	cin >> n;
	dfs(1);
	return 0;
}
