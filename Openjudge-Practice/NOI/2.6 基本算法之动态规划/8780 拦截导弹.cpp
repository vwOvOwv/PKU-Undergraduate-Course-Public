#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 20;
int n;
int h[N];
int f[N];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		f[i] = 1;
	}
	for (int i = n - 1; i >= 1; i--) {
		for (int k = n; k >= i + 1; k--) {
			if (h[i] >= h[k])
				f[i] = max(f[i], f[k] + 1);
		}
	}
	cout << *max_element(f + 1, f + n + 1);
	return 0;
}
