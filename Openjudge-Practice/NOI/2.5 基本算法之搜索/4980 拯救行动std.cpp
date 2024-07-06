#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const int maxn = 210;

int n, m, sr, sc;
char g[maxn][maxn];
int G[maxn][maxn];
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
struct Node {
    int r, c, t;
    Node(int r, int c, int t) : r(r), c(c), t(t) {}
};

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d", &m, &n);
        for(int i = 0; i < m; i++) {
            scanf("%s", g[i]);
            for(int j = 0; j < n; j++) {
                if(g[i][j] == 'x') G[i][j] = 2;
                else if(g[i][j] == '@' || g[i][j] == 'a') G[i][j] = 1;
                else if(g[i][j] == 'r') G[i][j] = 0, sr = i, sc = j;
                else G[i][j] = 0;
            }
        }
        queue<Node> q;
        q.push(Node(sr, sc, 0));
        int ans = 1 << 30;
        while(!q.empty()) {
            Node p = q.front();
            if(g[p.r][p.c] == 'a') {
                ans = min(ans, p.t);
                q.pop();
                break;
            }
            if(g[p.r][p.c] == 'x' && G[p.r][p.c] == 1) {
                q.push(Node(p.r, p.c, p.t+1));
                G[p.r][p.c] = 0;
            }
            else {
                for(int i = 0; i < 4; i++) {
                    int tr = p.r+dr[i];
                    int tc = p.c+dc[i];
                    if(tr >= 0 && tr < m && tc >= 0 && tc < n && G[tr][tc]) {
                        if(g[tr][tc] == 'x' && G[tr][tc] == 2) {
                            q.push(Node(tr, tc, p.t+1));
                            G[tr][tc] = 1;
                        }
                        else if(g[tr][tc] != 'x'){
                            q.push(Node(tr, tc, p.t+G[tr][tc]));
                            G[tr][tc] = 0;
                        }

                    }
                }
            }
            q.pop();
        }
        if(ans != 1 << 30) printf("%d\n", ans);
        else printf("Impossible\n");
    }
    return 0;
}
