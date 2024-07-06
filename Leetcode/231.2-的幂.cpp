/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0)
            return false;
        return !(n&(n-1));
    }
};
// @lc code=end

