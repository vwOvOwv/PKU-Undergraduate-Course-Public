/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slen=s.size(),tlen=t.size(),p=0,q=0;
        while(p<slen&&q<tlen){
            if(s[p]==t[q])
                p++,q++;
            else
                q++;
        }
        return p==slen;
    }
};
// @lc code=end

