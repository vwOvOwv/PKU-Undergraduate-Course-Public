#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

int w, h;
int x1, x2;
int yy1, yy2;
int a[85][85];
int visited[85][85];
bool flag;
int minlen;
int cnt;
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
void dfs(int x1, int y1, int x2, int y2,int memx,int memy) {
	if (x1 == x2 && y1 == y2) {
		flag = true;
		minlen = min(minlen, cnt);
		return;
	}
	for (int i = 0; i < 4; i++) {
		int x = x1 + dx[i];
		int y = y1 + dy[i];
		if ((x >= 0 && x <= h + 1 && y >= 0 && y <= w + 1 && visited[x][y] == 0 && a[x][y] == 0) || (x == x2 && y == y2)) {
			if (memx != -1 && memy != -1 && (x - memx) * (x - memx) + (y - memy) * (y - memy) == 2)//有拐角
				cnt++;
			if (cnt < minlen) {//不剪会超时
				visited[x][y] = 1;
				dfs(x, y, x2, y2, x1, y1);
				visited[x][y] = 0;
			}
			if (memx != -1 && memy != -1 && (x - memx) * (x - memx) + (y - memy) * (y - memy) == 2)
				cnt--;
		}
	}
}
int main()
{
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	int count1 = 0;
	while (cin >> w >> h) {
		if (w == 0 && h == 0)
			break;
		count1++;
		cout << "Board #" << count1 << ':' << endl;
		memset(a, 0, sizeof(a));
		cin.get();//注意
		for (int i = 1; i <= h; i++) {
			for (int j = 1; j <= w+1; j++) {
				char c;
				c = cin.get();
				if (c == 'X')
					a[i][j] = 1;
			}
		}
		int count2 = 0;
		while (cin >> yy1 >> x1 >> yy2 >> x2) {
			if (yy1 == 0 && x1 == 0 && yy2 == 0 && x2 == 0)
				break;
			count2++;
			flag = false;
			cnt = 1;
			minlen = INT_MAX;
			memset(visited, 0, sizeof(visited));
			visited[x1][yy1] = 1;
			dfs(x1, yy1, x2, yy2, -1, -1);
			cout << "Pair " << count2 << ": ";
			if (flag) {
				cout << minlen << " segments." << endl;
			}
			else
				cout << "impossible." << endl;
		}
		cout << endl;
	}
	return 0;
}
