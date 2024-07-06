#include<iostream>
#include<vector>
#include<iomanip>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>

using namespace std;

int n;
int f(int n, int maxi) {
	if (n == 0)
		return 1;
	if (n == 1)
		return 1;
	int ans = 0;
	for (int i = maxi; i >= 1; i--) {
		if (n - i >= 0)
			ans += f(n - i, i);
	}
	return ans;
}
int main() {
	while (cin >> n) {
		cout << f(n, n) << endl;
	}
}
