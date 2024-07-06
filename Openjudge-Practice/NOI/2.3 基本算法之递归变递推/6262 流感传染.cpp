#include<iostream>
#include<vector>
using namespace std;
vector<int>mem_x;
vector<int>mem_y;
int a[101][101] = { 0 };
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++){
			char c;
			cin >> c;
			if (c == '.')
				a[i][j] = 1;
			if (c == '#')
				a[i][j] = 0;
			if (c == '@') {
				a[i][j] = -1;
				mem_x.push_back(i);
				mem_y.push_back(j);
			}
		}
	int m;
	cin >> m;
	for (int i = 1; i < m; i++) {
		int size = mem_x.size();
		for (int k = 0; k < size; k++) {
			int x = mem_x[k];
			int y = mem_y[k];
			for(int h=x-1;h<=x+1;h++)
				for (int l = y - 1; l <= y + 1; l++) {
					if (h >= 0 && l >= 0 && h < n && l < n) {
						if (abs(h - x) + abs(l - y) > 1)
							continue;
						if (a[h][l] == 1) {
							a[h][l] = -1;
							mem_x.push_back(h);
							mem_y.push_back(l);
						}
					}
				}
		}
	}
	cout << mem_x.size();
	return 0;
}
