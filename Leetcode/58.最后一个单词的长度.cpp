/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int cnt=0;
        int len=s.length();
        int i;
        for(i=len-1;i>=0;i--){
            if(s[i]!=' ')
                break;
        }
        for(;i>=0;i--){
            if(s[i]==' ')
                break;
            cnt++;
        }
        return cnt;
    }
};
// @lc code=end

