#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

#define mem(a) memset(a,0,sizeof(a))

int n, m;
char a[110][110];
int visited[110][110];
int dx[8] = { 0,1,0,-1,1,1,-1,-1 }, dy[8] = { 1,0,-1,0,1,-1,1,-1 };
struct Node
{
	int x, y;
	Node(int xx, int yy) :x(xx), y(yy) {}
};
queue<Node>q;
int cnt = 0;
void bfs(int i, int j) {
	q.push(Node(i, j));
	visited[i][j] = 1;
	while (!q.empty()) {
		Node p = q.front();
		for (int i = 0; i < 8; i++) {
			int x = p.x + dx[i], y = p.y + dy[i];
			if (x >= 1 && x <= n && y >= 1 && y <= m && !visited[x][y]) {
				visited[x][y] = 1;
				q.push(Node(x, y));
			}
		}
		q.pop();
	}
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			if (a[i][j] == '.')
				visited[i][j] = 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visited[i][j]) {
				cnt++;
				bfs(i, j);
			}
		}
	}
	cout << cnt;
	return 0;
}
