#include<iostream>
#include<cmath>
#include<iomanip>
#include<climits>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int n, a, b;
pair<int, int>ans = make_pair(0, 1);
void simplify() {
	int sup = min(ans.first, ans.second);
	for (int i = sup; i >= 2; i--) {
		if (ans.first % i == 0 && ans.second % i == 0) {
			ans.first /= i;
			ans.second /= i;
			break;
		}
	}
}
int main()
{
	cin >> n >> a >> b;

	for (int mu = 1; mu <= n; mu++) {
		for (int zi = 1;; zi++) {
			if (zi * b < mu * a) {//比较分数用乘法
				if (zi * ans.second > ans.first * mu) {
					ans.first = zi;
					ans.second = mu;
				}
			}
			else
				break;
		}
	}
	simplify();
	cout << ans.first << ' ' << ans.second;
	return 0;
}
