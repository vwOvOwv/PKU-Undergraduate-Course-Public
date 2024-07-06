#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>

using namespace std;
#define mem(a) memset(a,0,sizeof(a))
//����ⲻ�ܼ򵥵���vis���صģ�û�취������˳��һ��һ����ѣ�������������Ҫһֱ�����ѣ�����ʵ��
//����Ҫ��¼�µ���ÿ��״̬��Ҫ��ʱ��ſ���
int n, m, v, mini, testCase;
char a[110][110];
int dis[110][110][4][11];//��¼��״̬����ʼ״̬�ľ���
int dx[4] = { 0,0,1,-1 }, dy[4] = { 1,-1,0,0 };
struct Node
{
	int x, y, dir, bat, t;
};
queue<Node>q;

void init() {
	mem(a);
	memset(dis, 0x3f, sizeof(dis));
	while (!q.empty())
		q.pop();
	mini = 1 << 30;
}
void bfs() {
	while (!q.empty()) {
		Node p = q.front();
		if (a[p.x][p.y] == 'T')
			mini = min(mini, p.t);
		if (a[p.x][p.y] == 'E') {//�ȿ��ǿ����������
			for (int j = 1; j <= p.bat; j++) {
				int x = p.x + dx[p.dir] * j;
				int y = p.y + dy[p.dir] * j;
				int d = dis[p.x][p.y][p.dir][p.bat];
				x = max(1, x), x = min(x, n);//��ס��
				y = max(1, y), y = min(y, m);
				if (a[x][y] != '#' && dis[x][y][p.dir][j] > d) {//���Ը���ص����״̬
					q.push({ x,y,p.dir,j,d });//ע����µ�ʱ������p.t��Ϊʲô��������
					dis[x][y][p.dir][j] = d;//��״̬������ӣ���Ϊ�õ������״̬�������и��ŵ�·��
				}
			}
		}
		for (int i = 0; i < 4; i++) {//�ٿ���������
			int x = p.x + dx[i], y = p.y + dy[i];
			int d = dis[p.x][p.y][p.dir][p.bat] + 1;
			if (x >= 1 && x <= n && y >= 1 && y <= m) {
				if (a[x][y] != '#') {
					if (dis[x][y][i][p.bat] > d) {//�и���·��
						q.push({ x,y,i,p.bat,d });
						dis[x][y][i][p.bat] = d;
					}
				}
			}
		}
		q.pop();
	}
	cout << "Case #" << ++testCase << ": ";
	if (mini == 1 << 30)
		cout << "-1" << endl;
	else
		cout << mini << endl;
}

int main() {
	while (cin >> n >> m >> v && n) {
		init();
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				cin >> a[i][j];
				if (a[i][j] == 'S') {
					q.push({ i,j,0,v,0 });//��㷽������
					dis[i][j][0][v] = dis[i][j][1][v] = dis[i][j][2][v] = dis[i][j][3][v] = 0;
				}
			}
		}
		bfs();
	}
	return 0;
}
