/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution {
public:
    bool repeatedSubstringPattern(string s) {//next数组
        int n=s.size();
        vector<int>next(n+1,0);
        next[0]=-1;
        int j=0,k=-1;
        while(j<n){
            while(k>=0&&s[j]!=s[k])
                k=next[k];
            k++,j++;
            next[j]=k;
        }
        if(n%(n-next[n])==0&&n/(n-next[n])>1)
            return true;
        else
            return false;
    }
};
// @lc code=end

