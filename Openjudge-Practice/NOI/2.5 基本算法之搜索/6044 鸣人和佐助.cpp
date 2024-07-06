#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

#define mem(a) memset(a,0,sizeof(a))

int m, n, e;
char a[210][210];
bool visited[210][210][2][10];
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
struct Node
{
	int x, y, e, t;
	Node(int xx, int yy, int ee, int tt) :x(xx), y(yy), e(ee), t(tt) {}
};
queue<Node>q;

int main() {
	cin >> m >> n >> e;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (a[i][j] == '@') {
				q.push(Node(i, j, e, 0));
				visited[i][j][0][e] = 1;
			}
		}
	}
	while (!q.empty()) {
		Node p = q.front();
		if (a[p.x][p.y] == '+') {
			cout << p.t << endl;
			goto loop;
		}
		for (int i = 0; i < 4; i++) {
			int x = p.x + dx[i], y = p.y + dy[i];
			if (x >= 1 && x <= m && y >= 1 && y <= n) {
				if ((a[x][y] == '*' || a[x][y] == '+' || a[x][y] == '@') && !visited[x][y][0][p.e]) {
					q.push(Node(x, y, p.e, p.t + 1));
					visited[x][y][0][p.e] = 1;
				}
				if (a[x][y] == '#') {
					if (p.e >= 1 && !visited[x][y][1][p.e-1]) {
						visited[x][y][1][p.e-1] = 1;
						q.push(Node(x, y, p.e - 1, p.t + 1));
					}
					else if (visited[x][y][1][p.e] && !visited[x][y][0][p.e]) {
						visited[x][y][0][p.e] = 1;
						q.push(Node(x, y, p.e, p.t + 1));
					}
				}
			}
		}
		q.pop();
	}
	cout << "-1" << endl;
loop:;
	return 0;
}
