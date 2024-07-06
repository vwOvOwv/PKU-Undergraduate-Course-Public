/*
 * @lc app=leetcode.cn id=1128 lang=cpp
 *
 * [1128] 等价多米诺骨牌对的数量
 */

// @lc code=start
class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int rec[100]={0};
        int ans=0;
        for(int i=0;i<dominoes.size();i++){
            int a=dominoes[i][0],b=dominoes[i][1];
            if(a>b){//统一大小序
                int tmp=a;
                a=b;
                b=tmp;
            }
            ans+=rec[a*10+b];//当前牌可以与前面每一张一样的牌两两组合
            rec[a*10+b]++;
        }
        return ans;
    }
};
// @lc code=end

