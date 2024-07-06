#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;
//0-1背包问题+决策优化
int n, m, k;
int ball[110], force[110];
int f[1010][510];
int main() {
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++)
		cin >> ball[i] >> force[i];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			f[i][j] = 1 << 31;
		}
	}
	int max_num = 0;
	int sur_blood = m;
	for (int i = 1; i <= k; i++) {
		for (int j = n; j >= ball[i]; j--) {
			for (int l = m; l >= force[i]; l--) {
				f[j][l] = max(f[j][l], f[j - ball[i]][l - force[i]] + 1);
				if (f[j][l] > max_num) {
					max_num = f[j][l];
					sur_blood = m - l;
				}
				else if (f[j][l] == max_num) {
					if (sur_blood < m - l)//剩余血量尽量多
						sur_blood = m - l;
				}
			}
		}
	}
	cout << max_num << ' ' << sur_blood << endl;
	return 0;
}
