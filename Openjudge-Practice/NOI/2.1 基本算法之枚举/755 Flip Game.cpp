#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
#include<map>

using namespace std;

int a[4], b[4];//棋盘
void SetBit(int& u, int v, int w) {
	if (w)
		u |= (1 << v);
	else
		u &= ~(1 << v);
}
int GetBit(int u, int v) {
	return (u >> v) & 1;
}
void FlipBit(int& u, int v) {
	u ^= (1 << v);
}
int count1(int u) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		if (GetBit(u, i))
			cnt++;
	}
	return cnt;
}
int solve() {
	int ans = 1 << 30;
	for (int n = 0; n < 16; n++) {
		int switches = n;
		memcpy(b, a, sizeof(a));
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			cnt += count1(switches);
			for (int j = 0; j < 4; j++) {
				if (GetBit(switches, j)) {
					FlipBit(b[i], j);
					if (j != 0)
						FlipBit(b[i], j - 1);
					if (j != 3)
						FlipBit(b[i], j + 1);
				}
			}
			if (i != 3)
				b[i + 1] ^= switches;
			switches = b[i];
		}
		if (b[3] == 0)
			ans = min(ans, cnt);
	}
	return ans == 1 << 30 ? -1 : ans;
}
int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 3; j >= 0; j--) {
			char c;
			cin >> c;
			if (c == 'b')
				SetBit(a[i], j, 1);
			else
				SetBit(a[i], j, 0);
		}
	}
	int ans = solve();
	for (int i = 0; i < 4; i++) {//全变成白的or全变成黑的
		for (int j = 0; j < 4; j++) {
			FlipBit(a[i], j);
		}
	}
	if (ans != -1)
		ans = min(ans, solve());
	else
		ans = solve();
	if (ans != -1)
		cout << ans;
	else
		cout << "Impossible";
	return 0;
}
