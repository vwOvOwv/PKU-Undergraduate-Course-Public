/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */

// @lc code=start
class Solution {
    /*
    1.dp
    2.分治
    */
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,0);//dp[i]表示以nums[i]结尾的最大子段和
        dp[0]=nums[0];
        for(int i=1;i<n;i++)
            dp[i]=max(dp[i-1]+nums[i],nums[i]);//决定是否向前延伸
        return *max_element(dp.begin(),dp.end());
    }
};
// @lc code=end

