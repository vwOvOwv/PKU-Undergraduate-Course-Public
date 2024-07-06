#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>

using namespace std;
int a[10][10];
int cnt;
void dfs(int k) {
	if (k == 9) {
		cout << "No. " << ++cnt << endl;
		for (int i = 1; i <= 8; i++) {
			for (int j = 1; j <= 8; j++) {
				cout << a[i][j];
				if (j != 8)
					cout << ' ';
			}
			cout << endl;
		}
		return;
	}
	for (int i = 1; i <= 8; i++) {
		bool flag = true;
		for (int j = 1; j < k; j++) {
			if (a[i][j]) {
				flag = false;
				goto loop;
			}
			for (int r = 1; r <= 8; r++) {
				if (a[r][j] && abs(r - i) == abs(j - k)) {
					flag = false;
					goto loop;
				}
			}
		}
	loop:;
		if (flag) {
			a[i][k] = 1;
			dfs(k + 1);
			a[i][k] = 0;
		}
	}
}
int main() {
	dfs(1);
	return 0;
}
