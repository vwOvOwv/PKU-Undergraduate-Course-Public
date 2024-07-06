#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>

using namespace std;

int n;
int a[110];
int f1[110], f2[110];


int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		f1[i] = f2[i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j])
				f1[i] = max(f1[i], f1[j] + 1);
		}
	}
	for (int i = n - 1; i >= 1; i--) {
		for (int j = n; j > i; j--) {
			if (a[i] > a[j])
				f2[i] = max(f2[i], f2[j] + 1);
		}
	}
	for (int i = 1; i <= n; i++) {
		f2[i] = f1[i] + f2[i] - 1;
	}
	cout << n - *max_element(f2 + 1, f2 + n + 1) << endl;
	return 0;
}
