#include<iostream>
#include<cstring>
#include<algorithm>
#include<climits>
#include<vector>
#include<queue>

using namespace std;

int m, n;
char a[30][30];
int visited[30][30];
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
struct Node
{
	int x, y, cnt;
	Node(int xx, int yy, int cc) :x(xx), y(yy), cnt(cc) {}
};
queue<Node>q;
void init() {
	memset(a, 0, sizeof(a));
	memset(visited, 0, sizeof(visited));
	while (!q.empty())
		q.pop();
}
void bfs() {
	while (!q.empty()) {
		Node p = q.front();
		if (a[p.x][p.y] == '*') {
			cout << p.cnt << endl;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int x = p.x + dx[i], y = p.y + dy[i];
			if (x >= 1 && x <= m && y >= 1 && y <= n && !visited[x][y]) {
				visited[x][y] = 1;
				q.push(Node(x, y, p.cnt + 1));
			}
		}
		q.pop();
	}
	cout << "-1" << endl;
}
int main()
{
	while (cin >> m >> n && n) {
		init();
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
				if (a[i][j] == '@') {
					q.push(Node(i, j, 0));
					visited[i][j] = 1;
				}
				if (a[i][j] == '#')
					visited[i][j] = 1;
			}
		}
		bfs();
	}
	return 0;
}
