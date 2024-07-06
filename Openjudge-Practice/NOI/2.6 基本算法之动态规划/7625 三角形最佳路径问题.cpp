#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 110;
int f[N];
int a[N][N];
int main()
{
	int h;
	cin >> h;
	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 1; i <= h; i++)
		f[i] = a[h][i];
	for (int i = h - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			f[j] = max(f[j], f[j + 1]) + a[i][j];
		}
	}
	cout << f[1];
	return 0;
}
