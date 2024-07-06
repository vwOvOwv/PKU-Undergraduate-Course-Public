/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if(n==1)
            return 1;
        if(n==0)
            return 0;
        return fib(n-1)+fib(n-2);
    }
};
// @lc code=end

