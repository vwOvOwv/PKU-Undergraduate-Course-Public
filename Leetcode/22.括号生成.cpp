/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    void generate(string ans,int left,int right,vector<string>&rec){
        if(!left&&!right){
            rec.push_back(ans);
            return;
        }
        if(left>right)
            return;
        if(left>0)
            generate(ans+'(',left-1,right,rec);
        if(right>0)
            generate(ans+')',left,right-1,rec);
    }
    vector<string> generateParenthesis(int n) {
        vector<string>rec;
        string ans;
        generate(ans,n,n,rec);
        return rec;
    }
};
// @lc code=end
