#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<climits>
#include<map>
using namespace std;

int t;
int n, m;
char a[210][210];
int visited[210][210][2];//只需对每个位置上的守卫状态进行记录即可
int s_x, s_y, e_x, e_y;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
struct Dot
{
	int x;
	int y;
	int t;
	Dot(int xx, int yy, int tt) :x(xx), y(yy), t(tt) {}
};
queue<Dot>q;

int main()
{
	cin >> t;
	while (t--) {
		cin >> n >> m;
		memset(a, 0, sizeof(a));
		memset(visited, 0, sizeof(visited));
		if (!q.empty())
			q.pop();
		s_x = -1, s_y = -1, e_x = -1, e_y = -1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> a[i][j];
				if (a[i][j] == 'r') {
					s_x = i;
					s_y = j;
				}
				if (a[i][j] == 'a') {
					e_x = i;
					e_y = j;
				}
			}
		}
		bool flag = false;
		int ans = INT_MAX;
		visited[s_x][s_y][0] = 1;
		q.push(Dot(s_x, s_y, 0));
		while (!q.empty()) {
			Dot p = q.front();
			if (p.x == e_x && p.y == e_y) {//为什么不能保证最优解？？？
				ans = min(ans, p.t);
				flag = true;
			}
			if (a[p.x][p.y] == 'x' && visited[p.x][p.y][1] == 0) {
				visited[p.x][p.y][1] = 1;
				q.pop();
				q.push(Dot(p.x, p.y, p.t + 1));
				continue;
			}
			for (int k = 0; k < 4; k++) {
				int x = p.x + dx[k];
				int y = p.y + dy[k];
				if (x >= 1 && x <= n && y >= 1 && y <= m) {
					if (a[x][y] == '@' || a[x][y] == 'r' || a[x][y] == 'a') {
						if (visited[x][y][0] == 0) {
							visited[x][y][0] = 1;
							q.push(Dot(x, y, p.t + 1));
						}
					}
					if (a[x][y] == 'x') {
						if (visited[x][y][0] == 0) {
							visited[x][y][0] = 1;
							q.push(Dot(x, y, p.t + 1));
						}
					}
				}
			}
			q.pop();
		}
		if (!flag)
			cout << "Impossible" << endl;
		else
			cout << ans << endl;
	}
	return 0;
}
