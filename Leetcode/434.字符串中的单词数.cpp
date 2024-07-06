/*
 * @lc app=leetcode.cn id=434 lang=cpp
 *
 * [434] 字符串中的单词数
 */

// @lc code=start
class Solution {
public:
    int countSegments(string s) {
        int cnt=0,n=s.size();
        if(!n)
            return 0;
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                cnt++;
                while(i<n&&s[i]!=' ')
                    i++;
            }
        }
        return cnt;
    }
};
// @lc code=end

