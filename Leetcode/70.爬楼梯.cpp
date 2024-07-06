/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        int t1=1,t2=2,ans=0;
        for(int i=3;i<=n;i++){
            ans=t1+t2;
            t1=t2,t2=ans;
        }
        return ans;
    }
};
// @lc code=end

