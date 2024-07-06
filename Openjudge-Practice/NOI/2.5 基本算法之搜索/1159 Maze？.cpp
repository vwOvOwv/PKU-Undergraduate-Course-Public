#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int m, n;
char a[30][30];
int visited[30][30];
int cnt[5];
bool t[5];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
int s_i, s_j, e_i, e_j;
struct Dot {
	int x;
	int y;
	Dot(int xx, int yy) :x(xx), y(yy) {}
};
queue<Dot>q;
int main()
{
	while (cin >> m >> n) {
		if (m == 0 && n == 0)
			break;
		memset(a, 0, sizeof(a));
		memset(visited, 0, sizeof(visited));
		memset(cnt, 0, sizeof(cnt));
		memset(t, 0, sizeof(t));
		while (!q.empty())
			q.pop();
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
				if (a[i][j] == 'S') {
					visited[i][j] = 0;
					s_i = i;
					s_j = j;
				}
				else if (a[i][j] == 'G') {
					visited[i][j] = 1;
					e_i = i;
					e_j = j;
				}
				else if (a[i][j] >= 'a' && a[i][j] <= 'e') {
					visited[i][j] = 2;
					cnt[a[i][j] - 'a']++;
					t[a[i][j] - 'a'] = true;
				}
				else if (a[i][j] >= 'A' && a[i][j] <= 'E') {
					visited[i][j] = 1;
				}
				else if (a[i][j] == '.')
					visited[i][j] = 1;
			}
		}
		bool flag = false;
		q.push(Dot(s_i, s_j));
		while (!q.empty()) {
			Dot p = q.front();
			if (p.x == e_i && p.y == e_j) {
				cout << "YES" << endl;
				flag = true;
				break;
			}
			for (int i = 0; i < 4; i++) {
				int x = p.x + dx[i];
				int y = p.y + dy[i];
				if (x >= 1 && x <= m && y >= 1 && y <= n && visited[x][y]) {
					if (a[x][y] == '.' || a[x][y] == 'G') {
						visited[x][y] = 0;
						q.push(Dot(x, y));
					}
					else if (a[x][y] >= 'a' && a[x][y] <= 'e') {
						if (visited[x][y] == 2)
							cnt[a[x][y] - 'a']--;
						visited[x][y]--;
						q.push(Dot(x, y));
					}
				}
			}
			for (int i = 0; i < 4; i++) {
				int x = p.x + dx[i];
				int y = p.y + dy[i];
				if (x >= 1 && x <= m && y >= 1 && y <= n && visited[x][y]) {
					if (a[x][y] >= 'A' && a[x][y] <= 'E') {
						if (cnt[a[x][y] - 'A'] == 0 && t[a[x][y] - 'A'] && visited[x][y] == 1) {
							visited[x][y] = 0;
							q.push(Dot(x, y));
						}
					}
				}
			}
			q.pop();
		}
		if (!flag)
			cout << "NO" << endl;
	}
	return 0;
}