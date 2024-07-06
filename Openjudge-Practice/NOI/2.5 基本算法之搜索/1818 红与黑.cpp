#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
int w, h;
char a[30][30];
int visited[30][30];
int s_i, s_j;
int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
struct Pot {
	int x;
	int y;
	Pot(int xx,int yy):x(xx),y(yy){}
};
int cnt;


int main()
{
	while (cin >> w >> h) {
		if (w == 0 && h == 0)
			break;
		cnt = 1;
		memset(a, 0, sizeof(a));
		memset(visited, 0, sizeof(visited));
		queue<Pot>q;
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w; j++) {
				cin >> a[i][j];
				if (a[i][j] == '@') {
					s_i = i;
					s_j = j;
				}
			}
		}
		q.push(Pot(s_i, s_j));
		visited[s_i][s_j] = 1;
		while (!q.empty()) {
			Pot p = q.front();
			for (int i = 0; i < 4; i++) {
				int x = p.x + dx[i];
				int y = p.y + dy[i];
				if (x >= 1 && x <= h && y >= 1 && y <= w && visited[x][y] == 0 && a[x][y] == '.') {
					cnt++;
					visited[x][y] = 1;
					q.push(Pot(x, y));
				}
			}
			q.pop();
		}
		cout << cnt << endl;
	}
	return 0;
}
