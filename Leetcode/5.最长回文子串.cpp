/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        bool dp[1010][1010]={0};//dp[i][j]表示从s[i]到s[j]是否是回文串
        int len=1;
        string ans;
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        ans.push_back(s[0]);//注意
        for(int j=0;j<n;j++){
            for(int i=j-1;i>=0;i--){
                dp[i][j]=(i==j-1?s[i]==s[j]:dp[i+1][j-1]&&s[i]==s[j]);//状态转移方程
                if(dp[i][j]){
                    if(len<j-i+1){
                        len=j-i+1;
                        ans=s.substr(i,len);
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

