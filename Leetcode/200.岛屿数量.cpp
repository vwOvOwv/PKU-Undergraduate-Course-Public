/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
class Solution {
public:
    class Node{
    public:
        int x,y;
        Node(int xx,int yy):x(xx),y(yy){}
    };
    queue<Node>q;
    int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};

    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,0));
        int cnt=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'&&!visited[i][j]){
                    cnt++;
                    while(!q.empty())q.pop();
                    q.push(Node(i,j));
                    visited[i][j]=1;
                    while(!q.empty()){
                        Node p=q.front();
                        for(int i=0;i<4;i++){
                            int x=p.x+dx[i],y=p.y+dy[i];
                            if(x>=0&&x<m&&y>=0&&y<n&&!visited[x][y]&&grid[x][y]=='1'){
                                visited[x][y]=1;
                                q.push(Node(x,y));
                            }
                        }
                        q.pop();
                    }
                }
            }
        }
        return cnt;
    }
};
// @lc code=end

