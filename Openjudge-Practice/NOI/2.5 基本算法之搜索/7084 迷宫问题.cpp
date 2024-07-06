#include<iostream>
#include<cstring>
#include<vector>//不能用queue因为要记录路径，需要保留顺序
using namespace std;
struct Pot{
	int x;
	int y;
	int prev;//记录前一个状态在队列中的位置
	Pot(int xx,int yy,int p):x(xx),y(yy),prev(p){}
	Pot() {}
};
vector<Pot>a(50);
int head = 1, tail = 1;//注意尾指针指向最后一个元素后面
int maze[10][10];
int visited[10][10];
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
void pop() {
	head++;
}
Pot front() {
	return a[head];
}
void push_back(Pot p) {
	a[tail] = p;
	tail++;
}
bool empty() {
	if (head == tail)
		return true;
	else
		return false;
}
int main()
{
	for (int i = 1; i <= 5; i++) {
		for (int j = 1; j <= 5; j++) {
			cin >> maze[i][j];
		}
	}
	visited[1][1] = 1;
	push_back(Pot(1, 1, -1));
	while (!empty()) {
		Pot p;
		p = front();
		if (p.x == 5 && p.y == 5) {
			vector<Pot>ans;
			int pre = p.prev;//回溯路径
			ans.push_back(p);
			while (pre != -1) {
				Pot tmp;
				tmp = a[pre];
				ans.push_back(tmp);
				pre = tmp.prev;
			}
			for (int i = ans.size() - 1; i >= 0; i--)//倒序输出
				cout << '(' << ans[i].x - 1 << ", " << ans[i].y - 1 << ')' << endl;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int x = p.x + dx[i];
			int y = p.y + dy[i];
			if (x >= 1 && x <= 5 && y >= 1 && y <= 5 && maze[x][y] == 0 && visited[x][y] == 0) {
				visited[x][y] = 1;
				push_back(Pot(x, y, head));
			}
		}
		pop();//重要
	}
	return 0;
}
