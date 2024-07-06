#include<iostream>
#include<vector>
#include<cstring>
#include<algorithm>
#include<climits>
#include<cmath>
using namespace std;
char a[110][110];
int k, n;
int s_i, s_j, e_i, e_j;
bool flag;
int visited[110][110];
void dfs(int i, int j) {
    if (flag) 
        return;
    if (i == e_i && j == e_j) {
        flag = true;
        return;
    }
    if (i - 1 >= 1 && a[i - 1][j] != '#' && visited[i - 1][j] == 0) {
        visited[i - 1][j] = 1;
        dfs(i - 1, j);//只需要找到一条路即可，因此无需回溯，回溯是为了选择其他路径（如找最短路径）！！！
    }
    if (i + 1 <= n && a[i + 1][j] != '#' && visited[i + 1][j] == 0) {
        visited[i + 1][j] = 1;
        dfs(i + 1, j);
    }
    if (j - 1 >= 1 && a[i][j - 1] != '#' && visited[i][j - 1] == 0) {
        visited[i][j - 1] = 1;
        dfs(i, j - 1);
    }
    if (j + 1 <= n && a[i][j + 1] != '#' && visited[i][j + 1] == 0) {
        visited[i][j + 1] = 1;
        dfs(i, j + 1);
    }
    return;
}
int main()
{
    cin >> k;
    while (k--) {
        memset(visited, 0, sizeof(visited));
        memset(a, 0, sizeof(a));
        flag = false;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
            }
        }
        cin >> s_i >> s_j >> e_i >> e_j;
        s_i++; s_j++; e_i++; e_j++;
        if (a[s_i][s_j] == '#' || a[e_i][e_j] == '#') {
            cout << "NO" << endl;
            continue;
        }
        visited[s_i][s_j] = 1;
        dfs(s_i, s_j);
        if (flag)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
