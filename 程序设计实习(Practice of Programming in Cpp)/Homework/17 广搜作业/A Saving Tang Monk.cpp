#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<climits>
using namespace std;
/*
bfs��״̬ѹ�����ѵ�����ȷ������ȥ�ص�״̬
visited[x][y][key][snake]��һ��״̬��
��Ϊ���Գ����߹����䲻��Կ�׵��������ɱ����ǰ���߹�ͬһ������Ҳ�ǲ�ͬ��״̬
��Ϊ������û������һ������ֻ����һ�Σ����Բ��ܽ��������������ȥ�أ���ν״̬Ӧ������ʵ��״��һһ��Ӧ�Ĺ�ϵ
��������ö��
*/
int n, m;
char a[110][110];
bool visited[110][110][10][1 << 6];//״̬ѹ����¼�����������ߵ�״̬
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
int s_x, s_y, e_x, e_y;
struct Dot
{
	int x;
	int y;
	int k;
	int s;
	int t;
	Dot(int xx, int yy, int kk, int ss, int tt) :x(xx), y(yy), k(kk), s(ss), t(tt) {}
};
struct Snake
{
	int x;
	int y;
	Snake(int xx,int yy):x(xx),y(yy){}
};
queue<Dot>q;
vector<Snake>v;
int main()
{
	while (cin >> n >> m) {
		if (n == 0 && m == 0)
			break;
		memset(a, 0, sizeof(a));
		memset(visited, 0, sizeof(visited));
		while (!q.empty())
			q.pop();
		v.clear();
		int s = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j];
				if (a[i][j] == 'K') {
					s_x = i;
					s_y = j;
				}
				if (a[i][j] == 'T') {
					e_x = i;
					e_y = j;
				}
				if (a[i][j] == 'S') {
					v.push_back(Snake(i, j));//��¼�ߵ�λ������
					s += (1 << (v.size() - 1));
				}
			}
		}
		bool flag = false;
		int mini = INT_MAX;
		q.push(Dot(s_x, s_y, 0, s, 0));
		visited[s_x][s_y][0][s] = 1;
		while (!q.empty()) {
			Dot p = q.front();
			if (p.x == e_x && p.y == e_y && p.k == m) {//����ȷ����ʱ���ǲ������Ž⣬���Բ��˳�ѭ��(���Է��ֲ������Ž�)
				flag = true;
				mini = min(p.t, mini);
				//break;
			}
			for (int i = 0; i < 4; i++) {
				int x = p.x + dx[i], y = p.y + dy[i];
				if (x >= 1 && x <= n && y >= 1 && y <= n) {
					if ((a[x][y] == '.' || a[x][y] == 'K' || a[x][y] == 'T') && visited[x][y][p.k][p.s] == 0) {
						visited[x][y][p.k][p.s] = 1;
						q.push(Dot(x, y, p.k, p.s, p.t + 1));
					}
					if (a[x][y] >= '1' && a[x][y] <= '9') {
						if (p.k + 1 == a[x][y] - '0' && visited[x][y][p.k + 1][p.s] == 0) {
							visited[x][y][p.k + 1][p.s] = 1;
							q.push(Dot(x, y, p.k + 1, p.s, p.t + 1));
						}
						if (p.k + 1 != a[x][y] - '0' && visited[x][y][p.k][p.s] == 0) {
							visited[x][y][p.k][p.s] = 1;
							q.push(Dot(x, y, p.k, p.s, p.t + 1));
						}
					}
					if (a[x][y] == 'S') {
						int i = 0;
						for (i = 0; i < v.size(); i++) {
							if (v[i].x == x && v[i].y == y) {
								if (((p.s >> i) & 1) == 1) {
									if (visited[x][y][p.k][p.s - (1 << i)] == 0) {
										q.push(Dot(x, y, p.k, p.s - (1 << i), p.t + 2));
										visited[x][y][p.k][p.s - (1 << i)] = 1;
									}
								}
								if (((p.s >> i) & 1) == 0) {
									if (visited[x][y][p.k][p.s] == 0) {
										q.push(Dot(x, y, p.k, p.s, p.t + 1));
										visited[x][y][p.k][p.s] = 1;
									}
								}
							}
						}
					}
				}
			}
			q.pop();
		}
		if (flag)
			cout << mini << endl;
		else
			cout << "impossible" << endl;
	}
	return 0;
}
