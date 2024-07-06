#include<iostream>
#include<cstring>
#include<algorithm>
#include<map>
#include<queue>

using namespace std;

#define mem(a) memset(a,0,sizeof(a))

int l, r, c;
char a[40][40][40];
int visited[40][40][40];
int dl[6] = { 0,0,0,0,1,-1 }, dx[6] = { 1,0,-1,0,0,0 }, dy[6] = { 0,1,0,-1,0,0 };
struct Node
{
	int l, x, y, t;
	Node(int ll, int xx, int yy, int tt) :l(ll), x(xx), y(yy), t(tt) {}
};
queue<Node>q;
void init() {
	mem(a), mem(visited);
	while (!q.empty())
		q.pop();
}
void bfs() {
	while (!q.empty()) {
		Node p = q.front();
		if (a[p.l][p.x][p.y] == 'E') {
			cout << "Escaped in " << p.t << " minute(s)." << endl;
			goto loop;
		}
		for (int i = 0; i < 6; i++) {
			int ll = p.l + dl[i], xx = p.x + dx[i], yy = p.y + dy[i];
			if (ll >= 1 && ll <= l && xx >= 1 && xx <= r && yy >= 1 && yy <= c && !visited[ll][xx][yy]) {
				visited[ll][xx][yy] = 1;
				q.push(Node(ll, xx, yy, p.t + 1));
			}
		}
		q.pop();
	}
	cout << "Trapped!" << endl;
loop:;
}

int main() {
	while ((cin >> l >> r >> c) && l) {
		init();
		for (int i = 1; i <= l; i++) {
			for (int j = 1; j <= r; j++) {
				for (int k = 1; k <= c; k++) {
					cin >> a[i][j][k];
					if (a[i][j][k] == 'S') {
						q.push(Node(i, j, k, 0));
						visited[i][j][k] = 1;
					}
					if (a[i][j][k] == '#')
						visited[i][j][k] = 1;
				}
			}
		}
		bfs();
	}
	return 0;
}
