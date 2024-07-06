/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        long long int y=0;//int会溢出
        int tmp=x;
        while(tmp!=0){
            int t=tmp%10;
            tmp/=10;
            y=y*10+t;
        }
        return y==x;
    }
};
// @lc code=end

