#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iomanip>

using namespace std;

int n, m;
int w[3412], d[3412];
int f[12890];
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> w[i] >> d[i];
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= w[i]; j--) {
			f[j] = max(f[j], f[j - w[i]] + d[i]);
		}
	}
	cout << f[m] << endl;
	return 0;
}
