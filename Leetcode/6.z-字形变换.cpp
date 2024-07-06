/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if(n==1||numRows>=n||numRows==1)
            return s;
        vector<string>rec(numRows,string(1010,' '));
        int x=0,y=0,dir=0;
        for(int i=0;i<n;i++){
            rec[x][y]=s[i];
            if(!dir){
                x++;
                if(x>=numRows){
                    x-=2;
                    y++;
                    dir=1;
                }
            }
            else{
                y++;
                x--;
                if(x<0){
                    x+=2;
                    y--;
                    dir=0;
                }
            }
        }
        string ans;
        int cnt=0;
        for(int i=0;i<numRows;i++){
            for(int j=0;j<1010;j++){
                if(rec[i][j]!=' '){
                    ans.push_back(rec[i][j]);
                    cnt++;
                }
                if(cnt==s.size())
                    goto loop;
            }
        }
        loop:;
        return ans;
    }
};
// @lc code=end

