#include<iostream>
#include<cstring>
#include<algorithm>
#include<climits>
#include<vector>
using namespace std;
int a[10][10];
int cnt = 0;
void dfs(int i) {
	if (i == 9) {
		cnt++;
		cout << "No. " << cnt << endl;
		for (int i = 1; i <= 8; i++) {
			for (int j = 1; j <= 8; j++) {
				cout << a[j][i];//注意观察输出格式！！！
				if (j < 8)
					cout << ' ';
				else
					cout << endl;
			}
		}
		return;
	}
	for (int j = 1; j <= 8; j++) {
		int flag = false;
		for (int ii = 1; ii < i; ii++) {
			for (int jj = 1; jj <= 8; jj++) {
				if (a[ii][jj] == 1 && (j == jj || abs(ii - i) == abs(jj - j)))
					flag = true;
			}
		}
		if (!flag) {
			a[i][j] = 1;
			dfs(i + 1);
			a[i][j] = 0;
		}
	}

}
int main()
{
	dfs(1);
	return 0;
}
