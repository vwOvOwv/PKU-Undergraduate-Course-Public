#include<iostream>
#include<cstring>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;
vector<string>ans;
string rec;
int a[10][10];
void dfs(int i) {
	if (i == 9) {
		ans.push_back(rec);
		return;
	}
	for (int j = 1; j <= 8; j++) {
		bool flag = true;
		for (int ii = 1; ii < i; ii++) {
			for (int jj = 1; jj <= 8; jj++) {
				if (a[ii][jj]==1&&(jj == j || abs(jj - j) == abs(ii - i)))
					flag = false;
			}
		}
		if (flag) {
			char c = j + '0';
			rec.push_back(c);
			a[i][j] = 1;
			dfs(i + 1);
			rec.erase(i - 1);
			a[i][j] = 0;
		}
	}
}
int main()
{
	int n;
	cin >> n;
	ans.push_back(string(" "));
	dfs(1);
	sort(ans.begin() + 1, ans.end());
	while (n--) {
		int b;
		cin >> b;
		cout << ans[b] << endl;
	}
}
