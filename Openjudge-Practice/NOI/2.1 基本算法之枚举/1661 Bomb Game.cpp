#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int m, n, k;
int r, s, p, t;
int a[110][110];
int max_a = 0;
int cnt = 0;
int main()
{
	cin >> m >> n >> k;
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= k; i++) {
		cin >> r >> s >> p >> t;
		if (t == 0) {
			for (int j = r - p / 2; j <= r + p / 2; j++) {
				for (int l = s - p / 2; l <= s + p / 2; l++) {
					if (l >= 1 && l <= n && j >= 1 && j <= m)
						a[j][l] = -1;
				}
			}
		}
		else {
			for (int j = r - p / 2; j <= r + p / 2; j++) {
				for (int l = s - p / 2; l <= s + p / 2; l++) {
					if (l >= 1 && l <= n && j >= 1 && j <= m) {
						if (a[j][l] == -1)
							continue;
						else {
							a[j][l]++;
							max_a = max(a[j][l], max_a);
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (a[i][j] == max_a && max_a != 0) {
				cnt++;
			}
		}
	}
	cout << cnt;
	return 0;
}
