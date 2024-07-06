#include<iostream>
#include<cmath>
#include<iomanip>
#include<climits>
#include<cstring>
#include<algorithm>
using namespace std;
int map[100][100];
int dfs(int i, int j,int n) {
	int ans = 0;
	if (n == 0)
		return 1;
	map[i][j] = -1;
	if (map[i + 1][j] == 0) {
		ans += dfs(i + 1, j, n - 1);
		map[i + 1][j] = 0;
	}
	if (map[i][j + 1] == 0) {
		ans += dfs(i, j + 1, n - 1);
		map[i][j + 1] = 0;
	}
	if (map[i][j - 1] == 0) {
		ans += dfs(i, j - 1, n - 1);
		map[i][j - 1] = 0;
	}
	return ans;
}
int main()
{
	int n;
	cin >> n;
	cout << dfs(0, 50, n);
	return 0;
}
