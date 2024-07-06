#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int r, c;
char a[50][50];
int visited[50][50];
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };

struct Pot {
	int x;
	int y;
	int cnt;
	Pot(int xx,int yy,int cc):x(xx),y(yy),cnt(cc){}
};
queue<Pot>q;
int main()
{
	cin >> r >> c;
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> a[i][j];
		}
	}
	q.push(Pot(1, 1, 1));
	visited[1][1] = 1;
	while (!q.empty()) {
		Pot p = q.front();
		if (p.x == r && p.y == c) {
			cout << p.cnt;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int x = p.x + dx[i], y = p.y + dy[i];
			if (x >= 1 && x <= r && y >= 1 && y <= c && a[x][y] == '.' && visited[x][y] == 0) {
				q.push(Pot(x, y, p.cnt + 1));
				visited[x][y] = 1;
			}
		}
		q.pop();
	}
	return 0;
}
