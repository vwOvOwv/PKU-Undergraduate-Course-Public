#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
int a[110][110];
int n, m;
int visited[110][110];
int s_i, s_j, e_i, e_j;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

struct Pot
{
	int x;
	int y;
	int layer;
	Pot(int xx,int yy,int ll):x(xx),y(yy),layer(ll){}
};
queue<Pot>q;
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c;
			cin >> c;
			if (c == 'S') {
				s_i = i;
				s_j = j;
			}
			else if (c == 'T') {
				e_i = i;
				e_j = j;
			}
			else if (c == '#')
				a[i][j] = 1;
		}
	}
	visited[s_i][s_j] = 1;
	q.push(Pot(s_i, s_j, 0));
	while (!q.empty()) {
		Pot p = q.front();
		if (p.x == e_i && p.y == e_j) {
			cout << p.layer << endl;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int x = p.x + dx[i], y = p.y + dy[i];
			if (x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != 1 && visited[x][y] == 0) {
				visited[x][y] = 1;
				q.push(Pot(x, y, p.layer + 1));
			}
		}
		q.pop();
	}
	return 0;
}
