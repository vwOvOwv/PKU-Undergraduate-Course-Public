#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;
int n, m;
int v[1010], w[1010];
int f[1010];
vector<vector<int>>ans(1010);//ans[i]记录背包体积不大于i时达到最大价值的方案
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
	}
	for (int i = 1; i <= n; i++)
		cin >> w[i];
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= v[i]; j--) {
			if (f[j] < f[j - v[i]] + w[i]) {
				ans[j] = ans[j - v[i]];
				ans[j].push_back(i);
				f[j] = f[j - v[i]] + w[i];
			}
		}
	}
	for (int j = 0; j < ans[m].size(); j++) {
		cout << ans[m][j] << endl;
	}
	return 0;
}
